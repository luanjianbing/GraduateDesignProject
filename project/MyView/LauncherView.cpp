#include "LauncherView.h"

namespace View {
	LauncherView::LauncherView(QWidget *parent) {
		// ��ȡ������������ͬʱ����Controller�ĸ������캯���ĳ�ʼ����
		int getCamerasNum = Controller::DomainController::getInstance()->getCameraNums();
		
		ui.setupUi(this);

		connect(ui.buttonLogIn, SIGNAL(released()), this, SLOT(onButtonLogIn()));
		connect(ui.buttonRegister, SIGNAL(released()), this, SLOT(onButtonRegister()));
		connect(ui.buttonExit, SIGNAL(released()), this, SLOT(onButtonExit()));

		// �������������ʾ
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
			connect(mView, SIGNAL(signalClose()), this, SLOT(onMyViewClose()));	// ������destroyed�ź����жϣ�main�����ִ����ȥ
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