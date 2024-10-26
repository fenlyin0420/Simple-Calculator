#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QString>
#include <QStack>
#include <QTime>
#include <QLineEdit>

using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWidget;
}
QT_END_NAMESPACE

class Calculator : public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    QString strInput="";
    bool flags = false;


private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_dot_clicked();

    void on_pushButton_evl_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_mul_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    void on_pushButton_AC_clicked();

    void on_pushButton_CE_clicked();

private:
    Ui::MainWidget *ui;
};
#endif // MAINWIDGET_H
