/********************************************************************************
** Form generated from reading UI file 'LauncherView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHERVIEW_H
#define UI_LAUNCHERVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LauncherView
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label;
    QLabel *labelCameraNum;
    QLabel *label_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *buttonLogIn;
    QPushButton *buttonRegister;
    QPushButton *buttonExit;

    void setupUi(QWidget *LauncherView)
    {
        if (LauncherView->objectName().isEmpty())
            LauncherView->setObjectName(QString::fromUtf8("LauncherView"));
        LauncherView->resize(300, 350);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        LauncherView->setFont(font);
        verticalLayout_2 = new QVBoxLayout(LauncherView);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(LauncherView);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setPixmap(QPixmap(QString::fromUtf8("Icon/Camera.png")));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 3);

        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(13);
        label->setFont(font1);

        gridLayout->addWidget(label, 1, 0, 1, 1);

        labelCameraNum = new QLabel(widget_2);
        labelCameraNum->setObjectName(QString::fromUtf8("labelCameraNum"));
        labelCameraNum->setFont(font1);
        labelCameraNum->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelCameraNum, 1, 1, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font2;
        font2.setPointSize(13);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 2, 1, 1);


        gridLayout_2->addWidget(widget_2, 0, 0, 1, 1);

        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        buttonLogIn = new QPushButton(widget_3);
        buttonLogIn->setObjectName(QString::fromUtf8("buttonLogIn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonLogIn->sizePolicy().hasHeightForWidth());
        buttonLogIn->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icon/LogIn.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonLogIn->setIcon(icon);

        verticalLayout_3->addWidget(buttonLogIn);

        buttonRegister = new QPushButton(widget_3);
        buttonRegister->setObjectName(QString::fromUtf8("buttonRegister"));
        sizePolicy.setHeightForWidth(buttonRegister->sizePolicy().hasHeightForWidth());
        buttonRegister->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Icon/Register.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonRegister->setIcon(icon1);

        verticalLayout_3->addWidget(buttonRegister);

        buttonExit = new QPushButton(widget_3);
        buttonExit->setObjectName(QString::fromUtf8("buttonExit"));
        sizePolicy.setHeightForWidth(buttonExit->sizePolicy().hasHeightForWidth());
        buttonExit->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Icon/Exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonExit->setIcon(icon2);

        verticalLayout_3->addWidget(buttonExit);


        gridLayout_2->addWidget(widget_3, 1, 0, 1, 1);


        verticalLayout_2->addWidget(widget);


        retranslateUi(LauncherView);

        QMetaObject::connectSlotsByName(LauncherView);
    } // setupUi

    void retranslateUi(QWidget *LauncherView)
    {
        LauncherView->setWindowTitle(QApplication::translate("LauncherView", "LauncherView", nullptr));
        label_4->setText(QString());
        label->setText(QApplication::translate("LauncherView", "\346\243\200\346\265\213\345\210\260", nullptr));
        labelCameraNum->setText(QApplication::translate("LauncherView", "0", nullptr));
        label_3->setText(QApplication::translate("LauncherView", "\344\270\252\347\233\270\346\234\272", nullptr));
        buttonLogIn->setText(QApplication::translate("LauncherView", "\347\231\273\345\275\225", nullptr));
        buttonRegister->setText(QApplication::translate("LauncherView", "\346\263\250\345\206\214", nullptr));
        buttonExit->setText(QApplication::translate("LauncherView", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LauncherView: public Ui_LauncherView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHERVIEW_H
