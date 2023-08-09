#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int money {0};

    void change_money(int diff);
    void check_disable();

private slots:
    void on_pB10_clicked();

    void on_pB50_clicked();

    void on_pB100_clicked();

    void on_pB500_clicked();

    void on_pB10000_clicked();

    void on_pBMAX_clicked();

    void on_pBreset_clicked();

    void on_pBcoffee_clicked();

    void on_pBtea_clicked();

    void on_pBmilk_clicked();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
