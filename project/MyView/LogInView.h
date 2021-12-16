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

		// �����û�������������
		const int userNameMaxNumLength = 11;
		const int userPasswardMaxNumLength = 11;

	private slots:
		// buttonLogIn�ۺ���
		void onButtonLogIn();
		// buttonRegister�ۺ���
		void onButtonCancel();
	signals:
		// ��½�ɹ��ź�
		void signalLogInSuccess();
	};
}

#endif