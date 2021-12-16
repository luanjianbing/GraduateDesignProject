#include "Algorithm.h"

DetectTypeProcess::DetectTypeProcess() {

}

DetectTypeProcess::~DetectTypeProcess() {

}

// Regular Running Process	（运行的时候需要用到的算法）
bool DetectTypeProcess::Check1TestRegularRunningProcess(cv::Mat &src) {
	std::cout << "DetectTypeProcess::Check1TestRegularRunningProcess" << std::endl;
	return rand() % 2;
}

bool DetectTypeProcess::Check2TestRegularRunningProcess(cv::Mat &src) {
	std::cout << "DetectTypeProcess::Check2TestRegularRunningProcess" << std::endl;
	return rand() % 2;
}

bool DetectTypeProcess::Check3TestRegularRunningProcess(cv::Mat &src) {
	std::cout << "DetectTypeProcess::Check3TestRegularRunningProcess" << std::endl;
	return rand() % 2;
}

bool DetectTypeProcess::Check4TestRegularRunningProcess(cv::Mat &src) {
	std::cout << "DetectTypeProcess::Check4TestRegularRunningProcess" << std::endl;
	return rand() % 2;
}

bool DetectTypeProcess::Check5TestRegularRunningProcess(cv::Mat &src) {
	std::cout << "DetectTypeProcess::Check5TestRegularRunningProcess" << std::endl;
	return rand() % 2;
}

bool DetectTypeProcess::Check6TestRegularRunningProcess(cv::Mat &src) {
	std::cout << "DetectTypeProcess::Check6TestRegularRunningProcess" << std::endl;
	return rand() % 2;
}

/*************************************************************/
DetectTypeRegulation::DetectTypeRegulation() {
	
}

DetectTypeRegulation::~DetectTypeRegulation() {
	
}

namespace Model {
	AlgorithmInterface::AlgorithmInterface() {
		if (mDetectTypeProcess == NULL)
			mDetectTypeProcess = new DetectTypeProcess();
	}
	
	AlgorithmInterface::~AlgorithmInterface() {
		if (mDetectTypeProcess != NULL)
			delete mDetectTypeProcess;
	}

	std::vector<std::string> AlgorithmInterface::getDetectTypeSettingNames() {
		return mDetectTypeSettingNames;
	}

	std::vector<std::vector<std::string>> AlgorithmInterface::getDetectTypeSettingParamNames() {
		return mDetectTypeSettingParamNames;
	}

	std::vector<bool> AlgorithmInterface::taskRun(std::vector<cv::Mat> &camerasMat,
		std::map<int, std::vector<int>> &mCameraParamIndex,
		std::map<int, int> &mBlockToCameraIndex,
		std::vector<std::vector<int>> &mBlockParam,
		std::vector<std::vector<int>> &mSettingParam) {

		// mCameraParamIndex;	// 每个相机对应的编号<cameraIndex, [这个相机对应的参数编号]>
		// mBlockToCameraIndex;	// 这个block对应的相机编号<blockIndex，[这个block是第几个相机的参数]>
		// mBlockParam;	// <blockIndex, [x1, y1, x2, y2]>
		// mSettingParam;	// <blockIndex, [设置的检测参数数据]>

		int taskNum = mSettingParam.size();

		errorCheckCateIndex.clear();
		errorCheckCateIndex.resize(taskNum);

		// (TODO)当前测试是单线程
		std::vector<bool> ans(taskNum, true);
		for (int i = 0; i < taskNum; ++i) {	// 测试从0开始
			cv::Mat thisCameraMat = camerasMat[mBlockToCameraIndex[i]]
				(cv::Range(mBlockParam[i][1], mBlockParam[i][3]), cv::Range(mBlockParam[i][0], mBlockParam[i][2]));		// 取出block图像
			// 获取单个任务的每个检测需求
			int singleCheckStatus = 0;
			for (int singleCheckIdx = 0; singleCheckIdx < mDetectTypeSettingNames.size(); ++singleCheckIdx) {
				int singleCheckStatusIdx = 0;	// 记录每种检测类型的检测标志位
				for (int tmpCountIdx = 0; tmpCountIdx < singleCheckIdx; ++tmpCountIdx) {
					singleCheckStatusIdx += (1 + mDetectTypeSettingParamNames[tmpCountIdx].size());
				}
				//singleCheckStatusIdx += 1;	// 得到每个处理类型的检测与否

				singleCheckStatus = mSettingParam[i][singleCheckStatusIdx];
				bool singleCheckResult = true;

				if (singleCheckStatus == 1) {
					switch (singleCheckIdx)
					{
						// 当前只有六个测试检测类型
						case 0: {
							singleCheckResult = Check1TestRegularRunningProcess(thisCameraMat);
							break;
						}
						case 1: {
							singleCheckResult = Check2TestRegularRunningProcess(thisCameraMat);
							break;
						}
						case 2: {
							singleCheckResult = Check3TestRegularRunningProcess(thisCameraMat);
							break;
						}
						case 3: {
							singleCheckResult = Check4TestRegularRunningProcess(thisCameraMat);
							break;
						}
						case 4: {
							singleCheckResult = Check5TestRegularRunningProcess(thisCameraMat);
							break;
						}
						case 5: {
							singleCheckResult = Check6TestRegularRunningProcess(thisCameraMat);
							break;
						}
						default:
							break;
					}
				}
				// 错误的话保存对应的检测类型
				if (!singleCheckResult) {
					errorCheckCateIndex[i].push_back(singleCheckIdx);
				}
				// 更新单个任务整体的处理结果
				ans[i] = ans[i] & singleCheckResult;
			}
		}
		return ans;
	}

	std::vector<int> AlgorithmInterface::getTargetTaskErrorCheck(int taskIndex) {
		return errorCheckCateIndex[taskIndex];
	}

	// 具体的算法处理，这里写完需要在Controller进一步做封装
	void AlgorithmInterface::Check1TestSettingPreprocess1(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreprocess1" << std::endl;
		mDetectTypeProcess->Check1TestSettingPreprocess1(src);
	}

	int AlgorithmInterface::Check1TestSettingPreProcess2(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreProcess2" << std::endl;
		return mDetectTypeProcess->Check1TestSettingPreProcess2(src);
	}

	// Regular Running Process	（运行的时候需要用到的算法）
	bool AlgorithmInterface::Check1TestRegularRunningProcess(cv::Mat &src) {
		return mDetectTypeProcess->Check1TestRegularRunningProcess(src);
	}

	bool AlgorithmInterface::Check2TestRegularRunningProcess(cv::Mat &src) {
		return mDetectTypeProcess->Check2TestRegularRunningProcess(src);
	}

	bool AlgorithmInterface::Check3TestRegularRunningProcess(cv::Mat &src) {
		return mDetectTypeProcess->Check3TestRegularRunningProcess(src);
	}

	bool AlgorithmInterface::Check4TestRegularRunningProcess(cv::Mat &src) {
		return mDetectTypeProcess->Check4TestRegularRunningProcess(src);
	}

	bool AlgorithmInterface::Check5TestRegularRunningProcess(cv::Mat &src) {
		return mDetectTypeProcess->Check5TestRegularRunningProcess(src);
	}

	bool AlgorithmInterface::Check6TestRegularRunningProcess(cv::Mat &src) {
		return mDetectTypeProcess->Check6TestRegularRunningProcess(src);
	}
}