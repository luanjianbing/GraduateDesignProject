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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterNewUserView
{
public:
    QGridLayout *gridLayout_5;
    QWidget *widget_2;
    QGridLayout *gridLayout_4;
    QTreeWidget *treeWidgetHasUser;
    QWidget *widget;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBoxNewUser;
    QGridLayout *gridLayout;
    QLabel *labelNewUserID;
    QLineEdit *lineEditNewUserName;
    QLabel *labelNewUserPassward;
    QLineEdit *lineEditNewUserPassward;
    QLabel *labelNewUserConfirmPassward;
    QLineEdit *lineEditNewUserConfirmPassward;
    QLabel *labelNewUserTrueName;
    QLineEdit *lineEditNewUserTrueName;
    QLabel *labelNewUserProductionLine;
    QLineEdit *lineEditNewUserProductionLine;
    QLabel *labelAuthority;
    QComboBox *comboBoxAuthority;
    QGroupBox *groupBoxSuperAuthority;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditSuperAuthorityUserID;
    QLabel *labelSuperAuthorityUserPassward;
    QLineEdit *lineEditSuperAuthorityUserPassward;
    QLabel *labelSuperAuthorityUserID;
    QLabel *labelTip;
    QPushButton *buttonModify;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *buttonCancel;

    void setupUi(QDialog *RegisterNewUserView)
    {
        if (RegisterNewUserView->objectName().isEmpty())
            RegisterNewUserView->setObjectName(QString::fromUtf8("RegisterNewUserView"));
        RegisterNewUserView->resize(700, 500);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(11);
        RegisterNewUserView->setFont(font);
        gridLayout_5 = new QGridLayout(RegisterNewUserView);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget_2 = new QWidget(RegisterNewUserView);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout_4 = new QGridLayout(widget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        treeWidgetHasUser = new QTreeWidget(widget_2);
        treeWidgetHasUser->setObjectName(QString::fromUtf8("treeWidgetHasUser"));

        gridLayout_4->addWidget(treeWidgetHasUser, 0, 0, 1, 1);


        gridLayout_5->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(RegisterNewUserView);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_3 = new QGridLayout(widget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer = new QSpacerItem(122, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("Icon/Register.png")));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(122, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        groupBoxNewUser = new QGroupBox(widget);
        groupBoxNewUser->setObjectName(QString::fromUtf8("groupBoxNewUser"));
        gridLayout = new QGridLayout(groupBoxNewUser);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelNewUserID = new QLabel(groupBoxNewUser);
        labelNewUserID->setObjectName(QString::fromUtf8("labelNewUserID"));
        labelNewUserID->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserID, 0, 0, 1, 1);

        lineEditNewUserName = new QLineEdit(groupBoxNewUser);
        lineEditNewUserName->setObjectName(QString::fromUtf8("lineEditNewUserName"));

        gridLayout->addWidget(lineEditNewUserName, 0, 1, 1, 1);

        labelNewUserPassward = new QLabel(groupBoxNewUser);
        labelNewUserPassward->setObjectName(QString::fromUtf8("labelNewUserPassward"));
        labelNewUserPassward->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserPassward, 1, 0, 1, 1);

        lineEditNewUserPassward = new QLineEdit(groupBoxNewUser);
        lineEditNewUserPassward->setObjectName(QString::fromUtf8("lineEditNewUserPassward"));

        gridLayout->addWidget(lineEditNewUserPassward, 1, 1, 1, 1);

        labelNewUserConfirmPassward = new QLabel(groupBoxNewUser);
        labelNewUserConfirmPassward->setObjectName(QString::fromUtf8("labelNewUserConfirmPassward"));
        labelNewUserConfirmPassward->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserConfirmPassward, 2, 0, 1, 1);

        lineEditNewUserConfirmPassward = new QLineEdit(groupBoxNewUser);
        lineEditNewUserConfirmPassward->setObjectName(QString::fromUtf8("lineEditNewUserConfirmPassward"));

        gridLayout->addWidget(lineEditNewUserConfirmPassward, 2, 1, 1, 1);

        labelNewUserTrueName = new QLabel(groupBoxNewUser);
        labelNewUserTrueName->setObjectName(QString::fromUtf8("labelNewUserTrueName"));
        labelNewUserTrueName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserTrueName, 3, 0, 1, 1);

        lineEditNewUserTrueName = new QLineEdit(groupBoxNewUser);
        lineEditNewUserTrueName->setObjectName(QString::fromUtf8("lineEditNewUserTrueName"));

        gridLayout->addWidget(lineEditNewUserTrueName, 3, 1, 1, 1);

        labelNewUserProductionLine = new QLabel(groupBoxNewUser);
        labelNewUserProductionLine->setObjectName(QString::fromUtf8("labelNewUserProductionLine"));
        labelNewUserProductionLine->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelNewUserProductionLine, 4, 0, 1, 1);

        lineEditNewUserProductionLine = new QLineEdit(groupBoxNewUser);
        lineEditNewUserProductionLine->setObjectName(QString::fromUtf8("lineEditNewUserProductionLine"));

        gridLayout->addWidget(lineEditNewUserProductionLine, 4, 1, 1, 1);

        labelAuthority = new QLabel(groupBoxNewUser);
        labelAuthority->setObjectName(QString::fromUtf8("labelAuthority"));
        labelAuthority->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelAuthority, 5, 0, 1, 1);

        comboBoxAuthority = new QComboBox(groupBoxNewUser);
        comboBoxAuthority->setObjectName(QString::fromUtf8("comboBoxAuthority"));

        gridLayout->addWidget(comboBoxAuthority, 5, 1, 1, 1);


        gridLayout_3->addWidget(groupBoxNewUser, 1, 0, 1, 3);

        groupBoxSuperAuthority = new QGroupBox(widget);
        groupBoxSuperAuthority->setObjectName(QString::fromUtf8("groupBoxSuperAuthority"));
        gridLayout_2 = new QGridLayout(groupBoxSuperAuthority);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEditSuperAuthorityUserID = new QLineEdit(groupBoxSuperAuthority);
        lineEditSuperAuthorityUserID->setObjectName(QString::fromUtf8("lineEditSuperAuthorityUserID"));

        gridLayout_2->addWidget(lineEditSuperAuthorityUserID, 1, 1, 1, 1);

        labelSuperAuthorityUserPassward = new QLabel(groupBoxSuperAuthority);
        labelSuperAuthorityUserPassward->setObjectName(QString::fromUtf8("labelSuperAuthorityUserPassward"));
        labelSuperAuthorityUserPassward->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelSuperAuthorityUserPassward, 2, 0, 1, 1);

        lineEditSuperAuthorityUserPassward = new QLineEdit(groupBoxSuperAuthority);
        lineEditSuperAuthorityUserPassward->setObjectName(QString::fromUtf8("lineEditSuperAuthorityUserPassward"));

        gridLayout_2->addWidget(lineEditSuperAuthorityUserPassward, 2, 1, 1, 1);

        labelSuperAuthorityUserID = new QLabel(groupBoxSuperAuthority);
        labelSuperAuthorityUserID->setObjectName(QString::fromUtf8("labelSuperAuthorityUserID"));
        labelSuperAuthorityUserID->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelSuperAuthorityUserID, 1, 0, 1, 1);

        labelTip = new QLabel(groupBoxSuperAuthority);
        labelTip->setObjectName(QString::fromUtf8("labelTip"));

        gridLayout_2->addWidget(labelTip, 0, 0, 1, 2);


        gridLayout_3->addWidget(groupBoxSuperAuthority, 2, 0, 1, 3);

        buttonModify = new QPushButton(widget);
        buttonModify->setObjectName(QString::fromUtf8("buttonModify"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonModify->sizePolicy().hasHeightForWidth());
        buttonModify->setSizePolicy(sizePolicy);
        buttonModify->setAutoDefault(false);

        gridLayout_3->addWidget(buttonModify, 3, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(123, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 3, 1, 1, 1);

        buttonCancel = new QPushButton(widget);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        sizePolicy.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy);
        buttonCancel->setAutoDefault(false);

        gridLayout_3->addWidget(buttonCancel, 3, 2, 1, 1);

        gridLayout_3->setRowStretch(0, 2);
        gridLayout_3->setRowStretch(1, 5);
        gridLayout_3->setRowStretch(2, 2);
        gridLayout_3->setRowStretch(3, 1);

        gridLayout_5->addWidget(widget, 0, 1, 1, 1);

        gridLayout_5->setColumnStretch(0, 4);
        gridLayout_5->setColumnStretch(1, 6);

        retranslateUi(RegisterNewUserView);

        buttonModify->setDefault(true);


        QMetaObject::connectSlotsByName(RegisterNewUserView);
    } // setupUi

    void retranslateUi(QDialog *RegisterNewUserView)
    {
        RegisterNewUserView->setWindowTitle(QApplication::translate("RegisterNewUserView", "RegisterNewUser", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidgetHasUser->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("RegisterNewUserView", "\345\267\262\346\234\211\347\224\250\346\210\267", nullptr));
        label->setText(QString());
        groupBoxNewUser->setTitle(QApplication::translate("RegisterNewUserView", "\346\226\260\347\224\250\346\210\267", nullptr));
        labelNewUserID->setText(QApplication::translate("RegisterNewUserView", "\347\224\250\346\210\267ID\357\274\232", nullptr));
        labelNewUserPassward->setText(QApplication::translate("RegisterNewUserView", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelNewUserConfirmPassward->setText(QApplication::translate("RegisterNewUserView", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        labelNewUserTrueName->setText(QApplication::translate("RegisterNewUserView", "\345\247\223\345\220\215\357\274\232", nullptr));
        labelNewUserProductionLine->setText(QApplication::translate("RegisterNewUserView", "\347\224\237\344\272\247\347\272\277\345\220\215\347\247\260\357\274\232", nullptr));
        labelAuthority->setText(QApplication::translate("RegisterNewUserView", "\346\235\203\351\231\220\357\274\232", nullptr));
        groupBoxSuperAuthority->setTitle(QApplication::translate("RegisterNewUserView", "\351\253\230\347\272\247\347\256\241\347\220\206\345\221\230", nullptr));
        labelSuperAuthorityUserPassward->setText(QApplication::translate("RegisterNewUserView", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelSuperAuthorityUserID->setText(QApplication::translate("RegisterNewUserView", "\347\224\250\346\210\267ID\357\274\232", nullptr));
        labelTip->setText(QApplication::translate("RegisterNewUserView", "\357\274\210\346\217\220\347\244\272\357\274\232\346\263\250\345\206\214\346\226\260\347\224\250\346\210\267\351\234\200\350\246\201\346\233\264\351\253\230\347\272\247\346\235\203\351\231\220\347\232\204\347\256\241\347\220\206\345\221\230\345\220\214\346\204\217\357\274\211", nullptr));
        buttonModify->setText(QApplication::translate("RegisterNewUserView", "\347\241\256\350\256\244", nullptr));
        buttonCancel->setText(QApplication::translate("RegisterNewUserView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterNewUserView: public Ui_RegisterNewUserView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERNEWUSERVIEW_H
