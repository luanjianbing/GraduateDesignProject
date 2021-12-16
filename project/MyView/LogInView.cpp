#include "LogInView.h"

namespace View {
	LogInView::LogInView(QDialog *parent) {
		ui.setupUi(this);

		connect(ui.buttonLogIn, SIGNAL(released()), this, SLOT(onButtonLogIn()));
		connect(ui.buttonCancel, SIGNAL(released()), this, SLOT(onButtonCancel()));

		// �����û�������
		ui.lineEditUserName->setPlaceholderText("Example: u0123456789");
		ui.lineEditUserName->setMaxLength(userNameMaxNumLength);
		QString userNameStr = "^u[0-9]{" + QString::fromStdString(std::to_string(userNameMaxNumLength - 1))	// �涨�û���������ʽ
			+ "," + QString::fromStdString(std::to_string(userNameMaxNumLength - 1)) + "}$";
		QRegExp regExp(userNameStr);
		ui.lineEditUserName->setValidator(new QRegExpValidator(regExp, this));

		// ������������
		ui.lineEditPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditPassward->setMaxLength(userPasswardMaxNumLength);	// ��󳤶�
		ui.lineEditPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// ��ʾ��ʽΪ������ʾ��ʽ
	}

	LogInView::~LogInView() {
		
	}

	void LogInView::onButtonLogIn() {
		// ȥ���ݿ��в�ѯ��ǰ�û��Ƿ���ڣ���½�ɹ�����
		std::string getLogInUserName = ui.lineEditUserName->text().toStdString();
		std::string getLogInUserPassward = ui.lineEditPassward->text().toStdString();
		bool logInSuccess = Controller::DomainController::getInstance()->userTryLogIn(getLogInUserName, getLogInUserPassward);

		if (logInSuccess) {
			accept();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("�û������������"), QMessageBox::Yes);
			ui.lineEditPassward->clear();	// �����������
			ui.lineEditPassward->setFocus();	// ������ƶ����������
		}
	}

	void LogInView::onButtonCancel() {
		close();
	}
}