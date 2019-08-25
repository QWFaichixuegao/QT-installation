#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QMutex>

class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);
    void doWork();

    void stopThread();

signals:
    void currentProgress(int value );


public slots:


private:
     bool m_isRun = true;
     QMutex *m_mutex;
};

#endif // MYTHREAD_H
