#pragma once

#ifndef REGISTERNEWUSERVIEW_H
#define REGISTERNEWUSERVIEW_H

#include <QDialog>
#include "ui_RegisterNewUserView.h"

#include <QRegExpValidator>
#include <QMessageBox>
#include <QTreeWidget>

#include "..\\MyController\Controller.h"

namespace View {
	class RegisterNewUserView : public QDialog
	{
		Q_OBJECT
	public:
		RegisterNewUserView(QDialog *parent = Q_NULLPTR);
		~RegisterNewUserView();
	private:
		Ui::RegisterNewUserView ui;

		// �����û�������������
		const int userNameMaxNumLength = 11;
		const int userPasswardMaxNumLength = 11;

		// ��ȡ��ѡȨ�޲���ʼ��������
		std::vector<std::string> mUserAuthorityStr;
		void initAuthorities();
		std::map<std::string, std::string> constructNewUserInfo();	// ���û���Ϣ

		// ��ʼ����������û���Ϣ
		void updateHaveUsersInfo();
		std::map<std::string, std::vector<std::vector<std::string>>> mHaveUsersInfo;
		void updateHaveUsersDisplay();

	private slots:
		// buttonModify�ۺ���
		void onButtonModify();
		// buttonCancel�ۺ���
		void onButtonCancel();
		// lineEditNewUserConfirmPassward�ۺ���
		void onLineEditNewUserConfirmPassward();
	};
}

#endif
