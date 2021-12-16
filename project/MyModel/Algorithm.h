#pragma once

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>
#include <map>

#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>

// �������ü�����Ͷ�Ӧ�Ĵ���(�㷨)
class DetectTypeProcess {
public:
	DetectTypeProcess();
	~DetectTypeProcess();

	// Setting Preprocess	(���õ�ʱ����Ҫ�õ���Ԥ�����㷨)
	void Check1TestSettingPreprocess1(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreprocess1" << std::endl;
	}

	int Check1TestSettingPreProcess2(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreProcess2" << std::endl;
		return privateTestProcess2(src);
	}

	// Regular Running Process	�����е�ʱ����Ҫ�õ����㷨��
	bool Check1TestRegularRunningProcess(cv::Mat &src);
	bool Check2TestRegularRunningProcess(cv::Mat &src);
	bool Check3TestRegularRunningProcess(cv::Mat &src);
	bool Check4TestRegularRunningProcess(cv::Mat &src);
	bool Check5TestRegularRunningProcess(cv::Mat &src);
	bool Check6TestRegularRunningProcess(cv::Mat &src);

private:
	// �޹صĴ����㷨����Ϊ˽��
	void privateTestProcess1(cv::Mat &src) {
		std::cout << "DetectTypeProcess::privateTestProcess1" << std::endl;
	}

	int privateTestProcess2(cv::Mat &src) {
		std::cout << "DetectTypeProcess::privateTestProcess2" << std::endl;
		return 9526;
	}
};

// �涨��������Լ���Ҫʹ�õ��㷨
class DetectTypeRegulation {
public:
	DetectTypeRegulation();
	~DetectTypeRegulation();
private:
	
protected:
	std::vector<std::string> mDetectTypeSettingNames = {
		"Check1",
		"Check2",
		"Check3",
		"Check4",
		"Check5",
		"Check6",
	};	// ������������
	std::vector<std::vector<std::string>> mDetectTypeSettingParamNames = {
		{ "param1", "param2" },
		{},
		{ "param3", "param4" },
		{ "param5" },
		{ "param6", "param7" },
		{},
	};	// ��Щ���������Ҫ���� (������Ҫ�����������ȥ���������Բ��������Ʋ���һ������������ͬ������)
};


namespace Model {
	// ������Ľӿ�
	class AlgorithmInterface : 
		public DetectTypeRegulation {
	public:
		AlgorithmInterface();
		~AlgorithmInterface();

		std::vector<std::string> getDetectTypeSettingNames();
		std::vector<std::vector<std::string>> getDetectTypeSettingParamNames();

		// ������㷨��������д����Ҫ��Controller��һ������װ
		void Check1TestSettingPreprocess1(cv::Mat &src);
		int Check1TestSettingPreProcess2(cv::Mat &src);
		
		// ʵ������ʱ�Ĵ����㷨
		std::vector<bool> taskRun(std::vector<cv::Mat> &camerasMat, 
			std::map<int, std::vector<int>> &mCameraParamIndex,
			std::map<int, int> &mBlockToCameraIndex,
			std::vector<std::vector<int>> &mBlockParam,
			std::vector<std::vector<int>> &mSettingParam);

		// ��ȡ����task�Ĵ�����
		std::vector<int> getTargetTaskErrorCheck(int taskIndex);

	private:

		DetectTypeProcess *mDetectTypeProcess = NULL;

		// Regular Running Process	�����е�ʱ����Ҫ�õ����㷨��
		bool Check1TestRegularRunningProcess(cv::Mat &src);
		bool Check2TestRegularRunningProcess(cv::Mat &src);
		bool Check3TestRegularRunningProcess(cv::Mat &src);
		bool Check4TestRegularRunningProcess(cv::Mat &src);
		bool Check5TestRegularRunningProcess(cv::Mat &src);
		bool Check6TestRegularRunningProcess(cv::Mat &src);

		// ���ڱ���ÿ�μ�����ļ������
		std::vector<std::vector<int>> errorCheckCateIndex;
	};
}

#endif