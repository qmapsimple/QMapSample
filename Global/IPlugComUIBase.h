/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：IPlugComUIBase.h
* 摘    要：界面插件基类头文件
*
*   创建者：刘筱
* 创建日期：2013年3月10日
* 完成日期：2013年10月13日
*
* 修改者  ：修改者名字
* 修改起始日期：XXXX年XX月XX日
* 修改完成日期：XXXX年XX月XX日
* 修改内容描述：简要描述对该文件的修改内容，如增加了XX方法、XX变量，修* 改了XX方法、XX变量。
*/


#ifndef IPLUGCOMUIBASE_H
#define IPLUGCOMUIBASE_H

#include "IPlugBase.h"

#define TYPE_BUTTON_CTRL 1
#define TYPE_CHECKBOX_CTRL 2
#define TYPE_COMBOBOX_CTRL 3
#define TYPE_POPBUTTON_CTRL 4
#define TYPE_EDIT_CTRL 5


//下拉列表数据项结构
typedef struct{
        char sName[100];//名称
        QIcon hIcon;//图标
}ITEM_INFO,*LPITEM_INFO;

//数据项数组
typedef QVector<ITEM_INFO> CITEM_INFOArray;

//控件信息结构
class CTRL_INFO
{
public:
    int nID;//控件ID
    char sName[100];//控件名称
    int nType;//1:按钮，2、复选框，3、下拉列表,4、上级菜单,5、编辑框，
    QIcon hIcon;//控件图标
    bool bEnable;//菜单项是否可用
};
typedef CTRL_INFO* LPCTRL_INFO;


//按钮信息结构
class BTN_INFO : public CTRL_INFO
{
public:
    //////////////////////////////////////////////////////////////////////
    //函数名:BTN_INFO
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    BTN_INFO()
    {
        nType=TYPE_BUTTON_CTRL;
    }
};
typedef BTN_INFO* LPBTN_INFO;

typedef QVector<BTN_INFO> CBTN_INFOArray; //按钮数组

//控件数组
class CLPCTRL_INFOArray : public QVector<LPCTRL_INFO>
{
public:
    //////////////////////////////////////////////////////////////////////
    //函数名:CLPCTRL_INFOArray
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    CLPCTRL_INFOArray()
    {
    }

    //////////////////////////////////////////////////////////////////////
    //函数名:~CLPCTRL_INFOArray()
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    ~CLPCTRL_INFOArray()
    {
    }

    //////////////////////////////////////////////////////////////////////
    //函数名:Clear()
    //返回值：无
    //参数:无
    //函数说明:清空数组，释放内存
    /////////////////////////////////////////////////////////////////////
    void Clear()
    {
        for(int i=0;i<size();i++)
            delete (*this)[i];

        this->clear();
    }
};


//CheckBox控件信息结构
class CHECK_INFO : public CTRL_INFO
{
public:
    bool bCheck;//选中状态

    //////////////////////////////////////////////////////////////////////
    //函数名:CHECK_INFO()
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    CHECK_INFO()
    {
        nType=TYPE_CHECKBOX_CTRL;
    }
};
typedef CHECK_INFO* LPCHECK_INFO;

//COMBOBOX控件结构
class COMBO_INFO : public CTRL_INFO
{
public:
    int nSelItem;//选中项

    //////////////////////////////////////////////////////////////////////
    //函数名:COMBO_INFO()
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    COMBO_INFO()
    {
        nType=TYPE_COMBOBOX_CTRL;     
        nSelItem=0;
        m_arrItems.clear();
    }

    //////////////////////////////////////////////////////////////////////
    //函数名:AddItem()
    //返回值：无
    //参数:QString strItem-项名称
    //    QIcon hIcon-图标
    //函数说明:添加项
    /////////////////////////////////////////////////////////////////////
    void AddItem(QString strItem,QIcon hIcon)//添加项
    {
        ITEM_INFO item;
        memset(&item,0,sizeof(ITEM_INFO));
        QByteArray str1=strItem.toLatin1();
        memcpy(item.sName,str1.data(),str1.size());
        item.hIcon=hIcon;
        m_arrItems.push_back(item);
    }

    CITEM_INFOArray m_arrItems;//选项数组

};
typedef COMBO_INFO* LPCOMBO_INFO;

//弹出按钮信息结构
class POPBTN_INFO : public CTRL_INFO
{
public:
    //////////////////////////////////////////////////////////////////////
    //函数名:POPBTN_INFO()
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    POPBTN_INFO()
    {
        nType=TYPE_POPBUTTON_CTRL;
    }

    //////////////////////////////////////////////////////////////////////
    //函数名:AddBtn()
    //返回值：无
    //参数:int nID-按钮ID
    //     QString strName-按钮名称
    //     QIcon hIcon-按钮图标
    //函数说明:添加下一级按钮
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
    CBTN_INFOArray m_arrBTN;//按钮数组
};
typedef POPBTN_INFO* LPPOPBTN_INFO;

//编辑框信息结构
class EDIT_INFO : public CTRL_INFO
{
public:
    //////////////////////////////////////////////////////////////////////
    //函数名:EDIT_INFO()
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    EDIT_INFO()
    {
        nType=TYPE_EDIT_CTRL;
        nWidth=50;
        memset(sEditText,0,200);
    }
    int nWidth;//宽度

    char sEditText[200];//文本内容
};
typedef EDIT_INFO* LPEDIT_INFO;




////////////////////////////////////////////
//公共控件插件基类
////////////////////////////////////////////
class IPlugComUIBase : public IPlugBase
{
public:
    //////////////////////////////////////////////////////////////////////
    //函数名:ProCommand()
    //返回值：无
    //参数: int nComID-菜单命令ID
    //     LPCTRL_INFO pCtrlInfo-菜单控件状态
    //函数说明:命令处理函数
    /////////////////////////////////////////////////////////////////////
    virtual void ProCommand(int nComID,LPCTRL_INFO pCtrlInfo)=0;

    //////////////////////////////////////////////////////////////////////
    //函数名:IPlugComUIBase()
    //返回值：无
    //参数:无
    //函数说明:构造函数
    /////////////////////////////////////////////////////////////////////
    IPlugComUIBase()
    {
        m_nPoPMenuCount=20000;
    };

    //////////////////////////////////////////////////////////////////////
    //函数名:Release()
    //返回值：无
    //参数:无
    //函数说明:释放函数，清空控件所占用内存
    /////////////////////////////////////////////////////////////////////
    virtual void Release()
    {
        m_arrCtrlInfo.Clear();
    }

protected:
    //////////////////////////////////////////////////////////////////////
    //函数名:InitBtnInfo()
    //返回值：LPBTN_INFO - 按钮信息指针
    //参数:int nID-按钮ID
    //    QString strName-按钮名称
    //    QIcon hIcon-按钮图标
    //函数说明:初始化按钮，用于添加按钮菜单项
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
    //函数名:InitCheckBoxInfo()
    //返回值：LPCHECK_INFO - 复选框信息指针
    //参数:int nID-ID
    //     QString strName-名称
    //     QIcon hIcon-图标
    //     bool bCheck-选中状态
    //函数说明:初始化复选框，用于添加复选框菜单项
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
    //函数名:InitComboInfo()
    //返回值：LPCOMBO_INFO - 复选框信息指针
    //参数:int nID-ID
    //     QString strName-名称
    //函数说明:初始化ComboBox，用于添加ComboBox菜单项
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
    //函数名:InitPopBtnInfo()
    //返回值：LPCOMBO_INFO - Pop菜单信息指针
    //参数:  QString strName-名称
    //      QIcon hIcon-图标
    //函数说明:初始化Pop按钮，用于添加Pop按钮菜单项
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
    //函数名:InitPopBtnInfo()
    //返回值：LPEDIT_INFO - Edit菜单信息指针
    //参数:  int nID-ID
    //      QString strName-名称
    //      int nWidth-宽度
    //函数说明:初始化Edit，用于添加Edit菜单项
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
    //函数名:IsCheckCommand()
    //返回值：bool - 复选框是否选中
    //参数:  int nComID-复选框ID
    //函数说明:判定复选框是否选中
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
    CLPCTRL_INFOArray m_arrCtrlInfo;//空间信息数组


    unsigned int m_nPoPMenuCount;//弹出菜单计数器

};



//界面插件基类
typedef struct{
        IPlugComUIBase* pObj;
        QLibrary* hIns;
        bool bInit;
}PLUGCOMUI_ST,*LPPLUGCOMUI_ST;

#endif // IPLUGCOMUIBASE_H
