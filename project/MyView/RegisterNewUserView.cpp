#include "RegisterNewUserView.h"

namespace View {
	RegisterNewUserView::RegisterNewUserView(QDialog *parent) {
		ui.setupUi(this);

		connect(ui.buttonModify, SIGNAL(released()), this, SLOT(onButtonModify()));
		connect(ui.buttonCancel, SIGNAL(released()), this, SLOT(onButtonCancel()));

		// 新用户
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

		// 高级管理员
		// 设置用户名输入
		ui.lineEditSuperAuthorityUserID->setPlaceholderText("Example: u0123456789");
		ui.lineEditSuperAuthorityUserID->setMaxLength(userNameMaxNumLength);
		ui.lineEditSuperAuthorityUserID->setValidator(new QRegExpValidator(regExp, this));

		// 设置密码输入
		ui.lineEditSuperAuthorityUserPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditSuperAuthorityUserPassward->setMaxLength(userPasswardMaxNumLength);	// 最大长度
		ui.lineEditSuperAuthorityUserPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// 显示形式为密码显示形式

		// 重复输入密码时判断两次输入是否一样
		connect(ui.lineEditNewUserConfirmPassward, SIGNAL(editingFinished()), this, SLOT(onLineEditNewUserConfirmPassward()));

		// 初始化可选权限下拉框
		initAuthorities();

		// 初始化左边已有用户信息
		updateHaveUsersInfo();
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
		std::string getSuperAuthorityUserName = ui.lineEditSuperAuthorityUserID->text().toStdString();
		std::string getSuperAuthorityUserPassward = ui.lineEditSuperAuthorityUserPassward->text().toStdString();
		bool logInSuccess = Controller::DomainController::getInstance()->userTryLogIn(getSuperAuthorityUserName, getSuperAuthorityUserPassward);

		if (logInSuccess) {	// 更高级管理员验证成功，可以开始验证新用户注册信息
			//  先检查权限
			if (ui.comboBoxAuthority->currentText() != "SuperAdministrator") {
				// 检查高级管理员是否有这个权限
				std::string getNewUserAuthority = ui.comboBoxAuthority->currentText().toStdString();
				bool hasModifyAuthority = Controller::DomainController::getInstance()->checkAuthority(getNewUserAuthority, getSuperAuthorityUserName);
				if (hasModifyAuthority) {
					std::map<std::string, std::string> mTempNewUserInfo = constructNewUserInfo();	// 读取新用户信息

					std::string getNewUserName = ui.lineEditNewUserName->text().toStdString();
					std::string getNewUserPassward = ui.lineEditNewUserPassward->text().toStdString();
					// 不允许为空限制
					if (getNewUserName.size() != 0 && getNewUserPassward.size() != 0) {
						bool isNewUser = Controller::DomainController::getInstance()->checkUserIsNewOne(getNewUserName);

						if (isNewUser) {	// 数据库中没有，是新用户
							bool registerNewUserSuccess = Controller::DomainController::getInstance()->userTryNewRegister(mTempNewUserInfo);
							if (registerNewUserSuccess) {
								QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("创建新用户成功！"), QMessageBox::Yes);
								updateHaveUsersInfo();
							}
							else {
								QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("创建新用户失败！"), QMessageBox::Yes);
								ui.lineEditSuperAuthorityUserPassward->clear();
								ui.lineEditSuperAuthorityUserPassward->setFocus();
							}
						}
						else {	// 数据库中有，不是新用户，修改其中的信息
							bool modifyUserInfoSuccess = Controller::DomainController::getInstance()->userTryModifyInfo(mTempNewUserInfo);
							if (modifyUserInfoSuccess) {
								QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("修改信息成功！"), QMessageBox::Yes);
								updateHaveUsersInfo();
							}
							else {
								QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("修改信息失败！"), QMessageBox::Yes);
								ui.lineEditSuperAuthorityUserPassward->clear();
								ui.lineEditSuperAuthorityUserPassward->setFocus();
							}
						}
					}
					else {
						QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("用户名或密码不能为空！"), QMessageBox::Yes);
					}
				}
				else {
					QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("权限不够，请检查！"), QMessageBox::Yes);
					ui.lineEditSuperAuthorityUserPassward->clear();
					ui.lineEditSuperAuthorityUserPassward->setFocus();
				}
			}
			else {
				QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("权限'SuperAdministrator'不开放注册功能！"), QMessageBox::Yes);
			}
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("警告"), QStringLiteral("高级管理员用户名或密码验证失败！"), QMessageBox::Yes);
			ui.lineEditSuperAuthorityUserPassward->clear();
			ui.lineEditSuperAuthorityUserPassward->setFocus();
		}
	}

	void RegisterNewUserView::onButtonCancel() {
		close();
	}

	void RegisterNewUserView::initAuthorities() {
		// 获取支持的权限
		mUserAuthorityStr = Controller::DomainController::getInstance()->getUserAuthorities();
		// 显示到下拉框中
		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			ui.comboBoxAuthority->addItem(QString::fromStdString(mUserAuthorityStr[i]));
		}
		ui.comboBoxAuthority->setCurrentIndex(-1);
	}

	std::map<std::string, std::string> RegisterNewUserView::constructNewUserInfo() {
		// 构建新用户数据信息
		std::map<std::string, std::string> mTempNewUserInfo;
		mTempNewUserInfo.insert({ "userID", ui.lineEditNewUserName->text().toStdString() });
		mTempNewUserInfo.insert({ "userPassward", ui.lineEditNewUserPassward->text().toStdString() });
		mTempNewUserInfo.insert({ "userTrueName", ui.lineEditNewUserTrueName->text().toStdString() });
		mTempNewUserInfo.insert({ "userProductionLine", ui.lineEditNewUserProductionLine->text().toStdString() });
		mTempNewUserInfo.insert({ "userAuthority", ui.comboBoxAuthority->currentText().toStdString() });
		return mTempNewUserInfo;
	}

	void RegisterNewUserView::updateHaveUsersInfo() {
		// 根据权限获取已有用户信息
		mHaveUsersInfo.clear();
		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			// 根据权限获取需要展示的用户信息
			std::vector<std::vector<std::string>> tmpThisAuthorityUsersInfo = 
				Controller::DomainController::getInstance()->getUsersFromAuthority(mUserAuthorityStr[i]);
			mHaveUsersInfo.insert({ mUserAuthorityStr[i], tmpThisAuthorityUsersInfo });
		}
		// 刷新界面显示
		updateHaveUsersDisplay();
	}

	void RegisterNewUserView::updateHaveUsersDisplay() {
		ui.treeWidgetHasUser->clear();

		ui.treeWidgetHasUser->setColumnCount(1); //设置列数
		ui.treeWidgetHasUser->setHeaderLabel(QStringLiteral("已有用户")); //设置头的标题

		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			// 一级树节点
			QTreeWidgetItem *tmpAuthorityTreeWidgetItem = 
				new QTreeWidgetItem(ui.treeWidgetHasUser, QStringList(QString::fromStdString(mUserAuthorityStr[i]
					+ " (" + std::to_string(mHaveUsersInfo.at(mUserAuthorityStr[i]).size()) + ")"
					)));
			// 二级树节点
			for (int j = 0; j < mHaveUsersInfo.at(mUserAuthorityStr[i]).size(); ++j) {
				QTreeWidgetItem *tmpUserIDTreeWidgetItem =
					new QTreeWidgetItem(tmpAuthorityTreeWidgetItem, QStringList(QString::fromStdString(mHaveUsersInfo.at(mUserAuthorityStr[i])[j][0])));
				// 三级树节点
				for (int m = 1; m < mHaveUsersInfo.at(mUserAuthorityStr[i])[j].size(); ++m) {
					QTreeWidgetItem *tmpUserAttrTreeWidgetItem =
						new QTreeWidgetItem(tmpUserIDTreeWidgetItem, QStringList(QString::fromStdString(mHaveUsersInfo.at(mUserAuthorityStr[i])[j][m])));

					tmpUserIDTreeWidgetItem->addChild(tmpUserAttrTreeWidgetItem);
				}

				tmpAuthorityTreeWidgetItem->addChild(tmpUserIDTreeWidgetItem);
			}
			
			ui.treeWidgetHasUser->addTopLevelItem(tmpAuthorityTreeWidgetItem);
		}

		ui.treeWidgetHasUser->expandAll();
	}
}