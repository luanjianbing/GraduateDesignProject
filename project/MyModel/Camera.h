#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <vector>

#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp>  
#include <opencv2/core/core.hpp>

#include "MvCameraControl.h"

// ��������Ļ�������
class SingleBaseCamera {
public:
	virtual bool getSingleImage(cv::Mat &singleMat) = 0;
	virtual cv::Size getCameraSize() = 0;

	SingleBaseCamera() {};
	virtual ~SingleBaseCamera() {};
private:
	virtual bool init() = 0;
	virtual bool close() = 0;

	virtual bool PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo) = 0;
	virtual bool Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char * pData, cv::Mat & srcImg) = 0;
	virtual int RGB2BGR(unsigned char* pRgbData, unsigned int nWidth, unsigned int nHeight) = 0;
};

// ��������������
class SingleSoftTrigglerCamera : public SingleBaseCamera {
public:
	virtual bool getSingleImage(cv::Mat &singleMat);
	virtual cv::Size getCameraSize();

	SingleSoftTrigglerCamera(MV_CC_DEVICE_INFO *);
	~SingleSoftTrigglerCamera();
private:
	MV_CC_DEVICE_INFO *pDeviceInfo;
	void* handle = NULL;
	int g_nPayloadSize = 0;
	MV_FRAME_OUT_INFO_EX stImageInfo = { 0 };
	unsigned char *pData = NULL;	// �̶����ͼ�񻺴���

	virtual bool init();
	virtual bool close();

	virtual bool PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo);
	virtual bool Convert2Mat(MV_FRAME_OUT_INFO_EX* pstImageInfo, unsigned char * pData, cv::Mat & srcImg);
	virtual int RGB2BGR(unsigned char* pRgbData, unsigned int nWidth, unsigned int nHeight);
};

namespace Model {
	class CamerasInterface {
	public:
		CamerasInterface();
		~CamerasInterface();

		// ��ȡ��ǰ���������
		int getCameraNums();

		// ��ȡĳ�������ͼ���С
		cv::Size getCameraSize(int cameraIdx);

		// ����ĳ��������������ץȡͼ��
		bool getSingleImage(int cameraIdx, cv::Mat &singleMat);

	private:
		// ӵ�е��������
		std::vector<SingleBaseCamera *> mValidCameras;
		MV_CC_DEVICE_INFO_LIST stDeviceList;

		// ���������ʼ��
		bool initCameras();

		// ��������ر�
		bool closeCameras();
	};
}

#endif