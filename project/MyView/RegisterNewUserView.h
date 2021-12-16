#pragma once

#ifndef REGISTERNEWUSERVIEW_H
#define REGISTERNEWUSERVIEW_H

#include <QDialog>
#include "ui_RegisterNewUserView.h"

#include <QRegExpValidator>
#include <QMessageBox>

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
