#ifndef ITHREADBASE_H
#define ITHREADBASE_H

#include <QMutex>

////////////////////////////////////////////////////////////////////
//线程对象基类，线程对象继承该类实现线程管理功能
///////////////////////////////////////////////////////////////////
class IThreadBase
{
public:
    virtual void run()=0;   //线程运行处理函数
    virtual void finished()=0;//线程退出处理函数

public:     
    QMutex m_ThreadMutex;  //线程锁，在run函数中必须实现lock和unlock操作
    int m_nPriority;  //优先级
};

#endif // ITHREADBASE_H
