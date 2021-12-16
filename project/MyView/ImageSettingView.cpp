#include "ImageSettingView.h"

namespace View {
	ImageSettingView::ImageSettingView() {
		ui.setupUi(this);

		// 接收响应鼠标事件的labelDisplay
		connect(ui.labelDisplay, SIGNAL(pressed(QMouseEvent *)), this, SLOT(onLabelDisplayPressed(QMouseEvent *)));
		connect(ui.labelDisplay, SIGNAL(released(QMouseEvent *)), this, SLOT(onLabelDisplayReleased(QMouseEvent *)));
		connect(ui.labelDisplay, SIGNAL(moved(QMouseEvent *)), this, SLOT(onLabelDisplayMoved(QMouseEvent *)));
		connect(ui.labelDisplay, SIGNAL(filter(QObject *, QEvent *)), this, SLOT(onLabelDisplayFilter(QObject *, QEvent *)));

		// 加载和新建模型
		connect(ui.buttonNewModel, SIGNAL(released()), this, SLOT(onButtonNewModel()));
		connect(ui.buttonLoadModel, SIGNAL(released()), this, SLOT(onButtonLoadModel()));

		// 获取外部相机数量
		mExternalCameraNums = Controller::DomainController::getInstance()->getCameraNums();
		if (mExternalCameraNums == 0) {
			QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("未检测到外部相机！"), QMessageBox::Yes);
		}
		else {
			// 根据相机数量初始化tabCameras
			std::cout << "initCamerasTab." << std::endl;
			initCamerasTab();
			std::cout << "initCamerasTab finish." << std::endl;
			// 初始化已有模型
			std::cout << "initModelMsg." << std::endl;
			initModelMsg();
			std::cout << "initModelMsg finish." << std::endl;
			// 初始化当前支持检测类型
			std::cout << "initDetectTypeSetting." << std::endl;
			initDetectTypeSetting();
			std::cout << "initDetectTypeSetting finish." << std::endl;

			// 计算局部block的表的列数 = 索引(1) + 检测/不检测 + 参数数目
			int tmpNeedParamNums = 0;
			for (int i = 0; i < mDetectTypeSettingParamNames.size(); ++i) {
				tmpNeedParamNums += mDetectTypeSettingParamNames[i].size();
			}
			needParamSetNum = mDetectTypeSettingNames.size() + tmpNeedParamNums;
		}
	}

	ImageSettingView::~ImageSettingView() {
		// 清除相机相关
		if (mCamerasDisplayTimer != nullptr) {
			if (mCamerasDisplayTimer->isActive() == true) {
				mCamerasDisplayTimer->stop();
			}
			delete mCamerasDisplayTimer;
		}
		// 清除detectType相关
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

				// 鼠标按下时初始化检测类型状态
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
		if (ev->button() == Qt::LeftButton) {	// 这里用ev->buttons()判断有问题，一直是0，无法区分左右按键
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
				if (x2 < x1 && y2 < y1) {	// 右下往左上
					std::cout << "Swap x1x2 and y1y2." << std::endl;
					std::swap(x1, x2);
					std::swap(y1, y2);
				}
				else if (x1 < x2 && y1 > y2) {	// 左下往右上
					std::cout << "Swap y1y2." << std::endl;
					std::swap(y1, y2);
				}
				else if (x1 > x2 && y1 < y2) {	// 右上往左下
					std::cout << "Swap x1x2." << std::endl;
					std::swap(x1, x2);
				}

				// 相关参数保存
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
			matForDrawPart.copyTo(mat_cp);	// 拷贝图片
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
				if (mBlockToCameraIndex[i] == tmpCurCameraIndex) {	// 如果这个编号的坐标是当前这个相机的再标记上去

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
			

			// 计算转换后的坐标
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
			// 保存坐标参数，索引为block的个数
			mBlockParam.push_back({ tmpPaintStartX, tmpPaintStartY, tmpPaintEndX, tmpPaintEndY });
			//std::cout << "new axis: [" << x1 << " " << y1 << " " << x2 << " " << y2 << "]" << std::endl;
			// 保存设置的参数
			std::vector<int> paramSetSingleLine(needParamSetNum, 0);
			mSettingParam.push_back({ paramSetSingleLine });
			// 设置每个相机对应的block索引号
			int tmpCurCameraIndex = ui.comboBoxCurrentCamera->currentIndex();
			if (mCameraParamIndex.find(tmpCurCameraIndex) != mCameraParamIndex.end()) {
				mCameraParamIndex[tmpCurCameraIndex].push_back(tmpCurBlockIndex);
			}
			else {
				mCameraParamIndex.insert({ tmpCurCameraIndex,{ tmpCurBlockIndex } });
			}
			// 保存这个block编号对应的相机
			mBlockToCameraIndex.insert({ tmpCurBlockIndex , tmpCurCameraIndex });
			
			// 往下面表格中插入一条数据
			refreshTableWidgetParam();

			// (TODO)
			// 如果有需要保存根据算法相关的一系列参数，可以根据这边开始
			cv::Mat tmpProcessMat;
			matForDrawPart.copyTo(tmpProcessMat);
			tmpProcessMat = tmpProcessMat(cv::Range(tmpPaintStartY, tmpPaintEndY), cv::Range(tmpPaintStartX, tmpPaintEndX));

			Controller::DomainController::getInstance()->Check1TestSettingPreprocess1(tmpProcessMat);
		}
	}

	void ImageSettingView::onButtonNewModel() {
		if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_INITIAL_NONE) {	// 新建
			mSettingProgressStatus = View::ImageSettingView::PROGRESS_NEW_MODEL;
			updateByProgressStatus();
		}
		else if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK) {	// 结束
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
				// 关闭相机显示相关
				ui.comboBoxCurrentCamera->setCurrentIndex(mExternalCameraNums);
				if (mSettingModelName.size() == 0) {	// 判断加载模型名称规范
					QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("加载模型失败！"), QMessageBox::Yes);
				}
				else {
					curModelName = ui.comboBoxLoadModel->currentText().toStdString();

					// 发送信号修改主界面的当前模型变量
					emit signalCurRunModel(curModelName);

					QMessageBox::information(NULL, QStringLiteral("提示"), "Load Model " + mSettingModelName + "!", QMessageBox::Yes);
				}
				
				break;
			}
			case View::ImageSettingView::PROGRESS_NEW_MODEL: {
				mSettingModelName = ui.lineEditNewModel->text();
				// 关闭相机显示相关
				ui.comboBoxCurrentCamera->setCurrentIndex(mExternalCameraNums);
				if (mSettingModelName.size() == 0) {	// 判断创建新模型名称规范
					QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("创建模型失败，请检查名称! "), QMessageBox::Yes);
					mSettingProgressStatus = View::ImageSettingView::PROGRESS_INITIAL_NONE;

				}
				else {
					curModelName = ui.lineEditNewModel->text().toStdString();
					// 将当前名称添加到已有的模型box当中
					// 先判断这个有没有，有的话不修改模型，只替换其所有相关数据
					int tmpJudgeIndex = -1;
					for (int i = 0; i < mModelNames.size(); ++i) {
						if (mModelNames[i] == curModelName) {
							tmpJudgeIndex = i;
							break;
						}
					}
					if (tmpJudgeIndex == -1) {	// 找不到再插入
						ui.comboBoxLoadModel->addItem(QString::fromStdString(curModelName));
						mModelNames.push_back(curModelName);
					}
					else {
						QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("已经存在此模型，重新设定将覆盖，如取消需要关闭后重新打开! "), QMessageBox::Yes);
					}
					QMessageBox::information(NULL, QStringLiteral("提示"), "Create New Model " + mSettingModelName + "!", QMessageBox::Yes);
					// 更换按钮文本
					ui.buttonNewModel->setText(QStringLiteral("结束"));
					// 使能检测参数设置
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
				// 更换按钮文本
				ui.buttonNewModel->setText(QStringLiteral("新建"));
				// 保存数据入库
				saveRelatedParam();
				// 失能参数设置
				ui.groupBoxDetectTypeSetting->setDisabled(true);
				break;
			}
			default:
				break;
		}
	}

	void ImageSettingView::saveRelatedParam() {
		QMessageBox::StandardButton rs = QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("是否保存当前模型参数?"), QMessageBox::Yes);
		if (rs == QMessageBox::Yes) {
			// 初始化状态机
			mSettingProgressStatus = View::ImageSettingView::PROGRESS_INITIAL_NONE;
			updateByProgressStatus();

			// 保存数据入库
			std::cout << "addNewModelName start." << std::endl;
			int tmpJudgeIndex = -1;
			for (int i = 0; i < mModelNames.size(); ++i) {
				if (mModelNames[i] == curModelName) {
					tmpJudgeIndex = i;
					break;
				}
			}
			if (tmpJudgeIndex == -1) {	// 找不到再插入
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

			std::cout << "数据入库完成" << std::endl;
		}		
	}

	void ImageSettingView::onComboBoxCurrentCameraChanged(int tabIdx) {
		if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_INITIAL_NONE) {	// 初始状态，负责显示连续图像视频
			if (tabIdx < mExternalCameraNums) {
				if (mCamerasDisplayTimer != nullptr) {
					if (mCamerasDisplayTimer->isActive() == true) {
						mCamerasDisplayTimer->stop();
					}
					QMessageBox::StandardButton rs = QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("正在切换相机..."), QMessageBox::Yes);
					if (rs == QMessageBox::Yes) {
						if (mCamerasDisplayTimer->isActive() == false) {
							mCamerasDisplayTimer->start();
						}
					}
				}
			}
			else {	// 关闭相机显示以及定时器
				ui.labelDisplay->clear();
				if (mCamerasDisplayTimer->isActive() == true) {
					mCamerasDisplayTimer->stop();
				}
			}
		}
		else if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL
			|| mSettingProgressStatus == View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK){		// 创建新的模型
			if (tabIdx < mExternalCameraNums) {
				Controller::DomainController::getInstance()->getSingleImage(tabIdx, mCamerasMat[tabIdx]);
				matForDrawPart = mCamerasMat[tabIdx].clone();
				calMarkParam();	// 计算一次参数
				
				cv::Mat matPartCpy;
				matForDrawPart.copyTo(matPartCpy);
				matPartCpy = matPartCpy(mPartWindowRect);
				// 更新显示
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
			else {	// 关闭相机显示
				ui.labelDisplay->clear();
				if (mSettingProgressStatus != View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK_NULL)
					mSettingProgressStatus = View::ImageSettingView::PROGRESS_NEW_MODEL_BLOCK_MARK_NULL;
			}
			updateByProgressStatus();
		}
		else if (mSettingProgressStatus == View::ImageSettingView::PROGRESS_LOAD_MODEL) {	// 调取已有的模型

		}
		//Controller::DomainController::getInstance()->getPicTest();
	}

	void ImageSettingView::calMarkParam() {
		frameSize = matForDrawPart.size();	// 更新尺寸
		// 计算图像实际缩放比率
		float ratioX = static_cast<float>(frameSize.width) / ui.labelDisplay->width();
		float ratioY = static_cast<float>(frameSize.height) / ui.labelDisplay->height();
		adaptRatio = MAX(ratioX, ratioY);	// 真正缩放的比率取大的
		if (adaptRatio == ratioX) {	// 取X作为放大倍数
			offsetPair.first = 0;
			offsetPair.second = static_cast<int>((ui.labelDisplay->height() - (frameSize.height / adaptRatio)) / 2);	// 居中显示存在一个偏移量
		}
		else {	// 取Y作为放大倍数
			offsetPair.first = 1;
			offsetPair.second = static_cast<int>((ui.labelDisplay->width() - (frameSize.width / adaptRatio)) / 2);	// 居中显示存在一个偏移量
		}
		// 记录窗口大小
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
				// 更新显示
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
				QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("相机获取图像失败！"), QMessageBox::Yes);
			}
		}
		else {	// 切换到空白标签页
			ui.labelDisplay->clear();
			if (mCamerasDisplayTimer->isActive() == true) {
				mCamerasDisplayTimer->stop();
			}
		}
	}

	//void ImageSettingView::onGetFin() {
	//	std::cout << "onGetFin" << std::endl;
	//	// 更新显示
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
		// 初始化相机数量
		ui.labelCamerasNum->setText(QString::fromStdString(std::to_string(mExternalCameraNums)));
		// 初始化comboBox条目
		for (int i = 0; i < mExternalCameraNums; ++i) {
			// 构造图像Mat
			cv::Mat tmpMat;
			Controller::DomainController::getInstance()->getSingleImage(i, tmpMat);
			mCamerasMat.push_back(tmpMat);
			// 往comboBox中添加条目
			ui.comboBoxCurrentCamera->addItem(QString::fromStdString("Camera " + std::to_string(i)));
		}
		// 往comboBox中添加关闭所有相机选项
		ui.comboBoxCurrentCamera->addItem(QString::fromStdString("Null"));
		// 初始化为空索引
		ui.comboBoxCurrentCamera->setCurrentIndex(mExternalCameraNums);
		// 链接
		connect(ui.comboBoxCurrentCamera, SIGNAL(currentIndexChanged(int)), 
			this, SLOT(onComboBoxCurrentCameraChanged(int)));
		// 初始化相机连续显示定时器
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
		// 获取所有的模型名称
		mModelNames = Controller::DomainController::getInstance()->readAllModelNames();
		// 添加进下拉框
		for (int i = 0; i < mModelNames.size(); ++i) {
			ui.comboBoxLoadModel->addItem(QString::fromStdString(mModelNames[i]));
		}
		// 设置index为-1
		ui.comboBoxLoadModel->setCurrentIndex(-1);
	}

	void ImageSettingView::initDetectTypeSetting() {
		mDetectTypeSettingNames = Controller::DomainController::getInstance()->getDetectTypeSettingNames();
		mDetectTypeSettingParamNames = Controller::DomainController::getInstance()->getDetectTypeSettingParamNames();

		// 1、初始化包含的检测类型
		mDetectTypeSettings.resize(mDetectTypeSettingNames.size());
		// 2、初始化嵌套在ScrollArea中布局的宽与高
		// 2、对于其中包含的每个检测类型分配空间、连接信号、添加到ScrollArea区域中
		for (int i = 0; i < mDetectTypeSettings.size(); ++i) {
			mDetectTypeSettings[i] = new DetectTypeSettingWidget(mDetectTypeSettingNames[i],
				mDetectTypeSettingParamNames[i]);
			ui.gridLayoutDetectTypeScrollArea->addWidget(mDetectTypeSettings[i], i / perLineDetectTypeNums, i % perLineDetectTypeNums);

			// 定义槽函数，这几个都链接到一个函数，根据对应检测框的名字来判断是第几个
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

			// 得到框的名字之后去找是第几个检测类型框，然后映射到paramset对应的位置
			int tmpIndex = -1;
			for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
				if (mDetectTypeSettingNames[i] == tmpName) {
					tmpIndex = i;
					break;
				}
			}
			std::cout << "当前设置检测类型: " << tmpIndex << std::endl;
			// 映射
			int paramSetIndex = 0;	// 索引位
			for (int i = 0; i < tmpIndex; ++i) {
				paramSetIndex += (1 + mDetectTypeSettingParamNames[i].size());
			}
			//paramSetIndex += 1;

			// 更新到mSettingParam中
			mSettingParam.back()[paramSetIndex] = static_cast<int>(status);
			// 更新到表格中
			refreshTableWidgetParam();
		}
	}

	void ImageSettingView::onLineEditSignal(int index, int value) {
		if (!isOnPartLeftClick) {
			QObject *obj = QObject::sender();
			DetectTypeSettingWidget *thisTriggerDetectTypeSettingWidget = qobject_cast<DetectTypeSettingWidget *>(obj);

			std::string tmpName = thisTriggerDetectTypeSettingWidget->getGroupBoxName();

			// 得到框的名字之后去找是第几个检测类型框，然后映射到paramset对应的位置
			int tmpIndex = -1;
			for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
				if (mDetectTypeSettingNames[i] == tmpName) {
					tmpIndex = i;
					break;
				}
			}

			// 映射
			int paramSetIndex = 0;	// 索引位
			for (int i = 0; i < tmpIndex; ++i) {
				paramSetIndex += (1 + mDetectTypeSettingParamNames[i].size());
			}
			paramSetIndex += (1 + index);

			// 更新到mSettingParam中
			mSettingParam.back()[paramSetIndex] = value;
			// 更新到表格中
			refreshTableWidgetParam();
		}
	}

	void ImageSettingView::refreshTableWidgetParam() {
		// 表格中刷新显示mSettingParam

		// 清空表格显示
		//ui.tableWidgetParam->clear();
		while (ui.tableWidgetParam->rowCount() > 0)
			ui.tableWidgetParam->removeRow(ui.tableWidgetParam->rowCount() - 1);

		// 设置表格属性
		//ui.tableWidgetParam->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);	// 均分
		ui.tableWidgetParam->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);	// 均分
		ui.tableWidgetParam->setSelectionBehavior(QAbstractItemView::SelectRows);	// 选中行
		ui.tableWidgetParam->setRowCount(mSettingParam.size());
		ui.tableWidgetParam->setColumnCount(needParamSetNum + 1);
		ui.tableWidgetParam->verticalHeader()->setVisible(false);	// 隐藏行表头
		ui.tableWidgetParam->resizeColumnsToContents();
		// 初始化列头名称
		QStringList header;
		header << "Index";	// 索引Header
		for (int i = 0; i < mDetectTypeSettingNames.size(); ++i) {
			header << QString::fromStdString(mDetectTypeSettingNames[i]);	// 检测标志位名称
			for (int j = 0; j < mDetectTypeSettingParamNames[i].size(); ++j) {
				header << QString::fromStdString(mDetectTypeSettingParamNames[i][j]);	// 检测需要的参数类型
			}
		}
		ui.tableWidgetParam->setHorizontalHeaderLabels(header);

		// 根据mSettingParam插入(需要自己设置索引)
		for (int i = 0; i < mSettingParam.size(); ++i) {
			// 设置参数显示
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
		// 分配空间
		if (mSingleDetectTypeLayout == NULL)	// 最外层的Layout
			mSingleDetectTypeLayout = new QGridLayout();
		if (mQGroupBoxSingleDetectType == NULL)	// QGroupBox
			mQGroupBoxSingleDetectType = new QGroupBox(QString::fromStdString(groupBoxName));
		if (mGroupBoxSingleDetectTypeLayout == NULL)	// QGroupBox本身的布局
			mGroupBoxSingleDetectTypeLayout = new QGridLayout();
		if (radioButtonYes == NULL)	// 启动检测QRadioButton
			radioButtonYes = new QRadioButton(QStringLiteral("启动检测"));
		if (radioButtonNo == NULL) {	// 关闭检测QRadioButton
			radioButtonNo = new QRadioButton(QStringLiteral("关闭检测"));
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

			// 多个lineEdit都连接到一个函数
			connect(tmpQLineEdit, SIGNAL(editingFinished()), this, SLOT(lineEditGroupEditingFinished()));
		}

		// 往QGroupBox的布局中添加子组件（该布局分为两列多行）
		mGroupBoxSingleDetectTypeLayout->setColumnStretch(2, 0);
		mGroupBoxSingleDetectTypeLayout->addWidget(radioButtonYes, 0, 0);	// Yes RadioButton 第0行第0个
		mGroupBoxSingleDetectTypeLayout->addWidget(radioButtonNo, 0, 1);	// No RadioButton 第0行第1个
		for (int i = 0; i < lineEditNames.size(); ++i) {	// 下方的参数
			mGroupBoxSingleDetectTypeLayout->addWidget(mQLabelParamNames[i], i + 1, 0);	// 第一列为param的名称
			mGroupBoxSingleDetectTypeLayout->addWidget(mQLineEditParamValues[i], i + 1, 1);	// 第二列为param的具体参数输入
		}
		
		// 设置QGroupBox的布局
		mQGroupBoxSingleDetectType->setLayout(mGroupBoxSingleDetectTypeLayout);
		// 添加QGroupBox到最外层的Layout
		mSingleDetectTypeLayout->addWidget(mQGroupBoxSingleDetectType);
		
		// 将QGroupBox添加进这个类的Layout中 
		setLayout(mSingleDetectTypeLayout);

		// 信号
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
		// 初始化检测状态标志位
		radioButtonNo->setChecked(true);
		// 初始化lineEdit内容
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