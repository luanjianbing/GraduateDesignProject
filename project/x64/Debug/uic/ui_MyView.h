/********************************************************************************
** Form generated from reading UI file 'MyView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYVIEW_H
#define UI_MYVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_projectClass
{
public:
    QAction *actionAbout;
    QAction *actionLog;
    QAction *actionImageSetting;
    QAction *actionSignal;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBoxData;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabRealTimeStatistics;
    QWidget *tabDataSetting;
    QWidget *tabHistoricalStatistics;
    QGroupBox *groupBoxError;
    QGridLayout *gridLayout_4;
    QListWidget *listWidgetError;
    QGroupBox *groupBoxCamera;
    QGridLayout *gridLayout_3;
    QLabel *labelCameraDisplay;
    QListWidget *listWidgetCameras;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuImageSetting;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menuRun;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *projectClass)
    {
        if (projectClass->objectName().isEmpty())
            projectClass->setObjectName(QString::fromUtf8("projectClass"));
        projectClass->resize(1280, 768);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        projectClass->setFont(font);
        actionAbout = new QAction(projectClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionLog = new QAction(projectClass);
        actionLog->setObjectName(QString::fromUtf8("actionLog"));
        actionImageSetting = new QAction(projectClass);
        actionImageSetting->setObjectName(QString::fromUtf8("actionImageSetting"));
        actionSignal = new QAction(projectClass);
        actionSignal->setObjectName(QString::fromUtf8("actionSignal"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icon/Signal.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSignal->setIcon(icon);
        centralWidget = new QWidget(projectClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBoxData = new QGroupBox(centralWidget);
        groupBoxData->setObjectName(QString::fromUtf8("groupBoxData"));
        gridLayout_2 = new QGridLayout(groupBoxData);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(groupBoxData);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabRealTimeStatistics = new QWidget();
        tabRealTimeStatistics->setObjectName(QString::fromUtf8("tabRealTimeStatistics"));
        tabWidget->addTab(tabRealTimeStatistics, QString());
        tabDataSetting = new QWidget();
        tabDataSetting->setObjectName(QString::fromUtf8("tabDataSetting"));
        tabWidget->addTab(tabDataSetting, QString());
        tabHistoricalStatistics = new QWidget();
        tabHistoricalStatistics->setObjectName(QString::fromUtf8("tabHistoricalStatistics"));
        tabWidget->addTab(tabHistoricalStatistics, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);


        gridLayout->addWidget(groupBoxData, 0, 1, 1, 1);

        groupBoxError = new QGroupBox(centralWidget);
        groupBoxError->setObjectName(QString::fromUtf8("groupBoxError"));
        gridLayout_4 = new QGridLayout(groupBoxError);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        listWidgetError = new QListWidget(groupBoxError);
        listWidgetError->setObjectName(QString::fromUtf8("listWidgetError"));
        listWidgetError->setFrameShape(QFrame::WinPanel);
        listWidgetError->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidgetError->setFlow(QListView::TopToBottom);

        gridLayout_4->addWidget(listWidgetError, 0, 0, 1, 1);


        gridLayout->addWidget(groupBoxError, 1, 1, 1, 1);

        groupBoxCamera = new QGroupBox(centralWidget);
        groupBoxCamera->setObjectName(QString::fromUtf8("groupBoxCamera"));
        gridLayout_3 = new QGridLayout(groupBoxCamera);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        labelCameraDisplay = new QLabel(groupBoxCamera);
        labelCameraDisplay->setObjectName(QString::fromUtf8("labelCameraDisplay"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelCameraDisplay->sizePolicy().hasHeightForWidth());
        labelCameraDisplay->setSizePolicy(sizePolicy);
        labelCameraDisplay->setStyleSheet(QString::fromUtf8("background:gray"));
        labelCameraDisplay->setFrameShape(QFrame::WinPanel);
        labelCameraDisplay->setFrameShadow(QFrame::Sunken);
        labelCameraDisplay->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelCameraDisplay, 0, 0, 1, 1);

        listWidgetCameras = new QListWidget(groupBoxCamera);
        listWidgetCameras->setObjectName(QString::fromUtf8("listWidgetCameras"));
        listWidgetCameras->setFrameShape(QFrame::WinPanel);
        listWidgetCameras->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidgetCameras->setFlow(QListView::LeftToRight);

        gridLayout_3->addWidget(listWidgetCameras, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 8);
        gridLayout_3->setRowStretch(1, 2);

        gridLayout->addWidget(groupBoxCamera, 0, 0, 2, 1);

        gridLayout->setRowStretch(0, 6);
        gridLayout->setRowStretch(1, 4);
        projectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(projectClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuImageSetting = new QMenu(menuBar);
        menuImageSetting->setObjectName(QString::fromUtf8("menuImageSetting"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QString::fromUtf8("menuRun"));
        projectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(projectClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        projectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(projectClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        projectClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuImageSetting->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuImageSetting->addAction(actionImageSetting);
        menu_3->addAction(actionLog);
        menu_4->addAction(actionAbout);
        mainToolBar->addAction(actionSignal);

        retranslateUi(projectClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(projectClass);
    } // setupUi

    void retranslateUi(QMainWindow *projectClass)
    {
        projectClass->setWindowTitle(QApplication::translate("projectClass", "project", nullptr));
        actionAbout->setText(QApplication::translate("projectClass", "About", nullptr));
        actionLog->setText(QApplication::translate("projectClass", "Log", nullptr));
        actionImageSetting->setText(QApplication::translate("projectClass", "ImageSetting", nullptr));
        actionSignal->setText(QApplication::translate("projectClass", "\345\215\225\346\254\241\350\247\246\345\217\221", nullptr));
        groupBoxData->setTitle(QApplication::translate("projectClass", "\344\277\241\346\201\257\346\225\260\346\215\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRealTimeStatistics), QApplication::translate("projectClass", "\345\256\236\346\227\266\347\273\237\350\256\241", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDataSetting), QApplication::translate("projectClass", "\346\225\260\346\215\256\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistoricalStatistics), QApplication::translate("projectClass", "\345\216\206\345\217\262\347\273\237\350\256\241", nullptr));
        groupBoxError->setTitle(QApplication::translate("projectClass", "\345\274\202\345\270\270", nullptr));
        groupBoxCamera->setTitle(QApplication::translate("projectClass", "\347\233\270\346\234\272", nullptr));
        labelCameraDisplay->setText(QString());
        menu->setTitle(QApplication::translate("projectClass", "\346\226\207\344\273\266", nullptr));
        menuImageSetting->setTitle(QApplication::translate("projectClass", "\345\233\276\345\203\217\350\256\276\347\275\256", nullptr));
        menu_3->setTitle(QApplication::translate("projectClass", "\345\216\206\345\217\262\350\256\260\345\275\225", nullptr));
        menu_4->setTitle(QApplication::translate("projectClass", "\345\270\256\345\212\251", nullptr));
        menuRun->setTitle(QApplication::translate("projectClass", "\350\277\220\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class projectClass: public Ui_projectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYVIEW_H
