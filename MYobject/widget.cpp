#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
               qDebug()<<"UI widget ThreadId:"<<QThread::currentThreadId();

        ui->progressBar->setValue(0);


        m_thread = new mythread();
        thread = new QThread();
        m_thread->moveToThread(thread);

        connect(m_thread,&mythread::currentProgress,this,&Widget::receiveProgress);


        connect(this,&Widget::startWork,m_thread,&mythread::doWork);//建立信号和槽的连接


        connect(thread,&QThread::finished,thread,&QThread::deleteLater);
        connect(thread,&QThread::finished,m_thread,&mythread::deleteLater);

}

Widget::~Widget()
{

}
