/********************************************************************************
** Form generated from reading UI file 'CropWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROPWIDGET_H
#define UI_CROPWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Form2
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QVTKWidget *qvtkWidget;

    void setupUi(QWidget *Form2)
    {
        if (Form2->objectName().isEmpty())
            Form2->setObjectName(QString::fromUtf8("Form2"));
        Form2->resize(934, 662);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MainWidget/resource/heart.png"), QSize(), QIcon::Normal, QIcon::Off);
        Form2->setWindowIcon(icon);
        Form2->setStyleSheet(QString::fromUtf8("background-image: url(:/MainWidget/resource/OIP-C.jfif);\n"
"background-color: rgb(208, 226, 255);"));
        gridLayout = new QGridLayout(Form2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_2 = new QPushButton(Form2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 55, 55,30%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));

        gridLayout->addWidget(pushButton_2, 1, 3, 1, 1);

        pushButton = new QPushButton(Form2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 55, 55,30%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        pushButton->setCheckable(false);
        pushButton->setChecked(false);
        pushButton->setAutoDefault(false);

        gridLayout->addWidget(pushButton, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        qvtkWidget = new QVTKWidget(Form2);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        gridLayout->addWidget(qvtkWidget, 0, 0, 1, 5);

        qvtkWidget->raise();
        pushButton_2->raise();
        pushButton->raise();

        retranslateUi(Form2);

        QMetaObject::connectSlotsByName(Form2);
    } // setupUi

    void retranslateUi(QWidget *Form2)
    {
        Form2->setWindowTitle(QCoreApplication::translate("Form2", "blood vessels", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Form2", "\346\217\220\345\217\226\344\270\255\345\277\203\347\272\277", nullptr));
        pushButton->setText(QCoreApplication::translate("Form2", "\346\210\252\351\235\242\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form2: public Ui_Form2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROPWIDGET_H
