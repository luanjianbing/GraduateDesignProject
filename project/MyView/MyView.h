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

			std::string curRunModelName = "";	// �������ý��洫�����źŽ����޸�

			std::map<int, std::vector<int>> mCameraParamIndex;	// ÿ�������Ӧ�ı��<cameraIndex, [��������Ӧ�Ĳ������]>
			std::map<int, int> mBlockToCameraIndex;	// ���block��Ӧ��������<blockIndex��[���block�ǵڼ�������Ĳ���]>
			std::vector<std::vector<int>> mBlockParam;	// <blockIndex, [x1, y1, x2, y2]>
			std::vector<std::vector<int>>	mSettingParam;	// <blockIndex, [���õļ���������]>

			int mCamerasNum = 0;

			QSize listWidgetCamerasItemWidgetSize = QSize(164, 10);
			std::vector<QListWidgetCamerasItem *> mListWidgetCamerasItemWidget;	// �����������ȥ����ͼƬ
			std::vector<cv::Mat> mCamerasMat;	// ���ڴ��ץȡ��Mat����СΪ�������
			std::vector<cv::Mat> mCamerasAfterProcessMat;	// ���ڴ�Ŵ������Mat����������ʾ�Դ�
			int mDisplayScale = 10;

			// ���δ���block�Ľ���洢
			int targetROINum = 0;	// Ŀ����Ҫ�����������������ͬ��Model��ͬ
			std::vector<bool> singleProcessResult;

			QSize listWidgetErrorItemWidgetSize = QSize(256, 64);
			std::vector<QListWidgetErrorItem *> mListWidgetErrorItemWidget;
			std::vector<QListWidgetItem *> mListWidgetErrorItem;

			std::vector<std::string> mDetectTypeSettingNames;

			// ������ʾ�����С
			int mBlockRectDisplayThickness = 10;
			// ������ʾ������ִ�С
			double mBlockTextDisplayFontScale = 6;
			int mBlockTextDisplayFontThickness = 12;

		private:
			// ��ʼ������ģ�����ƻ�ȡ������
			void initModelMsg();
			// ��ʼ���������������ʼ����ListWidgetCameras
			void initListWidgetCameras();
			// ����ץȡ���
			void initCamerasMat();
			// ���½�����ʾ
			void updateDisplay();
			// ���´���Item��ʾ
			void updateErrorItemDisplay();
			// ���´������block��ʾ
			void updateProcessBlockResult();

		private slots:
			// ͼ������
			void onActionImageSetting();
			// �����ź�
			void onActionSignal();
			// �õ����õ��ĵ�ǰģ��
			void onSignalCurRunModel(std::string);
			// ��ӦlistWidgetCamerasItem����ź�
			void onListWidgetCamerasItemPressed(int);
		signals:
			void signalClose();
		protected:
			void closeEvent(QCloseEvent * e);
	};
}

#endif