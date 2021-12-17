#include "RegisterNewUserView.h"

namespace View {
	RegisterNewUserView::RegisterNewUserView(QDialog *parent) {
		ui.setupUi(this);

		connect(ui.buttonModify, SIGNAL(released()), this, SLOT(onButtonModify()));
		connect(ui.buttonCancel, SIGNAL(released()), this, SLOT(onButtonCancel()));

		// ���û�
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

		// �߼�����Ա
		// �����û�������
		ui.lineEditSuperAuthorityUserID->setPlaceholderText("Example: u0123456789");
		ui.lineEditSuperAuthorityUserID->setMaxLength(userNameMaxNumLength);
		ui.lineEditSuperAuthorityUserID->setValidator(new QRegExpValidator(regExp, this));

		// ������������
		ui.lineEditSuperAuthorityUserPassward->setPlaceholderText("Tip: Support Limit "
			+ QString::fromStdString(std::to_string(userPasswardMaxNumLength)) + " Number");
		ui.lineEditSuperAuthorityUserPassward->setMaxLength(userPasswardMaxNumLength);	// ��󳤶�
		ui.lineEditSuperAuthorityUserPassward->setEchoMode(QLineEdit::PasswordEchoOnEdit);	// ��ʾ��ʽΪ������ʾ��ʽ

		// �ظ���������ʱ�ж����������Ƿ�һ��
		connect(ui.lineEditNewUserConfirmPassward, SIGNAL(editingFinished()), this, SLOT(onLineEditNewUserConfirmPassward()));

		// ��ʼ����ѡȨ��������
		initAuthorities();

		// ��ʼ����������û���Ϣ
		updateHaveUsersInfo();
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
		std::string getSuperAuthorityUserName = ui.lineEditSuperAuthorityUserID->text().toStdString();
		std::string getSuperAuthorityUserPassward = ui.lineEditSuperAuthorityUserPassward->text().toStdString();
		bool logInSuccess = Controller::DomainController::getInstance()->userTryLogIn(getSuperAuthorityUserName, getSuperAuthorityUserPassward);

		if (logInSuccess) {	// ���߼�����Ա��֤�ɹ������Կ�ʼ��֤���û�ע����Ϣ
			//  �ȼ��Ȩ��
			if (ui.comboBoxAuthority->currentText() != "SuperAdministrator") {
				// ���߼�����Ա�Ƿ������Ȩ��
				std::string getNewUserAuthority = ui.comboBoxAuthority->currentText().toStdString();
				bool hasModifyAuthority = Controller::DomainController::getInstance()->checkAuthority(getNewUserAuthority, getSuperAuthorityUserName);
				if (hasModifyAuthority) {
					std::map<std::string, std::string> mTempNewUserInfo = constructNewUserInfo();	// ��ȡ���û���Ϣ

					std::string getNewUserName = ui.lineEditNewUserName->text().toStdString();
					std::string getNewUserPassward = ui.lineEditNewUserPassward->text().toStdString();
					// ������Ϊ������
					if (getNewUserName.size() != 0 && getNewUserPassward.size() != 0) {
						bool isNewUser = Controller::DomainController::getInstance()->checkUserIsNewOne(getNewUserName);

						if (isNewUser) {	// ���ݿ���û�У������û�
							bool registerNewUserSuccess = Controller::DomainController::getInstance()->userTryNewRegister(mTempNewUserInfo);
							if (registerNewUserSuccess) {
								QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�������û��ɹ���"), QMessageBox::Yes);
								updateHaveUsersInfo();
							}
							else {
								QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("�������û�ʧ�ܣ�"), QMessageBox::Yes);
								ui.lineEditSuperAuthorityUserPassward->clear();
								ui.lineEditSuperAuthorityUserPassward->setFocus();
							}
						}
						else {	// ���ݿ����У��������û����޸����е���Ϣ
							bool modifyUserInfoSuccess = Controller::DomainController::getInstance()->userTryModifyInfo(mTempNewUserInfo);
							if (modifyUserInfoSuccess) {
								QMessageBox::information(NULL, QStringLiteral("��ʾ"), QStringLiteral("�޸���Ϣ�ɹ���"), QMessageBox::Yes);
								updateHaveUsersInfo();
							}
							else {
								QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("�޸���Ϣʧ�ܣ�"), QMessageBox::Yes);
								ui.lineEditSuperAuthorityUserPassward->clear();
								ui.lineEditSuperAuthorityUserPassward->setFocus();
							}
						}
					}
					else {
						QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("�û��������벻��Ϊ�գ�"), QMessageBox::Yes);
					}
				}
				else {
					QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("Ȩ�޲��������飡"), QMessageBox::Yes);
					ui.lineEditSuperAuthorityUserPassward->clear();
					ui.lineEditSuperAuthorityUserPassward->setFocus();
				}
			}
			else {
				QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("Ȩ��'SuperAdministrator'������ע�Ṧ�ܣ�"), QMessageBox::Yes);
			}
		}
		else {
			QMessageBox::warning(NULL, QStringLiteral("����"), QStringLiteral("�߼�����Ա�û�����������֤ʧ�ܣ�"), QMessageBox::Yes);
			ui.lineEditSuperAuthorityUserPassward->clear();
			ui.lineEditSuperAuthorityUserPassward->setFocus();
		}
	}

	void RegisterNewUserView::onButtonCancel() {
		close();
	}

	void RegisterNewUserView::initAuthorities() {
		// ��ȡ֧�ֵ�Ȩ��
		mUserAuthorityStr = Controller::DomainController::getInstance()->getUserAuthorities();
		// ��ʾ����������
		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			ui.comboBoxAuthority->addItem(QString::fromStdString(mUserAuthorityStr[i]));
		}
		ui.comboBoxAuthority->setCurrentIndex(-1);
	}

	std::map<std::string, std::string> RegisterNewUserView::constructNewUserInfo() {
		// �������û�������Ϣ
		std::map<std::string, std::string> mTempNewUserInfo;
		mTempNewUserInfo.insert({ "userID", ui.lineEditNewUserName->text().toStdString() });
		mTempNewUserInfo.insert({ "userPassward", ui.lineEditNewUserPassward->text().toStdString() });
		mTempNewUserInfo.insert({ "userTrueName", ui.lineEditNewUserTrueName->text().toStdString() });
		mTempNewUserInfo.insert({ "userProductionLine", ui.lineEditNewUserProductionLine->text().toStdString() });
		mTempNewUserInfo.insert({ "userAuthority", ui.comboBoxAuthority->currentText().toStdString() });
		return mTempNewUserInfo;
	}

	void RegisterNewUserView::updateHaveUsersInfo() {
		// ����Ȩ�޻�ȡ�����û���Ϣ
		mHaveUsersInfo.clear();
		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			// ����Ȩ�޻�ȡ��Ҫչʾ���û���Ϣ
			std::vector<std::vector<std::string>> tmpThisAuthorityUsersInfo = 
				Controller::DomainController::getInstance()->getUsersFromAuthority(mUserAuthorityStr[i]);
			mHaveUsersInfo.insert({ mUserAuthorityStr[i], tmpThisAuthorityUsersInfo });
		}
		// ˢ�½�����ʾ
		updateHaveUsersDisplay();
	}

	void RegisterNewUserView::updateHaveUsersDisplay() {
		ui.treeWidgetHasUser->clear();

		ui.treeWidgetHasUser->setColumnCount(1); //��������
		ui.treeWidgetHasUser->setHeaderLabel(QStringLiteral("�����û�")); //����ͷ�ı���

		for (int i = 0; i < mUserAuthorityStr.size(); ++i) {
			// һ�����ڵ�
			QTreeWidgetItem *tmpAuthorityTreeWidgetItem = 
				new QTreeWidgetItem(ui.treeWidgetHasUser, QStringList(QString::fromStdString(mUserAuthorityStr[i]
					+ " (" + std::to_string(mHaveUsersInfo.at(mUserAuthorityStr[i]).size()) + ")"
					)));
			// �������ڵ�
			for (int j = 0; j < mHaveUsersInfo.at(mUserAuthorityStr[i]).size(); ++j) {
				QTreeWidgetItem *tmpUserIDTreeWidgetItem =
					new QTreeWidgetItem(tmpAuthorityTreeWidgetItem, QStringList(QString::fromStdString(mHaveUsersInfo.at(mUserAuthorityStr[i])[j][0])));
				// �������ڵ�
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