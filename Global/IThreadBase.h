#ifndef ITHREADBASE_H
#define ITHREADBASE_H

#include <QMutex>

////////////////////////////////////////////////////////////////////
//�̶߳�����࣬�̶߳���̳и���ʵ���̹߳�����
///////////////////////////////////////////////////////////////////
class IThreadBase
{
public:
    virtual void run()=0;   //�߳����д�����
    virtual void finished()=0;//�߳��˳�������

public:     
    QMutex m_ThreadMutex;  //�߳�������run�����б���ʵ��lock��unlock����
    int m_nPriority;  //���ȼ�
};

#endif // ITHREADBASE_H
