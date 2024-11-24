#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void set_input_display(std::vector<int>& vect);

    void clear_values();

    void clear_saves();

    void update_save_display();

    bool check_for_ans(const std::vector<int>& vect);

    void process_number_input(int num);

    void on_numberOne_clicked();

    void on_numberTwo_clicked();

    void on_numberThree_clicked();

    void on_numberFour_clicked();

    void on_numberFive_clicked();

    void on_numberSix_clicked();

    void on_NumberSeven_clicked();

    void on_numberEight_clicked();

    void on_numberNine_clicked();

    void on_numberZero_clicked();

    void on_clearButton_clicked();

    void on_plusSign_clicked();

    void on_equalsSign_clicked();

    void on_minusSign_clicked();

    void on_multiplySign_clicked();

    void on_divideSign_clicked();

    void on_previousAnswerButton_clicked();

    void on_allClearButton_clicked();

    void on_negativeButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::MainWindow *ui;

    //initialize variables for mainwindow.cpp
    QString printedNumValue = "";
    QString valueHalf = "";

    std::vector<int> firstValues = {};
    std::vector<int> secondValues = {};

    double previousAns = 0;
    double value1 = 0;
    double value2 = 0;
    double answer = 0;
    bool zeroCount = false;
    bool checkAns1 = false;
    bool checkAns2 = false;
    bool checkNegative1 = false;
    bool checkNegative2 = false;
    bool checkOperator = false;
};
#endif // MAINWINDOW_H
