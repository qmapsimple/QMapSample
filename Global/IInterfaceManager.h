/*
* Copyright (c) 2013,���ӿ�ѧ�о�Ժ
* All rights reserved.
*
* �ļ����ƣ�IInterfaceManager.h
* ժ    Ҫ���ӿڹ�����ӿ�ͷ�ļ�
*
*   �����ߣ�����
* �������ڣ�2013��3��10��
* ������ڣ�2013��10��13��
*
* �޸���  ���޸�������
* �޸���ʼ���ڣ�XXXX��XX��XX��
* �޸�������ڣ�XXXX��XX��XX��
* �޸�������������Ҫ�����Ը��ļ����޸����ݣ���������XX������XX��������* ����XX������XX������
*/

#ifndef IINTERFACEMANAGER_H
#define IINTERFACEMANAGER_H

#include "QtCore"

class IPlugInterface;

//�ӿڹ�����ӿ�
class IInterfaceManager
{
public:
        ///////////////////////////////////////////////
        //�������ƣ�RegisterInterface
        //����ֵ:��
        //������strName-�ӿ�����
        //      pInterface-�ӿ�
        //����˵����ע�����ӿ�
    ///////////////////////////////////////////////
        virtual bool RegisterInterface(QString strName,IPlugInterface* pInterface)=0;

        ///////////////////////////////////////////////
        //�������ƣ�GetInterface
        //����ֵ:��
        //������strName-�ӿ�����
        //      pInterface-�ӿڣ������
        //����˵������ȡ����ӿ�
    ///////////////////////////////////////////////
        virtual void GetInterface(QString strName,IPlugInterface** pInterface)=0;

};

#endif // INTERFACEMANAGER_H
