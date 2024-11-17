
#include "math.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

enum CalcOperator {none, plus, minus, multiply, divide};

CalcOperator sign = none;
QString printedNumValue = "";
QString valueHalf = "";
std::array<QString, 4> savedCalculations = {};
int previousAns = 0;
int value1 = 0;
int value2 = 0;
int answer = 0;
bool checkNegative1 = false;
bool checkNegative2 = false;
bool checkOperator = false;


void MainWindow::on_numberOne_clicked()
{
    static const int textOne = 1;
    //previousInput = textOne;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textOne;
    } else {
        value2 *= 10;
        value2 += textOne;
    }

    printedNumValue = printedNumValue + "1";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberTwo_clicked()
{
    static const int textTwo = 2;
    //previousInput = textTwo;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textTwo;
    } else {
        value2 *= 10;
        value2 += textTwo;
    }

    printedNumValue = printedNumValue + "2";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberThree_clicked()
{
    static const int textThree = 3;
    //previousInput = textThree;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textThree;
    } else {
        value2 *= 10;
        value2 += textThree;
    }

    printedNumValue = printedNumValue + "3";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberFour_clicked()
{
    static const int textFour = 4;
    //previousInput = textFour;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textFour;
    } else {
        value2 *= 10;
        value2 += textFour;
    }

    printedNumValue = printedNumValue + "4";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberFive_clicked()
{
    static const int textFive = 5;
    //previousInput = textFive;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textFive;
    } else {
        value2 *= 10;
        value2 += textFive;
    }

    printedNumValue = printedNumValue + "5";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberSix_clicked()
{
    static const int textSix = 6;
   // previousInput = textSix;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textSix;
    } else {
        value2 *= 10;
        value2 += textSix;
    }

    printedNumValue = printedNumValue + "6";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_NumberSeven_clicked()
{
    static const int textSeven = 7;
    //previousInput = textSeven;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textSeven;
    } else {
        value2 *= 10;
        value2 += textSeven;
    }

    printedNumValue = printedNumValue + "7";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberEight_clicked()
{
    static const int textEight = 8;
   // previousInput = textEight;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textEight;
    } else {
        value2 *= 10;
        value2 += textEight;
    }

    printedNumValue = printedNumValue + "8";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberNine_clicked()
{
    static const int textNine = 9;
    //previousInput = textNine;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textNine;
    } else {
        value2 *= 10;
        value2 += textNine;
    }

    printedNumValue = printedNumValue + "9";
    ui->inputDisplay->setText(printedNumValue);
}


void MainWindow::on_numberZero_clicked()
{
    static const int textZero = 0;
   // previousInput = textZero;

    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        value1 += textZero;
    } else {
        value2 *= 10;
        value2 += textZero;
    }

    printedNumValue = printedNumValue + "0";
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_previousAnswerButton_clicked()
{
    //check if value1 or value2
    if(!checkOperator){
        value1 = previousAns;
    } else {
        value2 = previousAns;
    }

    printedNumValue = printedNumValue + "Ans";
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_negativeButton_clicked()
{
    //determine which number to make negative
    if(!checkOperator){
        checkNegative1 = true;

        //check if negitve sign is used properly, if placed in between an input, give Syntax Error
        if(printedNumValue == ""){
            printedNumValue = printedNumValue + '-';
            ui->inputDisplay->setText(printedNumValue);
        } else {
            //reset input
            checkNegative1 = false;
            checkNegative2 = false;
            checkOperator = false;
            sign = none;
            printedNumValue = "";
            //previousInput = 0;
            value1 = 0;
            value2 = 0;
            ui->inputDisplay->setText("Syntax Error");
        }
    } else {
        checkNegative2 = true;
        if(valueHalf == printedNumValue){
            printedNumValue = printedNumValue + '-';
            ui->inputDisplay->setText(printedNumValue);
        } else {
            //reset input
            checkNegative1 = false;
            checkNegative2 = false;
            checkOperator = false;
            sign = none;
            printedNumValue = "";
            //previousInput = 0;
            value1 = 0;
            value2 = 0;
            ui->inputDisplay->setText("Syntax Error");
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    //reverse previous input
    //check if removeing a number or an operator sign
    if(valueHalf == printedNumValue && checkOperator == true){
        checkOperator = false;
        if(!checkNegative1){
            printedNumValue = QString::number(value1);
        } else {
            printedNumValue = '-' + QString::number(value1);
        }
        ui->inputDisplay->setText(printedNumValue);
    } else if(checkOperator == true) {
        int previousInput = value2 % 10;
        value2 -= previousInput;
        value2 /= 10.0;
        if(value2 == 0){
            checkNegative2 = false;
            printedNumValue = valueHalf;
        } else {
            if(checkNegative2)
                printedNumValue = valueHalf + '-' + QString::number(value2);
            else
                printedNumValue = valueHalf + QString::number(value2);
        }
        ui->inputDisplay->setText(printedNumValue);
    } else {
        int previousInput = value1 % 10;
        value1 -= previousInput;
        value1 /= 10;
        //check if the first number was deleted, then reset
        if(value1 == 0){
            checkNegative1 = false;
            printedNumValue = "";
            ui->inputDisplay->setText("");
        } else {
            if(checkNegative1)
                printedNumValue = '-' + QString::number(value1);
            else
                printedNumValue = QString::number(value1);
            ui->inputDisplay->setText(printedNumValue);
        }
    }
}

void MainWindow::on_clearButton_clicked()
{
    checkOperator = false;
    checkNegative1 = false;
    checkNegative2 = false;
    value1 = 0;
    value2 = 0;
    //previousInput = 0;
    printedNumValue = "";
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_allClearButton_clicked()
{
    checkOperator = false;
    checkNegative1 = false;
    checkNegative2 = false;
    value1 = 0;
    value2 = 0;
    previousAns = 0;
    //previousInput = 0;
    printedNumValue = "";
    ui->inputDisplay->setText(printedNumValue);

    for(int i = 0; i < savedCalculations.size(); ++i){
        savedCalculations[i] = "";
    }

    ui->saveDisplay1->setText(savedCalculations[0]);
    ui->saveDisplay2->setText(savedCalculations[1]);
    ui->saveDisplay3->setText(savedCalculations[2]);
    ui->saveDisplay4->setText(savedCalculations[3]);
}

void MainWindow::on_plusSign_clicked()
{
    sign = plus;
    checkOperator = true;
    printedNumValue = printedNumValue + " + ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_minusSign_clicked()
{
    sign = minus;
    checkOperator = true;
    printedNumValue = printedNumValue + " - ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_multiplySign_clicked()
{
    sign = multiply;
    checkOperator = true;
    printedNumValue = printedNumValue + " x ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_divideSign_clicked()
{
    sign = divide;
    checkOperator = true;
    printedNumValue = printedNumValue + " ÷ ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_equalsSign_clicked()
{
    //check if a value is negative
    if(checkNegative1){
        value1 -= value1 * 2;
    }
    if(checkNegative2){
        value2 -= value2 * 2;
    }

    // performs desired calculation for answer
    switch(sign){
    case plus:
        answer = value1 + value2;
        break;
    case minus:
        answer = value1 - value2;
        break;
    case multiply:
        answer = value1 * value2;
        break;
    case divide:
        answer = value1 / value2;
        break;
    default:
        answer = value1;
        break;
    }

    //savedEquation1 = printedNumValue + " = " + QString::number(answer);
    //ui->saveDisplay1->setText(savedEquation1);

    //in decending order, move savedCalculations[i-1] forward 1 until input replaces save1
    for(int i = savedCalculations.size() - 1; i > 0; --i){
        savedCalculations[i] = savedCalculations[i-1];
    }
    savedCalculations[0] = printedNumValue + " = " + QString::number(answer);

    //print saves
    ui->saveDisplay1->setText(savedCalculations[0]);
    ui->saveDisplay2->setText(savedCalculations[1]);
    ui->saveDisplay3->setText(savedCalculations[2]);
    ui->saveDisplay4->setText(savedCalculations[3]);

    previousAns = answer;

    printedNumValue = "";
    ui->inputDisplay->setText(printedNumValue);
    value1 = 0;
    value2 = 0;
    answer = 0;
    checkOperator = false;
}

