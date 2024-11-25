// DO NOW
// fix the saves scroll bar not scrolling down all the way after an answer is entered
// do something about checkAns1 and checkAns2

// TODO
// allow more than 2 values for calculation in one expression (replace value1 & value2 with a vector to cover all values in the expression)
// simplify fractions and add ability to input fractions
// sin() cos() and tan() functions

#include <vector>

#include "math.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QScrollArea>
#include <QScrollBar>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QAbstractButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

enum CalcOperator {none, plus, minus, multiply, divide};
enum SpecialValues {negative = -2, ans = -1};

CalcOperator sign = none;

void MainWindow::clear_values(){
    checkOperator = false;
    checkNegative1 = false;
    checkNegative2 = false;
    zeroCount = false;
    firstValues.clear();
    secondValues.clear();
    value1 = 0;
    value2 = 0;
    answer = 0;
    printedNumValue = "";
    sign = none;
}

void MainWindow::clear_saves(){
    //get container widget inside the QScrollArea
    QWidget *container = ui->scrollSaveArea->widget();

    //get the layout of the container
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(container->layout());

    //revmove all widgets from the layout
    while(QLayoutItem *item = layout->takeAt(0)) {
        QWidget *widget = item->widget();
        if (widget) {
            widget->deleteLater(); // Delete the widget
        }
        delete item; // Delete the layout item
    }

    //clear lastLabel as all labels are deleted
    lastLabel = nullptr;
}

void MainWindow::update_save_display(){
    QLabel *newLabel = new QLabel(printedNumValue + " = " + QString::number(answer));
    QWidget *container = ui->scrollSaveArea->widget();

    //safety check
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(container->layout());
    if(!layout) {
        delete newLabel;
        return;
    }

    layout->setAlignment(Qt::AlignBottom);
    newLabel->setContentsMargins(9, 0, 9, 0);
    layout->setSpacing(10);

    //add newLabel to layout
    layout->addWidget(newLabel);

    lastLabel = newLabel;
}

void MainWindow::update_and_scroll(){
    //create new label for previous save
    update_save_display();

    //scroll to bottom of saves
    QScrollBar *vScrollBar = ui->scrollSaveArea->verticalScrollBar();
    vScrollBar->setValue(vScrollBar->maximum());
}

void MainWindow::delete_last_label(){
    if(lastLabel){
        QWidget *container = ui->scrollSaveArea->widget();
        QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(container->layout());

        //remove the label from the layout
        layout->removeWidget(lastLabel);

        //manually delete the label
        lastLabel->deleteLater();

        //clear the pointer
        lastLabel = nullptr;
    }
}

void MainWindow::set_input_display(std::vector<int>& vect){
    //set printedNumValue to all inputs except for the one deleted (including Ans and '-')
    for(int i = 0; i < vect.size(); ++i){
        if(vect[i] == negative){
            printedNumValue = printedNumValue + '-';
        } else if(vect[i] == ans) {
            printedNumValue = printedNumValue + "Ans";
        } else {
            printedNumValue = printedNumValue + QString::number(vect[i]);
        }
    }
}

bool MainWindow::check_for_ans(const std::vector<int>& vect){
    for(int i : vect){
        if(i == ans) return true;
    }
    return false;
}

void MainWindow::process_number_input(int num){
    //check if value1 or value2
    if(!checkOperator){
        value1 *= 10;
        checkNegative1 ? value1 -= num : value1 += num;
        firstValues.push_back(num);
    } else {
        value2 *= 10;
        checkNegative2 ? value2 -= num : value2 += num;
        secondValues.push_back(num);
    }

    printedNumValue = printedNumValue + QString::number(num);
    ui->inputDisplay->setText(printedNumValue);
}


//number inputs
void MainWindow::on_numberOne_clicked() { process_number_input(1); }

void MainWindow::on_numberTwo_clicked() { process_number_input(2); }

void MainWindow::on_numberThree_clicked() { process_number_input(3); }

void MainWindow::on_numberFour_clicked() { process_number_input(4); }

void MainWindow::on_numberFive_clicked() { process_number_input(5); }

void MainWindow::on_numberSix_clicked() { process_number_input(6); }

void MainWindow::on_NumberSeven_clicked() { process_number_input(7); }

void MainWindow::on_numberEight_clicked() { process_number_input(8); }

void MainWindow::on_numberNine_clicked() { process_number_input(9); }

void MainWindow::on_numberZero_clicked()
{
    if(value1 == 0 && !checkOperator)
        zeroCount = true;

    process_number_input(0);
}

void MainWindow::on_previousAnswerButton_clicked()
{
    checkAns2 = true;
    //check if value1 or value2
    if(!checkOperator){
        if(printedNumValue == ""){
            value1 = previousAns;
        } else {
            value1 *= 10;
            value1 += previousAns;
        }
        firstValues.push_back(ans);
    } else {
        if(printedNumValue == valueHalf){
            value2 = previousAns;
        } else {
            value2 *= 10;
            value2 += previousAns;
        }
        secondValues.push_back(ans);
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
            firstValues.push_back(negative);
            ui->inputDisplay->setText(printedNumValue);
        } else {
            //reset input
            checkNegative1 = false;
            checkNegative2 = false;
            checkOperator = false;
            sign = none;
            printedNumValue = "";
            value1 = 0;
            value2 = 0;
            ui->inputDisplay->setText("Syntax Error");
        }
    } else {
        checkNegative2 = true;
        if(valueHalf == printedNumValue){
            printedNumValue = printedNumValue + '-';
            secondValues.push_back(negative);
            ui->inputDisplay->setText(printedNumValue);
        } else {
            //reset input
            checkNegative1 = false;
            checkNegative2 = false;
            checkOperator = false;
            sign = none;
            printedNumValue = "";
            value1 = 0;
            value2 = 0;
            ui->inputDisplay->setText("Syntax Error");
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    //check if anything is in inputDisplay when pressed, if not, do nothing and return
    if(firstValues.size() <= 0) return;
    if(firstValues.size() <= 0 && secondValues.size() <= 0 && checkOperator == true){
        //removes the operator
        clear_values();
        printedNumValue = "";
        ui->inputDisplay->setText(printedNumValue);
    }

    //reverse previous input
    //check if removeing a number or an operator sign
    if(valueHalf == printedNumValue && checkOperator == true){
        //removes the operator
        checkOperator = false;
        sign = none;
        printedNumValue = "";
        set_input_display(firstValues);
        ui->inputDisplay->setText(printedNumValue);
    } else if(checkOperator == true) {
        //removes last input for value2

        //check if removing Ans, negative, or a number
        if(secondValues.back() != ans && secondValues.back() != negative){
            double previousInput = std::fmod(value2, 10.0);
            value2 -= previousInput;
            value2 /= 10.0;
            secondValues.pop_back();
            if(secondValues.size() == 0){
                checkNegative2 = false;
                printedNumValue = valueHalf;
            } else {
                printedNumValue = valueHalf;
                set_input_display(secondValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else if(secondValues.back() == ans){
            //removes Ans at back
            //check if Ans if is the only thing in value2
            if(value2 == previousAns && !checkNegative2){
                value2 = 0;
                printedNumValue = valueHalf;
                secondValues.pop_back();
                check_for_ans(secondValues) ? checkAns2 = true : checkAns2 = false;
                ui->inputDisplay->setText(printedNumValue);
            } else if(value2 == previousAns && checkNegative2) {
                value2 = 0;
                printedNumValue = valueHalf + '-';
                secondValues.pop_back();
                check_for_ans(secondValues) ? checkAns2 = true : checkAns2 = false;
                ui->inputDisplay->setText(printedNumValue);
            } else {
                secondValues.pop_back();
                value2 -= previousAns;
                value2 /= 10;
                check_for_ans(secondValues) ? checkAns2 = true : checkAns2 = false;

                printedNumValue = valueHalf;
                set_input_display(secondValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else {
            //removes negative sign at back
            secondValues.pop_back();
            checkNegative2 = !checkNegative2;

            printedNumValue = valueHalf;
            set_input_display(secondValues);
            ui->inputDisplay->setText(printedNumValue);
        }
        ui->inputDisplay->setText(printedNumValue);
    } else {
        //removes last input for value1

        //check if removing Ans, negative, or a number
        if(firstValues.back() != ans && firstValues.back() != negative){
            //removes number at back
            double previousInput = std::fmod(value1, 10.0);
            value1 -= previousInput;
            value1 /= 10;
            firstValues.pop_back();
            //check if the first number was deleted, then reset
            if(firstValues.size() == 0){
                checkNegative1 = false;
                zeroCount = false;
                printedNumValue = "";
                ui->inputDisplay->setText("");
            } else {
                printedNumValue = "";
                set_input_display(firstValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else if(firstValues.back() == ans){
            //removes Ans at back
            //check if Ans is the only thing in value1
            if(value1 == previousAns && !checkNegative1){
                value1 = 0;
                printedNumValue = "";
                firstValues.pop_back();
                check_for_ans(firstValues) ? checkAns2 = true : checkAns2 = false;
                ui->inputDisplay->setText(printedNumValue);
            } else if(value1 == previousAns && checkNegative1) {
                value1 = 0;
                printedNumValue = '-';
                firstValues.pop_back();
                check_for_ans(firstValues) ? checkAns2 = true : checkAns2 = false;
                ui->inputDisplay->setText(printedNumValue);
            } else {
                firstValues.pop_back();
                value1 -= previousAns;
                value1 /= 10;
                check_for_ans(firstValues) ? checkAns2 = true : checkAns2 = false;

                printedNumValue = "";
                set_input_display(firstValues);
                ui->inputDisplay->setText(printedNumValue);
            }
        } else {
            //removes negative sign at back
            firstValues.pop_back();
            checkNegative1 = !checkNegative1;

            printedNumValue = "";
            set_input_display(firstValues);
            ui->inputDisplay->setText(printedNumValue);
        }
    }
}

void MainWindow::on_clearButton_clicked()
{
    clear_values();
    checkAns2 = false;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_allClearButton_clicked()
{
    clear_values();
    clear_saves();
    previousAns = 0;
    checkAns1 = false;
    checkAns2 = false;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_plusSign_clicked()
{
    sign = plus;
    checkOperator = true;
    if(!zeroCount && value1 == 0 && !checkAns2 && checkAns1){
        printedNumValue = "Ans";
        value1 = previousAns;
        firstValues.push_back(ans);
    } else if(!zeroCount && value1 == 0 && !checkAns2){
        printedNumValue = '0';
        firstValues.push_back(0);
    }
    printedNumValue = printedNumValue + " + ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_minusSign_clicked()
{
    sign = minus;
    checkOperator = true;
    if(!zeroCount && value1 == 0 && !checkAns2 && checkAns1){
        printedNumValue = "Ans";
        value1 = previousAns;
    } else if(!zeroCount && value1 == 0 && !checkAns2){
        printedNumValue = '0';
    }
    printedNumValue = printedNumValue + " - ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_multiplySign_clicked()
{
    sign = multiply;
    checkOperator = true;
    if(!zeroCount && value1 == 0 && !checkAns2 && checkAns1){
        printedNumValue = "Ans";
        value1 = previousAns;
    } else if(!zeroCount && value1 == 0 && !checkAns2){
        printedNumValue = '0';
    }
    printedNumValue = printedNumValue + " x ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_divideSign_clicked()
{
    sign = divide;
    checkOperator = true;
    if(!zeroCount && value1 == 0 && !checkAns2 && checkAns1){
        printedNumValue = "Ans";
        value1 = previousAns;
    } else if(!zeroCount && value1 == 0 && !checkAns2){
        printedNumValue = '0';
    }
    printedNumValue = printedNumValue + " ÷ ";
    valueHalf = printedNumValue;
    ui->inputDisplay->setText(printedNumValue);
}

void MainWindow::on_equalsSign_clicked()
{
    //check if Ans was entered without a previous Ans
    if(!checkAns1 && checkAns2)
    {
        clear_values();
        ui->inputDisplay->setText("Ans Does Not Exist");
        checkAns2 = false;
        return;
    }

    if(firstValues.size() > 1 && check_for_ans(firstValues) == true && firstValues.front() != negative){
        clear_values();
        ui->inputDisplay->setText("Syntax Error");
        checkAns2 = false;
        return;
    }
    if(secondValues.size() > 1 && check_for_ans(secondValues) == true && secondValues.front() != negative){
        clear_values();
        ui->inputDisplay->setText("Syntax Error");
        checkAns2 = false;
        return;
    }

    //check if a value is negative
    if(checkNegative1 && value1 > 0){
        value1 -= value1 * 2;
    }
    if(checkNegative2 && value2 > 0){
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
        if(answer - (int)answer > 0 && answer - (int)answer <= 0.0005){
            answer = (int)answer;
        } else if(answer - (int)answer >= 0.9995 && answer - (int)answer < 1){
            answer = (int)answer + 1;
        }
        break;
    case divide:
        if(value2 != 0) {
            answer = value1 / value2;
            //round to the nearest thousandth
            answer = std::round(answer * 10000.0) / 10000.0;
        } else {
            clear_values();
            ui->inputDisplay->setText("Cant Divide by Zero");
            return;
        }
        break;
    default:
        answer = value1;
        break;
    }

    //create a new label for the previous save
    update_and_scroll();

    previousAns = answer;
    checkAns1 = true;
    checkAns2 = false;

    clear_values();
    ui->inputDisplay->setText(printedNumValue);

    previousAns < 0 ? checkNegative1 = true : checkNegative1 = false;
}

