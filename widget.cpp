#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    check_disable();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::change_money(int diff)
{
    QMessageBox mb;

    if ((money + diff) >= 0) {
        money += diff;
    }
    else{
        // error
        mb.information(nullptr, "title", "error");
    }

    ui->lcdNumber->display(money);
}

void Widget::check_disable()
{
    if (money < 100) {
        ui->pBcoffee->setEnabled(false);
        ui->pBtea->setEnabled(false);
        ui->pBmilk->setEnabled(false);
    }
    else if (money < 150) {
        ui->pBcoffee->setEnabled(true);
        ui->pBtea->setEnabled(false);
        ui->pBmilk->setEnabled(false);
    }
    else if (money < 200) {
        ui->pBcoffee->setEnabled(true);
        ui->pBtea->setEnabled(true);
        ui->pBmilk->setEnabled(false);
    }
    else {
        ui->pBcoffee->setEnabled(true);
        ui->pBtea->setEnabled(true);
        ui->pBmilk->setEnabled(true);
    }
}

void Widget::on_pB10_clicked()
{
    change_money(10);
    check_disable();
}


void Widget::on_pB50_clicked()
{
    change_money(50);
    check_disable();
}


void Widget::on_pB100_clicked()
{
    change_money(100);
    check_disable();
}


void Widget::on_pB500_clicked()
{
    change_money(500);
    check_disable();
}


void Widget::on_pB10000_clicked()
{
    change_money(10000);
    check_disable();
}


void Widget::on_pBMAX_clicked()
{
    money = 99999;
    ui->lcdNumber->display(money);
    check_disable();
}


void Widget::on_pBreset_clicked()
{
    QMessageBox mb;

    int num500 = 0;
    int num100 = 0;
    int num50 = 0;
    int num10 = 0;
    while (money >= 500) {
        money -= 500;
        num500++;
    }
    while (money >= 100) {
        money -= 100;
        num100++;
    }
    while (money >= 50) {
        money -= 50;
        num50++;
    }
    while (money >= 10) {
        money -= 10;
        num10++;
    }

    QString coins_info = QString("500won: %1 coins \t100won: %2 coins \n50won: %3 coins\t10won: %4 coins").arg(QString::number(num500)).arg(QString::number(num100)).arg(QString::number(num50)).arg(QString::number(num10));
    mb.information(nullptr, "title", coins_info);

    money = 0;
    ui->lcdNumber->display(money);
    check_disable();
}


void Widget::on_pBcoffee_clicked()
{
    change_money(-100);
    check_disable();
}


void Widget::on_pBtea_clicked()
{
    change_money(-150);
    check_disable();
}


void Widget::on_pBmilk_clicked()
{
    change_money(-200);
    check_disable();
}

