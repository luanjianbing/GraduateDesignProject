#pragma once

#ifndef MYVIEW_H
#define MYVIEW_H

#include <QtWidgets/QMainWindow>
#include "ui_MyView.h"

#include "ImageSettingView.h"

#include "QListWidgetCamerasItem.h"
#include "QListWidgetErrorItem.h"

namespace View {

	class MyView : public QMainWindow
	{
		Q_OBJECT

		public:
			MyView(QWidget *parent = Q_NULLPTR);
			~MyView();

		private:
			Ui::projectClass ui;

			std::string curRunModelName = "";	// 根据设置界面传来的信号进行修改

			std::map<int, std::vector<int>> mCameraParamIndex;	// 每个相机对应的编号<cameraIndex, [这个相机对应的参数编号]>
			std::map<int, int> mBlockToCameraIndex;	// 这个block对应的相机编号<blockIndex，[这个block是第几个相机的参数]>
			std::vector<std::vector<int>> mBlockParam;	// <blockIndex, [x1, y1, x2, y2]>
			std::vector<std::vector<int>>	mSettingParam;	// <blockIndex, [设置的检测参数数据]>

			int mCamerasNum = 0;

			QSize listWidgetCamerasItemWidgetSize = QSize(164, 10);
			std::vector<QListWidgetCamerasItem *> mListWidgetCamerasItemWidget;	// 用来根据这个去更新图片
			std::vector<cv::Mat> mCamerasMat;	// 用于存放抓取的Mat，大小为相机数量
			std::vector<cv::Mat> mCamerasAfterProcessMat;	// 用于存放处理后的Mat，仅用于显示对错
			int mDisplayScale = 10;

			// 单次处理block的结果存储
			int targetROINum = 0;	// 目标需要处理的区域个数，不同的Model不同
			std::vector<bool> singleProcessResult;

			QSize listWidgetErrorItemWidgetSize = QSize(256, 64);
			std::vector<QListWidgetErrorItem *> mListWidgetErrorItemWidget;
			std::vector<QListWidgetItem *> mListWidgetErrorItem;

			std::vector<std::string> mDetectTypeSettingNames;

			// 界面显示方框大小
			int mBlockRectDisplayThickness = 10;
			// 界面显示结果文字大小
			double mBlockTextDisplayFontScale = 6;
			int mBlockTextDisplayFontThickness = 12;

		private:
			// 初始化根据模型名称获取的数据
			void initModelMsg();
			// 初始化根据相机数量初始化的ListWidgetCameras
			void initListWidgetCameras();
			// 初步抓取相机
			void initCamerasMat();
			// 更新界面显示
			void updateDisplay();
			// 更新错误Item显示
			void updateErrorItemDisplay();
			// 更新处理结果block显示
			void updateProcessBlockResult();

		private slots:
			// 图像设置
			void onActionImageSetting();
			// 触发信号
			void onActionSignal();
			// 拿到设置到的当前模型
			void onSignalCurRunModel(std::string);
			// 响应listWidgetCamerasItem点击信号
			void onListWidgetCamerasItemPressed(int);
		signals:
			void signalClose();
		protected:
			void closeEvent(QCloseEvent * e);
	};
}

#endif
