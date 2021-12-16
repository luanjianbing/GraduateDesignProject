#include "Controller.h"
namespace Controller {
	Model::CamerasInterface *CameraController::mCameras = NULL;

	//void CameraSingleShotWorker::doWork(int i) {
	//	std::cout << "doWork:" << mCameras->getSingleImage(i, retPic) << std::endl;
	//	
	//	emit resultReady(1);
	//}

	//int CameraSingleShotWorker::getCameraNums() {
	//	return mCameras->getCameraNums();
	//}

	//bool CameraSingleShotWorker::getSingleImage(int cameraIdx, cv::Mat &singleMat) {
	//	return mCameras->getSingleImage(cameraIdx, singleMat);
	//}

	//cv::Size CameraSingleShotWorker::getCameraSize(int cameraIdx) {
	//	return mCameras->getCameraSize(cameraIdx);
	//}

	//cv::Mat CameraSingleShotWorker::getTest() {
	//	return retPic.clone();
	//}
}

namespace Controller {
	Model::DataBaseInterface *DomainController::mDataBase = NULL;
}

namespace Controller {
	Model::AlgorithmInterface *DomainController::mAlgorithm = NULL;
}

namespace Controller {
	// 需要在cpp文件中对类中的static变量做初始化，不然会报错
	DomainController *DomainController::uniqueInstance = nullptr;
	std::mutex DomainController::mMutex;

	DomainController::~DomainController() {
		//workerThread.quit();
		//workerThread.wait();
	}

	/********************************Camera Controller********************************/
	int DomainController::getCameraNums() {
		return mCameras->getCameraNums();
	}

	bool DomainController::getSingleImage(int cameraIdx, cv::Mat &singleMat) {
		return mCameras->getSingleImage(cameraIdx, singleMat);
	}

	cv::Size DomainController::getCameraSize(int cameraIdx) {
		return mCameras->getCameraSize(cameraIdx);
	}

	//void DomainController::handleResults(const int result) {
	//	std::cout << "handleResults" << std::endl;
	//	cv::Mat test = worker->getTest();
	//	cv::imwrite("result.jpg", test);
	//	emit getPicFinished();
	//	
	//}

	//void DomainController::setPicTest() {
	//	emit operate(0);
	//}

	//void DomainController::getPicTest() {
	//	//CameraSingleShotWorker *worker = new CameraSingleShotWorker;
	//	////调用moveToThread将该任务交给workThread
	//	//worker->moveToThread(&workerThread);
	//	////operate信号发射后启动线程工作
	//	//connect(this, SIGNAL(operate(const int)), worker, SLOT(doWork(int)));
	//	////该线程结束时销毁
	//	//connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
	//	////线程结束后发送信号，对结果进行处理
	//	//connect(worker, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
	//	////启动线程
	//	//workerThread.start();
	//	emit operate(0);
	//}

	/********************************Database Controller********************************/
	bool DomainController::userTryLogIn(std::string userName, std::string userPassward) {
		return true;
	}

	bool DomainController::userTryRegister(std::string userName, std::string userPassward) {
		return true;
	}

	std::vector<std::string> DomainController::readAllModelNames() {
		try
		{
			std::vector<std::vector<std::string>> mTable = mDataBase->queryAllData("model_name", 2);
			std::vector<std::string> ans(mTable.size());
			for (int i = 0; i < ans.size(); ++i)
				ans[i] = mTable[i][1];
			return ans;
		}
		catch (const std::exception &e)
		{
			std::cout << "DomainController::readAllModelNames()->" << e.what() << std::endl;
			return {};
		}
	}

	void DomainController::addNewModelName(int newModelNum, std::string newModelName) {
		try
		{
			std::vector<std::string> newModelRow = { std::to_string(newModelNum), newModelName };
			mDataBase->insertSingleRowData("model_name", newModelRow);
		}
		catch (const std::exception &e)
		{
			std::cout << "DomainController::addNewModelName()->" << e.what() << std::endl;
		}
	}

	// 坐标表
	std::vector<std::vector<int>> DomainController::readTargetModelBlockParam(std::string targetModelName) {
		std::vector<std::vector<int>> mBlockParam;

		// 查询对应的model_id
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}
		if (targetSaveModelIndex != -1) {
			try
			{
				std::vector<std::vector<std::string>> queryAns;
				// 计算对应的col个数
				int colNum = mDataBase->findColNumsFromTargetTable("model_block");
				queryAns = mDataBase->queryAllData("model_block", colNum, "model_id", std::to_string(targetSaveModelIndex), "id");
				// 取出后面的坐标
				for (int i = 0; i < queryAns.size(); ++i) {
					std::vector<int> tmpSingleBlock = 
					{ atoi(queryAns[i][2].c_str()), atoi(queryAns[i][3].c_str()), atoi(queryAns[i][4].c_str()), atoi(queryAns[i][5].c_str()) };
					mBlockParam.push_back(tmpSingleBlock);
				}
			}
			catch (const std::exception &e)
			{
				std::cout << "DomainController::readTargetModelBlockParam()->" << e.what() << std::endl;
			}
		}
		else {
			std::cout << "DomainController::readTargetModelBlockParam()->not find targetSaveModelIndex" << std::endl;
		}

		return mBlockParam;
	}

	void DomainController::saveTargetModelBlockParam(std::vector<std::vector<int>> &mBlockParam, std::string targetModelName) {
		// 拿到modelName对应的index
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}
		//std::cout << "get target model index -> " << targetSaveModelIndex << std::endl;

		if (targetSaveModelIndex != -1) {
			// 拿到的block是没有id的，需要在这里添加id
			std::vector<std::vector<std::string>> tmpBlockParam;
			for (int i = 0; i < mBlockParam.size(); ++i) {
				std::vector<std::string> tmpSingleBlock;
				tmpSingleBlock.push_back(std::to_string(targetSaveModelIndex));	// 压入model_id
				tmpSingleBlock.push_back(std::to_string(i));
				for (int j = 0; j < mBlockParam[i].size(); ++j)
					tmpSingleBlock.push_back(std::to_string(mBlockParam[i][j]));
				tmpBlockParam.push_back(tmpSingleBlock);
			}
			try
			{
				mDataBase->deleteAndReplaceSatisfiedNewData("model_block", tmpBlockParam, "model_id", targetSaveModelIndex);
			}
			catch (const std::exception &e)
			{
				std::cout << "DomainController::saveTargetModelBlockParam()->" << e.what() << std::endl;
			}
		}
		else {
			std::cout << "DomainController::saveTargetModelBlockParam()->not find targetSaveModelIndex" << std::endl;
		}
	}

	// 参数表（根据模型名称与param大小去创建，因为不知道有多少列）
	std::vector<std::vector<int>> DomainController::readTargetModelSettingParam(std::string targetModelName) {
		std::vector<std::vector<int>> mSettingParam;

		std::string tmpTableName = targetModelName + "_setting_param";
		try
		{
			std::vector<std::vector<std::string>> queryAns;
			// 计算对应的col个数
			int colNum = mDataBase->findColNumsFromTargetTable(tmpTableName.c_str());
			queryAns = mDataBase->queryAllData(tmpTableName.c_str(), colNum, "id");
			// 取出后面的参数
			for (int i = 0; i < queryAns.size(); ++i) {
				std::vector<int> tmpSingleParam;
				for (int j = 1; j < queryAns[i].size(); ++j) {
					tmpSingleParam.push_back(atoi(queryAns[i][j].c_str()));
				}
				mSettingParam.push_back(tmpSingleParam);
			}
		}
		catch (const std::exception &e)
		{
			std::cout << "DomainController::saveTargetModelBlockParam()->" << e.what() << std::endl;
		}

		return mSettingParam;
	}

	void DomainController::saveTargetModelSettingParam(std::vector<std::vector<int>> &mSettingParam, std::string targetModelName) {
		// 创建model_name + "_setting_param"表
		std::vector<std::string> mDetectTypeSettingNames = this->getDetectTypeSettingNames();	// 获取在这个过程中需要的参数名称
		std::vector<std::vector<std::string>> mDetectTypeSettingParamNames = this->getDetectTypeSettingParamNames();	// 获取在这个过程中需要的参数

		std::vector<std::string> tabelName;
		tabelName.push_back("id");
		for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
			tabelName.push_back(mDetectTypeSettingNames[i]);
			for (int j = 0; j < mDetectTypeSettingParamNames[i].size(); ++j) {
				tabelName.push_back(mDetectTypeSettingParamNames[i][j]);
			}
		}
		
		// 创建表格
		std::string tmpTableName = targetModelName + "_setting_param";

		if (mDataBase->findTargetTable(tmpTableName.c_str())) {	// 如果已经新建过这个表的话，直接删掉表格
			mDataBase->deleteTabel(tmpTableName.c_str());
		}
		// 新建表格
		try
		{
			mDataBase->createTargetTable(tmpTableName.c_str(), tabelName);
		}
		catch (const std::exception &e)
		{
			std::cout << "DomainController::saveTargetModelSettingParam(create)->" << e.what() << std::endl;
		}

		// 往表格中插入数据(增加id列)
		std::vector<std::vector<std::string>> tmpSettingParam;
		for (int i = 0; i < mSettingParam.size(); ++i) {
			std::vector<std::string> tmpSingleSettingParam;
			tmpSingleSettingParam.push_back(std::to_string(i));
			for (int j = 0; j < mSettingParam[i].size(); ++j) {
				tmpSingleSettingParam.push_back(std::to_string(mSettingParam[i][j]));
			}
			tmpSettingParam.push_back(tmpSingleSettingParam);
		}

		try
		{
			mDataBase->deleteAndReplaceNewData(tmpTableName.c_str(), tmpSettingParam);
		}
		catch (const std::exception &e)
		{
			std::cout << "DomainController::saveTargetModelSettingParam(save)->" << e.what() << std::endl;
		}

	}

	// <blockIndex, cameraIndex>
	std::map<int, int> DomainController::readTargetModelBlock2CameraIndexParam(std::string targetModelName) {
		std::map<int, int> mBlockToCameraIndex;

		// 查询对应的model_id
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}

		if (targetSaveModelIndex != -1) {
			try
			{
				std::vector<std::vector<std::string>> queryAns;
				// 计算对应的col个数
				int colNum = mDataBase->findColNumsFromTargetTable("model_block_to_camera_index");
				queryAns = mDataBase->queryAllData("model_block_to_camera_index", colNum, "model_id", std::to_string(targetSaveModelIndex), "block_idx");
				// 取出后面的两列
				for (int i = 0; i < queryAns.size(); ++i) {
					mBlockToCameraIndex.insert({ atoi(queryAns[i][1].c_str()), atoi(queryAns[i][2].c_str()) });
				}
			}
			catch (const std::exception &e)
			{
				std::cout << "DomainController::readTargetModelBlock2CameraIndexParam()->" << e.what() << std::endl;
			}
		}
		else {
			std::cout << "DomainController::readTargetModelBlock2CameraIndexParam()->not find targetSaveModelIndex" << std::endl;
		}

		return mBlockToCameraIndex;
	}

	void DomainController::saveTargetModelBlock2CameraIndexParam(std::map<int, int> &mBlockToCameraIndex, std::string targetModelName) {
		// 拿到modelName对应的index
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}

		if (targetSaveModelIndex != -1) {
			// 添加id
			std::vector<std::vector<std::string>> tmpBlock2CameraIndexParam;
			for (auto iter = mBlockToCameraIndex.begin(); iter != mBlockToCameraIndex.end(); ++iter) {
				std::vector<std::string> tmpSingleBlock2Camera;
				tmpSingleBlock2Camera.push_back(std::to_string(targetSaveModelIndex));	// 压入model_id
				tmpSingleBlock2Camera.push_back(std::to_string(iter->first));
				tmpSingleBlock2Camera.push_back(std::to_string(iter->second));
				tmpBlock2CameraIndexParam.push_back(tmpSingleBlock2Camera);
			}

			// 删除符合条件的数据，然后插入新的数据
			try
			{
				mDataBase->deleteAndReplaceSatisfiedNewData("model_block_to_camera_index", tmpBlock2CameraIndexParam, "model_id", targetSaveModelIndex);
			}
			catch (const std::exception &e)
			{
				std::cout << "DomainController::saveTargetModelBlock2CameraIndexParam()->" << e.what() << std::endl;
			}
		}
		else {
			std::cout << "DomainController::saveTargetModelBlock2CameraIndexParam()->not find targetSaveModelIndex" << std::endl;
		}
	}

	// <cameraIndex, [blockIndex]>
	std::map<int, std::vector<int>> DomainController::readTargetModelCamera2BlockIndexParam(std::string targetModelName) {
		std::map<int, std::vector<int>> mCameraParamIndex;

		// 查询对应的model_id
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}

		if (targetSaveModelIndex != -1) {
			try
			{
				std::vector<std::vector<std::string>> queryAns;
				// 计算对应的col个数
				int colNum = mDataBase->findColNumsFromTargetTable("model_camera_to_block_index");
				queryAns = mDataBase->queryAllData("model_camera_to_block_index", colNum, "model_id", std::to_string(targetSaveModelIndex), "camera_idx");
				// 取出后面的两列
				for (int i = 0; i < queryAns.size(); ++i) {
					std::string tmpBlockIdxStr = queryAns[i][2];
					QString tmpBlockIdxQStr = QString::fromStdString(tmpBlockIdxStr);
					QStringList tmpBlockListQStr = tmpBlockIdxQStr.split("#");
					std::vector<int> tmpSingleBlockIdx;
					for (int j = 1; j < tmpBlockListQStr.size() - 1; ++j) {	// 去掉头和尾，剩下的压入
						tmpSingleBlockIdx.push_back(atoi(tmpBlockListQStr[j].toStdString().c_str()));
					}
					mCameraParamIndex.insert({ atoi(queryAns[i][1].c_str()), tmpSingleBlockIdx });
				}
			}
			catch (const std::exception &e)
			{
				std::cout << "DomainController::readTargetModelBlock2CameraIndexParam()->" << e.what() << std::endl;
			}
		}
		else {
			std::cout << "DomainController::readTargetModelBlock2CameraIndexParam()->not find targetSaveModelIndex" << std::endl;
		}

		return mCameraParamIndex;
	}

	void DomainController::saveTargetModelCamera2BlockIndexParam(std::map<int, std::vector<int>> &mCameraParamIndex, std::string targetModelName) {
		// 以‘#’作为分割的编号
		// 拿到modelName对应的index
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}

		if (targetSaveModelIndex != -1) {
			// 添加id
			std::vector<std::vector<std::string>> tmpCamera2BlockIndexParam;
			for (auto iter = mCameraParamIndex.begin(); iter != mCameraParamIndex.end(); ++iter) {
				std::vector<std::string> tmpSingleCamera2Block;
				tmpSingleCamera2Block.push_back(std::to_string(targetSaveModelIndex));	// 压入model_id

				tmpSingleCamera2Block.push_back(std::to_string(iter->first));
				// 编码camera所包括的各个block
				std::string tmpSingleBlockCombineString = "#";
				for (int j = 0; j < iter->second.size(); ++j) {
					tmpSingleBlockCombineString.append(std::to_string(iter->second[j])).append("#");
				}
				tmpSingleCamera2Block.push_back(tmpSingleBlockCombineString);
				tmpCamera2BlockIndexParam.push_back(tmpSingleCamera2Block);
			}
			// 删除符合条件的数据，然后插入新的数据
			try
			{
				mDataBase->deleteAndReplaceSatisfiedNewData("model_camera_to_block_index", tmpCamera2BlockIndexParam, "model_id", targetSaveModelIndex);
			}
			catch (const std::exception &e)
			{
				std::cout << "DomainController::saveTargetModelBlock2CameraIndexParam()->" << e.what() << std::endl;
			}
		}
		else {
			std::cout << "DomainController::saveTargetModelCamera2BlockIndexParam()->not find targetSaveModelIndex" << std::endl;
		}
	}

	/********************************Algorithm Controller********************************/
	std::vector<std::string> DomainController::getDetectTypeSettingNames() {
		return mAlgorithm->getDetectTypeSettingNames();
	}

	std::vector<std::vector<std::string>> DomainController::getDetectTypeSettingParamNames() {
		return mAlgorithm->getDetectTypeSettingParamNames();
	}

	void DomainController::Check1TestSettingPreprocess1(cv::Mat &src) {
		return mAlgorithm->Check1TestSettingPreprocess1(src);
	}

	int DomainController::Check1TestSettingPreProcess2(cv::Mat &src) {
		return mAlgorithm->Check1TestSettingPreProcess2(src);
	}

	std::vector<bool> DomainController::taskRun(std::vector<cv::Mat> &camerasMat,
		std::map<int, std::vector<int>> &mCameraParamIndex,
		std::map<int, int> &mBlockToCameraIndex,
		std::vector<std::vector<int>> &mBlockParam,
		std::vector<std::vector<int>> &mSettingParam) {
		return mAlgorithm->taskRun(camerasMat, mCameraParamIndex, mBlockToCameraIndex, mBlockParam, mSettingParam);
	}

	std::vector<int> DomainController::getTargetTaskErrorCheck(int taskIndex) {
		return mAlgorithm->getTargetTaskErrorCheck(taskIndex);
	}
}