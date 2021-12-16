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
	// �����Զ�������������(��ǰ���Ļ��ڲ���λ��������ʾ����ʱδ����)
	class DetectTypeSettingWidget : public QWidget {
		Q_OBJECT
	public:
		DetectTypeSettingWidget(
			std::string groupBoxName,	
			std::vector<std::string> lineEditNames);
		~DetectTypeSettingWidget();
	public:
		// ��ʼ��״̬
		void resetParamStatus();
		// ��ȡ����
		std::string getGroupBoxName();
	private:
		std::string groupBoxName;	// ��ǰ��Ͽ�����
		std::vector<std::string> lineEditNames;	// ��ǰ��������Ŀ

		QGridLayout *mSingleDetectTypeLayout = NULL;	// �����������Layout
		QGridLayout *mGroupBoxSingleDetectTypeLayout = NULL;	// ����GroupBox�ڲ��Ĳ���
		QGroupBox *mQGroupBoxSingleDetectType = NULL;	// ������QGroupBox
		QRadioButton *radioButtonYes = NULL;	// ����������Yes
		QRadioButton *radioButtonNo = NULL;	// ����������No
		QButtonGroup *radioButtonGroup = NULL;
		std::vector<QLabel *> mQLabelParamNames;	// �����������Ҫ�Ĳ���QLabel����
		std::vector<QLineEdit *> mQLineEditParamValues;	// �����������Ҫ�Ĳ���QLineEdit����

	signals:
		void radioButtonSignal(bool status);	// 1Ϊ��⣬0Ϊ�����
		void lineEditSignal(int index, int value);	// �ڼ���������ֵΪvalue
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

			int mExternalCameraNums = 0;	// �����������
			void initCamerasTab();	// ��ʼ��tab
			std::vector<cv::Mat> mCamerasMat;	// ���ڴ����ʾ��Mat����СΪ�������
			std::string curModelName = "";	// ��ǰModelName
			std::map<int, std::vector<int>> mCameraParamIndex;	// ÿ�������Ӧ�ı��<cameraIndex, [��������Ӧ�Ĳ������]>
			std::map<int, int> mBlockToCameraIndex;	// ���block��Ӧ��������<blockIndex��[���block�ǵڼ�������Ĳ���]>
			std::vector<std::vector<int>> mBlockParam;	// <blockIndex, [x1, y1, x2, y2]>
			std::vector<std::vector<int>>	mSettingParam;	// <blockIndex, [���õļ���������]>
			QTimer *mCamerasDisplayTimer = nullptr;	// ���ڿ�������ץȡͼ����ʾ
			int mDisplayScale = 10;	// ��ʾ��ʱ������Ч����һ��

			// ���洦��״̬(״̬������)
			enum PROGRESSSTATUS {
				PROGRESS_INITIAL_NONE,
				PROGRESS_LOAD_MODEL,
				PROGRESS_NEW_MODEL,
				PROGRESS_NEW_MODEL_BLOCK_MARK,
				PROGRESS_NEW_MODEL_BLOCK_MARK_NULL,
				PROGRESS_NEW_MODEL_FINISH,
			};
			PROGRESSSTATUS mSettingProgressStatus = PROGRESS_INITIAL_NONE;	// ״̬���任
			void updateByProgressStatus();	// ����״̬���¶�Ӧ�Ľ��������Ϣ
			QString mSettingModelName = "";	// ��ǰ���õĶ�������

			void initModelMsg();
			std::vector<std::string> mModelNames;	// ���ڴ洢���ݿ��е�����ģ������

			int x1 = 0, y1 = 0, x2 = 0, y2 = 0;	// ��갴�����ͷŵ�����
			int paintStartX = 0, paintStartY = 0, paintEndX = 0, paintEndY = 0;	// ʵʱ���������
			cv::Mat matForDrawPart;	// ������ͼ��ͼ��
			cv::Size frameSize;	// ��ȡͼ���С
			float adaptRatio = 0.0;	// ��¼ʵ�����ŵı���
			std::pair<int, int> offsetPair;	// key: 0����X����ƫ���� 1����Y����ƫ����  val: ����ƫ������ֵ
			// ��Ǿֲ���ʱ��ķ���
			cv::Rect mPartWindowRect;	// ������ʾ�ľ��ο�
			int mPartScale = 2;	// labelDisplay������ʾ�Ĺ�ģ
			bool isOnPartLeftClick = false;	// �Ƿ�������������
			std::pair<int, int> labelDisplayStartOffset;	// �洢������ʾͼ������Ͻ�ƫ����
			std::map<int, std::vector<int>> mBlockAxis;	// ���ڱ��������Ŷ�Ӧ��block

			// ֧�ּ�����Ͳ���
			void initDetectTypeSetting();
			std::vector<DetectTypeSettingWidget *> mDetectTypeSettings;	// ��ӵļ�����ʹ���
			std::vector<std::string> mDetectTypeSettingNames;	// ������������
			std::vector<std::vector<std::string>> mDetectTypeSettingParamNames;	// ��Щ���������Ҫ����
			int needParamSetNum = 0;	// ��Ҫ�Ĳ�����ĸ�������ǰ����Ϊ���� + ��Ӧ�ļ����Ŀ
			int perDetectTypeWidth = 250;		// ÿ��������͵Ŀ��
			int perDetectTypeHeight = 100;		// ÿ��������͵ĸ߶�
			int perLineDetectTypeNums = 2;	// ÿ�м�����͵ĸ���

			void relateParamSaving();	// �ɿ����ʱ��صĲ�������
			// ����paramSetˢ��һ�α����ʾ
			void refreshTableWidgetParam();

			// ��Ǵ����еĿ�
			void landMarkRun(cv::Mat &);

			// �����ǵ�ʱ�����ز���
			void calMarkParam();

			//bool isOnCreateModel = false;	// ��ǰ�Ƿ����ڴ����½�ģ�͵���

			void saveRelatedParam();

		private slots:

			// �Զ�����Ӧ����¼�QLabel�ۺ���
			void onLabelDisplayPressed(QMouseEvent *);
			void onLabelDisplayReleased(QMouseEvent *);
			void onLabelDisplayMoved(QMouseEvent *);
			bool onLabelDisplayFilter(QObject *, QEvent *);

			// comboBoxCurrentCamera�ۺ���
			void onComboBoxCurrentCameraChanged(int);
			// mCamerasDisplayTimer�ۺ���
			void onCamerasDisplayTimerTimeOut();

			//void onGetFin();

			// buttonNewModel�ۺ���
			void onButtonNewModel();
			// buttonLoadModel�ۺ���
			void onButtonLoadModel();

			// ���ü�����ʱ��Ӧ���ź�
			void onRadioButtonSignal(bool status);	// 1Ϊ��⣬0Ϊ�����
			void onLineEditSignal(int index, int value);	// �ڼ���������ֵΪvalue
		signals:
			void signalCurRunModel(std::string);
	};
}

#endif