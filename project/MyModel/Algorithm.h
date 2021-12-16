#pragma once

#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <vector>
#include <map>

#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>

// 用来设置检测类型对应的窗口(算法)
class DetectTypeProcess {
public:
	DetectTypeProcess();
	~DetectTypeProcess();

	// Setting Preprocess	(设置的时候需要用到的预处理算法)
	void Check1TestSettingPreprocess1(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreprocess1" << std::endl;
	}

	int Check1TestSettingPreProcess2(cv::Mat &src) {
		std::cout << "DetectTypeProcess::Check1TestSettingPreProcess2" << std::endl;
		return privateTestProcess2(src);
	}

	// Regular Running Process	（运行的时候需要用到的算法）
	bool Check1TestRegularRunningProcess(cv::Mat &src);
	bool Check2TestRegularRunningProcess(cv::Mat &src);
	bool Check3TestRegularRunningProcess(cv::Mat &src);
	bool Check4TestRegularRunningProcess(cv::Mat &src);
	bool Check5TestRegularRunningProcess(cv::Mat &src);
	bool Check6TestRegularRunningProcess(cv::Mat &src);

private:
	// 无关的处理算法定义为私有
	void privateTestProcess1(cv::Mat &src) {
		std::cout << "DetectTypeProcess::privateTestProcess1" << std::endl;
	}

	int privateTestProcess2(cv::Mat &src) {
		std::cout << "DetectTypeProcess::privateTestProcess2" << std::endl;
		return 9526;
	}
};

// 规定检测类型以及需要使用的算法
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
	};	// 检测的类型名称
	std::vector<std::vector<std::string>> mDetectTypeSettingParamNames = {
		{ "param1", "param2" },
		{},
		{ "param3", "param4" },
		{ "param5" },
		{ "param6", "param7" },
		{},
	};	// 有些检测类型需要参数 (由于需要根据这个参数去创建表，所以参数的名称不能一样，否则有相同的列名)
};


namespace Model {
	// 给对外的接口
	class AlgorithmInterface : 
		public DetectTypeRegulation {
	public:
		AlgorithmInterface();
		~AlgorithmInterface();

		std::vector<std::string> getDetectTypeSettingNames();
		std::vector<std::vector<std::string>> getDetectTypeSettingParamNames();

		// 具体的算法处理，这里写完需要在Controller进一步做封装
		void Check1TestSettingPreprocess1(cv::Mat &src);
		int Check1TestSettingPreProcess2(cv::Mat &src);
		
		// 实际运行时的处理算法
		std::vector<bool> taskRun(std::vector<cv::Mat> &camerasMat, 
			std::map<int, std::vector<int>> &mCameraParamIndex,
			std::map<int, int> &mBlockToCameraIndex,
			std::vector<std::vector<int>> &mBlockParam,
			std::vector<std::vector<int>> &mSettingParam);

		// 获取单个task的错误结果
		std::vector<int> getTargetTaskErrorCheck(int taskIndex);

	private:

		DetectTypeProcess *mDetectTypeProcess = NULL;

		// Regular Running Process	（运行的时候需要用到的算法）
		bool Check1TestRegularRunningProcess(cv::Mat &src);
		bool Check2TestRegularRunningProcess(cv::Mat &src);
		bool Check3TestRegularRunningProcess(cv::Mat &src);
		bool Check4TestRegularRunningProcess(cv::Mat &src);
		bool Check5TestRegularRunningProcess(cv::Mat &src);
		bool Check6TestRegularRunningProcess(cv::Mat &src);

		// 用于保存每次检测错误的检测类型
		std::vector<std::vector<int>> errorCheckCateIndex;
	};
}

#endif