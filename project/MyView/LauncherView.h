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
		// buttonLogIn槽函数
		void onButtonLogIn();
		// buttonRegister槽函数
		void onButtonRegister();
		// buttonLogIn槽函数
		void onButtonExit();

		// 主界面关闭槽函数
		void onMyViewClose();
	};
}

#endif