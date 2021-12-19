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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
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
    QGroupBox *groupBoxCamera;
    QGridLayout *gridLayout_3;
    QLabel *labelCameraDisplay;
    QListWidget *listWidgetCameras;
    QGroupBox *groupBoxData;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabRealTimeStatistics;
    QGridLayout *gridLayout_13;
    QWidget *widget;
    QGridLayout *gridLayout_6;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QLabel *label;
    QLabel *labelUserID;
    QLabel *label_2;
    QLabel *labelTrueName;
    QLabel *label_3;
    QLabel *labelProductionLine;
    QLabel *label_10;
    QLabel *labelOnlineStartTime;
    QWidget *widget_2;
    QGridLayout *gridLayout_7;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_14;
    QLabel *labelNowOKQuantity;
    QLabel *labelAlreadyOKQuantity;
    QLabel *labelNowFinishQuantity;
    QLabel *label_9;
    QLabel *labelOrderNumber;
    QLabel *label_13;
    QLabel *label_15;
    QLabel *labelOrderQuantity;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_18;
    QLabel *labelCreateTime;
    QLabel *labelAlreadyFinishQuantity;
    QLabel *labelAlreadyNGQuantity;
    QLabel *labelNowNGQuantity;
    QWidget *tabDataSetting;
    QWidget *widget_3;
    QGridLayout *gridLayout_11;
    QTreeWidget *treeWidgetOrderNumberToUser;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QLabel *label_20;
    QLabel *label_22;
    QLineEdit *lineEditLoadOrderNumberUserTargetQuantity;
    QLabel *label_21;
    QLineEdit *lineEditLoadOrderNumberUserTargetUnFinishQuantity;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *buttonSureInLoadOrderNumber;
    QComboBox *comboBoxLoadOrderNumberUsers;
    QLabel *label_4;
    QLineEdit *lineEditToLoadOrderNumber;
    QPushButton *buttonToLoadOrderNumber;
    QWidget *widget_4;
    QGridLayout *gridLayout_9;
    QTreeWidget *treeWidgetUserToOrderNumber;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_8;
    QLabel *label_6;
    QComboBox *comboBoxLoadUserOrderNumbers;
    QLabel *label_11;
    QLineEdit *lineEditLoadUserOrderNumberTargetQuantity;
    QLabel *label_19;
    QLineEdit *lineEditLoadUserOrderNumberTargetUnFinishQuantity;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonSureInLoadUser;
    QLabel *label_5;
    QLineEdit *lineEditToLoadUser;
    QPushButton *buttonToLoadUser;
    QWidget *tabHistoricalStatistics;
    QGroupBox *groupBoxError;
    QGridLayout *gridLayout_4;
    QListWidget *listWidgetError;
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

        groupBoxData = new QGroupBox(centralWidget);
        groupBoxData->setObjectName(QString::fromUtf8("groupBoxData"));
        gridLayout_2 = new QGridLayout(groupBoxData);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget = new QTabWidget(groupBoxData);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setTabPosition(QTabWidget::South);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabRealTimeStatistics = new QWidget();
        tabRealTimeStatistics->setObjectName(QString::fromUtf8("tabRealTimeStatistics"));
        gridLayout_13 = new QGridLayout(tabRealTimeStatistics);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        widget = new QWidget(tabRealTimeStatistics);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_6 = new QGridLayout(widget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(79);
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("background:#2c2c2c;color:#e6e6e6"));
        label_7->setFrameShape(QFrame::WinPanel);
        label_7->setFrameShadow(QFrame::Sunken);
        label_7->setTextFormat(Qt::AutoText);
        label_7->setScaledContents(false);
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(false);

        gridLayout_6->addWidget(label_7, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 6);
        gridLayout_6->setColumnStretch(2, 1);

        gridLayout_13->addWidget(widget, 0, 0, 1, 1);

        groupBox = new QGroupBox(tabRealTimeStatistics);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_5->addWidget(label, 0, 0, 1, 1);

        labelUserID = new QLabel(groupBox);
        labelUserID->setObjectName(QString::fromUtf8("labelUserID"));

        gridLayout_5->addWidget(labelUserID, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_5->addWidget(label_2, 1, 0, 1, 1);

        labelTrueName = new QLabel(groupBox);
        labelTrueName->setObjectName(QString::fromUtf8("labelTrueName"));

        gridLayout_5->addWidget(labelTrueName, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_5->addWidget(label_3, 2, 0, 1, 1);

        labelProductionLine = new QLabel(groupBox);
        labelProductionLine->setObjectName(QString::fromUtf8("labelProductionLine"));

        gridLayout_5->addWidget(labelProductionLine, 2, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_5->addWidget(label_10, 3, 0, 1, 1);

        labelOnlineStartTime = new QLabel(groupBox);
        labelOnlineStartTime->setObjectName(QString::fromUtf8("labelOnlineStartTime"));

        gridLayout_5->addWidget(labelOnlineStartTime, 3, 1, 1, 1);


        gridLayout_13->addWidget(groupBox, 0, 1, 1, 1);

        widget_2 = new QWidget(tabRealTimeStatistics);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_7 = new QGridLayout(widget_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_16 = new QLabel(widget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_7->addWidget(label_16, 1, 2, 1, 1);

        label_17 = new QLabel(widget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_7->addWidget(label_17, 2, 0, 1, 1);

        label_14 = new QLabel(widget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_7->addWidget(label_14, 4, 0, 1, 1);

        labelNowOKQuantity = new QLabel(widget_2);
        labelNowOKQuantity->setObjectName(QString::fromUtf8("labelNowOKQuantity"));

        gridLayout_7->addWidget(labelNowOKQuantity, 4, 1, 1, 1);

        labelAlreadyOKQuantity = new QLabel(widget_2);
        labelAlreadyOKQuantity->setObjectName(QString::fromUtf8("labelAlreadyOKQuantity"));

        gridLayout_7->addWidget(labelAlreadyOKQuantity, 2, 1, 1, 1);

        labelNowFinishQuantity = new QLabel(widget_2);
        labelNowFinishQuantity->setObjectName(QString::fromUtf8("labelNowFinishQuantity"));

        gridLayout_7->addWidget(labelNowFinishQuantity, 3, 1, 1, 1);

        label_9 = new QLabel(widget_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_7->addWidget(label_9, 1, 0, 1, 1);

        labelOrderNumber = new QLabel(widget_2);
        labelOrderNumber->setObjectName(QString::fromUtf8("labelOrderNumber"));

        gridLayout_7->addWidget(labelOrderNumber, 0, 1, 1, 1);

        label_13 = new QLabel(widget_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_7->addWidget(label_13, 0, 2, 1, 1);

        label_15 = new QLabel(widget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_7->addWidget(label_15, 4, 2, 1, 1);

        labelOrderQuantity = new QLabel(widget_2);
        labelOrderQuantity->setObjectName(QString::fromUtf8("labelOrderQuantity"));

        gridLayout_7->addWidget(labelOrderQuantity, 1, 1, 1, 1);

        label_12 = new QLabel(widget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_7->addWidget(label_12, 3, 0, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_7->addWidget(label_8, 0, 0, 1, 1);

        label_18 = new QLabel(widget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_7->addWidget(label_18, 2, 2, 1, 1);

        labelCreateTime = new QLabel(widget_2);
        labelCreateTime->setObjectName(QString::fromUtf8("labelCreateTime"));

        gridLayout_7->addWidget(labelCreateTime, 0, 3, 1, 1);

        labelAlreadyFinishQuantity = new QLabel(widget_2);
        labelAlreadyFinishQuantity->setObjectName(QString::fromUtf8("labelAlreadyFinishQuantity"));

        gridLayout_7->addWidget(labelAlreadyFinishQuantity, 1, 3, 1, 1);

        labelAlreadyNGQuantity = new QLabel(widget_2);
        labelAlreadyNGQuantity->setObjectName(QString::fromUtf8("labelAlreadyNGQuantity"));

        gridLayout_7->addWidget(labelAlreadyNGQuantity, 2, 3, 1, 1);

        labelNowNGQuantity = new QLabel(widget_2);
        labelNowNGQuantity->setObjectName(QString::fromUtf8("labelNowNGQuantity"));

        gridLayout_7->addWidget(labelNowNGQuantity, 4, 3, 1, 1);


        gridLayout_13->addWidget(widget_2, 1, 0, 1, 2);

        gridLayout_13->setRowStretch(0, 5);
        gridLayout_13->setRowStretch(1, 5);
        gridLayout_13->setColumnStretch(0, 5);
        gridLayout_13->setColumnStretch(1, 5);
        tabWidget->addTab(tabRealTimeStatistics, QString());
        tabDataSetting = new QWidget();
        tabDataSetting->setObjectName(QString::fromUtf8("tabDataSetting"));
        widget_3 = new QWidget(tabDataSetting);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 600, 170));
        gridLayout_11 = new QGridLayout(widget_3);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        treeWidgetOrderNumberToUser = new QTreeWidget(widget_3);
        treeWidgetOrderNumberToUser->setObjectName(QString::fromUtf8("treeWidgetOrderNumberToUser"));

        gridLayout_11->addWidget(treeWidgetOrderNumberToUser, 0, 0, 1, 3);

        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_10->addWidget(label_20, 0, 0, 1, 1);

        label_22 = new QLabel(groupBox_3);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_10->addWidget(label_22, 1, 0, 1, 1);

        lineEditLoadOrderNumberUserTargetQuantity = new QLineEdit(groupBox_3);
        lineEditLoadOrderNumberUserTargetQuantity->setObjectName(QString::fromUtf8("lineEditLoadOrderNumberUserTargetQuantity"));

        gridLayout_10->addWidget(lineEditLoadOrderNumberUserTargetQuantity, 1, 1, 1, 2);

        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_10->addWidget(label_21, 2, 0, 1, 1);

        lineEditLoadOrderNumberUserTargetUnFinishQuantity = new QLineEdit(groupBox_3);
        lineEditLoadOrderNumberUserTargetUnFinishQuantity->setObjectName(QString::fromUtf8("lineEditLoadOrderNumberUserTargetUnFinishQuantity"));

        gridLayout_10->addWidget(lineEditLoadOrderNumberUserTargetUnFinishQuantity, 2, 1, 1, 2);

        horizontalSpacer_4 = new QSpacerItem(220, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer_4, 3, 0, 1, 2);

        buttonSureInLoadOrderNumber = new QPushButton(groupBox_3);
        buttonSureInLoadOrderNumber->setObjectName(QString::fromUtf8("buttonSureInLoadOrderNumber"));

        gridLayout_10->addWidget(buttonSureInLoadOrderNumber, 3, 2, 1, 1);

        comboBoxLoadOrderNumberUsers = new QComboBox(groupBox_3);
        comboBoxLoadOrderNumberUsers->addItem(QString());
        comboBoxLoadOrderNumberUsers->setObjectName(QString::fromUtf8("comboBoxLoadOrderNumberUsers"));

        gridLayout_10->addWidget(comboBoxLoadOrderNumberUsers, 0, 1, 1, 2);


        gridLayout_11->addWidget(groupBox_3, 0, 3, 2, 1);

        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_11->addWidget(label_4, 1, 0, 1, 1);

        lineEditToLoadOrderNumber = new QLineEdit(widget_3);
        lineEditToLoadOrderNumber->setObjectName(QString::fromUtf8("lineEditToLoadOrderNumber"));

        gridLayout_11->addWidget(lineEditToLoadOrderNumber, 1, 1, 1, 1);

        buttonToLoadOrderNumber = new QPushButton(widget_3);
        buttonToLoadOrderNumber->setObjectName(QString::fromUtf8("buttonToLoadOrderNumber"));

        gridLayout_11->addWidget(buttonToLoadOrderNumber, 1, 2, 1, 1);

        widget_4 = new QWidget(tabDataSetting);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 170, 600, 170));
        gridLayout_9 = new QGridLayout(widget_4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        treeWidgetUserToOrderNumber = new QTreeWidget(widget_4);
        treeWidgetUserToOrderNumber->setObjectName(QString::fromUtf8("treeWidgetUserToOrderNumber"));

        gridLayout_9->addWidget(treeWidgetUserToOrderNumber, 0, 0, 1, 3);

        groupBox_2 = new QGroupBox(widget_4);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_8 = new QGridLayout(groupBox_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_8->addWidget(label_6, 0, 0, 1, 1);

        comboBoxLoadUserOrderNumbers = new QComboBox(groupBox_2);
        comboBoxLoadUserOrderNumbers->addItem(QString());
        comboBoxLoadUserOrderNumbers->setObjectName(QString::fromUtf8("comboBoxLoadUserOrderNumbers"));

        gridLayout_8->addWidget(comboBoxLoadUserOrderNumbers, 0, 1, 1, 2);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_8->addWidget(label_11, 1, 0, 1, 1);

        lineEditLoadUserOrderNumberTargetQuantity = new QLineEdit(groupBox_2);
        lineEditLoadUserOrderNumberTargetQuantity->setObjectName(QString::fromUtf8("lineEditLoadUserOrderNumberTargetQuantity"));

        gridLayout_8->addWidget(lineEditLoadUserOrderNumberTargetQuantity, 1, 1, 1, 2);

        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_8->addWidget(label_19, 2, 0, 1, 1);

        lineEditLoadUserOrderNumberTargetUnFinishQuantity = new QLineEdit(groupBox_2);
        lineEditLoadUserOrderNumberTargetUnFinishQuantity->setObjectName(QString::fromUtf8("lineEditLoadUserOrderNumberTargetUnFinishQuantity"));

        gridLayout_8->addWidget(lineEditLoadUserOrderNumberTargetUnFinishQuantity, 2, 1, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(199, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_3, 3, 0, 1, 2);

        buttonSureInLoadUser = new QPushButton(groupBox_2);
        buttonSureInLoadUser->setObjectName(QString::fromUtf8("buttonSureInLoadUser"));

        gridLayout_8->addWidget(buttonSureInLoadUser, 3, 2, 1, 1);


        gridLayout_9->addWidget(groupBox_2, 0, 3, 2, 1);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_9->addWidget(label_5, 1, 0, 1, 1);

        lineEditToLoadUser = new QLineEdit(widget_4);
        lineEditToLoadUser->setObjectName(QString::fromUtf8("lineEditToLoadUser"));

        gridLayout_9->addWidget(lineEditToLoadUser, 1, 1, 1, 1);

        buttonToLoadUser = new QPushButton(widget_4);
        buttonToLoadUser->setObjectName(QString::fromUtf8("buttonToLoadUser"));

        gridLayout_9->addWidget(buttonToLoadUser, 1, 2, 1, 1);

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
        groupBoxCamera->setTitle(QApplication::translate("projectClass", "\347\233\270\346\234\272", nullptr));
        labelCameraDisplay->setText(QString());
        groupBoxData->setTitle(QApplication::translate("projectClass", "\344\277\241\346\201\257\346\225\260\346\215\256", nullptr));
        label_7->setText(QApplication::translate("projectClass", "OK", nullptr));
        groupBox->setTitle(QApplication::translate("projectClass", "\344\275\277\347\224\250\344\272\272\345\221\230\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("projectClass", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelUserID->setText(QApplication::translate("projectClass", "u", nullptr));
        label_2->setText(QApplication::translate("projectClass", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelTrueName->setText(QApplication::translate("projectClass", "/", nullptr));
        label_3->setText(QApplication::translate("projectClass", "\347\224\237\344\272\247\347\272\277\357\274\232", nullptr));
        labelProductionLine->setText(QApplication::translate("projectClass", "/", nullptr));
        label_10->setText(QApplication::translate("projectClass", "\347\231\273\351\231\206\346\227\266\351\227\264\357\274\232", nullptr));
        labelOnlineStartTime->setText(QApplication::translate("projectClass", "/", nullptr));
        label_16->setText(QApplication::translate("projectClass", "\347\264\257\350\256\241\345\267\262\345\256\214\346\210\220\346\225\260\351\207\217\357\274\232", nullptr));
        label_17->setText(QApplication::translate("projectClass", "\347\264\257\350\256\241\345\220\210\346\240\274\346\225\260\351\207\217\357\274\232", nullptr));
        label_14->setText(QApplication::translate("projectClass", "\346\234\254\346\254\241\345\220\210\346\240\274\346\225\260\351\207\217\357\274\232", nullptr));
        labelNowOKQuantity->setText(QApplication::translate("projectClass", "/", nullptr));
        labelAlreadyOKQuantity->setText(QApplication::translate("projectClass", "/", nullptr));
        labelNowFinishQuantity->setText(QApplication::translate("projectClass", "/", nullptr));
        label_9->setText(QApplication::translate("projectClass", "\350\256\242\345\215\225\346\225\260\351\207\217\357\274\232", nullptr));
        labelOrderNumber->setText(QApplication::translate("projectClass", "/", nullptr));
        label_13->setText(QApplication::translate("projectClass", "\350\256\242\345\215\225\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        label_15->setText(QApplication::translate("projectClass", "\346\234\254\346\254\241\344\270\215\345\220\210\346\240\274\346\225\260\351\207\217\357\274\232", nullptr));
        labelOrderQuantity->setText(QApplication::translate("projectClass", "/", nullptr));
        label_12->setText(QApplication::translate("projectClass", "\346\234\254\346\254\241\345\256\214\346\210\220\346\225\260\351\207\217\357\274\232", nullptr));
        label_8->setText(QApplication::translate("projectClass", "\350\256\242\345\215\225\347\274\226\345\217\267\357\274\232", nullptr));
        label_18->setText(QApplication::translate("projectClass", "\347\264\257\350\256\241\344\270\215\345\220\210\346\240\274\346\225\260\351\207\217\357\274\232", nullptr));
        labelCreateTime->setText(QApplication::translate("projectClass", "/", nullptr));
        labelAlreadyFinishQuantity->setText(QApplication::translate("projectClass", "/", nullptr));
        labelAlreadyNGQuantity->setText(QApplication::translate("projectClass", "/", nullptr));
        labelNowNGQuantity->setText(QApplication::translate("projectClass", "/", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRealTimeStatistics), QApplication::translate("projectClass", "\345\256\236\346\227\266\347\273\237\350\256\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetOrderNumberToUser->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("projectClass", "\346\234\252\345\256\214\346\210\220\346\225\260\351\207\217", nullptr));
        ___qtreewidgetitem->setText(1, QApplication::translate("projectClass", "\345\267\262\345\256\214\346\210\220\346\225\260\351\207\217", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("projectClass", "\350\256\242\345\215\225\347\274\226\345\217\267-\347\224\250\346\210\267\345\220\215", nullptr));
        groupBox_3->setTitle(QApplication::translate("projectClass", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        label_20->setText(QApplication::translate("projectClass", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_22->setText(QApplication::translate("projectClass", "\351\234\200\345\256\214\346\210\220\346\225\260\351\207\217\357\274\232", nullptr));
        label_21->setText(QApplication::translate("projectClass", "\346\234\252\345\256\214\346\210\220\346\225\260\351\207\217\357\274\232", nullptr));
        lineEditLoadOrderNumberUserTargetUnFinishQuantity->setText(QString());
        buttonSureInLoadOrderNumber->setText(QApplication::translate("projectClass", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        comboBoxLoadOrderNumberUsers->setItemText(0, QApplication::translate("projectClass", "(add new user)", nullptr));

        label_4->setText(QApplication::translate("projectClass", "\350\256\242\345\215\225\347\274\226\345\217\267\357\274\232", nullptr));
        buttonToLoadOrderNumber->setText(QApplication::translate("projectClass", "\345\212\240\350\275\275", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidgetUserToOrderNumber->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("projectClass", "\346\234\252\345\256\214\346\210\220\346\225\260\351\207\217", nullptr));
        ___qtreewidgetitem1->setText(1, QApplication::translate("projectClass", "\345\267\262\345\256\214\346\210\220\346\225\260\351\207\217", nullptr));
        ___qtreewidgetitem1->setText(0, QApplication::translate("projectClass", "\347\224\250\346\210\267\345\220\215-\350\256\242\345\215\225\347\274\226\345\217\267", nullptr));
        groupBox_2->setTitle(QApplication::translate("projectClass", "\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        label_6->setText(QApplication::translate("projectClass", "\350\256\242\345\215\225\347\274\226\345\217\267\357\274\232", nullptr));
        comboBoxLoadUserOrderNumbers->setItemText(0, QApplication::translate("projectClass", "(add new order)", nullptr));

        label_11->setText(QApplication::translate("projectClass", "\351\234\200\345\256\214\346\210\220\346\225\260\351\207\217\357\274\232", nullptr));
        label_19->setText(QApplication::translate("projectClass", "\346\234\252\345\256\214\346\210\220\346\225\260\351\207\217\357\274\232", nullptr));
        lineEditLoadUserOrderNumberTargetUnFinishQuantity->setText(QString());
        buttonSureInLoadUser->setText(QApplication::translate("projectClass", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        label_5->setText(QApplication::translate("projectClass", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        buttonToLoadUser->setText(QApplication::translate("projectClass", "\345\212\240\350\275\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDataSetting), QApplication::translate("projectClass", "\350\256\242\345\215\225\350\256\276\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistoricalStatistics), QApplication::translate("projectClass", "\345\216\206\345\217\262\347\273\237\350\256\241", nullptr));
        groupBoxError->setTitle(QApplication::translate("projectClass", "\345\274\202\345\270\270", nullptr));
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
