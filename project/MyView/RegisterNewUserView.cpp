#include "RegisterNewUserView.h"

namespace View {
	RegisterNewUserView::RegisterNewUserView(QDialog *parent) {
		ui.setupUi(this);

		connect(ui.buttonModify, SIGNAL(released()), this, SLOT(onButtonModify()));
		connect(ui.buttonCancel, SIGNAL(released()), this, SLOT(onButtonCancel()));

		// �����û�������
		ui.lineEditNewUserName->setPlaceholderText("Example: u0123456789");
		ui.lineEditNewUserName->setMaxLength(userNameMaxNumLength);
		QString userNameStr = "^u[0-9]{" + QString::fromStdString(std::to_string(userNameMaxNumLength - 1))	// �涨�û���������ʽ
			+ "," + QString::fromStdString(std::to_string(userNameMaxNumLength - 1)) + "}$";
		QRegExp regExp(userNameStr);
		ui.lineEditNewUserName->setValidator(new QRegExpValidator(regExp, this));

		// ������������
		ui.lineEditNewUserPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditNewUserPassward->setMaxLength(userPasswardMaxNumLength);	// ��󳤶�
		ui.lineEditNewUserPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// ��ʾ��ʽΪ������ʾ��ʽ

		// ���������ظ�����
		ui.lineEditNewUserConfirmPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditNewUserConfirmPassward->setMaxLength(userPasswardMaxNumLength);	// ��󳤶�
		ui.lineEditNewUserConfirmPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// ��ʾ��ʽΪ������ʾ��ʽ

		// �ظ���������ʱ�ж����������Ƿ�һ��
		connect(ui.lineEditNewUserConfirmPassward, SIGNAL(editingFinished()), this, SLOT(onLineEditNewUserConfirmPassward()));

		// (TODO)��ʼ����ѡȨ��������
	}

	RegisterNewUserView::~RegisterNewUserView() {
		
	}

	void RegisterNewUserView::onLineEditNewUserConfirmPassward() {
		QString firstPassward = ui.lineEditNewUserPassward->text();
		QString secondPassward = ui.lineEditNewUserConfirmPassward->text();

		if (firstPassward == secondPassward) {
			std::cout << "������������һ��" << std::endl;;
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("���벻һ��"), QMessageBox::Yes);
			ui.lineEditNewUserPassward->clear();
			ui.lineEditNewUserConfirmPassward->clear();
			ui.lineEditNewUserPassward->setFocus();
		}
	}

	void RegisterNewUserView::onButtonModify() {
		std::string getNewUserName = ui.lineEditNewUserName->text().toStdString();
		std::string getNewUserPassward = ui.lineEditNewUserPassward->text().toStdString();
		bool isNewUser = Controller::DomainController::getInstance()->userTryRegister(getNewUserName, getNewUserPassward);

		if (isNewUser) {
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�������û��ɹ�"), QMessageBox::Yes);
		}
		else {
			QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�޸�����ɹ�"), QMessageBox::Yes);
		}
	}

	void RegisterNewUserView::onButtonCancel() {
		close();
	}
}