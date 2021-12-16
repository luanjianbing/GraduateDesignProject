/********************************************************************************
** Form generated from reading UI file 'RegisterNewUserView.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERNEWUSERVIEW_H
#define UI_REGISTERNEWUSERVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterNewUserView
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *buttonCancel;
    QPushButton *buttonModify;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *labelNewUserName;
    QLineEdit *lineEditNewUserName;
    QLabel *labelNewUserPassward;
    QLineEdit *lineEditNewUserPassward;
    QLabel *labelNewUserConfirmPassward;
    QLineEdit *lineEditNewUserConfirmPassward;
    QLabel *labelAuthority;
    QComboBox *comboBoxAuthority;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *RegisterNewUserView)
    {
        if (RegisterNewUserView->objectName().isEmpty())
            RegisterNewUserView->setObjectName(QString::fromUtf8("RegisterNewUserView"));
        RegisterNewUserView->resize(400, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        RegisterNewUserView->setFont(font);
        gridLayout_2 = new QGridLayout(RegisterNewUserView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(RegisterNewUserView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("Icon/Register.png")));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 3);

        buttonCancel = new QPushButton(RegisterNewUserView);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setAutoDefault(false);

        gridLayout_2->addWidget(buttonCancel, 2, 3, 1, 2);

        buttonModify = new QPushButton(RegisterNewUserView);
        buttonModify->setObjectName(QString::fromUtf8("buttonModify"));
        sizePolicy.setHeightForWidth(buttonModify->sizePolicy().hasHeightForWidth());
        buttonModify->setSizePolicy(sizePolicy);
        buttonModify->setAutoDefault(false);

        gridLayout_2->addWidget(buttonModify, 2, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        widget = new QWidget(RegisterNewUserView);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelNewUserName = new QLabel(widget);
        labelNewUserName->setObjectName(QString::fromUtf8("labelNewUserName"));
        labelNewUserName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserName, 0, 0, 1, 1);

        lineEditNewUserName = new QLineEdit(widget);
        lineEditNewUserName->setObjectName(QString::fromUtf8("lineEditNewUserName"));

        gridLayout->addWidget(lineEditNewUserName, 0, 1, 1, 1);

        labelNewUserPassward = new QLabel(widget);
        labelNewUserPassward->setObjectName(QString::fromUtf8("labelNewUserPassward"));
        labelNewUserPassward->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserPassward, 1, 0, 1, 1);

        lineEditNewUserPassward = new QLineEdit(widget);
        lineEditNewUserPassward->setObjectName(QString::fromUtf8("lineEditNewUserPassward"));

        gridLayout->addWidget(lineEditNewUserPassward, 1, 1, 1, 1);

        labelNewUserConfirmPassward = new QLabel(widget);
        labelNewUserConfirmPassward->setObjectName(QString::fromUtf8("labelNewUserConfirmPassward"));
        labelNewUserConfirmPassward->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserConfirmPassward, 2, 0, 1, 1);

        lineEditNewUserConfirmPassward = new QLineEdit(widget);
        lineEditNewUserConfirmPassward->setObjectName(QString::fromUtf8("lineEditNewUserConfirmPassward"));

        gridLayout->addWidget(lineEditNewUserConfirmPassward, 2, 1, 1, 1);

        labelAuthority = new QLabel(widget);
        labelAuthority->setObjectName(QString::fromUtf8("labelAuthority"));
        labelAuthority->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelAuthority, 3, 0, 1, 1);

        comboBoxAuthority = new QComboBox(widget);
        comboBoxAuthority->setObjectName(QString::fromUtf8("comboBoxAuthority"));

        gridLayout->addWidget(comboBoxAuthority, 3, 1, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 5);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 2, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 2);
        gridLayout_2->setRowStretch(1, 6);
        gridLayout_2->setRowStretch(2, 2);

        retranslateUi(RegisterNewUserView);

        QMetaObject::connectSlotsByName(RegisterNewUserView);
    } // setupUi

    void retranslateUi(QDialog *RegisterNewUserView)
    {
        RegisterNewUserView->setWindowTitle(QApplication::translate("RegisterNewUserView", "RegisterNewUser", nullptr));
        label->setText(QString());
        buttonCancel->setText(QApplication::translate("RegisterNewUserView", "\345\217\226\346\266\210", nullptr));
        buttonModify->setText(QApplication::translate("RegisterNewUserView", "\347\241\256\350\256\244", nullptr));
        labelNewUserName->setText(QApplication::translate("RegisterNewUserView", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labelNewUserPassward->setText(QApplication::translate("RegisterNewUserView", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelNewUserConfirmPassward->setText(QApplication::translate("RegisterNewUserView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        labelAuthority->setText(QApplication::translate("RegisterNewUserView", "\346\235\203\351\231\220\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterNewUserView: public Ui_RegisterNewUserView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERNEWUSERVIEW_H
