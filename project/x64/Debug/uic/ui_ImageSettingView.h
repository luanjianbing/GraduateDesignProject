/********************************************************************************
** Form generated from reading UI file 'ImageSettingView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESETTINGVIEW_H
#define UI_IMAGESETTINGVIEW_H

#include <../../../MySubView/QLabelWithMouseEvent.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageSettingView
{
public:
    QGridLayout *gridLayout;
    QLabelWithMouseEvent *labelDisplay;
    QWidget *widgetCameras;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBoxModel;
    QGridLayout *gridLayout_2;
    QPushButton *buttonLoadModel;
    QPushButton *buttonNewModel;
    QComboBox *comboBoxLoadModel;
    QLineEdit *lineEditNewModel;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBoxCameraSelect;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *labelCamerasNum;
    QLabel *label;
    QComboBox *comboBoxCurrentCamera;
    QGroupBox *groupBoxDetectTypeSetting;
    QGridLayout *gridLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContentsDetectTypeSetting;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayoutDetectTypeScrollArea;
    QGroupBox *groupBoxDetectParamSetting;
    QGridLayout *gridLayout_5;
    QTableWidget *tableWidgetParam;

    void setupUi(QWidget *ImageSettingView)
    {
        if (ImageSettingView->objectName().isEmpty())
            ImageSettingView->setObjectName(QString::fromUtf8("ImageSettingView"));
        ImageSettingView->resize(1280, 768);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ImageSettingView->sizePolicy().hasHeightForWidth());
        ImageSettingView->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        ImageSettingView->setFont(font);
        gridLayout = new QGridLayout(ImageSettingView);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelDisplay = new QLabelWithMouseEvent(ImageSettingView);
        labelDisplay->setObjectName(QString::fromUtf8("labelDisplay"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelDisplay->sizePolicy().hasHeightForWidth());
        labelDisplay->setSizePolicy(sizePolicy1);
        labelDisplay->setStyleSheet(QString::fromUtf8("background:gray"));
        labelDisplay->setFrameShape(QFrame::WinPanel);
        labelDisplay->setFrameShadow(QFrame::Sunken);
        labelDisplay->setPixmap(QPixmap(QString::fromUtf8("../../../\347\272\277\350\267\257\346\235\277\346\243\200\346\265\213/\350\275\257\344\273\2662.0/ConnectorInspection/ConnectorInspection/Icon/LabelNull.png")));
        labelDisplay->setScaledContents(false);
        labelDisplay->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelDisplay, 0, 0, 1, 1);

        widgetCameras = new QWidget(ImageSettingView);
        widgetCameras->setObjectName(QString::fromUtf8("widgetCameras"));
        gridLayout_3 = new QGridLayout(widgetCameras);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBoxModel = new QGroupBox(widgetCameras);
        groupBoxModel->setObjectName(QString::fromUtf8("groupBoxModel"));
        gridLayout_2 = new QGridLayout(groupBoxModel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonLoadModel = new QPushButton(groupBoxModel);
        buttonLoadModel->setObjectName(QString::fromUtf8("buttonLoadModel"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonLoadModel->sizePolicy().hasHeightForWidth());
        buttonLoadModel->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(buttonLoadModel, 0, 1, 1, 1);

        buttonNewModel = new QPushButton(groupBoxModel);
        buttonNewModel->setObjectName(QString::fromUtf8("buttonNewModel"));

        gridLayout_2->addWidget(buttonNewModel, 0, 4, 1, 1);

        comboBoxLoadModel = new QComboBox(groupBoxModel);
        comboBoxLoadModel->setObjectName(QString::fromUtf8("comboBoxLoadModel"));

        gridLayout_2->addWidget(comboBoxLoadModel, 0, 0, 1, 1);

        lineEditNewModel = new QLineEdit(groupBoxModel);
        lineEditNewModel->setObjectName(QString::fromUtf8("lineEditNewModel"));

        gridLayout_2->addWidget(lineEditNewModel, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 4);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        gridLayout_2->setColumnStretch(3, 3);
        gridLayout_2->setColumnStretch(4, 1);

        gridLayout_3->addWidget(groupBoxModel, 0, 0, 1, 1);

        groupBoxCameraSelect = new QGroupBox(widgetCameras);
        groupBoxCameraSelect->setObjectName(QString::fromUtf8("groupBoxCameraSelect"));
        horizontalLayout = new QHBoxLayout(groupBoxCameraSelect);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBoxCameraSelect);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        labelCamerasNum = new QLabel(groupBoxCameraSelect);
        labelCamerasNum->setObjectName(QString::fromUtf8("labelCamerasNum"));
        labelCamerasNum->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelCamerasNum);

        label = new QLabel(groupBoxCameraSelect);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBoxCurrentCamera = new QComboBox(groupBoxCameraSelect);
        comboBoxCurrentCamera->setObjectName(QString::fromUtf8("comboBoxCurrentCamera"));

        horizontalLayout->addWidget(comboBoxCurrentCamera);


        gridLayout_3->addWidget(groupBoxCameraSelect, 1, 0, 1, 1);

        groupBoxDetectTypeSetting = new QGroupBox(widgetCameras);
        groupBoxDetectTypeSetting->setObjectName(QString::fromUtf8("groupBoxDetectTypeSetting"));
        groupBoxDetectTypeSetting->setEnabled(false);
        gridLayout_4 = new QGridLayout(groupBoxDetectTypeSetting);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        scrollArea = new QScrollArea(groupBoxDetectTypeSetting);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContentsDetectTypeSetting = new QWidget();
        scrollAreaWidgetContentsDetectTypeSetting->setObjectName(QString::fromUtf8("scrollAreaWidgetContentsDetectTypeSetting"));
        scrollAreaWidgetContentsDetectTypeSetting->setGeometry(QRect(0, 0, 462, 248));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContentsDetectTypeSetting);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 551, 341));
        gridLayoutDetectTypeScrollArea = new QGridLayout(gridLayoutWidget);
        gridLayoutDetectTypeScrollArea->setObjectName(QString::fromUtf8("gridLayoutDetectTypeScrollArea"));
        gridLayoutDetectTypeScrollArea->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContentsDetectTypeSetting);

        gridLayout_4->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxDetectTypeSetting, 2, 0, 1, 1);

        groupBoxDetectParamSetting = new QGroupBox(widgetCameras);
        groupBoxDetectParamSetting->setObjectName(QString::fromUtf8("groupBoxDetectParamSetting"));
        gridLayout_5 = new QGridLayout(groupBoxDetectParamSetting);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tableWidgetParam = new QTableWidget(groupBoxDetectParamSetting);
        tableWidgetParam->setObjectName(QString::fromUtf8("tableWidgetParam"));
        tableWidgetParam->setEditTriggers(QAbstractItemView::NoEditTriggers);

        gridLayout_5->addWidget(tableWidgetParam, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxDetectParamSetting, 3, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 1);
        gridLayout_3->setRowStretch(1, 1);
        gridLayout_3->setRowStretch(2, 4);
        gridLayout_3->setRowStretch(3, 4);

        gridLayout->addWidget(widgetCameras, 0, 1, 1, 1);

        gridLayout->setColumnStretch(0, 6);
        gridLayout->setColumnStretch(1, 4);

        retranslateUi(ImageSettingView);

        QMetaObject::connectSlotsByName(ImageSettingView);
    } // setupUi

    void retranslateUi(QWidget *ImageSettingView)
    {
        ImageSettingView->setWindowTitle(QApplication::translate("ImageSettingView", "\345\233\276\345\203\217\350\256\276\347\275\256", nullptr));
        labelDisplay->setText(QString());
        groupBoxModel->setTitle(QApplication::translate("ImageSettingView", "\346\250\241\345\236\213\351\200\211\346\213\251\357\274\232", nullptr));
        buttonLoadModel->setText(QApplication::translate("ImageSettingView", "\345\212\240\350\275\275", nullptr));
        buttonNewModel->setText(QApplication::translate("ImageSettingView", "\346\226\260\345\273\272", nullptr));
        groupBoxCameraSelect->setTitle(QApplication::translate("ImageSettingView", "\347\233\270\346\234\272\351\200\211\346\213\251:", nullptr));
        label_2->setText(QApplication::translate("ImageSettingView", "\347\233\270\346\234\272\346\225\260\351\207\217\357\274\232", nullptr));
        labelCamerasNum->setText(QApplication::translate("ImageSettingView", "0", nullptr));
        label->setText(QApplication::translate("ImageSettingView", "\345\275\223\345\211\215\347\233\270\346\234\272\357\274\232", nullptr));
        groupBoxDetectTypeSetting->setTitle(QApplication::translate("ImageSettingView", "\346\243\200\346\265\213\347\261\273\345\236\213\357\274\232", nullptr));
        groupBoxDetectParamSetting->setTitle(QApplication::translate("ImageSettingView", "\346\243\200\346\265\213\346\225\260\346\215\256\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageSettingView: public Ui_ImageSettingView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESETTINGVIEW_H
