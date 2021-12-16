#pragma once

#ifndef IMAGESETTINGVIEW_H
#define IMAGESETTINGVIEW_H

#include <QtWidgets\QWidget>
#include "ui_ImageSettingView.h"

#include "..\\MyController\Controller.h"

#include <iostream>
#include <vector>
#include <map>

#include <QMessageBox>
#include <QTimer>
#include <QRadioButton>
#include <QGridLayout>
#include <QDebug>
#include <QButtonGroup>
#include <QHeaderView>

namespace View {
	// 用于自定义参数检测类型(当前中文会在部分位置乱码显示，暂时未考虑)
	class DetectTypeSettingWidget : public QWidget {
		Q_OBJECT
	public:
		DetectTypeSettingWidget(
			std::string groupBoxName,	
			std::vector<std::string> lineEditNames);
		~DetectTypeSettingWidget();
	public:
		// 初始化状态
		void resetParamStatus();
		// 获取框名
		std::string getGroupBoxName();
	private:
		std::string groupBoxName;	// 当前组合框名称
		std::vector<std::string> lineEditNames;	// 当前参数的数目

		QGridLayout *mSingleDetectTypeLayout = NULL;	// 这个是最外层的Layout
		QGridLayout *mGroupBoxSingleDetectTypeLayout = NULL;	// 这是GroupBox内部的布局
		QGroupBox *mQGroupBoxSingleDetectType = NULL;	// 最外层的QGroupBox
		QRadioButton *radioButtonYes = NULL;	// 区域检测类型Yes
		QRadioButton *radioButtonNo = NULL;	// 区域检测类型No
		QButtonGroup *radioButtonGroup = NULL;
		std::vector<QLabel *> mQLabelParamNames;	// 区域检测可能需要的参数QLabel名称
		std::vector<QLineEdit *> mQLineEditParamValues;	// 区域检测可能需要的参数QLineEdit名称

	signals:
		void radioButtonSignal(bool status);	// 1为检测，0为不检测
		void lineEditSignal(int index, int value);	// 第几个参数，值为value
	private slots:
		void radioButtonGroupToggled(int, bool);
		void lineEditGroupEditingFinished();
	};
}

namespace View {
	class ImageSettingView :public QWidget {
		Q_OBJECT

		public:
			ImageSettingView();
			~ImageSettingView();
		private:
			Ui::ImageSettingView ui;

			int mExternalCameraNums = 0;	// 接入相机数量
			void initCamerasTab();	// 初始化tab
			std::vector<cv::Mat> mCamerasMat;	// 用于存放显示的Mat，大小为相机数量
			std::string curModelName = "";	// 当前ModelName
			std::map<int, std::vector<int>> mCameraParamIndex;	// 每个相机对应的编号<cameraIndex, [这个相机对应的参数编号]>
			std::map<int, int> mBlockToCameraIndex;	// 这个block对应的相机编号<blockIndex，[这个block是第几个相机的参数]>
			std::vector<std::vector<int>> mBlockParam;	// <blockIndex, [x1, y1, x2, y2]>
			std::vector<std::vector<int>>	mSettingParam;	// <blockIndex, [设置的检测参数数据]>
			QTimer *mCamerasDisplayTimer = nullptr;	// 用于控制连续抓取图像并显示
			int mDisplayScale = 10;	// 显示的时候缩放效果好一点

			// 界面处理状态(状态机分流)
			enum PROGRESSSTATUS {
				PROGRESS_INITIAL_NONE,
				PROGRESS_LOAD_MODEL,
				PROGRESS_NEW_MODEL,
				PROGRESS_NEW_MODEL_BLOCK_MARK,
				PROGRESS_NEW_MODEL_BLOCK_MARK_NULL,
				PROGRESS_NEW_MODEL_FINISH,
			};
			PROGRESSSTATUS mSettingProgressStatus = PROGRESS_INITIAL_NONE;	// 状态机变换
			void updateByProgressStatus();	// 根据状态更新对应的界面相关信息
			QString mSettingModelName = "";	// 当前设置的对象名称

			void initModelMsg();
			std::vector<std::string> mModelNames;	// 用于存储数据库中的所有模型名称

			int x1 = 0, y1 = 0, x2 = 0, y2 = 0;	// 鼠标按下与释放的坐标
			int paintStartX = 0, paintStartY = 0, paintEndX = 0, paintEndY = 0;	// 实时作框的坐标
			cv::Mat matForDrawPart;	// 用于作图的图像
			cv::Size frameSize;	// 获取图像大小
			float adaptRatio = 0.0;	// 记录实际缩放的比率
			std::pair<int, int> offsetPair;	// key: 0代表X存在偏移量 1代表Y存在偏移量  val: 代表偏移量的值
			// 标记局部的时候的方框
			cv::Rect mPartWindowRect;	// 缩放显示的矩形框
			int mPartScale = 2;	// labelDisplay缩放显示的规模
			bool isOnPartLeftClick = false;	// 是否处在鼠标左键按下
			std::pair<int, int> labelDisplayStartOffset;	// 存储用于显示图像的左上角偏移量
			std::map<int, std::vector<int>> mBlockAxis;	// 用于保存相机编号对应的block

			// 支持检测类型参数
			void initDetectTypeSetting();
			std::vector<DetectTypeSettingWidget *> mDetectTypeSettings;	// 添加的检测类型窗口
			std::vector<std::string> mDetectTypeSettingNames;	// 检测的类型名称
			std::vector<std::vector<std::string>> mDetectTypeSettingParamNames;	// 有些检测类型需要参数
			int needParamSetNum = 0;	// 需要的参数表的个数，当前定义为索引 + 对应的检测数目
			int perDetectTypeWidth = 250;		// 每个检测类型的宽度
			int perDetectTypeHeight = 100;		// 每个检测类型的高度
			int perLineDetectTypeNums = 2;	// 每行检测类型的个数

			void relateParamSaving();	// 松开鼠标时相关的参数保存
			// 根据paramSet刷新一次表格显示
			void refreshTableWidgetParam();

			// 标记处已有的框
			void landMarkRun(cv::Mat &);

			// 计算标记的时候的相关参数
			void calMarkParam();

			//bool isOnCreateModel = false;	// 当前是否正在处于新建模型当中

			void saveRelatedParam();

		private slots:

			// 自定义响应鼠标事件QLabel槽函数
			void onLabelDisplayPressed(QMouseEvent *);
			void onLabelDisplayReleased(QMouseEvent *);
			void onLabelDisplayMoved(QMouseEvent *);
			bool onLabelDisplayFilter(QObject *, QEvent *);

			// comboBoxCurrentCamera槽函数
			void onComboBoxCurrentCameraChanged(int);
			// mCamerasDisplayTimer槽函数
			void onCamerasDisplayTimerTimeOut();

			//void onGetFin();

			// buttonNewModel槽函数
			void onButtonNewModel();
			// buttonLoadModel槽函数
			void onButtonLoadModel();

			// 设置检测参数时响应的信号
			void onRadioButtonSignal(bool status);	// 1为检测，0为不检测
			void onLineEditSignal(int index, int value);	// 第几个参数，值为value
		signals:
			void signalCurRunModel(std::string);
	};
}

#endif