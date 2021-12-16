#include <QtWidgets/QApplication>
#include ".//MyView/LauncherView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	View::LauncherView mLauncher;	// ��������
	mLauncher.show();

	a.exec();

	std::cout << "Close System." << std::endl;

	return 1;
}
