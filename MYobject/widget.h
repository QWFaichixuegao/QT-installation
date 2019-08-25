#ifndef WIDGET_H
#define WIDGET_H
#include "mythread.h"
#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();


signals:
    void startWork();

private slots:

    void receiveProgress(int value);

    void on_doWorkButton_clicked();

private:
    Ui::Widget *ui;
    QThread* thread;
    mythread* m_thread;
};

#endif // WIDGET_H
