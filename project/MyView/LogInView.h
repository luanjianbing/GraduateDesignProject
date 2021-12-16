#pragma once

#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QDialog>
#include "ui_LogInView.h"

#include <QRegExpValidator>
#include <QMessageBox>

#include "..\\MyController\Controller.h"

namespace View {
	class LogInView : public QDialog
	{
		Q_OBJECT
	public:
		LogInView(QDialog *parent = Q_NULLPTR);
		~LogInView();

	private:
		Ui::LogInView ui;

		// 限制用户与密码的最长个数
		const int userNameMaxNumLength = 11;
		const int userPasswardMaxNumLength = 11;

	private slots:
		// buttonLogIn槽函数
		void onButtonLogIn();
		// buttonRegister槽函数
		void onButtonCancel();
	signals:
		// 登陆成功信号
		void signalLogInSuccess();
	};
}

#endif