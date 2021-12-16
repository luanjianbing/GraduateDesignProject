#include "RegisterNewUserView.h"

namespace View {
	RegisterNewUserView::RegisterNewUserView(QDialog *parent) {
		ui.setupUi(this);

		connect(ui.buttonModify, SIGNAL(released()), this, SLOT(onButtonModify()));
		connect(ui.buttonCancel, SIGNAL(released()), this, SLOT(onButtonCancel()));

		// 设置用户名输入
		ui.lineEditNewUserName->setPlaceholderText("Example: u0123456789");
		ui.lineEditNewUserName->setMaxLength(userNameMaxNumLength);
		QString userNameStr = "^u[0-9]{" + QString::fromStdString(std::to_string(userNameMaxNumLength - 1))	// 规定用户名正则表达式
			+ "," + QString::fromStdString(std::to_string(userNameMaxNumLength - 1)) + "}$";
		QRegExp regExp(userNameStr);
		ui.lineEditNewUserName->setValidator(new QRegExpValidator(regExp, this));

		// 设置密码输入
		ui.lineEditNewUserPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditNewUserPassward->setMaxLength(userPasswardMaxNumLength);	// 最大长度
		ui.lineEditNewUserPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// 显示形式为密码显示形式

		// 设置密码重复输入
		ui.lineEditNewUserConfirmPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditNewUserConfirmPassward->setMaxLength(userPasswardMaxNumLength);	// 最大长度
		ui.lineEditNewUserConfirmPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// 显示形式为密码显示形式

		// 重复输入密码时判断两次输入是否一样
		connect(ui.lineEditNewUserConfirmPassward, SIGNAL(editingFinished()), this, SLOT(onLineEditNewUserConfirmPassward()));

		// (TODO)初始化可选权限下拉框
	}

	RegisterNewUserView::~RegisterNewUserView() {
		
	}

	void RegisterNewUserView::onLineEditNewUserConfirmPassward() {
		QString firstPassward = ui.lineEditNewUserPassward->text();
		QString secondPassward = ui.lineEditNewUserConfirmPassward->text();

		if (firstPassward == secondPassward) {
			std::cout << "两次输入密码一致" << std::endl;;
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("密码不一致"), QMessageBox::Yes);
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
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("创建新用户成功"), QMessageBox::Yes);
		}
		else {
			QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("修改密码成功"), QMessageBox::Yes);
		}
	}

	void RegisterNewUserView::onButtonCancel() {
		close();
	}
}