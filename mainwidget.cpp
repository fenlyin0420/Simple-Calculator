#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QDebug>
bool isNum(QChar ch);
bool isOperator(QChar ch);
int level(QChar ch);

double getValue(double a, QChar op, double b);


bool isNum(QChar ch){
    if (('0' <= ch && ch <= '9') || ch == '.')
        return true;
    return false;
}

bool isOperator(QChar ch){
    if (ch == '+' || ch == '-' || ch == 'x' || ch == '/' || '#')
        return true;
    return false;
}
double getValue(double a, QChar op, double b){
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == 'x')
        return a * b;
    else
        return a / b;
}

int level(QChar ch){
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch =='x' || ch == '/')
        return 2;
    else
        return 0;
}


/** Calculator 类成员函数的定义 */
Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_pushButton_0_clicked()
{
    if (strInput == "")
        strInput = "0";
    else
        strInput += "0";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_dot_clicked()
{
    if (strInput == "")
        strInput = ".";
    else
        strInput += ".";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_evl_clicked()
{
    QStack<QChar> optr;
    QStack<double> oprand;
    double a, b;
    QChar op;
    QString numStr="";
    strInput += '#';

    for (int i = 0; i < strInput.size(); ++i){
        QChar ch = strInput[i];
        if (isNum(ch))
            numStr += ch;

        else if (isOperator(ch)){
            oprand.push(numStr.toDouble());
            numStr = "";

        lable:
            if (optr.empty())
                optr.push(ch);
            else {
                if (level(ch) > level(optr.top())){
                    optr.push(ch);
                }
                else {
                    b = oprand.top(); oprand.pop();
                    a = oprand.top(); oprand.pop();
                    op = optr.top(); optr.pop();
                    oprand.push(getValue(a, op, b));
                    goto lable;
                }
            }
        }
    }
    strInput = QString::number(oprand.top());
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_add_clicked()
{
    if (strInput == "")
        strInput = "+";
    else
        strInput += "+";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_1_clicked()
{
    if (strInput == "")
        strInput = "1";
    else
        strInput += "1";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_2_clicked()
{
    if (strInput == "")
        strInput = "2";
    else
        strInput += "2";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_3_clicked()
{
    if (strInput == "")
        strInput = "3";
    else
        strInput += "3";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_sub_clicked()
{
    if (strInput == "")
        strInput = "-";
    else
        strInput += "-";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_4_clicked()
{
    if (strInput == "")
        strInput = "4";
    else
        strInput += "4";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_5_clicked()
{
    if (strInput == "")
        strInput = "5";
    else
        strInput += "5";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_6_clicked()
{
    if (strInput == "")
        strInput = "6";
    else
        strInput += "6";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_mul_clicked()
{
    if (strInput == "")
        strInput = "x";
    else
        strInput += "x";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_7_clicked()
{
    if (strInput == "")
        strInput = "7";
    else
        strInput += "7";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_8_clicked()
{
    if (strInput == "")
        strInput = "8";
    else
        strInput += "8";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_9_clicked()
{
    if (strInput == "")
        strInput = "9";
    else
        strInput += "9";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_div_clicked()
{
    if (strInput == "")
        strInput = "/";
    else
        strInput += "/";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_left_clicked()
{
    if (strInput == "")
        strInput = "(";
    else
        strInput += "(";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_right_clicked()
{
    if (strInput == "")
        strInput = ")";
    else
        strInput += ")";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_AC_clicked()
{
    strInput = "";
    ui->display->setText(strInput);
}

void Calculator::on_pushButton_CE_clicked()
{
    if (strInput == "")
        ;
    else
        strInput.chop(1);
    ui->display->setText(strInput);
}
