/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：PlugBase.h
* 摘    要：普通插件基类头文件
*
*   创建者：刘筱
* 创建日期：2013年3月10日
* 完成日期：2013年9月24日
*
* 修改者  ：修改者名字
* 修改起始日期：XXXX年XX月XX日
* 修改完成日期：XXXX年XX月XX日
* 修改内容描述：简要描述对该文件的修改内容，如增加了XX方法、XX变量，修* 改了XX方法、XX变量。
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
class IMenuControl;//菜单控制接口
class ILogPrinter;//日志打印接口
class IUserControl;//用户信息获取接口
class IWndStateControl;//窗体状态查询接口

struct WndInfo
{
    QString strName;
    HWND hWnd;
    int nType;//1:地图视图,2,Web视图,3:面板
};

typedef QVector<WndInfo> CWndInfoArray;

class IPlugBase
{
public:
    ///////////////////////////////////////////////
    //函数名称：GetIcon
    //返回值:HICON-插件图标
    //参数：无
    //函数说明：返回插件的图标
    ///////////////////////////////////////////////
    virtual QIcon GetIcon()=0;

    ///////////////////////////////////////////////
    //函数名称：GetVersion
    //返回值:无
    //参数：LPSTR sVersion-版本信息
    //     LPSTR sCompanyAndDate-插件制作单位及版本年限
    //函数说明：返回插件的版本
    ///////////////////////////////////////////////
    virtual void GetPlugInfo(LPSTR sVersion,LPSTR sCompanyAndDate)=0;


    ///////////////////////////////////////////////
    //函数名称：Release
    //返回值:无
    //参数：无
    //函数说明：插件释放函数
    ///////////////////////////////////////////////
    virtual void Release()
    {

    }

    ///////////////////////////////////////////////
    //函数名称：GetName
    //返回值:无
    //参数：LPSTR sName-插件名称
    //函数说明：返回插件的名称
    ///////////////////////////////////////////////
    virtual void GetName(LPSTR sName)           //返回插件名称
    {
        QByteArray str1=m_strName.toLocal8Bit();
        memcpy(sName,str1.data(),str1.size());
    }

    ///////////////////////////////////////////////
    //函数名称：Init
    //返回值:无
    //参数： HWND hParent-父窗体句柄
    //      LPSTR sName-插件名称
    //      LPSTR sParentWndName-插件父窗体名称
    //      CWndInfoArray& arrWndInfo-窗体信息数组（定购窗体消息）
    //函数说明：返回插件的名称
    ///////////////////////////////////////////////
    virtual void Init(HWND hParent,LPSTR sName,LPSTR sParentWndName,CWndInfoArray& arrWndInfo)//插件初始化函数
    {
        m_strName=QString::fromLocal8Bit(sName);
        m_hParent=hParent;
        m_strWndName=QString(sParentWndName);
    }

    ///////////////////////////////////////////////
    //函数名称：InitFinished
    //返回值:无
    //参数：无
    //函数说明：插件初始化完成回调函数，所有插件初始化完成后调用
    ///////////////////////////////////////////////
    virtual void InitFinished()=0;

    ///////////////////////////////////////////////
    //函数名称：ProMessage
    //返回值:LRESULT-消息处理情况 0：表示成功
    //参数：LPSTR sSender-发送者
    //		LPSTR sMessage-消息名称
    //		WPARAM wParam-参数1
    //		LPARAM lParam-参数2
    //函数说明：处理插件消息函数
    ///////////////////////////////////////////////
    virtual LRESULT ProMessage(LPSTR sSender,LPSTR sMessage,WPARAM pParam,LPARAM nSize)=0;//处理插件消息函数

    ///////////////////////////////////////////////
    //函数名称：ProMainWndMessage
    //返回值:LRESULT-消息处理情况 0：表示成功
    //参数：QEvent* pEvent-事件对象指针
    //函数说明：处理主窗口消息
    ///////////////////////////////////////////////
    virtual LRESULT ProMainWndMessage(QEvent* pEvent)=0;

    ///////////////////////////////////////////////
    //函数名称：ProChildWndMessage
    //返回值:LRESULT-消息处理情况 0：表示成功
    //参数：QEvent* pEvent-事件对象指针
    //函数说明：处理子窗口消息
    ///////////////////////////////////////////////
    virtual LRESULT ProChildWndMessage(QString strWndName,QEvent* pEvent)=0;//处理子窗口消息

    ///////////////////////////////////////////////
    //函数名称：RegisterAllInterface
    //返回值:无
    //参数：无
    //函数说明：注册所有接口
    ///////////////////////////////////////////////
    virtual void RegisterAllInterface()=0;

    ///////////////////////////////////////////////
    //函数名称：ProNetMsg
    //返回值:无
    //参数：int nType-消息类型
    //     const string strContent-消息内容
    //函数说明：处理网络消息
    ///////////////////////////////////////////////
    virtual int ProNetMsg(int nType, const string strContent)
    {
        return 0l;
    }


    virtual void WndChanged(LPSTR sWndName)
    {

    }

    ///////////////////////////////////////////////
    //函数名称：RegisterInterface
    //返回值:无
    //参数：strName-接口名称
    //      pInterface-接口
    //函数说明：注册插件接口
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
    //函数名称：IPlugBase
    //返回值:无
    //参数：无
    //函数说明：类构造函数
    ///////////////////////////////////////////////
    IPlugBase()
    {
        m_pInterfaceManager=NULL;
    }

    ///////////////////////////////////////////////
    //函数名称：SetInterfaceManager
    //返回值:无
    //参数：IInterfaceManager* pInterfaceManager-插件接口管理对象
    //函数说明：设置插件接口管理对象
    ///////////////////////////////////////////////
    void SetInterfaceManager(IInterfaceManager* pInterfaceManager)
    {
        m_pInterfaceManager=pInterfaceManager;
    }

    ///////////////////////////////////////////////
    //函数名称：GetInterface
    //返回值:无
    //参数：strName-接口名称
    //      pInterface-接口（输出）
    //函数说明：获取插件接口
    ///////////////////////////////////////////////
    void GetInterface(QString strName,IPlugInterface** pInterface)
    {
        if(m_pInterfaceManager)
            m_pInterfaceManager->GetInterface(strName,pInterface);
    }

    ///////////////////////////////////////////////
    //函数名称：ClearInterfaceManager
    //返回值:无
    //参数：无
    //函数说明：清理插件接口管理对象
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
    //函数名称：SetPlugFinder
    //返回值:无
    //参数：IPlugFinder* pPlugFinder-插件查找对象
    //函数说明：设置插件查找接口对象
    ///////////////////////////////////////////////
    void SetPlugFinder(IPlugFinder* pPlugFinder)
    {
        m_pPlugFinder=pPlugFinder;
    }

    ///////////////////////////////////////////////
    //函数名称：SetPlugMessagerControl
    //返回值:无
    //参数：IPlugMessageControl* pPlugMessagerControl-插件消息控制对象
    //函数说明：设置插件消息控制对象
    ///////////////////////////////////////////////
    void SetPlugMessagerControl(IPlugMessageControl* pPlugMessagerControl)
    {
        m_pPlugMessagerControl=pPlugMessagerControl;
    }

    ///////////////////////////////////////////////
    //函数名称：SetMenuControl
    //返回值:无
    //参数：IMenuControl* pMenuControl-菜单控制接口对象
    //函数说明：设置菜单控制接口对象
    ///////////////////////////////////////////////
    void SetMenuControl(IMenuControl* pMenuControl)
    {
        m_pMenuControl=pMenuControl;
    }

    ///////////////////////////////////////////////
    //函数名称：SetLogPrinter
    //返回值:无
    //参数：ILogPrinter* pLogPrinter-日志打印接口对象
    //函数说明：设置日志打印接口对象
    ///////////////////////////////////////////////
    void SetLogPrinter(ILogPrinter* pLogPrinter)
    {
        m_pLogPrinter=pLogPrinter;
    }

    ///////////////////////////////////////////////
    //函数名称：SetUserControl
    //返回值:无
    //参数：IUserControl* pUserControl-用户信息获取接口对象
    //函数说明：设置用户信息获取接口对象
    ///////////////////////////////////////////////
    void SetUserControl(IUserControl* pUserControl)
    {
        m_pUserControl=pUserControl;
    }

    ///////////////////////////////////////////////
    //函数名称：SetWndStateControl
    //返回值:无
    //参数：IWndStateControl* pWndStateControl-窗体状态查询接口对象
    //函数说明：设置窗体状态查询接口对象
    ///////////////////////////////////////////////
    void SetWndStateControl(IWndStateControl* pWndStateControl)
    {
        m_pWndStateControl=pWndStateControl;
    }
protected:
        IInterfaceManager* m_pInterfaceManager;//插件接口管理指针

        IPlugFinder* m_pPlugFinder;//插件查询接口，用于获取插件
        IPlugMessageControl* m_pPlugMessagerControl;//插件消息管理接口，用于发送定购插件消息
        IMenuControl* m_pMenuControl;//菜单控制接口
        ILogPrinter* m_pLogPrinter;//日志打印接口
        IUserControl* m_pUserControl;//用户信息获取接口
        IWndStateControl* m_pWndStateControl;//窗体状态查询接口


        QString m_strName;//插件名称
        HWND m_hParent;//父窗体句柄
        QString m_strWndName;//父窗体名称
};


//插件存储结构
typedef struct{
    IPlugBase* pObj;
    QLibrary* hIns;
}PLUG_ST,*LPPLUG_ST;

#endif // PLUGBASE_H
