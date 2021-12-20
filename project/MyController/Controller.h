#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../MyModel/Camera.h"
#include "../MyModel/DataBase.h"
#include "../MyModel/Algorithm.h"
#include "../MyModel/UserCache.h"

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
	//// 主要用作实现子线程获取图像任务，具体实现不用管
	//class CameraSingleShotWorker : public QObject, public CameraController {
	//	Q_OBJECT
	//public:
	//	CameraSingleShotWorker(QObject* parent = nullptr) {}

	//	// CameraController实现函数
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

	class UserCacheController {
	public:
		UserCacheController() {
			if (mUserCache == NULL)
				mUserCache = new Model::UserCacheInterface();
		}
		~UserCacheController() {
			if (mUserCache != NULL)
				delete mUserCache;
		}
	protected:
		static Model::UserCacheInterface *mUserCache;
	};

	class DomainController : public QObject, 
		public CameraController, 
		public DataBaseController,
		public AlgorithmController,
		public UserCacheController{
		//Q_OBJECT
		//QThread workerThread;
		//CameraSingleShotWorker *worker = nullptr;
	public:
		virtual ~DomainController();

		// CameraController实现函数
		int getCameraNums();
		bool getSingleImage(int cameraIdx, cv::Mat &singleMat);
		cv::Size getCameraSize(int cameraIdx);

		// DataBaseController实现函数
		// 用户登录
		bool userTryLogIn(std::string userName, std::string userPassward);
		// 用户注册
		bool userTryNewRegister(std::map<std::string, std::string> newUserInfo);
		// 用户已经存在，修改其中的信息
		bool userTryModifyInfo(std::map<std::string, std::string> newUserInfo);
		// 检查用户是否是未存在的新用户
		bool checkUserIsNewOne(std::string userName);
		// 判断权限是否符合要求
		bool checkAuthority(std::string toManualAuthority, std::string superUserId);
		// 查询某个权限的所有用户
		std::vector<std::vector<std::string>> getUsersFromAuthority(std::string toMatchAuthority);
		// 查询某个用户的相关信息
		std::map<std::string, std::string> getTargetUserInfo(std::string userID);
		// 判断是否有某个订单
		bool tryToLoadTargetOrder(std::string orderNumber);
		// 创建新订单
		bool tryCreateNewOrder(std::string orderNumber, std::string createTime, std::string orderQuantity);
		// 根据订单编号查询这个订单安排的用户情况
		std::vector<std::vector<std::string>> getUsersMsgSearchByOrderNumber(std::string orderNumber);
		// 添加订单任务安排
		bool addOrderNewUserTask(std::string orderNumber, std::string newUserID, std::string targetTotalNum);
		// 根据用户ID查询这个用户的任务安排情况
		std::vector<std::vector<std::string>> getOrderMsgSearchByUserID(std::string userID);
		// 根据订单ID查看这个订单的情况
		std::vector<std::string> getTargetOrderMsg(std::string orderNumber);

		// model_name表
		std::vector<std::string> readAllModelNames();	// 读取已经存取的model模型名称
		void addNewModelName(int newModelNum, std::string newModelName);	// 增加新建的模型名称
		// 坐标表
		std::vector<std::vector<int>> readTargetModelBlockParam(std::string targetModelName);	// 读取对应模型的坐标参数
		void saveTargetModelBlockParam(std::vector<std::vector<int>> &mBlockParam, std::string targetModelName);	// 保存对应的模型的坐标参数
		// 参数表（根据模型名称与param大小去创建，因为不知道有多少列）
		std::vector<std::vector<int>> readTargetModelSettingParam(std::string targetModelName);	// 读取对应模型的模型参数
		void saveTargetModelSettingParam(std::vector<std::vector<int>> &mSettingParam, std::string targetModelName);	// 保存对应的模型参数
		// <blockIndex, cameraIndex>
		std::map<int, int> readTargetModelBlock2CameraIndexParam(std::string targetModelName);	// 框对应的相机坐标
		void saveTargetModelBlock2CameraIndexParam(std::map<int, int> &mBlockToCameraIndex, std::string targetModelName);
		// <cameraIndex, [blockIndex]>
		std::map<int, std::vector<int>> readTargetModelCamera2BlockIndexParam(std::string targetModelName);	// 相机对应的框的坐标集合
		void saveTargetModelCamera2BlockIndexParam(std::map<int, std::vector<int>> &mCameraParamIndex, std::string targetModelName);

		// AlgorithmController实现函数
		std::vector<std::string> getDetectTypeSettingNames();	// 读取需要检测的类型名称
		std::vector<std::vector<std::string>> getDetectTypeSettingParamNames();	// 读取各类检测类型需要人工输入的参数
		
		// UserCacheController实现函数
		std::vector<std::string> getUserAuthorities();
		void setCurrentUser(std::map<std::string, std::string> userInfo);
		std::map<std::string, std::string> getCurrentUser();

		// 下面是算法测试函数
		// 建立模型时调用
		void Check1TestSettingPreprocess1(cv::Mat &src);
		int Check1TestSettingPreProcess2(cv::Mat &src);
		// 实际运行时调用
		std::vector<bool> taskRun(std::vector<cv::Mat> &camerasMat,
			std::map<int, std::vector<int>> &mCameraParamIndex,
			std::map<int, int> &mBlockToCameraIndex,
			std::vector<std::vector<int>> &mBlockParam,
			std::vector<std::vector<int>> &mSettingParam);

		std::vector<int> getTargetTaskErrorCheck(int taskIndex);
		//void getPicTest();
		//void setPicTest();

		// 单例接口
		static DomainController *&getInstance() {
			if (uniqueInstance == nullptr) {
				std::unique_lock<std::mutex> lock(mMutex);
				if (uniqueInstance == nullptr) {   // 当为空的时候，创建一次
					uniqueInstance = new DomainController();
				}
			}
			return uniqueInstance; // 返回创建的类对象
		}

	private:
		//// 私有化构造函数

		//DomainController(QObject *parent = nullptr) {
		//	if (worker == nullptr) {
		//		worker = new CameraSingleShotWorker;
		//		//调用moveToThread将该任务交给workThread
		//		worker->moveToThread(&workerThread);
		//		//operate信号发射后启动线程工作
		//		connect(this, SIGNAL(operate(const int)), worker, SLOT(doWork(int)));
		//		//该线程结束时销毁
		//		connect(&workerThread, &QThread::finished, worker, &QObject::deleteLater);
		//		//线程结束后发送信号，对结果进行处理
		//		connect(worker, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));
		//		//启动线程
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