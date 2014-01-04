/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：IPlugFinder.h
* 摘    要：插件功能接口头文件
*
* 创建者：刘筱
* 创建日期：2013年3月10日
* 完成日期：2013年10月8日
*
* 修改者  ：修改者名字
* 修改起始日期：XXXX年XX月XX日
* 修改完成日期：XXXX年XX月XX日
* 修改内容描述：简要描述对该文件的修改内容，如增加了XX方法、XX变量，修* 改了XX方法、XX变量。
*/

#ifndef PLUGFINDER_H
#define PLUGFINDER_H

#include "IPlugBase.h"

//插件查询接口
class IPlugFinder
{
public:
    ///////////////////////////////////////////////
    //函数名称：GetObject
    //返回值:bool-查询插件对象成功
    //参数：strName-查询的插件名称
    //     pPlugBase-返回的插件对象
    //函数说明：查询插件对象
    ///////////////////////////////////////////////
    virtual bool GetObject(LPSTR strName,IPlugBase** pPlugBase)=0;
};

//插件通信接口
class IPlugMessageControl
{
public:
    ///////////////////////////////////////////////
    //函数名称：SendMessage
    //返回值:bool-发送消息成功
    //参数：LPSTR strSend-发送者
    //     LPSTR strMessage-消息名
    //     WPARAM wParam-参数1
    //     LPARAM lParam-参数2
    //函数说明：发送插件消息
    ///////////////////////////////////////////////
    virtual bool SendMessage(LPSTR strSend,LPSTR strMessage,WPARAM wParam,LPARAM lParam)=0;

    ///////////////////////////////////////////////
    //函数名称：SubMessage
    //返回值:bool-定购消息成功
    //参数：LPSTR strMessage-消息名
    //     IPlugBase* pPlug-定购消息的插件对象
    //函数说明：定购插件消息
    ///////////////////////////////////////////////
    virtual bool SubMessage(LPSTR strMsg,IPlugBase* pPlug)=0;//定购插件消息
};

//菜单管理接口，提供菜单状态设置相关函数
class IMenuControl
{
public:
    ///////////////////////////////////////////////
    //函数名称：SetControlStatus
    //返回值:无
    //参数：IPlugBase* pObj-插件对象
    //     int nComID-菜单ID
    //     bool bEnable-是否可用，true：可用，false：不可用
    //函数说明：设置菜单是否可用
    ///////////////////////////////////////////////
    virtual void SetControlStatus(IPlugBase* pObj,int nComID,bool bEnable)=0;

    ///////////////////////////////////////////////
    //函数名称：SetCheckBoxStatus
    //返回值:无
    //参数：IPlugBase* pObj-插件对象
    //     int nComID-菜单ID
    //     bool bChecked-是否选中，true：选中，false：不选中
    //函数说明：设置菜单复选框是否选中
    ///////////////////////////////////////////////
    virtual void SetCheckBoxStatus(IPlugBase* pObj,int nComID,bool bChecked)=0;
};

//插件日志接口，提供自定义调试日志打印函数
class ILogPrinter
{
public:
    ///////////////////////////////////////////////
    //函数名称：PrinterLog
    //返回值:无
    //参数：IPlugBase* pObj-插件对象
    //     LPSTR strContent-输出消息内容
    //函数说明：打印调试信息
    ///////////////////////////////////////////////
    virtual void PrinterLog(IPlugBase* pObj,LPSTR strContent)=0;
};

//用户状态查询接口，提供用户权限查询函数
class IUserControl
{
public:
    ///////////////////////////////////////////////
    //函数名称：GetUserRole
    //返回值:无
    //参数：LPSTR sName-返回的用户名
    //     UINT& nRole-返回的用户权限
    //函数说明：获取用户权限
    ///////////////////////////////////////////////
    virtual void GetUserRole(LPSTR sName,uint& nRole)=0;
};

//窗体状态查询接口，提供窗体状态查询函数
class IWndStateControl
{
public:
    ///////////////////////////////////////////////
    //函数名称：GetActiveWndName
    //返回值:无
    //参数：LPSTR sWndName-激活窗体名称
    //函数说明：获取激活窗体名称
    ///////////////////////////////////////////////
    virtual bool GetActiveWndName(LPSTR sWndName)=0;
};

#endif // PLUGFINDER_H
