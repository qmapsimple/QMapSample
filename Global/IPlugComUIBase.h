/*
* Copyright (c) 2013,���ӿ�ѧ�о�Ժ
* All rights reserved.
*
* �ļ����ƣ�IPlugComUIBase.h
* ժ    Ҫ������������ͷ�ļ�
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


#ifndef IPLUGCOMUIBASE_H
#define IPLUGCOMUIBASE_H

#include "IPlugBase.h"

#define TYPE_BUTTON_CTRL 1
#define TYPE_CHECKBOX_CTRL 2
#define TYPE_COMBOBOX_CTRL 3
#define TYPE_POPBUTTON_CTRL 4
#define TYPE_EDIT_CTRL 5


//�����б�������ṹ
typedef struct{
        char sName[100];//����
        QIcon hIcon;//ͼ��
}ITEM_INFO,*LPITEM_INFO;

//����������
typedef QVector<ITEM_INFO> CITEM_INFOArray;

//�ؼ���Ϣ�ṹ
class CTRL_INFO
{
public:
    int nID;//�ؼ�ID
    char sName[100];//�ؼ�����
    int nType;//1:��ť��2����ѡ��3�������б�,4���ϼ��˵�,5���༭��
    QIcon hIcon;//�ؼ�ͼ��
    bool bEnable;//�˵����Ƿ����
};
typedef CTRL_INFO* LPCTRL_INFO;


//��ť��Ϣ�ṹ
class BTN_INFO : public CTRL_INFO
{
public:
    //////////////////////////////////////////////////////////////////////
    //������:BTN_INFO
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    BTN_INFO()
    {
        nType=TYPE_BUTTON_CTRL;
    }
};
typedef BTN_INFO* LPBTN_INFO;

typedef QVector<BTN_INFO> CBTN_INFOArray; //��ť����

//�ؼ�����
class CLPCTRL_INFOArray : public QVector<LPCTRL_INFO>
{
public:
    //////////////////////////////////////////////////////////////////////
    //������:CLPCTRL_INFOArray
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    CLPCTRL_INFOArray()
    {
    }

    //////////////////////////////////////////////////////////////////////
    //������:~CLPCTRL_INFOArray()
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    ~CLPCTRL_INFOArray()
    {
    }

    //////////////////////////////////////////////////////////////////////
    //������:Clear()
    //����ֵ����
    //����:��
    //����˵��:������飬�ͷ��ڴ�
    /////////////////////////////////////////////////////////////////////
    void Clear()
    {
        for(int i=0;i<size();i++)
            delete (*this)[i];

        this->clear();
    }
};


//CheckBox�ؼ���Ϣ�ṹ
class CHECK_INFO : public CTRL_INFO
{
public:
    bool bCheck;//ѡ��״̬

    //////////////////////////////////////////////////////////////////////
    //������:CHECK_INFO()
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    CHECK_INFO()
    {
        nType=TYPE_CHECKBOX_CTRL;
    }
};
typedef CHECK_INFO* LPCHECK_INFO;

//COMBOBOX�ؼ��ṹ
class COMBO_INFO : public CTRL_INFO
{
public:
    int nSelItem;//ѡ����

    //////////////////////////////////////////////////////////////////////
    //������:COMBO_INFO()
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    COMBO_INFO()
    {
        nType=TYPE_COMBOBOX_CTRL;     
        nSelItem=0;
        m_arrItems.clear();
    }

    //////////////////////////////////////////////////////////////////////
    //������:AddItem()
    //����ֵ����
    //����:QString strItem-������
    //    QIcon hIcon-ͼ��
    //����˵��:�����
    /////////////////////////////////////////////////////////////////////
    void AddItem(QString strItem,QIcon hIcon)//�����
    {
        ITEM_INFO item;
        memset(&item,0,sizeof(ITEM_INFO));
        QByteArray str1=strItem.toLatin1();
        memcpy(item.sName,str1.data(),str1.size());
        item.hIcon=hIcon;
        m_arrItems.push_back(item);
    }

    CITEM_INFOArray m_arrItems;//ѡ������

};
typedef COMBO_INFO* LPCOMBO_INFO;

//������ť��Ϣ�ṹ
class POPBTN_INFO : public CTRL_INFO
{
public:
    //////////////////////////////////////////////////////////////////////
    //������:POPBTN_INFO()
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    POPBTN_INFO()
    {
        nType=TYPE_POPBUTTON_CTRL;
    }

    //////////////////////////////////////////////////////////////////////
    //������:AddBtn()
    //����ֵ����
    //����:int nID-��ťID
    //     QString strName-��ť����
    //     QIcon hIcon-��ťͼ��
    //����˵��:�����һ����ť
    /////////////////////////////////////////////////////////////////////
    void AddBtn(int nID,QString strName,QIcon hIcon)
    {
        BTN_INFO btn;
        memset(&btn,0,sizeof(BTN_INFO));
        btn.nID=nID;
        btn.hIcon=hIcon;
        QByteArray str1=strName.toLatin1();
        memcpy(btn.sName,str1.data(),str1.size());
        m_arrBTN.push_back(btn);
    }
public:
    CBTN_INFOArray m_arrBTN;//��ť����
};
typedef POPBTN_INFO* LPPOPBTN_INFO;

//�༭����Ϣ�ṹ
class EDIT_INFO : public CTRL_INFO
{
public:
    //////////////////////////////////////////////////////////////////////
    //������:EDIT_INFO()
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    EDIT_INFO()
    {
        nType=TYPE_EDIT_CTRL;
        nWidth=50;
        memset(sEditText,0,200);
    }
    int nWidth;//���

    char sEditText[200];//�ı�����
};
typedef EDIT_INFO* LPEDIT_INFO;




////////////////////////////////////////////
//�����ؼ��������
////////////////////////////////////////////
class IPlugComUIBase : public IPlugBase
{
public:
    //////////////////////////////////////////////////////////////////////
    //������:ProCommand()
    //����ֵ����
    //����: int nComID-�˵�����ID
    //     LPCTRL_INFO pCtrlInfo-�˵��ؼ�״̬
    //����˵��:�������
    /////////////////////////////////////////////////////////////////////
    virtual void ProCommand(int nComID,LPCTRL_INFO pCtrlInfo)=0;

    //////////////////////////////////////////////////////////////////////
    //������:IPlugComUIBase()
    //����ֵ����
    //����:��
    //����˵��:���캯��
    /////////////////////////////////////////////////////////////////////
    IPlugComUIBase()
    {
        m_nPoPMenuCount=20000;
    };

    //////////////////////////////////////////////////////////////////////
    //������:Release()
    //����ֵ����
    //����:��
    //����˵��:�ͷź�������տؼ���ռ���ڴ�
    /////////////////////////////////////////////////////////////////////
    virtual void Release()
    {
        m_arrCtrlInfo.Clear();
    }

protected:
    //////////////////////////////////////////////////////////////////////
    //������:InitBtnInfo()
    //����ֵ��LPBTN_INFO - ��ť��Ϣָ��
    //����:int nID-��ťID
    //    QString strName-��ť����
    //    QIcon hIcon-��ťͼ��
    //����˵��:��ʼ����ť��������Ӱ�ť�˵���
    /////////////////////////////////////////////////////////////////////
    LPBTN_INFO InitBtnInfo(int nID,QString strName,QIcon hIcon)
    {
        LPBTN_INFO pBtnInfo=new BTN_INFO;
        pBtnInfo->nID=nID;
        pBtnInfo->nType=TYPE_BUTTON_CTRL;
        pBtnInfo->hIcon=hIcon;
        pBtnInfo->bEnable=true;
        memset(pBtnInfo->sName,0,100);
        QByteArray str1=strName.toLocal8Bit();
        memcpy(pBtnInfo->sName,str1.data(),str1.size());
        m_arrCtrlInfo.push_back(pBtnInfo);
        return pBtnInfo;
    }

    //////////////////////////////////////////////////////////////////////
    //������:InitCheckBoxInfo()
    //����ֵ��LPCHECK_INFO - ��ѡ����Ϣָ��
    //����:int nID-ID
    //     QString strName-����
    //     QIcon hIcon-ͼ��
    //     bool bCheck-ѡ��״̬
    //����˵��:��ʼ����ѡ��������Ӹ�ѡ��˵���
    /////////////////////////////////////////////////////////////////////
    LPCHECK_INFO InitCheckBoxInfo(int nID,QString strName,QIcon hIcon,bool bCheck)
    {
        LPCHECK_INFO pCheckInfo=new CHECK_INFO;
        pCheckInfo->nID=nID;
        pCheckInfo->nType=TYPE_CHECKBOX_CTRL;
        pCheckInfo->bCheck=bCheck;
        pCheckInfo->hIcon=hIcon;
        pCheckInfo->bEnable=true;
        memset(pCheckInfo->sName,0,100);
        QByteArray str1=strName.toLocal8Bit();
        memcpy(pCheckInfo->sName,str1.data(),str1.size());
        m_arrCtrlInfo.push_back(pCheckInfo);
        return pCheckInfo;
    }

    //////////////////////////////////////////////////////////////////////
    //������:InitComboInfo()
    //����ֵ��LPCOMBO_INFO - ��ѡ����Ϣָ��
    //����:int nID-ID
    //     QString strName-����
    //����˵��:��ʼ��ComboBox���������ComboBox�˵���
    /////////////////////////////////////////////////////////////////////
    LPCOMBO_INFO InitComboInfo(int nID,QString strName)//
    {
        LPCOMBO_INFO pComboInfo=new COMBO_INFO;
        pComboInfo->nID=nID;
        pComboInfo->nType=TYPE_COMBOBOX_CTRL;
        pComboInfo->bEnable=true;
        memset(pComboInfo->sName,0,100);
        QByteArray str1=strName.toLocal8Bit();
        memcpy(pComboInfo->sName,str1.data(),str1.size());
        m_arrCtrlInfo.push_back(pComboInfo);
        return pComboInfo;
    }

    //////////////////////////////////////////////////////////////////////
    //������:InitPopBtnInfo()
    //����ֵ��LPCOMBO_INFO - Pop�˵���Ϣָ��
    //����:  QString strName-����
    //      QIcon hIcon-ͼ��
    //����˵��:��ʼ��Pop��ť���������Pop��ť�˵���
    /////////////////////////////////////////////////////////////////////
    LPPOPBTN_INFO InitPopBtnInfo(QString strName,QIcon hIcon)//
    {
        m_nPoPMenuCount++;
        LPPOPBTN_INFO pBtnInfo=new POPBTN_INFO;
        pBtnInfo->nID=m_nPoPMenuCount;
        pBtnInfo->hIcon=hIcon;
        pBtnInfo->nType=TYPE_POPBUTTON_CTRL;
        pBtnInfo->bEnable=true;
        memset(pBtnInfo->sName,0,100);
        QByteArray str1=strName.toLocal8Bit();
        memcpy(pBtnInfo->sName,str1.data(),str1.size());
        m_arrCtrlInfo.push_back(pBtnInfo);
        return pBtnInfo;
    }

    //////////////////////////////////////////////////////////////////////
    //������:InitPopBtnInfo()
    //����ֵ��LPEDIT_INFO - Edit�˵���Ϣָ��
    //����:  int nID-ID
    //      QString strName-����
    //      int nWidth-���
    //����˵��:��ʼ��Edit���������Edit�˵���
    /////////////////////////////////////////////////////////////////////
    LPEDIT_INFO InitEditInfo(int nID,QString strName,int nWidth)
    {
        LPEDIT_INFO pEditInfo=new EDIT_INFO;
        pEditInfo->nID=nID;     
        pEditInfo->nType=TYPE_EDIT_CTRL;
        pEditInfo->nWidth=nWidth;
        pEditInfo->bEnable=true;
        memset(pEditInfo->sName,0,100);
        QByteArray str1=strName.toLocal8Bit();
        memcpy(pEditInfo->sName,str1.data(),str1.size());
        m_arrCtrlInfo.push_back(pEditInfo);
        return pEditInfo;
    }


public:
    //////////////////////////////////////////////////////////////////////
    //������:IsCheckCommand()
    //����ֵ��bool - ��ѡ���Ƿ�ѡ��
    //����:  int nComID-��ѡ��ID
    //����˵��:�ж���ѡ���Ƿ�ѡ��
    /////////////////////////////////////////////////////////////////////
    virtual bool IsCheckCommand(int nComID)
    {
        bool bRet=TRUE;
        for(int i=0;i<m_arrCtrlInfo.size();i++)
        {
            if( m_arrCtrlInfo[i]->nType == TYPE_CHECKBOX_CTRL )
            {
                LPCHECK_INFO pCheckInfo=(LPCHECK_INFO)m_arrCtrlInfo[i];

                if(pCheckInfo->nID==nComID)
                {
                    bRet=pCheckInfo->bCheck;
                    break;
                }
            }
        }

        return bRet;
    }

public:
    CLPCTRL_INFOArray m_arrCtrlInfo;//�ռ���Ϣ����


    unsigned int m_nPoPMenuCount;//�����˵�������

};



//����������
typedef struct{
        IPlugComUIBase* pObj;
        QLibrary* hIns;
        bool bInit;
}PLUGCOMUI_ST,*LPPLUGCOMUI_ST;

#endif // IPLUGCOMUIBASE_H
