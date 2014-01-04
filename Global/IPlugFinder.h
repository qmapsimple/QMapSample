/*
* Copyright (c) 2013,���ӿ�ѧ�о�Ժ
* All rights reserved.
*
* �ļ����ƣ�IPlugFinder.h
* ժ    Ҫ��������ܽӿ�ͷ�ļ�
*
* �����ߣ�����
* �������ڣ�2013��3��10��
* ������ڣ�2013��10��8��
*
* �޸���  ���޸�������
* �޸���ʼ���ڣ�XXXX��XX��XX��
* �޸�������ڣ�XXXX��XX��XX��
* �޸�������������Ҫ�����Ը��ļ����޸����ݣ���������XX������XX��������* ����XX������XX������
*/

#ifndef PLUGFINDER_H
#define PLUGFINDER_H

#include "IPlugBase.h"

//�����ѯ�ӿ�
class IPlugFinder
{
public:
    ///////////////////////////////////////////////
    //�������ƣ�GetObject
    //����ֵ:bool-��ѯ�������ɹ�
    //������strName-��ѯ�Ĳ������
    //     pPlugBase-���صĲ������
    //����˵������ѯ�������
    ///////////////////////////////////////////////
    virtual bool GetObject(LPSTR strName,IPlugBase** pPlugBase)=0;
};

//���ͨ�Žӿ�
class IPlugMessageControl
{
public:
    ///////////////////////////////////////////////
    //�������ƣ�SendMessage
    //����ֵ:bool-������Ϣ�ɹ�
    //������LPSTR strSend-������
    //     LPSTR strMessage-��Ϣ��
    //     WPARAM wParam-����1
    //     LPARAM lParam-����2
    //����˵�������Ͳ����Ϣ
    ///////////////////////////////////////////////
    virtual bool SendMessage(LPSTR strSend,LPSTR strMessage,WPARAM wParam,LPARAM lParam)=0;

    ///////////////////////////////////////////////
    //�������ƣ�SubMessage
    //����ֵ:bool-������Ϣ�ɹ�
    //������LPSTR strMessage-��Ϣ��
    //     IPlugBase* pPlug-������Ϣ�Ĳ������
    //����˵�������������Ϣ
    ///////////////////////////////////////////////
    virtual bool SubMessage(LPSTR strMsg,IPlugBase* pPlug)=0;//���������Ϣ
};

//�˵�����ӿڣ��ṩ�˵�״̬������غ���
class IMenuControl
{
public:
    ///////////////////////////////////////////////
    //�������ƣ�SetControlStatus
    //����ֵ:��
    //������IPlugBase* pObj-�������
    //     int nComID-�˵�ID
    //     bool bEnable-�Ƿ���ã�true�����ã�false��������
    //����˵�������ò˵��Ƿ����
    ///////////////////////////////////////////////
    virtual void SetControlStatus(IPlugBase* pObj,int nComID,bool bEnable)=0;

    ///////////////////////////////////////////////
    //�������ƣ�SetCheckBoxStatus
    //����ֵ:��
    //������IPlugBase* pObj-�������
    //     int nComID-�˵�ID
    //     bool bChecked-�Ƿ�ѡ�У�true��ѡ�У�false����ѡ��
    //����˵�������ò˵���ѡ���Ƿ�ѡ��
    ///////////////////////////////////////////////
    virtual void SetCheckBoxStatus(IPlugBase* pObj,int nComID,bool bChecked)=0;
};

//�����־�ӿڣ��ṩ�Զ��������־��ӡ����
class ILogPrinter
{
public:
    ///////////////////////////////////////////////
    //�������ƣ�PrinterLog
    //����ֵ:��
    //������IPlugBase* pObj-�������
    //     LPSTR strContent-�����Ϣ����
    //����˵������ӡ������Ϣ
    ///////////////////////////////////////////////
    virtual void PrinterLog(IPlugBase* pObj,LPSTR strContent)=0;
};

//�û�״̬��ѯ�ӿڣ��ṩ�û�Ȩ�޲�ѯ����
class IUserControl
{
public:
    ///////////////////////////////////////////////
    //�������ƣ�GetUserRole
    //����ֵ:��
    //������LPSTR sName-���ص��û���
    //     UINT& nRole-���ص��û�Ȩ��
    //����˵������ȡ�û�Ȩ��
    ///////////////////////////////////////////////
    virtual void GetUserRole(LPSTR sName,uint& nRole)=0;
};

//����״̬��ѯ�ӿڣ��ṩ����״̬��ѯ����
class IWndStateControl
{
public:
    ///////////////////////////////////////////////
    //�������ƣ�GetActiveWndName
    //����ֵ:��
    //������LPSTR sWndName-���������
    //����˵������ȡ���������
    ///////////////////////////////////////////////
    virtual bool GetActiveWndName(LPSTR sWndName)=0;
};

#endif // PLUGFINDER_H
