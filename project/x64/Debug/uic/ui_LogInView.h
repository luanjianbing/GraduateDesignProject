/********************************************************************************
** Form generated from reading UI file 'LogInView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINVIEW_H
#define UI_LOGINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogInView
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelUserName;
    QLineEdit *lineEditUserName;
    QLabel *labelPassward;
    QLineEdit *lineEditPassward;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QPushButton *buttonCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonLogIn;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *LogInView)
    {
        if (LogInView->objectName().isEmpty())
            LogInView->setObjectName(QString::fromUtf8("LogInView"));
        LogInView->resize(400, 250);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        LogInView->setFont(font);
        gridLayout_2 = new QGridLayout(LogInView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widget = new QWidget(LogInView);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelUserName = new QLabel(widget);
        labelUserName->setObjectName(QString::fromUtf8("labelUserName"));
        labelUserName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelUserName, 0, 0, 1, 1);

        lineEditUserName = new QLineEdit(widget);
        lineEditUserName->setObjectName(QString::fromUtf8("lineEditUserName"));

        gridLayout->addWidget(lineEditUserName, 0, 1, 1, 1);

        labelPassward = new QLabel(widget);
        labelPassward->setObjectName(QString::fromUtf8("labelPassward"));
        labelPassward->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPassward, 1, 0, 1, 1);

        lineEditPassward = new QLineEdit(widget);
        lineEditPassward->setObjectName(QString::fromUtf8("lineEditPassward"));

        gridLayout->addWidget(lineEditPassward, 1, 1, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        label = new QLabel(LogInView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("Icon/LogIn.png")));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 3);

        buttonCancel = new QPushButton(LogInView);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setAutoDefault(false);

        gridLayout_2->addWidget(buttonCancel, 2, 3, 1, 2);

        horizontalSpacer = new QSpacerItem(75, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        buttonLogIn = new QPushButton(LogInView);
        buttonLogIn->setObjectName(QString::fromUtf8("buttonLogIn"));
        sizePolicy.setHeightForWidth(buttonLogIn->sizePolicy().hasHeightForWidth());
        buttonLogIn->setSizePolicy(sizePolicy);
        buttonLogIn->setAutoDefault(false);
        buttonLogIn->setFlat(false);

        gridLayout_2->addWidget(buttonLogIn, 2, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 3);
        gridLayout_2->setRowStretch(1, 4);
        gridLayout_2->setRowStretch(2, 3);

        retranslateUi(LogInView);

        buttonLogIn->setDefault(false);


        QMetaObject::connectSlotsByName(LogInView);
    } // setupUi

    void retranslateUi(QDialog *LogInView)
    {
        LogInView->setWindowTitle(QApplication::translate("LogInView", "LogIn", nullptr));
        labelUserName->setText(QApplication::translate("LogInView", "\347\224\250\346\210\267ID\357\274\232", nullptr));
        labelPassward->setText(QApplication::translate("LogInView", "\345\257\206\347\240\201\357\274\232", nullptr));
        label->setText(QString());
        buttonCancel->setText(QApplication::translate("LogInView", "\345\217\226\346\266\210", nullptr));
        buttonLogIn->setText(QApplication::translate("LogInView", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogInView: public Ui_LogInView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINVIEW_H
