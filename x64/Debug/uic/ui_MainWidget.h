/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidgetClass
{
public:
    QAction *openaction;
    QAction *closeaction;
    QAction *action_X;
    QAction *cropaction;
    QAction *setaction;
    QAction *actionvalue;
    QAction *actionmax;
    QAction *actionminvalue;
    QAction *actionslice_x;
    QAction *actionslice_y;
    QAction *actionslice_z;
    QAction *actionvalue_2;
    QAction *actionvalue_max;
    QAction *actionvalue_min;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_2;
    QSlider *horizontalSlider;
    QLabel *label_31;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_17;
    QLabel *label_22;
    QVBoxLayout *verticalLayout;
    QLabel *label_21;
    QLabel *label_24;
    QLabel *label_26;
    QLabel *label_25;
    QSlider *horizontalSlider_2;
    QLabel *label_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_10;
    QLabel *label_6;
    QLabel *label_32;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_16;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_28;
    QLabel *label_27;
    QLabel *label_30;
    QLabel *label_23;
    QLabel *label_29;
    QVTKWidget *qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuslice;
    QMenu *menuwindow;
    QMenu *menulevel;
    QMenu *menu_O;
    QMenu *menu_Q;
    QMenu *menu_X;
    QMenu *menu_C;

    void setupUi(QMainWindow *MainWidgetClass)
    {
        if (MainWidgetClass->objectName().isEmpty())
            MainWidgetClass->setObjectName(QString::fromUtf8("MainWidgetClass"));
        MainWidgetClass->resize(1133, 800);
        MainWidgetClass->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MainWidget/resource/heart.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWidgetClass->setWindowIcon(icon);
        MainWidgetClass->setStyleSheet(QString::fromUtf8("#centralWidget{background-image: url(:/MainWidget/resource/OIP-C.jfif);}"));
        MainWidgetClass->setUnifiedTitleAndToolBarOnMac(false);
        openaction = new QAction(MainWidgetClass);
        openaction->setObjectName(QString::fromUtf8("openaction"));
        closeaction = new QAction(MainWidgetClass);
        closeaction->setObjectName(QString::fromUtf8("closeaction"));
        action_X = new QAction(MainWidgetClass);
        action_X->setObjectName(QString::fromUtf8("action_X"));
        cropaction = new QAction(MainWidgetClass);
        cropaction->setObjectName(QString::fromUtf8("cropaction"));
        setaction = new QAction(MainWidgetClass);
        setaction->setObjectName(QString::fromUtf8("setaction"));
        actionvalue = new QAction(MainWidgetClass);
        actionvalue->setObjectName(QString::fromUtf8("actionvalue"));
        actionmax = new QAction(MainWidgetClass);
        actionmax->setObjectName(QString::fromUtf8("actionmax"));
        actionminvalue = new QAction(MainWidgetClass);
        actionminvalue->setObjectName(QString::fromUtf8("actionminvalue"));
        actionslice_x = new QAction(MainWidgetClass);
        actionslice_x->setObjectName(QString::fromUtf8("actionslice_x"));
        actionslice_y = new QAction(MainWidgetClass);
        actionslice_y->setObjectName(QString::fromUtf8("actionslice_y"));
        actionslice_z = new QAction(MainWidgetClass);
        actionslice_z->setObjectName(QString::fromUtf8("actionslice_z"));
        actionvalue_2 = new QAction(MainWidgetClass);
        actionvalue_2->setObjectName(QString::fromUtf8("actionvalue_2"));
        actionvalue_max = new QAction(MainWidgetClass);
        actionvalue_max->setObjectName(QString::fromUtf8("actionvalue_max"));
        actionvalue_min = new QAction(MainWidgetClass);
        actionvalue_min->setObjectName(QString::fromUtf8("actionvalue_min"));
        actionAbout = new QAction(MainWidgetClass);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralWidget = new QWidget(MainWidgetClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_12, 0, 7, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 10, 8, 1, 1);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 1, 1, 1, 1);

        label_31 = new QLabel(centralWidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        gridLayout->addWidget(label_31, 2, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 6, 1, 1);

        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        gridLayout->addWidget(label_19, 8, 0, 1, 2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_13, 0, 8, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 5, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_2->addWidget(label_12);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_2->addWidget(label_13);

        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_2->addWidget(label_17);

        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_2->addWidget(label_22);


        gridLayout->addLayout(verticalLayout_2, 5, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_21->setWordWrap(true);

        verticalLayout->addWidget(label_21);

        label_24 = new QLabel(centralWidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_24->setWordWrap(true);

        verticalLayout->addWidget(label_24);

        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_26->setWordWrap(true);

        verticalLayout->addWidget(label_26);

        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_25->setWordWrap(true);

        verticalLayout->addWidget(label_25);


        gridLayout->addLayout(verticalLayout, 5, 1, 1, 1);

        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_2, 3, 1, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_9, 0, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_10, 0, 3, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 4, 1, 1, 1);

        label_32 = new QLabel(centralWidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        gridLayout->addWidget(label_32, 4, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 1, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_3->addWidget(label_16);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_3->addWidget(label_14);

        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_3->addWidget(label_15);

        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setStyleSheet(QString::fromUtf8("font: 63 9pt \"Bahnschrift SemiBold\";"));

        verticalLayout_3->addWidget(label_18);


        gridLayout->addLayout(verticalLayout_3, 6, 0, 2, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_28 = new QLabel(centralWidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_28->setWordWrap(true);

        verticalLayout_4->addWidget(label_28);

        label_27 = new QLabel(centralWidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_27->setWordWrap(true);

        verticalLayout_4->addWidget(label_27);

        label_30 = new QLabel(centralWidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_30->setWordWrap(true);

        verticalLayout_4->addWidget(label_30);

        label_23 = new QLabel(centralWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}"));
        label_23->setWordWrap(true);

        verticalLayout_4->addWidget(label_23);


        gridLayout->addLayout(verticalLayout_4, 6, 1, 2, 1);

        label_29 = new QLabel(centralWidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setStyleSheet(QString::fromUtf8("*{background-color: rgba(0, 25, 25,10%);\n"
"border: 2px solid rgba(20, 65, 60,40%);}\n"
"\n"
"\n"
""));
        label_29->setWordWrap(true);

        gridLayout->addWidget(label_29, 9, 0, 2, 2);

        qvtkWidget = new QVTKWidget(centralWidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        gridLayout->addWidget(qvtkWidget, 1, 2, 10, 7);

        MainWidgetClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWidgetClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1133, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuslice = new QMenu(menu);
        menuslice->setObjectName(QString::fromUtf8("menuslice"));
        menuwindow = new QMenu(menu);
        menuwindow->setObjectName(QString::fromUtf8("menuwindow"));
        menulevel = new QMenu(menu);
        menulevel->setObjectName(QString::fromUtf8("menulevel"));
        menu_O = new QMenu(menuBar);
        menu_O->setObjectName(QString::fromUtf8("menu_O"));
        menu_Q = new QMenu(menuBar);
        menu_Q->setObjectName(QString::fromUtf8("menu_Q"));
        menu_X = new QMenu(menuBar);
        menu_X->setObjectName(QString::fromUtf8("menu_X"));
        menu_C = new QMenu(menuBar);
        menu_C->setObjectName(QString::fromUtf8("menu_C"));
        MainWidgetClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_O->menuAction());
        menuBar->addAction(menu_Q->menuAction());
        menuBar->addAction(menu_X->menuAction());
        menuBar->addAction(menu_C->menuAction());
        menu->addAction(menuslice->menuAction());
        menu->addSeparator();
        menu->addAction(menuwindow->menuAction());
        menu->addAction(menulevel->menuAction());
        menu->addSeparator();
        menuslice->addAction(actionslice_x);
        menuslice->addAction(actionslice_y);
        menuslice->addAction(actionslice_z);
        menuwindow->addAction(actionvalue);
        menuwindow->addAction(actionmax);
        menuwindow->addAction(actionminvalue);
        menulevel->addAction(actionvalue_2);
        menulevel->addAction(actionvalue_max);
        menulevel->addAction(actionvalue_min);
        menu_O->addAction(openaction);
        menu_Q->addAction(closeaction);
        menu_X->addAction(action_X);
        menu_X->addAction(cropaction);
        menu_C->addAction(actionAbout);

        retranslateUi(MainWidgetClass);
        QObject::connect(closeaction, SIGNAL(triggered()), MainWidgetClass, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWidgetClass)
    {
        MainWidgetClass->setWindowTitle(QCoreApplication::translate("MainWidgetClass", "MainWidget", nullptr));
        openaction->setText(QCoreApplication::translate("MainWidgetClass", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        openaction->setToolTip(QCoreApplication::translate("MainWidgetClass", "\346\211\223\345\274\200", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        openaction->setShortcut(QCoreApplication::translate("MainWidgetClass", "O", nullptr));
#endif // QT_CONFIG(shortcut)
        closeaction->setText(QCoreApplication::translate("MainWidgetClass", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        closeaction->setToolTip(QCoreApplication::translate("MainWidgetClass", "\351\200\200\345\207\272", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        closeaction->setShortcut(QCoreApplication::translate("MainWidgetClass", "Q", nullptr));
#endif // QT_CONFIG(shortcut)
        action_X->setText(QCoreApplication::translate("MainWidgetClass", "\346\270\262\346\237\223", nullptr));
#if QT_CONFIG(tooltip)
        action_X->setToolTip(QCoreApplication::translate("MainWidgetClass", "\346\270\262\346\237\223", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        action_X->setShortcut(QCoreApplication::translate("MainWidgetClass", "X", nullptr));
#endif // QT_CONFIG(shortcut)
        cropaction->setText(QCoreApplication::translate("MainWidgetClass", "\345\210\206\345\211\262", nullptr));
#if QT_CONFIG(tooltip)
        cropaction->setToolTip(QCoreApplication::translate("MainWidgetClass", "\345\210\206\345\211\262", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        cropaction->setShortcut(QCoreApplication::translate("MainWidgetClass", "C", nullptr));
#endif // QT_CONFIG(shortcut)
        setaction->setText(QCoreApplication::translate("MainWidgetClass", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        setaction->setToolTip(QCoreApplication::translate("MainWidgetClass", "\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        setaction->setShortcut(QCoreApplication::translate("MainWidgetClass", "S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionvalue->setText(QCoreApplication::translate("MainWidgetClass", "value", nullptr));
        actionmax->setText(QCoreApplication::translate("MainWidgetClass", "MaxValue", nullptr));
        actionminvalue->setText(QCoreApplication::translate("MainWidgetClass", "MinValue", nullptr));
        actionslice_x->setText(QCoreApplication::translate("MainWidgetClass", "slice_x", nullptr));
        actionslice_y->setText(QCoreApplication::translate("MainWidgetClass", "slice_y", nullptr));
        actionslice_z->setText(QCoreApplication::translate("MainWidgetClass", "slice_z", nullptr));
        actionvalue_2->setText(QCoreApplication::translate("MainWidgetClass", "value", nullptr));
        actionvalue_max->setText(QCoreApplication::translate("MainWidgetClass", "MaxValue", nullptr));
        actionvalue_min->setText(QCoreApplication::translate("MainWidgetClass", "MinValue", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWidgetClass", "About", nullptr));
        label_5->setText(QString());
        label_31->setText(QCoreApplication::translate("MainWidgetClass", "windowvalue", nullptr));
        label_19->setText(QCoreApplication::translate("MainWidgetClass", "description", nullptr));
        label_12->setText(QCoreApplication::translate("MainWidgetClass", "Name", nullptr));
        label_13->setText(QCoreApplication::translate("MainWidgetClass", "Sex", nullptr));
        label_17->setText(QCoreApplication::translate("MainWidgetClass", "ID", nullptr));
        label_22->setText(QCoreApplication::translate("MainWidgetClass", "age", nullptr));
        label_21->setText(QString());
        label_24->setText(QString());
        label_26->setText(QString());
        label_25->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWidgetClass", "Level", nullptr));
        label->setText(QCoreApplication::translate("MainWidgetClass", "Window", nullptr));
        label_6->setText(QString());
        label_32->setText(QCoreApplication::translate("MainWidgetClass", "levelvalue", nullptr));
        label_16->setText(QCoreApplication::translate("MainWidgetClass", "modility", nullptr));
        label_14->setText(QCoreApplication::translate("MainWidgetClass", "time", nullptr));
        label_15->setText(QCoreApplication::translate("MainWidgetClass", "hospital", nullptr));
        label_18->setText(QCoreApplication::translate("MainWidgetClass", "manufacture", nullptr));
        label_28->setText(QString());
        label_27->setText(QString());
        label_30->setText(QString());
        label_23->setText(QString());
        label_29->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWidgetClass", "\350\256\276\347\275\256", nullptr));
        menuslice->setTitle(QCoreApplication::translate("MainWidgetClass", "slice", nullptr));
        menuwindow->setTitle(QCoreApplication::translate("MainWidgetClass", "window", nullptr));
        menulevel->setTitle(QCoreApplication::translate("MainWidgetClass", "level", nullptr));
        menu_O->setTitle(QCoreApplication::translate("MainWidgetClass", "\346\211\223\345\274\200", nullptr));
        menu_Q->setTitle(QCoreApplication::translate("MainWidgetClass", "\351\200\200\345\207\272", nullptr));
        menu_X->setTitle(QCoreApplication::translate("MainWidgetClass", "\345\267\245\345\205\267", nullptr));
        menu_C->setTitle(QCoreApplication::translate("MainWidgetClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWidgetClass: public Ui_MainWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
