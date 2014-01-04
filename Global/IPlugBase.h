/*
* Copyright (c) 2013,���ӿ�ѧ�о�Ժ
* All rights reserved.
*
* �ļ����ƣ�PlugBase.h
* ժ    Ҫ����ͨ�������ͷ�ļ�
*
*   �����ߣ�����
* �������ڣ�2013��3��10��
* ������ڣ�2013��9��24��
*
* �޸���  ���޸�������
* �޸���ʼ���ڣ�XXXX��XX��XX��
* �޸�������ڣ�XXXX��XX��XX��
* �޸�������������Ҫ�����Ը��ļ����޸����ݣ���������XX������XX��������* ����XX������XX������
*/

#ifndef PLUGBASE_H
#define PLUGBASE_H


#include "QtCore"
#include "QtGui"
#include "string"
using namespace std;

#ifndef LPSTR
#define LPSTR char*
#endif

#ifndef LRESULT
#define LRESULT unsigned long
#endif

#ifndef LPARAM
#define LPARAM unsigned long
#endif

#ifndef WPARAM
#define WPARAM void*
#endif

#ifndef BOOL
#define BOOL bool
#endif

#include "IPlugInterface.h"
#include "IInterfaceManager.h"

class IPlugFinder;
class IPlugMessageControl;
class IMenuControl;//�˵����ƽӿ�
class ILogPrinter;//��־��ӡ�ӿ�
class IUserControl;//�û���Ϣ��ȡ�ӿ�
class IWndStateControl;//����״̬��ѯ�ӿ�

struct WndInfo
{
    QString strName;
    HWND hWnd;
    int nType;//1:��ͼ��ͼ,2,Web��ͼ,3:���
};

typedef QVector<WndInfo> CWndInfoArray;

class IPlugBase
{
public:
    ///////////////////////////////////////////////
    //�������ƣ�GetIcon
    //����ֵ:HICON-���ͼ��
    //��������
    //����˵�������ز����ͼ��
    ///////////////////////////////////////////////
    virtual QIcon GetIcon()=0;

    ///////////////////////////////////////////////
    //�������ƣ�GetVersion
    //����ֵ:��
    //������LPSTR sVersion-�汾��Ϣ
    //     LPSTR sCompanyAndDate-���������λ���汾����
    //����˵�������ز���İ汾
    ///////////////////////////////////////////////
    virtual void GetPlugInfo(LPSTR sVersion,LPSTR sCompanyAndDate)=0;


    ///////////////////////////////////////////////
    //�������ƣ�Release
    //����ֵ:��
    //��������
    //����˵��������ͷź���
    ///////////////////////////////////////////////
    virtual void Release()
    {

    }

    ///////////////////////////////////////////////
    //�������ƣ�GetName
    //����ֵ:��
    //������LPSTR sName-�������
    //����˵�������ز��������
    ///////////////////////////////////////////////
    virtual void GetName(LPSTR sName)           //���ز������
    {
        QByteArray str1=m_strName.toLocal8Bit();
        memcpy(sName,str1.data(),str1.size());
    }

    ///////////////////////////////////////////////
    //�������ƣ�Init
    //����ֵ:��
    //������ HWND hParent-��������
    //      LPSTR sName-�������
    //      LPSTR sParentWndName-�������������
    //      CWndInfoArray& arrWndInfo-������Ϣ���飨����������Ϣ��
    //����˵�������ز��������
    ///////////////////////////////////////////////
    virtual void Init(HWND hParent,LPSTR sName,LPSTR sParentWndName,CWndInfoArray& arrWndInfo)//�����ʼ������
    {
        m_strName=QString::fromLocal8Bit(sName);
        m_hParent=hParent;
        m_strWndName=QString(sParentWndName);
    }

    ///////////////////////////////////////////////
    //�������ƣ�InitFinished
    //����ֵ:��
    //��������
    //����˵���������ʼ����ɻص����������в����ʼ����ɺ����
    ///////////////////////////////////////////////
    virtual void InitFinished()=0;

    ///////////////////////////////////////////////
    //�������ƣ�ProMessage
    //����ֵ:LRESULT-��Ϣ������� 0����ʾ�ɹ�
    //������LPSTR sSender-������
    //		LPSTR sMessage-��Ϣ����
    //		WPARAM wParam-����1
    //		LPARAM lParam-����2
    //����˵������������Ϣ����
    ///////////////////////////////////////////////
    virtual LRESULT ProMessage(LPSTR sSender,LPSTR sMessage,WPARAM pParam,LPARAM nSize)=0;//��������Ϣ����

    ///////////////////////////////////////////////
    //�������ƣ�ProMainWndMessage
    //����ֵ:LRESULT-��Ϣ������� 0����ʾ�ɹ�
    //������QEvent* pEvent-�¼�����ָ��
    //����˵����������������Ϣ
    ///////////////////////////////////////////////
    virtual LRESULT ProMainWndMessage(QEvent* pEvent)=0;

    ///////////////////////////////////////////////
    //�������ƣ�ProChildWndMessage
    //����ֵ:LRESULT-��Ϣ������� 0����ʾ�ɹ�
    //������QEvent* pEvent-�¼�����ָ��
    //����˵���������Ӵ�����Ϣ
    ///////////////////////////////////////////////
    virtual LRESULT ProChildWndMessage(QString strWndName,QEvent* pEvent)=0;//�����Ӵ�����Ϣ

    ///////////////////////////////////////////////
    //�������ƣ�RegisterAllInterface
    //����ֵ:��
    //��������
    //����˵����ע�����нӿ�
    ///////////////////////////////////////////////
    virtual void RegisterAllInterface()=0;

    ///////////////////////////////////////////////
    //�������ƣ�ProNetMsg
    //����ֵ:��
    //������int nType-��Ϣ����
    //     const string strContent-��Ϣ����
    //����˵��������������Ϣ
    ///////////////////////////////////////////////
    virtual int ProNetMsg(int nType, const string strContent)
    {
        return 0l;
    }


    virtual void WndChanged(LPSTR sWndName)
    {

    }

    ///////////////////////////////////////////////
    //�������ƣ�RegisterInterface
    //����ֵ:��
    //������strName-�ӿ�����
    //      pInterface-�ӿ�
    //����˵����ע�����ӿ�
    ///////////////////////////////////////////////
    bool RegisterInterface(QString strName,IPlugInterface* pInterface)
    {
        bool bRt=false;
        if(m_pInterfaceManager)
        {
            bRt=m_pInterfaceManager->RegisterInterface(strName,pInterface);
        }

        return bRt;
    }

    ///////////////////////////////////////////////
    //�������ƣ�IPlugBase
    //����ֵ:��
    //��������
    //����˵�����๹�캯��
    ///////////////////////////////////////////////
    IPlugBase()
    {
        m_pInterfaceManager=NULL;
    }

    ///////////////////////////////////////////////
    //�������ƣ�SetInterfaceManager
    //����ֵ:��
    //������IInterfaceManager* pInterfaceManager-����ӿڹ������
    //����˵�������ò���ӿڹ������
    ///////////////////////////////////////////////
    void SetInterfaceManager(IInterfaceManager* pInterfaceManager)
    {
        m_pInterfaceManager=pInterfaceManager;
    }

    ///////////////////////////////////////////////
    //�������ƣ�GetInterface
    //����ֵ:��
    //������strName-�ӿ�����
    //      pInterface-�ӿڣ������
    //����˵������ȡ����ӿ�
    ///////////////////////////////////////////////
    void GetInterface(QString strName,IPlugInterface** pInterface)
    {
        if(m_pInterfaceManager)
            m_pInterfaceManager->GetInterface(strName,pInterface);
    }

    ///////////////////////////////////////////////
    //�������ƣ�ClearInterfaceManager
    //����ֵ:��
    //��������
    //����˵�����������ӿڹ������
    ///////////////////////////////////////////////
    void ClearInterfaceManager()
    {
        if(m_pInterfaceManager)
        {
            delete m_pInterfaceManager;
            m_pInterfaceManager=NULL;
        }

    }

    ///////////////////////////////////////////////
    //�������ƣ�SetPlugFinder
    //����ֵ:��
    //������IPlugFinder* pPlugFinder-������Ҷ���
    //����˵�������ò�����ҽӿڶ���
    ///////////////////////////////////////////////
    void SetPlugFinder(IPlugFinder* pPlugFinder)
    {
        m_pPlugFinder=pPlugFinder;
    }

    ///////////////////////////////////////////////
    //�������ƣ�SetPlugMessagerControl
    //����ֵ:��
    //������IPlugMessageControl* pPlugMessagerControl-�����Ϣ���ƶ���
    //����˵�������ò����Ϣ���ƶ���
    ///////////////////////////////////////////////
    void SetPlugMessagerControl(IPlugMessageControl* pPlugMessagerControl)
    {
        m_pPlugMessagerControl=pPlugMessagerControl;
    }

    ///////////////////////////////////////////////
    //�������ƣ�SetMenuControl
    //����ֵ:��
    //������IMenuControl* pMenuControl-�˵����ƽӿڶ���
    //����˵�������ò˵����ƽӿڶ���
    ///////////////////////////////////////////////
    void SetMenuControl(IMenuControl* pMenuControl)
    {
        m_pMenuControl=pMenuControl;
    }

    ///////////////////////////////////////////////
    //�������ƣ�SetLogPrinter
    //����ֵ:��
    //������ILogPrinter* pLogPrinter-��־��ӡ�ӿڶ���
    //����˵����������־��ӡ�ӿڶ���
    ///////////////////////////////////////////////
    void SetLogPrinter(ILogPrinter* pLogPrinter)
    {
        m_pLogPrinter=pLogPrinter;
    }

    ///////////////////////////////////////////////
    //�������ƣ�SetUserControl
    //����ֵ:��
    //������IUserControl* pUserControl-�û���Ϣ��ȡ�ӿڶ���
    //����˵���������û���Ϣ��ȡ�ӿڶ���
    ///////////////////////////////////////////////
    void SetUserControl(IUserControl* pUserControl)
    {
        m_pUserControl=pUserControl;
    }

    ///////////////////////////////////////////////
    //�������ƣ�SetWndStateControl
    //����ֵ:��
    //������IWndStateControl* pWndStateControl-����״̬��ѯ�ӿڶ���
    //����˵�������ô���״̬��ѯ�ӿڶ���
    ///////////////////////////////////////////////
    void SetWndStateControl(IWndStateControl* pWndStateControl)
    {
        m_pWndStateControl=pWndStateControl;
    }
protected:
        IInterfaceManager* m_pInterfaceManager;//����ӿڹ���ָ��

        IPlugFinder* m_pPlugFinder;//�����ѯ�ӿڣ����ڻ�ȡ���
        IPlugMessageControl* m_pPlugMessagerControl;//�����Ϣ����ӿڣ����ڷ��Ͷ��������Ϣ
        IMenuControl* m_pMenuControl;//�˵����ƽӿ�
        ILogPrinter* m_pLogPrinter;//��־��ӡ�ӿ�
        IUserControl* m_pUserControl;//�û���Ϣ��ȡ�ӿ�
        IWndStateControl* m_pWndStateControl;//����״̬��ѯ�ӿ�


        QString m_strName;//�������
        HWND m_hParent;//��������
        QString m_strWndName;//����������
};


//����洢�ṹ
typedef struct{
    IPlugBase* pObj;
    QLibrary* hIns;
}PLUG_ST,*LPPLUG_ST;

#endif // PLUGBASE_H
