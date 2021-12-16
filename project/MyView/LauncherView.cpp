#include "LauncherView.h"

namespace View {
	LauncherView::LauncherView(QWidget *parent) {
		// 获取相机数量（这边同时进行Controller的各个构造函数的初始化）
		int getCamerasNum = Controller::DomainController::getInstance()->getCameraNums();
		
		ui.setupUi(this);

		connect(ui.buttonLogIn, SIGNAL(released()), this, SLOT(onButtonLogIn()));
		connect(ui.buttonRegister, SIGNAL(released()), this, SLOT(onButtonRegister()));
		connect(ui.buttonExit, SIGNAL(released()), this, SLOT(onButtonExit()));

		// 设置相机个数显示
		ui.labelCameraNum->setText(QString::fromStdString(std::to_string(getCamerasNum)));
	}

	LauncherView::~LauncherView() {

	}

	void LauncherView::onButtonLogIn() {
		View::LogInView *logInView = new View::LogInView();
		this->setVisible(false);

		if (logInView->exec() == QDialog::Accepted) {
			delete logInView;

			MyView *mView = new MyView();
			mView->setAttribute(Qt::WA_DeleteOnClose);
			mView->show();
			connect(mView, SIGNAL(signalClose()), this, SLOT(onMyViewClose()));	// 不能用destroyed信号来判断，main里面会执行下去
		}
		else {
			this->setVisible(true);
		}
	}

	void LauncherView::onButtonRegister() {
		View::RegisterNewUserView *registerNewUserView = new View::RegisterNewUserView();
		this->setVisible(false);

		registerNewUserView->exec();

		this->setVisible(true);
	}

	void LauncherView::onButtonExit() {
		this->close();
	}

	void LauncherView::onMyViewClose() {
		std::cout << "From MyView to LauncherView" << std::endl;
		if (!this->isVisible()) {
			this->setVisible(true);
		}
	}
}