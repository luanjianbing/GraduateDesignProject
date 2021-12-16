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
	// ��Ҫ��cpp�ļ��ж����е�static��������ʼ������Ȼ�ᱨ��
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
	//	////����moveToThread�������񽻸�workThread
	//	//worker->moveToThread(&workerThread);
	//	////operate�źŷ���������̹߳���
	//	//connect(this, SIGNAL(operate(const int)), worker, SLOT(doWork(int)));
	//	////���߳̽���ʱ����
	//	//connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
	//	////�߳̽��������źţ��Խ�����д���
	//	//connect(worker, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
	//	////�����߳�
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

	// �����
	std::vector<std::vector<int>> DomainController::readTargetModelBlockParam(std::string targetModelName) {
		std::vector<std::vector<int>> mBlockParam;

		// ��ѯ��Ӧ��model_id
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
				// �����Ӧ��col����
				int colNum = mDataBase->findColNumsFromTargetTable("model_block");
				queryAns = mDataBase->queryAllData("model_block", colNum, "model_id", std::to_string(targetSaveModelIndex), "id");
				// ȡ�����������
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
		// �õ�modelName��Ӧ��index
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
			// �õ���block��û��id�ģ���Ҫ���������id
			std::vector<std::vector<std::string>> tmpBlockParam;
			for (int i = 0; i < mBlockParam.size(); ++i) {
				std::vector<std::string> tmpSingleBlock;
				tmpSingleBlock.push_back(std::to_string(targetSaveModelIndex));	// ѹ��model_id
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

	// ����������ģ��������param��Сȥ��������Ϊ��֪���ж����У�
	std::vector<std::vector<int>> DomainController::readTargetModelSettingParam(std::string targetModelName) {
		std::vector<std::vector<int>> mSettingParam;

		std::string tmpTableName = targetModelName + "_setting_param";
		try
		{
			std::vector<std::vector<std::string>> queryAns;
			// �����Ӧ��col����
			int colNum = mDataBase->findColNumsFromTargetTable(tmpTableName.c_str());
			queryAns = mDataBase->queryAllData(tmpTableName.c_str(), colNum, "id");
			// ȡ������Ĳ���
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
		// ����model_name + "_setting_param"��
		std::vector<std::string> mDetectTypeSettingNames = this->getDetectTypeSettingNames();	// ��ȡ�������������Ҫ�Ĳ�������
		std::vector<std::vector<std::string>> mDetectTypeSettingParamNames = this->getDetectTypeSettingParamNames();	// ��ȡ�������������Ҫ�Ĳ���

		std::vector<std::string> tabelName;
		tabelName.push_back("id");
		for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
			tabelName.push_back(mDetectTypeSettingNames[i]);
			for (int j = 0; j < mDetectTypeSettingParamNames[i].size(); ++j) {
				tabelName.push_back(mDetectTypeSettingParamNames[i][j]);
			}
		}
		
		// �������
		std::string tmpTableName = targetModelName + "_setting_param";

		if (mDataBase->findTargetTable(tmpTableName.c_str())) {	// ����Ѿ��½��������Ļ���ֱ��ɾ�����
			mDataBase->deleteTabel(tmpTableName.c_str());
		}
		// �½����
		try
		{
			mDataBase->createTargetTable(tmpTableName.c_str(), tabelName);
		}
		catch (const std::exception &e)
		{
			std::cout << "DomainController::saveTargetModelSettingParam(create)->" << e.what() << std::endl;
		}

		// ������в�������(����id��)
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

		// ��ѯ��Ӧ��model_id
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
				// �����Ӧ��col����
				int colNum = mDataBase->findColNumsFromTargetTable("model_block_to_camera_index");
				queryAns = mDataBase->queryAllData("model_block_to_camera_index", colNum, "model_id", std::to_string(targetSaveModelIndex), "block_idx");
				// ȡ�����������
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
		// �õ�modelName��Ӧ��index
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}

		if (targetSaveModelIndex != -1) {
			// ���id
			std::vector<std::vector<std::string>> tmpBlock2CameraIndexParam;
			for (auto iter = mBlockToCameraIndex.begin(); iter != mBlockToCameraIndex.end(); ++iter) {
				std::vector<std::string> tmpSingleBlock2Camera;
				tmpSingleBlock2Camera.push_back(std::to_string(targetSaveModelIndex));	// ѹ��model_id
				tmpSingleBlock2Camera.push_back(std::to_string(iter->first));
				tmpSingleBlock2Camera.push_back(std::to_string(iter->second));
				tmpBlock2CameraIndexParam.push_back(tmpSingleBlock2Camera);
			}

			// ɾ���������������ݣ�Ȼ������µ�����
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

		// ��ѯ��Ӧ��model_id
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
				// �����Ӧ��col����
				int colNum = mDataBase->findColNumsFromTargetTable("model_camera_to_block_index");
				queryAns = mDataBase->queryAllData("model_camera_to_block_index", colNum, "model_id", std::to_string(targetSaveModelIndex), "camera_idx");
				// ȡ�����������
				for (int i = 0; i < queryAns.size(); ++i) {
					std::string tmpBlockIdxStr = queryAns[i][2];
					QString tmpBlockIdxQStr = QString::fromStdString(tmpBlockIdxStr);
					QStringList tmpBlockListQStr = tmpBlockIdxQStr.split("#");
					std::vector<int> tmpSingleBlockIdx;
					for (int j = 1; j < tmpBlockListQStr.size() - 1; ++j) {	// ȥ��ͷ��β��ʣ�µ�ѹ��
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
		// �ԡ�#����Ϊ�ָ�ı��
		// �õ�modelName��Ӧ��index
		std::vector<std::string> tmpModelNames = this->readAllModelNames();
		int targetSaveModelIndex = -1;
		for (int i = 0; i < tmpModelNames.size(); ++i) {
			if (tmpModelNames[i] == targetModelName) {
				targetSaveModelIndex = i;
				break;
			}
		}

		if (targetSaveModelIndex != -1) {
			// ���id
			std::vector<std::vector<std::string>> tmpCamera2BlockIndexParam;
			for (auto iter = mCameraParamIndex.begin(); iter != mCameraParamIndex.end(); ++iter) {
				std::vector<std::string> tmpSingleCamera2Block;
				tmpSingleCamera2Block.push_back(std::to_string(targetSaveModelIndex));	// ѹ��model_id

				tmpSingleCamera2Block.push_back(std::to_string(iter->first));
				// ����camera�������ĸ���block
				std::string tmpSingleBlockCombineString = "#";
				for (int j = 0; j < iter->second.size(); ++j) {
					tmpSingleBlockCombineString.append(std::to_string(iter->second[j])).append("#");
				}
				tmpSingleCamera2Block.push_back(tmpSingleBlockCombineString);
				tmpCamera2BlockIndexParam.push_back(tmpSingleCamera2Block);
			}
			// ɾ���������������ݣ�Ȼ������µ�����
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