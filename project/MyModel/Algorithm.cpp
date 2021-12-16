#include "Algorithm.h"

DetectTypeProcess::DetectTypeProcess() {

}

DetectTypeProcess::~DetectTypeProcess() {

}

// Regular Running Process	�����е�ʱ����Ҫ�õ����㷨��
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

		// mCameraParamIndex;	// ÿ�������Ӧ�ı��<cameraIndex, [��������Ӧ�Ĳ������]>
		// mBlockToCameraIndex;	// ���block��Ӧ��������<blockIndex��[���block�ǵڼ�������Ĳ���]>
		// mBlockParam;	// <blockIndex, [x1, y1, x2, y2]>
		// mSettingParam;	// <blockIndex, [���õļ���������]>

		int taskNum = mSettingParam.size();

		errorCheckCateIndex.clear();
		errorCheckCateIndex.resize(taskNum);

		// (TODO)��ǰ�����ǵ��߳�
		std::vector<bool> ans(taskNum, true);
		for (int i = 0; i < taskNum; ++i) {	// ���Դ�0��ʼ
			cv::Mat thisCameraMat = camerasMat[mBlockToCameraIndex[i]]
				(cv::Range(mBlockParam[i][1], mBlockParam[i][3]), cv::Range(mBlockParam[i][0], mBlockParam[i][2]));		// ȡ��blockͼ��
			// ��ȡ���������ÿ���������
			int singleCheckStatus = 0;
			for (int singleCheckIdx = 0; singleCheckIdx < mDetectTypeSettingNames.size(); ++singleCheckIdx) {
				int singleCheckStatusIdx = 0;	// ��¼ÿ�ּ�����͵ļ���־λ
				for (int tmpCountIdx = 0; tmpCountIdx < singleCheckIdx; ++tmpCountIdx) {
					singleCheckStatusIdx += (1 + mDetectTypeSettingParamNames[tmpCountIdx].size());
				}
				//singleCheckStatusIdx += 1;	// �õ�ÿ���������͵ļ�����

				singleCheckStatus = mSettingParam[i][singleCheckStatusIdx];
				bool singleCheckResult = true;

				if (singleCheckStatus == 1) {
					switch (singleCheckIdx)
					{
						// ��ǰֻ���������Լ������
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
				// ����Ļ������Ӧ�ļ������
				if (!singleCheckResult) {
					errorCheckCateIndex[i].push_back(singleCheckIdx);
				}
				// ���µ�����������Ĵ�����
				ans[i] = ans[i] & singleCheckResult;
			}
		}
		return ans;
	}

	std::vector<int> AlgorithmInterface::getTargetTaskErrorCheck(int taskIndex) {
		return errorCheckCateIndex[taskIndex];
	}

	// ������㷨��������д����Ҫ��Controller��һ������װ
	void AlgorithmInterface::Check1TestSettingPreprocess1(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreprocess1" << std::endl;
		mDetectTypeProcess->Check1TestSettingPreprocess1(src);
	}

	int AlgorithmInterface::Check1TestSettingPreProcess2(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreProcess2" << std::endl;
		return mDetectTypeProcess->Check1TestSettingPreProcess2(src);
	}

	// Regular Running Process	�����е�ʱ����Ҫ�õ����㷨��
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