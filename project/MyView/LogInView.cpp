#include "LogInView.h"

namespace View {
	LogInView::LogInView(QDialog *parent) {
		ui.setupUi(this);

		connect(ui.buttonLogIn, SIGNAL(released()), this, SLOT(onButtonLogIn()));
		connect(ui.buttonCancel, SIGNAL(released()), this, SLOT(onButtonCancel()));

		// 设置用户名输入
		ui.lineEditUserName->setPlaceholderText("Example: u0123456789");
		ui.lineEditUserName->setMaxLength(userNameMaxNumLength);
		QString userNameStr = "^u[0-9]{" + QString::fromStdString(std::to_string(userNameMaxNumLength - 1))	// 规定用户名正则表达式
			+ "," + QString::fromStdString(std::to_string(userNameMaxNumLength - 1)) + "}$";
		QRegExp regExp(userNameStr);
		ui.lineEditUserName->setValidator(new QRegExpValidator(regExp, this));

		// 设置密码输入
		ui.lineEditPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditPassward->setMaxLength(userPasswardMaxNumLength);	// 最大长度
		ui.lineEditPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// 显示形式为密码显示形式
	}

	LogInView::~LogInView() {
		
	}

	void LogInView::onButtonLogIn() {
		// 去数据库中查询当前用户是否存在，登陆成功返回
		std::string getLogInUserName = ui.lineEditUserName->text().toStdString();
		std::string getLogInUserPassward = ui.lineEditPassward->text().toStdString();
		bool logInSuccess = Controller::DomainController::getInstance()->userTryLogIn(getLogInUserName, getLogInUserPassward);

		if (logInSuccess) {
			accept();
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("用户名或密码错误"), QMessageBox::Yes);
			ui.lineEditPassward->clear();	// 清除密码内容
			ui.lineEditPassward->setFocus();	// 将光标移动到密码框内
		}
	}

	void LogInView::onButtonCancel() {
		close();
	}
}