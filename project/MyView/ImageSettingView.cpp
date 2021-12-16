#include "ImageSettingView.h"

namespace View {
	ImageSettingView::ImageSettingView() {
		ui.setupUi(this);

		// ������Ӧ����¼���labelDisplay
		connect(ui.labelDisplay, SIGNAL(pressed(QMouseEvent *)), this, SLOT(onLabelDisplayPressed(QMouseEvent *)));
		connect(ui.labelDisplay, SIGNAL(released(QMouseEvent *)), this, SLOT(onLabelDisplayReleased(QMouseEvent *)));
		connect(ui.labelDisplay, SIGNAL(moved(QMouseEvent *)), this, SLOT(onLabelDisplayMoved(QMouseEvent *)));
		connect(ui.labelDisplay, SIGNAL(filter(QObject *, QEvent *)), this, SLOT(onLabelDisplayFilter(QObject *, QEvent *)));

		// ���غ��½�ģ��
		connect(ui.buttonNewModel, SIGNAL(released()), this, SLOT(onButtonNewModel()));
		connect(ui.buttonLoadModel, SIGNAL(released()), this, SLOT(onButtonLoadModel()));

		// ��ȡ�ⲿ�������
		mExternalCameraNums = Controller::DomainController::getInstance()->getCameraNums();
		if (mExternalCameraNums == 0) {
			QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("δ��⵽�ⲿ�����"), QMessageBox::Yes);
		}
		else {
			// �������������ʼ��tabCameras
			std::cout << "initCamerasTab." << std::endl;
			initCamerasTab();
			std::cout << "initCamerasTab finish." << std::endl;
			// ��ʼ������ģ��
			std::cout << "initModelMsg." << std::endl;
			initModelMsg();
			std::cout << "initModelMsg finish." << std::endl;
			// ��ʼ����ǰ֧�ּ������
			std::cout << "initDetectTypeSetting." << std::endl;
			initDetectTypeSetting();
			std::cout << "initDetectTypeSetting finish." << std::endl;

			// ����ֲ�block�ı������ = ����(1) + ���/����� + ������Ŀ
			int tmpNeedParamNums = 0;
			for (int i = 0; i < mDetectTypeSettingParamNames.size(); ++i) {
				tmpNeedParamNums += mDetectTypeSettingParamNames[i].size();
			}
			needParamSetNum = mDetectTypeSettingNames.size() + tmpNeedParamNums;
		}
	}

	ImageSettingView::~ImageSettingView() {
		// ���������
		if (mCamerasDisplayTimer != nullptr) {
			if (mCamerasDisplayTimer->isActive() == true) {
				mCamerasDisplayTimer->stop();
			}
			delete mCamerasDisplayTimer;
		}
		// ���detectType���
		for (int i = 0; i < mDetectTypeSettings.size(); ++i) {
			if (mDetectTypeSettings[i] != NULL)
				delete mDetectTypeSettings[i];
		}
	}

	void ImageSettingView::onLabelDisplayPressed(QMouseEvent *ev) {
		//std::cout << "Pressed : [" << ev->pos().x() << "," << ev->pos().y() << "]" << std::endl;
		//std::cout << "Pressed : [" << ev->buttons() << std::endl;
		if (ev->buttons() & Qt::LeftButton) {
			if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {
				isOnPartLeftClick = true;
				std::cout << "Button Left Clicked-[";
				x1 = ev->pos().x() - labelDisplayStartOffset.first;
				y1 = ev->pos().y() - labelDisplayStartOffset.second;
				if (x1 < 0) x1 = 0;
				if (y1 < 0) y1 = 0;
				if (x1 > ui.labelDisplay->width()) x1 = ui.labelDisplay->width();
				if (y1 > ui.labelDisplay->height()) y1 = ui.labelDisplay->height();
				std::cout << x1 << "," << y1 << "]" << std::endl;
				x2 = x1;
				y2 = y1;

				// ��갴��ʱ��ʼ���������״̬
				for (int i = 0; i < mDetectTypeSettings.size(); ++i){
					//std::cout << i << std::endl;
					mDetectTypeSettings[i]->resetParamStatus();
				}
			}
		}
		else if (ev->buttons() & Qt::RightButton) {
			if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {
				std::cout << "Button Right Clicked-[";
				x1 = ev->pos().x() - labelDisplayStartOffset.first;
				y1 = ev->pos().y() - labelDisplayStartOffset.second;
				if (x1 < 0) x1 = 0;
				if (y1 < 0) y1 = 0;
				if (x1 > ui.labelDisplay->width()) x1 = ui.labelDisplay->width();
				if (y1 > ui.labelDisplay->height()) y1 = ui.labelDisplay->height();
				x2 = x1;
				y2 = y1;
				std::cout << x1 << "," << y1 << "]" << std::endl;
			}
		}
	}

	void ImageSettingView::onLabelDisplayReleased(QMouseEvent *ev) {
		//std::cout << "Released : [" << ev->pos().x() << "," << ev->pos().y() << "]" << std::endl;
		//std::cout << "Released : [" << ev->button() << std::endl;
		if (ev->button() == Qt::LeftButton) {	// ������ev->buttons()�ж������⣬һֱ��0���޷��������Ұ���
			if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {
				isOnPartLeftClick = false;
				std::cout << "Button Left Released-[";
				x2 = ev->pos().x() - labelDisplayStartOffset.first;
				y2 = ev->pos().y() - labelDisplayStartOffset.second;
				if (x2 < 0) x2 = 0;
				if (y2 < 0) y2 = 0;
				if (x2 > ui.labelDisplay->width()) x2 = ui.labelDisplay->width();
				if (y2 > ui.labelDisplay->height()) y2 = ui.labelDisplay->height();
				std::cout << x2 << "," << y2 << "]" << std::endl;
				if (x2 < x1 && y2 < y1) {	// ����������
					std::cout << "Swap x1x2 and y1y2." << std::endl;
					std::swap(x1, x2);
					std::swap(y1, y2);
				}
				else if (x1 < x2 && y1 > y2) {	// ����������
					std::cout << "Swap y1y2." << std::endl;
					std::swap(y1, y2);
				}
				else if (x1 > x2 && y1 < y2) {	// ����������
					std::cout << "Swap x1x2." << std::endl;
					std::swap(x1, x2);
				}

				// ��ز�������
				relateParamSaving();
				
				update();
			}
		}
		else if (ev->button() == Qt::RightButton) {
			
		}
	}

	void ImageSettingView::onLabelDisplayMoved(QMouseEvent *ev) {
		//std::cout << "Moved : [" << ev->pos().x() << "," << ev->pos().y() << "]" << std::endl;
		if (ev->buttons() & Qt::LeftButton) {
			if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {
				x2 = ev->pos().x() - labelDisplayStartOffset.first;
				y2 = ev->pos().y() - labelDisplayStartOffset.second;
				if (x2 < 0) x2 = 0;
				if (y2 < 0) y2 = 0;
				if (x2 > ui.labelDisplay->width()) x2 = ui.labelDisplay->width();
				if (y2 > ui.labelDisplay->height()) y2 = ui.labelDisplay->height();
				update();
			}
		}
		else if (ev->buttons() & Qt::RightButton) {
			if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {
				x2 = ev->pos().x() - labelDisplayStartOffset.first;
				y2 = ev->pos().y() - labelDisplayStartOffset.second;
				if (x2 < 0) x2 = 0;
				if (y2 < 0) y2 = 0;
				if (x2 > ui.labelDisplay->width()) x2 = ui.labelDisplay->width();
				if (y2 > ui.labelDisplay->height()) y2 = ui.labelDisplay->height();
				mPartWindowRect.x += (x2 - x1);
				mPartWindowRect.y += (y2 - y1);
				if (mPartWindowRect.x < 0) mPartWindowRect.x = 0;
				if (mPartWindowRect.y < 0) mPartWindowRect.y = 0;
				if (mPartWindowRect.y + mPartWindowRect.height > frameSize.height) {
					mPartWindowRect.y = frameSize.height - mPartWindowRect.height;
				}
				if (mPartWindowRect.x + mPartWindowRect.width > frameSize.width) {
					mPartWindowRect.x = frameSize.width - mPartWindowRect.width;
				}
				update();
			}
		}
	}

	bool ImageSettingView::onLabelDisplayFilter(QObject *obj, QEvent *ev) {
		if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {
			ui.labelDisplay->clear();
			cv::Mat mat_cp;
			matForDrawPart.copyTo(mat_cp);	// ����ͼƬ
			landMarkRun(mat_cp);
			//std::cout << isOnPartLeftClick << std::endl;
			if (isOnPartLeftClick) {
				if (offsetPair.first == 1) {
					paintStartX = static_cast<int>((x1 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.x;
					paintStartY = static_cast<int>(y1 * adaptRatio / mPartScale) + mPartWindowRect.y;
					paintEndX = static_cast<int>((x2 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.x;
					paintEndY = static_cast<int>(y2 * adaptRatio / mPartScale) + mPartWindowRect.y;
				}
				else if (offsetPair.first == 0) {
					paintStartX = static_cast<int>(x1 * adaptRatio / mPartScale) + mPartWindowRect.x;
					paintStartY = static_cast<int>((y1 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.y;
					paintEndX = static_cast<int>(x2 * adaptRatio / mPartScale) + mPartWindowRect.x;
					paintEndY = static_cast<int>((y2 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.y;
				}
				if (paintStartX < 0) paintStartX = 0;
				if (paintStartY < 0) paintStartY = 0;
				if (paintEndX >= frameSize.width) paintEndX = frameSize.width - 1;
				if (paintEndY >= frameSize.height) paintEndY = frameSize.height - 1;
				cv::rectangle(mat_cp, cv::Point(paintStartX, paintStartY),
					cv::Point(paintEndX, paintEndY), cv::Scalar(0, 255, 0), 6);
			}
			cv::cvtColor(mat_cp, mat_cp, cv::COLOR_BGR2RGB);
			mat_cp = mat_cp(mPartWindowRect);
			cv::resize(mat_cp, mat_cp, cv::Size(mat_cp.cols / mDisplayScale, mat_cp.rows / mDisplayScale), 0, 0, cv::INTER_NEAREST);
			QImage imgForDrawQImage = QImage(mat_cp.data, mat_cp.cols, mat_cp.rows, mat_cp.step, QImage::Format_RGB888);
			ui.labelDisplay->setPixmap(QPixmap::fromImage(imgForDrawQImage)
				.scaled(ui.labelDisplay->width(), ui.labelDisplay->height(), Qt::KeepAspectRatio));
		}
		return QWidget::eventFilter(obj, ev);
	}

	void ImageSettingView::landMarkRun(cv::Mat &mat_cp) {
		if (mBlockParam.size() >0) {
			int tmpCurCameraIndex = ui.comboBoxCurrentCamera->currentIndex();
			for (int i = 0; i < mBlockParam.size(); ++i) {
				if (mBlockToCameraIndex[i] == tmpCurCameraIndex) {	// ��������ŵ������ǵ�ǰ���������ٱ����ȥ

					cv::Size fontSize = cv::getTextSize(std::to_string(i), cv::FONT_HERSHEY_SIMPLEX, 4, 12, 0);
					cv::rectangle(mat_cp, cv::Point(mBlockParam[i][0], mBlockParam[i][1] - fontSize.height),
						cv::Point(mBlockParam[i][0] + fontSize.width, mBlockParam[i][1]), CvScalar(255, 0, 0), cv::FILLED);

					cv::rectangle(mat_cp, cv::Point(mBlockParam[i][0], mBlockParam[i][1]),
						cv::Point(mBlockParam[i][2], mBlockParam[i][3]), cv::Scalar(255, 0, 0), 12);
					cv::putText(mat_cp, std::to_string(i), cv::Point(mBlockParam[i][0], mBlockParam[i][1]),
						cv::FONT_HERSHEY_SIMPLEX, 4, CvScalar(255, 255, 255), 12);
				}
			}
		}
	}

	void ImageSettingView::relateParamSaving() {
		if (x1 != x2 && y1 != y2) {
			

			// ����ת���������
			int tmpPaintStartX = 0, tmpPaintStartY = 0, tmpPaintEndX = 0, tmpPaintEndY = 0;
			if (offsetPair.first == 1) {
				tmpPaintStartX = static_cast<int>((x1 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.x;
				tmpPaintStartY = static_cast<int>(y1 * adaptRatio / mPartScale) + mPartWindowRect.y;
				tmpPaintEndX = static_cast<int>((x2 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.x;
				tmpPaintEndY = static_cast<int>(y2 * adaptRatio / mPartScale) + mPartWindowRect.y;
			}
			else if (offsetPair.first == 0) {
				tmpPaintStartX = static_cast<int>(x1 * adaptRatio / mPartScale) + mPartWindowRect.x;
				tmpPaintStartY = static_cast<int>((y1 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.y;
				tmpPaintEndX = static_cast<int>(x2 * adaptRatio / mPartScale) + mPartWindowRect.x;
				tmpPaintEndY = static_cast<int>((y2 - offsetPair.second) * adaptRatio / mPartScale) + mPartWindowRect.y;
			}
			if (tmpPaintStartX < 0) tmpPaintStartX = 0;
			if (tmpPaintStartY < 0) tmpPaintStartY = 0;
			if (tmpPaintEndX >= frameSize.width) tmpPaintEndX = frameSize.width - 1;
			if (tmpPaintEndY >= frameSize.height) tmpPaintEndY = frameSize.height - 1;


			int tmpCurBlockIndex = mBlockParam.size();
			// �����������������Ϊblock�ĸ���
			mBlockParam.push_back({ tmpPaintStartX, tmpPaintStartY, tmpPaintEndX, tmpPaintEndY });
			//std::cout << "new axis: [" << x1 << " " << y1 << " " << x2 << " " << y2 << "]" << std::endl;
			// �������õĲ���
			std::vector<int> paramSetSingleLine(needParamSetNum, 0);
			mSettingParam.push_back({ paramSetSingleLine });
			// ����ÿ�������Ӧ��block������
			int tmpCurCameraIndex = ui.comboBoxCurrentCamera->currentIndex();
			if (mCameraParamIndex.find(tmpCurCameraIndex) != mCameraParamIndex.end()) {
				mCameraParamIndex[tmpCurCameraIndex].push_back(tmpCurBlockIndex);
			}
			else {
				mCameraParamIndex.insert({ tmpCurCameraIndex,{ tmpCurBlockIndex } });
			}
			// �������block��Ŷ�Ӧ�����
			mBlockToCameraIndex.insert({ tmpCurBlockIndex , tmpCurCameraIndex });
			
			// ���������в���һ������
			refreshTableWidgetParam();

			// (TODO)
			// �������Ҫ��������㷨��ص�һϵ�в��������Ը�����߿�ʼ
			cv::Mat tmpProcessMat;
			matForDrawPart.copyTo(tmpProcessMat);
			tmpProcessMat = tmpProcessMat(cv::Range(tmpPaintStartY, tmpPaintEndY), cv::Range(tmpPaintStartX, tmpPaintEndX));

			Controller::DomainController::getInstance()->Check1TestSettingPreprocess1(tmpProcessMat);
		}
	}

	void ImageSettingView::onButtonNewModel() {
		if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_INITIAL_NONE) {	// �½�
			mSettingProgressStatus = View::ImageSettingView::PROGRESS_NEW_MODEL;
			updateByProgressStatus();
		}
		else if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {	// ����
			mSettingProgressStatus = View::ImageSettingView::PROGRESS_NEW_MODEL_FINISH;
			updateByProgressStatus();
		}
	}

	void ImageSettingView::onButtonLoadModel() {
		if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_INITIAL_NONE) {
			mSettingProgressStatus = View::ImageSettingView::PROGRESS_LOAD_MODEL;
			updateByProgressStatus();
		}
	}

	void ImageSettingView::updateByProgressStatus() {
		switch (mSettingProgressStatus)
		{
			case View::ImageSettingView::PROGRESS_LOAD_MODEL: {
				mSettingModelName = ui.comboBoxLoadModel->currentText();
				// �ر������ʾ���
				ui.comboBoxCurrentCamera->setCurrentIndex(mExternalCameraNums);
				if (mSettingModelName.size() == 0) {	// �жϼ���ģ�����ƹ淶
					QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("����ģ��ʧ�ܣ�"), QMessageBox::Yes);
				}
				else {
					curModelName = ui.comboBoxLoadModel->currentText().toStdString();

					// �����ź��޸�������ĵ�ǰģ�ͱ���
					emit signalCurRunModel(curModelName);

					QMessageBox::information(NULL, QStringLiteral("��ʾ"), "Load Model " + mSettingModelName + "!", QMessageBox::Yes);
				}
				
				break;
			}
			case View::ImageSettingView::PROGRESS_NEW_MODEL: {
				mSettingModelName = ui.lineEditNewModel->text();
				// �ر������ʾ���
				ui.comboBoxCurrentCamera->setCurrentIndex(mExternalCameraNums);
				if (mSettingModelName.size() == 0) {	// �жϴ�����ģ�����ƹ淶
					QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("����ģ��ʧ�ܣ���������! "), QMessageBox::Yes);
					mSettingProgressStatus = View::ImageSettingView::PROGRESS_INITIAL_NONE;

				}
				else {
					curModelName = ui.lineEditNewModel->text().toStdString();
					// ����ǰ������ӵ����е�ģ��box����
					// ���ж������û�У��еĻ����޸�ģ�ͣ�ֻ�滻�������������
					int tmpJudgeIndex = -1;
					for (int i = 0; i < mModelNames.size(); ++i) {
						if (mModelNames[i] == curModelName) {
							tmpJudgeIndex = i;
							break;
						}
					}
					if (tmpJudgeIndex == -1) {	// �Ҳ����ٲ���
						ui.comboBoxLoadModel->addItem(QString::fromStdString(curModelName));
						mModelNames.push_back(curModelName);
					}
					else {
						QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("�Ѿ����ڴ�ģ�ͣ������趨�����ǣ���ȡ����Ҫ�رպ����´�! "), QMessageBox::Yes);
					}
					QMessageBox::information(NULL, QStringLiteral("��ʾ"), "Create New Model " + mSettingModelName + "!", QMessageBox::Yes);
					// ������ť�ı�
					ui.buttonNewModel->setText(QStringLiteral("����"));
					// ʹ�ܼ���������
					ui.groupBoxDetectTypeSetting->setEnabled(true);
				}
				break;
			}
			case View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK: {
				labelDisplayStartOffset.first = ui.labelDisplay->pos().x();
				labelDisplayStartOffset.second = ui.labelDisplay->pos().y();
				break;
			}
			case View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK_NULL: {
				break;
			}
			case View::ImageSettingView::PROGRESS_NEW_MODEL_FINISH: {
				// ������ť�ı�
				ui.buttonNewModel->setText(QStringLiteral("�½�"));
				// �����������
				saveRelatedParam();
				// ʧ�ܲ�������
				ui.groupBoxDetectTypeSetting->setDisabled(true);
				break;
			}
			default:
				break;
		}
	}

	void ImageSettingView::saveRelatedParam() {
		QMessageBox::StandardButton rs = QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�Ƿ񱣴浱ǰģ�Ͳ���?"), QMessageBox::Yes);
		if (rs == QMessageBox::Yes) {
			// ��ʼ��״̬��
			mSettingProgressStatus = View::ImageSettingView::PROGRESS_INITIAL_NONE;
			updateByProgressStatus();

			// �����������
			std::cout << "addNewModelName start." << std::endl;
			int tmpJudgeIndex = -1;
			for (int i = 0; i < mModelNames.size(); ++i) {
				if (mModelNames[i] == curModelName) {
					tmpJudgeIndex = i;
					break;
				}
			}
			if (tmpJudgeIndex == -1) {	// �Ҳ����ٲ���
				Controller::DomainController::getInstance()->addNewModelName(mModelNames.size(), curModelName);
			}
			else {
				std::cout << "already have, no need to recreate" << std::endl;
			}
			std::cout << "addNewModelName end." << std::endl;

			std::cout << "saveTargetModelBlockParam start." << std::endl;
			Controller::DomainController::getInstance()->saveTargetModelBlockParam(mBlockParam, curModelName);
			std::cout << "saveTargetModelBlockParam end." << std::endl;

			std::cout << "saveTargetModelSettingParam start." << std::endl;
			Controller::DomainController::getInstance()->saveTargetModelSettingParam(mSettingParam, curModelName);
			std::cout << "saveTargetModelSettingParam end." << std::endl;

			std::cout << "saveTargetModelBlock2CameraIndexParam start." << std::endl;
			Controller::DomainController::getInstance()->saveTargetModelBlock2CameraIndexParam(mBlockToCameraIndex, curModelName);
			std::cout << "saveTargetModelBlock2CameraIndexParam end." << std::endl;

			std::cout << "saveTargetModelCamera2BlockIndexParam start." << std::endl;
			Controller::DomainController::getInstance()->saveTargetModelCamera2BlockIndexParam(mCameraParamIndex, curModelName);
			std::cout << "saveTargetModelCamera2BlockIndexParam end." << std::endl;

			std::cout << "����������" << std::endl;
		}		
	}

	void ImageSettingView::onComboBoxCurrentCameraChanged(int tabIdx) {
		if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_INITIAL_NONE) {	// ��ʼ״̬��������ʾ����ͼ����Ƶ
			if (tabIdx < mExternalCameraNums) {
				if (mCamerasDisplayTimer != nullptr) {
					if (mCamerasDisplayTimer->isActive() == true) {
						mCamerasDisplayTimer->stop();
					}
					QMessageBox::StandardButton rs = QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�����л����..."), QMessageBox::Yes);
					if (rs == QMessageBox::Yes) {
						if (mCamerasDisplayTimer->isActive() == false) {
							mCamerasDisplayTimer->start();
						}
					}
				}
			}
			else {	// �ر������ʾ�Լ���ʱ��
				ui.labelDisplay->clear();
				if (mCamerasDisplayTimer->isActive() == true) {
					mCamerasDisplayTimer->stop();
				}
			}
		}
		else if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL
			|| mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK){		// �����µ�ģ��
			if (tabIdx < mExternalCameraNums) {
				Controller::DomainController::getInstance()->getSingleImage(tabIdx, mCamerasMat[tabIdx]);
				matForDrawPart = mCamerasMat[tabIdx].clone();
				calMarkParam();	// ����һ�β���
				
				cv::Mat matPartCpy;
				matForDrawPart.copyTo(matPartCpy);
				matPartCpy = matPartCpy(mPartWindowRect);
				// ������ʾ
				cv::Mat thisTabCameraMat(matPartCpy.size(), matPartCpy.type());
				cv::cvtColor(matPartCpy, thisTabCameraMat, CV_BGR2RGB);
				cv::resize(thisTabCameraMat, thisTabCameraMat, cv::Size(thisTabCameraMat.cols / mDisplayScale, thisTabCameraMat.rows / mDisplayScale), 0, 0, cv::INTER_NEAREST);
				QImage singleQImage(thisTabCameraMat.data, thisTabCameraMat.cols,
					thisTabCameraMat.rows, thisTabCameraMat.cols*thisTabCameraMat.channels(), QImage::Format_RGB888);
				ui.labelDisplay->setPixmap(QPixmap::fromImage(singleQImage).
					scaled(ui.labelDisplay->width(), ui.labelDisplay->height(), Qt::KeepAspectRatio));

				if (mSettingProgressStatus != View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK)
					mSettingProgressStatus = View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK;
			}
			else {	// �ر������ʾ
				ui.labelDisplay->clear();
				if (mSettingProgressStatus != View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK_NULL)
					mSettingProgressStatus = View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK_NULL;
			}
			updateByProgressStatus();
		}
		else if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_LOAD_MODEL) {	// ��ȡ���е�ģ��

		}
		//Controller::DomainController::getInstance()->getPicTest();
	}

	void ImageSettingView::calMarkParam() {
		frameSize = matForDrawPart.size();	// ���³ߴ�
		// ����ͼ��ʵ�����ű���
		float ratioX = static_cast<float>(frameSize.width) / ui.labelDisplay->width();
		float ratioY = static_cast<float>(frameSize.height) / ui.labelDisplay->height();
		adaptRatio = MAX(ratioX, ratioY);	// �������ŵı���ȡ���
		if (adaptRatio == ratioX) {	// ȡX��Ϊ�Ŵ���
			offsetPair.first = 0;
			offsetPair.second = static_cast<int>((ui.labelDisplay->height() - (frameSize.height / adaptRatio)) / 2);	// ������ʾ����һ��ƫ����
		}
		else {	// ȡY��Ϊ�Ŵ���
			offsetPair.first = 1;
			offsetPair.second = static_cast<int>((ui.labelDisplay->width() - (frameSize.width / adaptRatio)) / 2);	// ������ʾ����һ��ƫ����
		}
		// ��¼���ڴ�С
		mPartWindowRect.x = 0;
		mPartWindowRect.y = 0;
		mPartWindowRect.width = static_cast<int>(static_cast<float>(frameSize.width) / mPartScale);
		mPartWindowRect.height = static_cast<int>(static_cast<float>(frameSize.height) / mPartScale);
	}

	void ImageSettingView::onCamerasDisplayTimerTimeOut() {
		int tabIdx = ui.comboBoxCurrentCamera->currentIndex();
		if (tabIdx < mExternalCameraNums) {
			try
			{
				// ������ʾ
				cv::Mat thisTabCameraMat(mCamerasMat[tabIdx].size(), mCamerasMat[tabIdx].type());
				Controller::DomainController::getInstance()->getSingleImage(tabIdx, mCamerasMat[tabIdx]);
				cv::cvtColor(mCamerasMat[tabIdx], thisTabCameraMat, CV_BGR2RGB);
				cv::resize(thisTabCameraMat, thisTabCameraMat, cv::Size(thisTabCameraMat.cols / mDisplayScale, thisTabCameraMat.rows / mDisplayScale), 0, 0, cv::INTER_NEAREST);
				QImage singleQImage(thisTabCameraMat.data, thisTabCameraMat.cols,
					thisTabCameraMat.rows, thisTabCameraMat.cols*thisTabCameraMat.channels(), QImage::Format_RGB888);
				ui.labelDisplay->setPixmap(QPixmap::fromImage(singleQImage).
					scaled(ui.labelDisplay->width(), ui.labelDisplay->height(), Qt::KeepAspectRatio));
			}
			catch (const std::exception&)
			{
				QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("�����ȡͼ��ʧ�ܣ�"), QMessageBox::Yes);
			}
		}
		else {	// �л����հױ�ǩҳ
			ui.labelDisplay->clear();
			if (mCamerasDisplayTimer->isActive() == true) {
				mCamerasDisplayTimer->stop();
			}
		}
	}

	//void ImageSettingView::onGetFin() {
	//	std::cout << "onGetFin" << std::endl;
	//	// ������ʾ
	//	cv::Mat thisTabCameraMat(mCamerasMat[0].size(), mCamerasMat[0].type());
	//	thisTabCameraMat = cv::imread("result.jpg");
	//	cv::resize(thisTabCameraMat, thisTabCameraMat, cv::Size(thisTabCameraMat.cols / 100, thisTabCameraMat.rows / 100), 0, 0, cv::INTER_NEAREST);
	//	cv::cvtColor(mCamerasMat[0], thisTabCameraMat, CV_BGR2RGB);
	//	QImage singleQImage(thisTabCameraMat.data, thisTabCameraMat.cols,
	//		thisTabCameraMat.rows, thisTabCameraMat.cols*thisTabCameraMat.channels(), QImage::Format_RGB888);
	//	ui.labelDisplay->setPixmap(QPixmap::fromImage(singleQImage).
	//		scaled(ui.labelDisplay->width(), ui.labelDisplay->height(), Qt::KeepAspectRatio));
	//	Controller::DomainController::getInstance()->setPicTest();
	//}

	void ImageSettingView::initCamerasTab() {
		// ��ʼ���������
		ui.labelCamerasNum->setText(QString::fromStdString(std::to_string(mExternalCameraNums)));
		// ��ʼ��comboBox��Ŀ
		for (int i = 0; i < mExternalCameraNums; ++i) {
			// ����ͼ��Mat
			cv::Mat tmpMat;
			Controller::DomainController::getInstance()->getSingleImage(i, tmpMat);
			mCamerasMat.push_back(tmpMat);
			// ��comboBox�������Ŀ
			ui.comboBoxCurrentCamera->addItem(QString::fromStdString("Camera " + std::to_string(i)));
		}
		// ��comboBox����ӹر��������ѡ��
		ui.comboBoxCurrentCamera->addItem(QString::fromStdString("Null"));
		// ��ʼ��Ϊ������
		ui.comboBoxCurrentCamera->setCurrentIndex(mExternalCameraNums);
		// ����
		connect(ui.comboBoxCurrentCamera, SIGNAL(currentIndexChanged(int)), 
			this, SLOT(onComboBoxCurrentCameraChanged(int)));
		// ��ʼ�����������ʾ��ʱ��
		if (mCamerasDisplayTimer == nullptr) {
			mCamerasDisplayTimer = new QTimer();
			mCamerasDisplayTimer->setInterval(10);
			connect(mCamerasDisplayTimer, SIGNAL(timeout()),
				this, SLOT(onCamerasDisplayTimerTimeOut()));
		}
		//connect(Controller::DomainController::getInstance(), SIGNAL(getPicFinished()),
		//	this, SLOT(onGetFin()));
		
	}

	void ImageSettingView::initModelMsg() {
		// ��ȡ���е�ģ������
		mModelNames = Controller::DomainController::getInstance()->readAllModelNames();
		// ��ӽ�������
		for (int i = 0; i < mModelNames.size(); ++i) {
			ui.comboBoxLoadModel->addItem(QString::fromStdString(mModelNames[i]));
		}
		// ����indexΪ-1
		ui.comboBoxLoadModel->setCurrentIndex(-1);
	}

	void ImageSettingView::initDetectTypeSetting() {
		mDetectTypeSettingNames = Controller::DomainController::getInstance()->getDetectTypeSettingNames();
		mDetectTypeSettingParamNames = Controller::DomainController::getInstance()->getDetectTypeSettingParamNames();

		// 1����ʼ�������ļ������
		mDetectTypeSettings.resize(mDetectTypeSettingNames.size());
		// 2����ʼ��Ƕ����ScrollArea�в��ֵĿ����
		// 2���������а�����ÿ��������ͷ���ռ䡢�����źš���ӵ�ScrollArea������
		for (int i = 0; i < mDetectTypeSettings.size(); ++i) {
			mDetectTypeSettings[i] = new DetectTypeSettingWidget(mDetectTypeSettingNames[i],
				mDetectTypeSettingParamNames[i]);
			ui.gridLayoutDetectTypeScrollArea->addWidget(mDetectTypeSettings[i], i / perLineDetectTypeNums, i % perLineDetectTypeNums);

			// ����ۺ������⼸�������ӵ�һ�����������ݶ�Ӧ������������ж��ǵڼ���
			connect(mDetectTypeSettings[i], SIGNAL(radioButtonSignal(bool)), this, SLOT(onRadioButtonSignal(bool)));
			connect(mDetectTypeSettings[i], SIGNAL(lineEditSignal(int, int)), this, SLOT(onLineEditSignal(int, int)));
		}
		ui.scrollAreaWidgetContentsDetectTypeSetting->setMinimumWidth(perDetectTypeWidth * perLineDetectTypeNums);
		ui.scrollAreaWidgetContentsDetectTypeSetting->setMinimumHeight(perDetectTypeHeight * (mDetectTypeSettings.size() / perLineDetectTypeNums + 1));
	}

	void ImageSettingView::onRadioButtonSignal(bool status) {
		if (!isOnPartLeftClick) {
			QObject *obj = QObject::sender();
			DetectTypeSettingWidget *thisTriggerDetectTypeSettingWidget = qobject_cast<DetectTypeSettingWidget *>(obj);

			std::string tmpName = thisTriggerDetectTypeSettingWidget->getGroupBoxName();

			// �õ��������֮��ȥ���ǵڼ���������Ϳ�Ȼ��ӳ�䵽paramset��Ӧ��λ��
			int tmpIndex = -1;
			for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
				if (mDetectTypeSettingNames[i] == tmpName) {
					tmpIndex = i;
					break;
				}
			}
			std::cout << "��ǰ���ü������: " << tmpIndex << std::endl;
			// ӳ��
			int paramSetIndex = 0;	// ����λ
			for (int i = 0; i < tmpIndex; ++i) {
				paramSetIndex += (1 + mDetectTypeSettingParamNames[i].size());
			}
			//paramSetIndex += 1;

			// ���µ�mSettingParam��
			mSettingParam.back()[paramSetIndex] = static_cast<int>(status);
			// ���µ������
			refreshTableWidgetParam();
		}
	}

	void ImageSettingView::onLineEditSignal(int index, int value) {
		if (!isOnPartLeftClick) {
			QObject *obj = QObject::sender();
			DetectTypeSettingWidget *thisTriggerDetectTypeSettingWidget = qobject_cast<DetectTypeSettingWidget *>(obj);

			std::string tmpName = thisTriggerDetectTypeSettingWidget->getGroupBoxName();

			// �õ��������֮��ȥ���ǵڼ���������Ϳ�Ȼ��ӳ�䵽paramset��Ӧ��λ��
			int tmpIndex = -1;
			for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
				if (mDetectTypeSettingNames[i] == tmpName) {
					tmpIndex = i;
					break;
				}
			}

			// ӳ��
			int paramSetIndex = 0;	// ����λ
			for (int i = 0; i < tmpIndex; ++i) {
				paramSetIndex += (1 + mDetectTypeSettingParamNames[i].size());
			}
			paramSetIndex += (1 + index);

			// ���µ�mSettingParam��
			mSettingParam.back()[paramSetIndex] = value;
			// ���µ������
			refreshTableWidgetParam();
		}
	}

	void ImageSettingView::refreshTableWidgetParam() {
		// �����ˢ����ʾmSettingParam

		// ��ձ����ʾ
		//ui.tableWidgetParam->clear();
		while (ui.tableWidgetParam->rowCount() > 0)
			ui.tableWidgetParam->removeRow(ui.tableWidgetParam->rowCount() - 1);

		// ���ñ������
		//ui.tableWidgetParam->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);	// ����
		ui.tableWidgetParam->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);	// ����
		ui.tableWidgetParam->setSelectionBehavior(QAbstractItemView::SelectRows);	// ѡ����
		ui.tableWidgetParam->setRowCount(mSettingParam.size());
		ui.tableWidgetParam->setColumnCount(needParamSetNum + 1);
		ui.tableWidgetParam->verticalHeader()->setVisible(false);	// �����б�ͷ
		ui.tableWidgetParam->resizeColumnsToContents();
		// ��ʼ����ͷ����
		QStringList header;
		header << "Index";	// ����Header
		for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
			header << QString::fromStdString(mDetectTypeSettingNames[i]);	// ����־λ����
			for (int j = 0; j < mDetectTypeSettingParamNames[i].size(); ++j) {
				header << QString::fromStdString(mDetectTypeSettingParamNames[i][j]);	// �����Ҫ�Ĳ�������
			}
		}
		ui.tableWidgetParam->setHorizontalHeaderLabels(header);

		// ����mSettingParam����(��Ҫ�Լ���������)
		for (int i = 0; i < mSettingParam.size(); ++i) {
			// ���ò�����ʾ
			ui.tableWidgetParam->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(std::to_string(i))));
			for (int j = 0; j < mSettingParam[i].size(); ++j) {
				ui.tableWidgetParam->setItem(i, j + 1, new QTableWidgetItem(QString::fromStdString(std::to_string(mSettingParam[i][j]))));
			}
		}

		//for (int i = 0; i < mSettingParam.size(); ++i) {
		//	for (int j = 0; j < mSettingParam[i].size(); ++j) {
		//		std::cout << mSettingParam[i][j] << " ";
		//	}
		//	std::cout << std::endl;
		//}
	}
}

namespace View {
	DetectTypeSettingWidget::DetectTypeSettingWidget(
		std::string groupBoxName,
		std::vector<std::string> lineEditNames)
	: groupBoxName(groupBoxName), lineEditNames(lineEditNames){
		// ����ռ�
		if (mSingleDetectTypeLayout == NULL)	// ������Layout
			mSingleDetectTypeLayout = new QGridLayout();
		if (mQGroupBoxSingleDetectType == NULL)	// QGroupBox
			mQGroupBoxSingleDetectType = new QGroupBox(QString::fromStdString(groupBoxName));
		if (mGroupBoxSingleDetectTypeLayout == NULL)	// QGroupBox����Ĳ���
			mGroupBoxSingleDetectTypeLayout = new QGridLayout();
		if (radioButtonYes == NULL)	// �������QRadioButton
			radioButtonYes = new QRadioButton(QStringLiteral("�������"));
		if (radioButtonNo == NULL) {	// �رռ��QRadioButton
			radioButtonNo = new QRadioButton(QStringLiteral("�رռ��"));
			radioButtonNo->setChecked(true);
		}
		if (radioButtonGroup == NULL) {
			radioButtonGroup = new QButtonGroup(this);
			radioButtonGroup->addButton(radioButtonYes, 0);
			radioButtonGroup->addButton(radioButtonNo, 1);
		}
		for (int i = 0; i < lineEditNames.size(); ++i) {
			// QLabels
			QLabel *tmpQLabel = new QLabel(QString::fromStdString(lineEditNames[i]));
			tmpQLabel->setObjectName(QString::fromStdString("label_" + std::to_string(i)));
			mQLabelParamNames.push_back(tmpQLabel);
			// QLineEdits
			QLineEdit *tmpQLineEdit = new QLineEdit();
			tmpQLineEdit->setObjectName(QString::fromStdString("lineEdit_" + std::to_string(i)));
			mQLineEditParamValues.push_back(tmpQLineEdit);
			tmpQLineEdit->setText("0");

			// ���lineEdit�����ӵ�һ������
			connect(tmpQLineEdit, SIGNAL(editingFinished()), this, SLOT(lineEditGroupEditingFinished()));
		}

		// ��QGroupBox�Ĳ����������������ò��ַ�Ϊ���ж��У�
		mGroupBoxSingleDetectTypeLayout->setColumnStretch(2, 0);
		mGroupBoxSingleDetectTypeLayout->addWidget(radioButtonYes, 0, 0);	// Yes RadioButton ��0�е�0��
		mGroupBoxSingleDetectTypeLayout->addWidget(radioButtonNo, 0, 1);	// No RadioButton ��0�е�1��
		for (int i = 0; i < lineEditNames.size(); ++i) {	// �·��Ĳ���
			mGroupBoxSingleDetectTypeLayout->addWidget(mQLabelParamNames[i], i + 1, 0);	// ��һ��Ϊparam������
			mGroupBoxSingleDetectTypeLayout->addWidget(mQLineEditParamValues[i], i + 1, 1);	// �ڶ���Ϊparam�ľ����������
		}
		
		// ����QGroupBox�Ĳ���
		mQGroupBoxSingleDetectType->setLayout(mGroupBoxSingleDetectTypeLayout);
		// ���QGroupBox��������Layout
		mSingleDetectTypeLayout->addWidget(mQGroupBoxSingleDetectType);
		
		// ��QGroupBox��ӽ�������Layout�� 
		setLayout(mSingleDetectTypeLayout);

		// �ź�
		connect(radioButtonGroup, SIGNAL(buttonToggled(int, bool)), this, SLOT(radioButtonGroupToggled(int, bool)));
	}

	void DetectTypeSettingWidget::lineEditGroupEditingFinished() {
		QObject *obj = QObject::sender();
		QLineEdit *thisTriggerLineEdit = qobject_cast<QLineEdit *>(obj);
		QString thisTriggerLineEditName = thisTriggerLineEdit->objectName();

		QStringList nameSplitLists = thisTriggerLineEditName.split('_');
		int triggerIndex = nameSplitLists.back().toInt();

		//std::cout << triggerIndex << " " << thisTriggerLineEdit->text().toInt() << std::endl;

		if (thisTriggerLineEdit->text().size() > 0 && thisTriggerLineEdit->text() != "0")
			emit lineEditSignal(triggerIndex, thisTriggerLineEdit->text().toInt());
	}

	void DetectTypeSettingWidget::radioButtonGroupToggled(int index, bool status) {
		if (status == 1) {
			if (index == 0) {
				emit radioButtonSignal(1);
			}
			else {
				emit radioButtonSignal(0);
			}
		}
	}

	void DetectTypeSettingWidget::resetParamStatus() {
		// ��ʼ�����״̬��־λ
		radioButtonNo->setChecked(true);
		// ��ʼ��lineEdit����
		for (int i = 0; i < mQLineEditParamValues.size(); ++i) {
			mQLineEditParamValues[i]->setText("0");
		}
	}

	std::string DetectTypeSettingWidget::getGroupBoxName() {
		return groupBoxName;
	}

	DetectTypeSettingWidget::~DetectTypeSettingWidget() {
		//if (radioButtonYes != NULL)
		//	delete radioButtonYes;
		//if (radioButtonNo != NULL)
		//	delete radioButtonNo;
		//if (mQGroupBoxSingleDetectType != NULL)
		//	delete mQGroupBoxSingleDetectType;
		//if (mSingleDetectTypeLayout != NULL)
		//	delete mSingleDetectTypeLayout;
		//if (mGroupBoxSingleDetectTypeLayout != NULL)
		//	delete mGroupBoxSingleDetectTypeLayout;
		//for (int i = 0; i < mQLabelParamNames.size(); ++i) {
		//	if (mQLabelParamNames[i] != NULL)
		//		delete mQLabelParamNames[i];
		//	if (mQLineEditParamValues[i] != NULL)
		//		delete mQLineEditParamValues[i];
		//}
	}
}