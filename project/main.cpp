#include <QtWidgets/QApplication>
#include ".//MyView/LauncherView.h"

#include "MyModel\Log.h"

int main(int argc, char *argv[])
{
	LOG_INFO("System Start");

    QApplication a(argc, argv);

	View::LauncherView mLauncher;	// ��������
	mLauncher.show();

	a.exec();

	LOG_INFO("System Close");
	std::cout << "Close System." << std::endl;

	return 1;
}
