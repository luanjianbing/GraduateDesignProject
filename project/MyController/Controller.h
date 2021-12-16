#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../MyModel/Camera.h"
#include "../MyModel/DataBase.h"
#include "../MyModel/Algorithm.h"

#include <mutex>

#include <QThread>

namespace Controller {
	class CameraController {
	public:
		CameraController() {
			if (mCameras == NULL)
				mCameras = new Model::CamerasInterface();
			//std::cout << "CameraController Constructor" << std::endl;
		}
		virtual ~CameraController() {
			if (mCameras != NULL)
				delete mCameras;
			//std::cout << "CameraController deConstructor" << std::endl;
		}

		virtual int getCameraNums() =0;
		virtual bool getSingleImage(int cameraIdx, cv::Mat &singleMat) =0;
		virtual cv::Size getCameraSize(int cameraIdx) =0;

	protected:
		static Model::CamerasInterface *mCameras;
	};
	//// ��Ҫ����ʵ�����̻߳�ȡͼ�����񣬾���ʵ�ֲ��ù�
	//class CameraSingleShotWorker : public QObject, public CameraController {
	//	Q_OBJECT
	//public:
	//	CameraSingleShotWorker(QObject* parent = nullptr) {}

	//	// CameraControllerʵ�ֺ���
	//	int getCameraNums();
	//	bool getSingleImage(int cameraIdx, cv::Mat &singleMat);
	//	cv::Size getCameraSize(int cameraIdx);

	//	cv::Mat retPic;
	//	cv::Mat getTest();
	//public slots :
	//	void doWork(int i);
	//signals:
	//	void resultReady(const int result);
	//};

	class DataBaseController {
	public:
		DataBaseController() {
			if (mDataBase == NULL)
				mDataBase = new Model::DataBaseInterface();
		}
		virtual ~DataBaseController() {
			if (mDataBase != NULL)
				delete mDataBase;
		}
	protected:
		static Model::DataBaseInterface *mDataBase;
	};

	class AlgorithmController {
	public:
		AlgorithmController() {
			if (mAlgorithm == NULL)
				mAlgorithm = new Model::AlgorithmInterface();
		}
		~AlgorithmController() {
			if (mAlgorithm != NULL)
				delete mAlgorithm;
		}
	protected:
		static Model::AlgorithmInterface *mAlgorithm;
	};

	class DomainController : public QObject, 
		public CameraController, 
		public DataBaseController,
		public AlgorithmController{
		//Q_OBJECT
		//QThread workerThread;
		//CameraSingleShotWorker *worker = nullptr;
	public:
		virtual ~DomainController();

		// CameraControllerʵ�ֺ���
		int getCameraNums();
		bool getSingleImage(int cameraIdx, cv::Mat &singleMat);
		cv::Size getCameraSize(int cameraIdx);

		// DataBaseControllerʵ�ֺ���
		// �û���¼
		bool userTryLogIn(std::string userName, std::string userPassward);
		// �û�ע��
		bool userTryRegister(std::string userName, std::string userPassward);

		// model_name��
		std::vector<std::string> readAllModelNames();	// ��ȡ�Ѿ���ȡ��modelģ������
		void addNewModelName(int newModelNum, std::string newModelName);	// �����½���ģ������
		// �����
		std::vector<std::vector<int>> readTargetModelBlockParam(std::string targetModelName);	// ��ȡ��Ӧģ�͵��������
		void saveTargetModelBlockParam(std::vector<std::vector<int>> &mBlockParam, std::string targetModelName);	// �����Ӧ��ģ�͵��������
		// ����������ģ��������param��Сȥ��������Ϊ��֪���ж����У�
		std::vector<std::vector<int>> readTargetModelSettingParam(std::string targetModelName);	// ��ȡ��Ӧģ�͵�ģ�Ͳ���
		void saveTargetModelSettingParam(std::vector<std::vector<int>> &mSettingParam, std::string targetModelName);	// �����Ӧ��ģ�Ͳ���
		// <blockIndex, cameraIndex>
		std::map<int, int> readTargetModelBlock2CameraIndexParam(std::string targetModelName);	// ���Ӧ���������
		void saveTargetModelBlock2CameraIndexParam(std::map<int, int> &mBlockToCameraIndex, std::string targetModelName);
		// <cameraIndex, [blockIndex]>
		std::map<int, std::vector<int>> readTargetModelCamera2BlockIndexParam(std::string targetModelName);	// �����Ӧ�Ŀ�����꼯��
		void saveTargetModelCamera2BlockIndexParam(std::map<int, std::vector<int>> &mCameraParamIndex, std::string targetModelName);

		// AlgorithmControllerʵ�ֺ���
		std::vector<std::string> getDetectTypeSettingNames();	// ��ȡ��Ҫ������������
		std::vector<std::vector<std::string>> getDetectTypeSettingParamNames();	// ��ȡ������������Ҫ�˹�����Ĳ���
		
		// �������㷨���Ժ���
		// ����ģ��ʱ����
		void Check1TestSettingPreprocess1(cv::Mat &src);
		int Check1TestSettingPreProcess2(cv::Mat &src);
		// ʵ������ʱ����
		std::vector<bool> taskRun(std::vector<cv::Mat> &camerasMat,
			std::map<int, std::vector<int>> &mCameraParamIndex,
			std::map<int, int> &mBlockToCameraIndex,
			std::vector<std::vector<int>> &mBlockParam,
			std::vector<std::vector<int>> &mSettingParam);

		std::vector<int> getTargetTaskErrorCheck(int taskIndex);
		//void getPicTest();
		//void setPicTest();

		// �����ӿ�
		static DomainController *&getInstance() {
			if (uniqueInstance == nullptr) {
				std::unique_lock<std::mutex> lock(mMutex);
				if (uniqueInstance == nullptr) {   // ��Ϊ�յ�ʱ�򣬴���һ��
					uniqueInstance = new DomainController();
				}
			}
			return uniqueInstance; // ���ش����������
		}

	private:
		//// ˽�л����캯��

		//DomainController(QObject *parent = nullptr) {
		//	if (worker == nullptr) {
		//		worker = new CameraSingleShotWorker;
		//		//����moveToThread�������񽻸�workThread
		//		worker->moveToThread(&workerThread);
		//		//operate�źŷ���������̹߳���
		//		connect(this, SIGNAL(operate(const int)), worker, SLOT(doWork(int)));
		//		//���߳̽���ʱ����
		//		connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
		//		//�߳̽��������źţ��Խ�����д���
		//		connect(worker, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
		//		//�����߳�
		//		workerThread.start();
		//	}
		//};
		DomainController() {};
		DomainController(const DomainController &) {};
		DomainController& operator=(const DomainController &) {};

		static DomainController* uniqueInstance;
		static std::mutex mMutex;
	private slots:
		//void handleResults(const int result);
	signals:
		//void operate(const int);

		//void getPicFinished();
	};
}

#endif