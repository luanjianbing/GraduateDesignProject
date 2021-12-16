#include "MyView.h"

namespace View {
	MyView::MyView(QWidget *parent)
		: QMainWindow(parent)
	{
		ui.setupUi(this);

		connect(ui.actionImageSetting, SIGNAL(triggered()), this, SLOT(onActionImageSetting()));
		connect(ui.actionSignal, SIGNAL(triggered()), this, SLOT(onActionSignal()));

		mCamerasNum = Controller::DomainController::getInstance()->getCameraNums();		// ��ȡ�������

		if (mCamerasNum > 0) {
			// ��ʼ���������������ʼ����ListWidgetCameras
			initListWidgetCameras();
		}
	}

	MyView::~MyView() {

	}

	void MyView::onActionSignal() {
		std::cout << "get external signal." << std::endl;
		if (curRunModelName != "") {	// ѡȡĿ��ģ��

			// ����ץȡͼ��
			mCamerasMat.clear();
			mCamerasAfterProcessMat.clear();
			mCamerasMat.resize(mCamerasNum);
			mCamerasAfterProcessMat.resize(mCamerasNum);
			for (int i = 0; i < mCamerasNum; ++i) {
				Controller::DomainController::getInstance()->getSingleImage(i, mCamerasMat[i]);
				mCamerasAfterProcessMat[i] = mCamerasMat[i].clone();
			}
			// ��ȡ������
			singleProcessResult.clear();
			singleProcessResult = Controller::DomainController::getInstance()
				->taskRun(mCamerasMat, mCameraParamIndex, mBlockToCameraIndex, mBlockParam, mSettingParam);

			// ������ʾ���
			updateDisplay();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("��������ģ�ͣ�"), QMessageBox::Yes);
		}
	}

	void MyView::updateDisplay() {
		// ���´���Item��ʾ
		updateErrorItemDisplay();
		// ����ͼ����ʾ����֤��Block�����һ����������Ӱ��������ʾ��
		updateProcessBlockResult();
	}

	void MyView::updateProcessBlockResult() {
		for (int i = 0; i < singleProcessResult.size(); ++i) {
			if (singleProcessResult[i]) {
				cv::rectangle(mCamerasAfterProcessMat[mBlockToCameraIndex[i]],
					cv::Point(mBlockParam[i][0], mBlockParam[i][1]),
					cv::Point(mBlockParam[i][2], mBlockParam[i][3]), CvScalar(0, 170, 0), mBlockRectDisplayThickness, cv::LINE_8, 0);

				cv::Size fontSize = cv::getTextSize(std::to_string(i), cv::FONT_HERSHEY_SIMPLEX, mBlockTextDisplayFontScale, mBlockTextDisplayFontThickness, 0);
				cv::rectangle(mCamerasAfterProcessMat[mBlockToCameraIndex[i]],
					cv::Point(mBlockParam[i][0], mBlockParam[i][1] - fontSize.height),
					cv::Point(mBlockParam[i][0] + fontSize.width, mBlockParam[i][1]), CvScalar(0, 170, 0), cv::FILLED);
				cv::putText(mCamerasAfterProcessMat[mBlockToCameraIndex[i]], 
					std::to_string(i), cv::Point(mBlockParam[i][0], mBlockParam[i][1]), cv::FONT_HERSHEY_SIMPLEX, mBlockTextDisplayFontScale, (0, 0, 0), mBlockTextDisplayFontThickness);
			}
			else {
				cv::rectangle(mCamerasAfterProcessMat[mBlockToCameraIndex[i]],
					cv::Point(mBlockParam[i][0], mBlockParam[i][1]),
					cv::Point(mBlockParam[i][2], mBlockParam[i][3]), CvScalar(0, 85, 255), mBlockRectDisplayThickness, cv::LINE_8, 0);

				cv::Size fontSize = cv::getTextSize(std::to_string(i), cv::FONT_HERSHEY_SIMPLEX, mBlockTextDisplayFontScale, mBlockTextDisplayFontThickness, 0);
				cv::rectangle(mCamerasAfterProcessMat[mBlockToCameraIndex[i]],
					cv::Point(mBlockParam[i][0], mBlockParam[i][1] - fontSize.height),
					cv::Point(mBlockParam[i][0] + fontSize.width, mBlockParam[i][1]), CvScalar(0, 85, 255), cv::FILLED);
				cv::putText(mCamerasAfterProcessMat[mBlockToCameraIndex[i]],
					std::to_string(i), cv::Point(mBlockParam[i][0], mBlockParam[i][1]), cv::FONT_HERSHEY_SIMPLEX, mBlockTextDisplayFontScale, (0, 0, 0), mBlockTextDisplayFontThickness);

				// �ж��ĸ�����
				std::vector<int> thisTaskErrorCheckItem = Controller::DomainController::getInstance()->getTargetTaskErrorCheck(i);
				std::cout << "Task Error Index:[" << i << "]����[ ";
				for (int lineIdx = 0; lineIdx < thisTaskErrorCheckItem.size(); ++lineIdx) {
					std::cout << mDetectTypeSettingNames[thisTaskErrorCheckItem[lineIdx]] << " ";
					// (TODO)��ʾ��������

				}
				std::wcout << "]" << std::endl;
			}
		}
		// ��ʾ��ListWidgetCameras��
		for (int i = 0; i < mCamerasNum; ++i) {
			cv::Mat toDisplayMat = mCamerasAfterProcessMat[i].clone();
			cv::cvtColor(toDisplayMat, toDisplayMat, CV_BGR2RGB);
			cv::resize(toDisplayMat, toDisplayMat, cv::Size(toDisplayMat.cols / mDisplayScale, toDisplayMat.rows / mDisplayScale), 0, 0, cv::INTER_NEAREST);
			QImage singleQImage(toDisplayMat.data, toDisplayMat.cols, toDisplayMat.rows, toDisplayMat.cols * toDisplayMat.channels(), QImage::Format_RGB888);
			mListWidgetCamerasItemWidget[i]->setSingleCameraItem(singleQImage);	// ����ͼ����ʾ
		}
		// ��ÿ�ζ��������0������Ĵ�label��
		onListWidgetCamerasItemPressed(0);
	}

	void MyView::updateErrorItemDisplay() {
		// ֻ�е�Ŀǰ������ʾ����Item�ĸ���������ǰ����ʱ���ڸ��£���һ�������ӳټ��صķ�ʽ
		int singleErrorCount = 0;	// ��¼���δ������е�����������ĸ���
		for (int i = 0; i < singleProcessResult.size(); ++i) {
			if (!singleProcessResult[i]) {
				// �ж��Ƿ񳬹���ǰmListWidgetErrorItem����
				if (singleErrorCount >= mListWidgetErrorItemWidget.size()) {
					QListWidgetErrorItem *tmpErrorItem = new QListWidgetErrorItem(singleErrorCount, i, mBlockToCameraIndex[i]);	// ���ǵڼ��������Item���ڼ���block���ǵڼ��������
					mListWidgetErrorItemWidget.push_back(tmpErrorItem);

					QListWidgetItem *tmpListItem = new QListWidgetItem(ui.listWidgetError);
					mListWidgetErrorItem.push_back(tmpListItem);

					ui.listWidgetError->addItem(tmpListItem);
					tmpListItem->setSizeHint(listWidgetErrorItemWidgetSize);
					ui.listWidgetError->setItemWidget(tmpListItem, tmpErrorItem);
				}
				else {
					mListWidgetErrorItemWidget[singleErrorCount]->setErrorItemIndex(singleErrorCount);
					mListWidgetErrorItemWidget[singleErrorCount]->setErrorItemBlockIndex(i);
					mListWidgetErrorItemWidget[singleErrorCount]->setErrorItemCameraIndex(mBlockToCameraIndex[i]);
				}
				qApp->processEvents();	// �����������䣬����ָ�new��itemʱlabel��С�����

				// ����ͼ��
				cv::Mat toDisplayMat = mCamerasAfterProcessMat[mBlockToCameraIndex[i]]
					(cv::Range(mBlockParam[i][1], mBlockParam[i][3]), cv::Range(mBlockParam[i][0], mBlockParam[i][2]));
				cv::cvtColor(toDisplayMat, toDisplayMat, CV_BGR2RGB);
				QImage singleQImage(toDisplayMat.data, toDisplayMat.cols, toDisplayMat.rows, toDisplayMat.step, QImage::Format_RGB888);

				mListWidgetErrorItemWidget[singleErrorCount]->setErrorItemDisplayImage(singleQImage, singleQImage);

				// �������+1
				singleErrorCount += 1;
			}
		}

		// ɾ���������
		while (singleErrorCount < mListWidgetErrorItemWidget.size()) {
			ui.listWidgetError->removeItemWidget(mListWidgetErrorItem.back());

			// ��delete�������
			delete mListWidgetErrorItem.back();
			delete mListWidgetErrorItemWidget.back();

			mListWidgetErrorItem.pop_back();
			mListWidgetErrorItemWidget.pop_back();
		}
	}

	void MyView::initModelMsg() {
		// ���
		mBlockParam.clear();
		mSettingParam.clear();
		mBlockToCameraIndex.clear();
		mCameraParamIndex.clear();

		// ���¶�
		std::cout << "readTargetModelBlockParam start" << std::endl;
		mBlockParam = Controller::DomainController::getInstance()->readTargetModelBlockParam(curRunModelName);
		std::cout << "readTargetModelBlockParam end" << std::endl;

		std::cout << "readTargetModelSettingParam start" << std::endl;
		mSettingParam = Controller::DomainController::getInstance()->readTargetModelSettingParam(curRunModelName);
		std::cout << "readTargetModelSettingParam end" << std::endl;

		std::cout << "readTargetModelBlock2CameraIndexParam start" << std::endl;
		mBlockToCameraIndex = Controller::DomainController::getInstance()->readTargetModelBlock2CameraIndexParam(curRunModelName);
		std::cout << "readTargetModelBlock2CameraIndexParam end" << std::endl;

		std::cout << "readTargetModelCamera2BlockIndexParam start" << std::endl;
		mCameraParamIndex = Controller::DomainController::getInstance()->readTargetModelCamera2BlockIndexParam(curRunModelName);
		std::cout << "readTargetModelCamera2BlockIndexParam end" << std::endl;

		// ����ROI����
		targetROINum = mBlockParam.size();
		std::cout << "targetROINum: " << targetROINum << std::endl;

		// ����block�ĸ�����ʼ�����δ洢���
		singleProcessResult.clear();
		singleProcessResult.resize(targetROINum);

		mDetectTypeSettingNames.clear();
		mDetectTypeSettingNames = Controller::DomainController::getInstance()->getDetectTypeSettingNames();
	}

	void MyView::onSignalCurRunModel(std::string modelName) {
		std::cout << "curRunModelName: " << modelName << std::endl;
		curRunModelName = modelName;

		// ÿ��ģ�����Ʊ仯֮��Ҫȥ���ݿ������¶�ȡһ������
		initModelMsg();

		// ÿ��ģ�ͱ仯֮�����ץȡһ��ͼ��
		initCamerasMat();
	}

	void MyView::initCamerasMat() {
		mCamerasMat.clear();
		mCamerasAfterProcessMat.clear();

		mCamerasMat.resize(mCamerasNum);
		mCamerasAfterProcessMat.resize(mCamerasNum);
		for (int i = 0; i < mCamerasNum; ++i) {
			Controller::DomainController::getInstance()->getSingleImage(i, mCamerasMat[i]);
			mCamerasAfterProcessMat[i] = mCamerasMat[i].clone();

			// ��ʾ��ListWidgetCameras��
			cv::Mat toDisplayMat = mCamerasAfterProcessMat[i].clone();
			cv::cvtColor(toDisplayMat, toDisplayMat, CV_BGR2RGB);
			cv::resize(toDisplayMat, toDisplayMat, cv::Size(toDisplayMat.cols / mDisplayScale, toDisplayMat.rows / mDisplayScale), 0, 0, cv::INTER_NEAREST);
			QImage singleQImage(toDisplayMat.data, toDisplayMat.cols, toDisplayMat.rows, toDisplayMat.cols * toDisplayMat.channels(), QImage::Format_RGB888);
			mListWidgetCamerasItemWidget[i]->setSingleCameraItem(singleQImage);	// ����ͼ����ʾ
		}
	}

	void MyView::onActionImageSetting() {
		ImageSettingView *mImageSetting = new ImageSettingView();
		mImageSetting->setAttribute(Qt::WA_DeleteOnClose);
		mImageSetting->show();
		connect(mImageSetting, SIGNAL(signalCurRunModel(std::string)), this, SLOT(onSignalCurRunModel(std::string)));
	}

	void MyView::initListWidgetCameras() {
		for (int i = 0; i < mCamerasNum; ++i) {
			QListWidgetCamerasItem *tmpItemWidget = new QListWidgetCamerasItem(std::to_string(i));	// �������������������źŸ������תΪ��int����
			QListWidgetItem *tmpListItem = new QListWidgetItem(ui.listWidgetCameras);
			ui.listWidgetCameras->addItem(tmpListItem);
			tmpListItem->setSizeHint(listWidgetCamerasItemWidgetSize);
			ui.listWidgetCameras->setItemWidget(tmpListItem, tmpItemWidget);
			// ��¼��ַ�����ں�������ͼ��
			mListWidgetCamerasItemWidget.push_back(tmpItemWidget);
			// ����������Ӧ����ź�
			connect(tmpItemWidget, SIGNAL(itemPressed(int)), this, SLOT(onListWidgetCamerasItemPressed(int)));
		}
	}

	void MyView::onListWidgetCamerasItemPressed(int itemIdx) {
		if (curRunModelName != "") {	
			cv::Mat toDisplayMat = mCamerasAfterProcessMat[itemIdx].clone();
			cv::cvtColor(toDisplayMat, toDisplayMat, CV_BGR2RGB);
			cv::resize(toDisplayMat, toDisplayMat, cv::Size(toDisplayMat.cols / mDisplayScale, toDisplayMat.rows / mDisplayScale), 0, 0, cv::INTER_NEAREST);
			QImage singleQImage(toDisplayMat.data, toDisplayMat.cols, toDisplayMat.rows, toDisplayMat.cols * toDisplayMat.channels(), QImage::Format_RGB888);
			// ��ʾ���Ϸ���label��
			ui.labelCameraDisplay->setPixmap(QPixmap::fromImage(singleQImage)
				.scaled(ui.labelCameraDisplay->width(), ui.labelCameraDisplay->height(), Qt::KeepAspectRatio));
			// ����groupbox����������ʾ�����
			ui.groupBoxCamera->setTitle(QStringLiteral("���") + QString::fromStdString(std::to_string(itemIdx)));
		}
		else {
			std::cout << "Have no choose Model" << std::endl;
		}
	}

	void MyView::closeEvent(QCloseEvent *event)
	{
		// ���˳�����֮ǰ�������ź���ʾ
		emit signalClose();
	}
}
