/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *numberFour;
    QLabel *inputDisplay;
    QPushButton *numberOne;
    QPushButton *NumberSeven;
    QPushButton *numberTwo;
    QPushButton *numberFive;
    QPushButton *numberEight;
    QPushButton *numberThree;
    QPushButton *numberSix;
    QPushButton *numberNine;
    QPushButton *numberZero;
    QPushButton *equalsSign;
    QPushButton *plusSign;
    QPushButton *clearButton;
    QPushButton *minusSign;
    QPushButton *multiplySign;
    QPushButton *divideSign;
    QLabel *screenDisplay;
    QPushButton *allClearButton;
    QPushButton *negativeButton;
    QPushButton *deleteButton;
    QPushButton *previousAnswerButton;
    QLabel *saveDisplay1;
    QLabel *saveDisplay2;
    QLabel *saveDisplay3;
    QLabel *saveDisplay4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(440, 541);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        numberFour = new QPushButton(centralwidget);
        numberFour->setObjectName("numberFour");
        numberFour->setGeometry(QRect(120, 290, 51, 41));
        numberFour->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        inputDisplay = new QLabel(centralwidget);
        inputDisplay->setObjectName("inputDisplay");
        inputDisplay->setGeometry(QRect(60, 175, 291, 51));
        QFont font;
        font.setPointSize(18);
        inputDisplay->setFont(font);
        inputDisplay->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: #e8e8e8;\n"
"}"));
        inputDisplay->setFrameShape(QFrame::Shape::NoFrame);
        inputDisplay->setTextFormat(Qt::TextFormat::AutoText);
        inputDisplay->setScaledContents(false);
        inputDisplay->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        inputDisplay->setMargin(0);
        inputDisplay->setIndent(10);
        numberOne = new QPushButton(centralwidget);
        numberOne->setObjectName("numberOne");
        numberOne->setGeometry(QRect(120, 240, 51, 41));
        numberOne->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        NumberSeven = new QPushButton(centralwidget);
        NumberSeven->setObjectName("NumberSeven");
        NumberSeven->setGeometry(QRect(120, 340, 51, 41));
        NumberSeven->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        numberTwo = new QPushButton(centralwidget);
        numberTwo->setObjectName("numberTwo");
        numberTwo->setGeometry(QRect(180, 240, 51, 41));
        numberTwo->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        numberFive = new QPushButton(centralwidget);
        numberFive->setObjectName("numberFive");
        numberFive->setGeometry(QRect(180, 290, 51, 41));
        numberFive->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        numberEight = new QPushButton(centralwidget);
        numberEight->setObjectName("numberEight");
        numberEight->setGeometry(QRect(180, 340, 51, 41));
        numberEight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        numberThree = new QPushButton(centralwidget);
        numberThree->setObjectName("numberThree");
        numberThree->setGeometry(QRect(240, 240, 51, 41));
        numberThree->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        numberSix = new QPushButton(centralwidget);
        numberSix->setObjectName("numberSix");
        numberSix->setGeometry(QRect(240, 290, 51, 41));
        numberSix->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        numberNine = new QPushButton(centralwidget);
        numberNine->setObjectName("numberNine");
        numberNine->setGeometry(QRect(240, 340, 51, 41));
        numberNine->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        numberZero = new QPushButton(centralwidget);
        numberZero->setObjectName("numberZero");
        numberZero->setGeometry(QRect(180, 390, 51, 41));
        numberZero->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        equalsSign = new QPushButton(centralwidget);
        equalsSign->setObjectName("equalsSign");
        equalsSign->setGeometry(QRect(240, 390, 51, 41));
        equalsSign->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        plusSign = new QPushButton(centralwidget);
        plusSign->setObjectName("plusSign");
        plusSign->setGeometry(QRect(300, 240, 51, 41));
        plusSign->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(60, 390, 51, 41));
        clearButton->setAutoFillBackground(false);
        clearButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(168, 16, 85);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(157, 15, 81);\n"
"}"));
        minusSign = new QPushButton(centralwidget);
        minusSign->setObjectName("minusSign");
        minusSign->setGeometry(QRect(300, 290, 51, 41));
        minusSign->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        multiplySign = new QPushButton(centralwidget);
        multiplySign->setObjectName("multiplySign");
        multiplySign->setGeometry(QRect(300, 340, 51, 41));
        multiplySign->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        divideSign = new QPushButton(centralwidget);
        divideSign->setObjectName("divideSign");
        divideSign->setGeometry(QRect(300, 390, 51, 41));
        divideSign->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        screenDisplay = new QLabel(centralwidget);
        screenDisplay->setObjectName("screenDisplay");
        screenDisplay->setGeometry(QRect(60, 62, 291, 164));
        screenDisplay->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	border: 2px solid rgb(135, 135, 135);\n"
"	border-radius: 12px;\n"
"	color: #e8e8e8;\n"
"}"));
        allClearButton = new QPushButton(centralwidget);
        allClearButton->setObjectName("allClearButton");
        allClearButton->setGeometry(QRect(60, 340, 51, 41));
        allClearButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(168, 16, 85);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(157, 15, 81);\n"
"}"));
        negativeButton = new QPushButton(centralwidget);
        negativeButton->setObjectName("negativeButton");
        negativeButton->setGeometry(QRect(120, 390, 51, 41));
        negativeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setGeometry(QRect(60, 240, 51, 41));
        deleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(168, 16, 85);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(157, 15, 81);\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::EditClear));
        deleteButton->setIcon(icon);
        previousAnswerButton = new QPushButton(centralwidget);
        previousAnswerButton->setObjectName("previousAnswerButton");
        previousAnswerButton->setGeometry(QRect(60, 290, 51, 41));
        previousAnswerButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 2px solid rgb(42, 42, 42);\n"
"	background-color: rgb(42, 42, 42);\n"
"	border-radius: 12px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: rgb(50, 50, 50);\n"
"}"));
        saveDisplay1 = new QLabel(centralwidget);
        saveDisplay1->setObjectName("saveDisplay1");
        saveDisplay1->setGeometry(QRect(60, 150, 291, 26));
        saveDisplay1->setIndent(10);
        saveDisplay2 = new QLabel(centralwidget);
        saveDisplay2->setObjectName("saveDisplay2");
        saveDisplay2->setGeometry(QRect(60, 124, 291, 26));
        saveDisplay2->setIndent(10);
        saveDisplay3 = new QLabel(centralwidget);
        saveDisplay3->setObjectName("saveDisplay3");
        saveDisplay3->setGeometry(QRect(60, 98, 291, 26));
        saveDisplay3->setIndent(10);
        saveDisplay4 = new QLabel(centralwidget);
        saveDisplay4->setObjectName("saveDisplay4");
        saveDisplay4->setGeometry(QRect(60, 72, 291, 26));
        saveDisplay4->setIndent(10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 440, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        numberFour->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        inputDisplay->setText(QCoreApplication::translate("MainWindow", "Enter Number", nullptr));
        numberOne->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        NumberSeven->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        numberTwo->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        numberFive->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        numberEight->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        numberThree->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        numberSix->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        numberNine->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        numberZero->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        equalsSign->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        plusSign->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        minusSign->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        multiplySign->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        divideSign->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        screenDisplay->setText(QString());
        allClearButton->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        negativeButton->setText(QCoreApplication::translate("MainWindow", "(-)", nullptr));
        deleteButton->setText(QString());
        previousAnswerButton->setText(QCoreApplication::translate("MainWindow", "Ans", nullptr));
        saveDisplay1->setText(QString());
        saveDisplay2->setText(QString());
        saveDisplay3->setText(QString());
        saveDisplay4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
