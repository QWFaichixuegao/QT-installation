#include "mythread.h"

#include <QDebug>

#include <QThread>

mythread::mythread(QObject *parent) : QObject(parent)
{
    qDebug()<<"construction ThreadID:"<<QThread::currentThreadId();
      m_mutex = new QMutex();

}

void mythread::doWork()
{
    for(int i = 0;i<=100;i+=10)
    {
        if(!m_isRun)
            return;

        qDebug()<<"doWork() ThreadID:"<<QThread::currentThreadId();

        emit currentProgress(i);

        QThread::msleep(200);
    }

    qDebug()<<"doWork over";

}


void mythread::stopThread()
{
    QMutexLocker(*m_mutex);
    m_isRun = false;
}









