#pragma once

#ifndef LAUNCHERVIEW_H
#define LAUNCHERVIEW_H

#include <QtWidgets\QWidget>
#include "ui_LauncherView.h"

#include "..//MyController/Controller.h"

#include "MyView.h"
#include "LogInView.h"
#include "RegisterNewUserView.h"

namespace View {
	class LauncherView : public QWidget {
		Q_OBJECT
	public:
		LauncherView(QWidget *parent = Q_NULLPTR);
		~LauncherView();
	private:
		Ui::LauncherView ui;
	private slots:
		// buttonLogIn�ۺ���
		void onButtonLogIn();
		// buttonRegister�ۺ���
		void onButtonRegister();
		// buttonLogIn�ۺ���
		void onButtonExit();

		// ������رղۺ���
		void onMyViewClose();
	};
}

#endif