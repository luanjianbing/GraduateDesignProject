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

		// 限制用户与密码的最长个数
		const int userNameMaxNumLength = 11;
		const int userPasswardMaxNumLength = 11;

		// 获取可选权限并初始化下拉框
		std::vector<std::string> mUserAuthorityStr;
		void initAuthorities();
		std::map<std::string, std::string> constructNewUserInfo();	// 新用户信息

		// 初始化左边已有用户信息
		void updateHaveUsersInfo();
		std::map<std::string, std::vector<std::vector<std::string>>> mHaveUsersInfo;
		void updateHaveUsersDisplay();

	private slots:
		// buttonModify槽函数
		void onButtonModify();
		// buttonCancel槽函数
		void onButtonCancel();
		// lineEditNewUserConfirmPassward槽函数
		void onLineEditNewUserConfirmPassward();
	};
}

#endif
