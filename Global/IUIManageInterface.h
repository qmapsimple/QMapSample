/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：IUIManageInterface.h
* 摘    要：界面管理插件对外提供接口头文件
*
*   创建者：刘冰
* 创建日期：2013年8月20日
* 完成日期：2013年10月31日
*
* 修改者  ：修改者名字
* 修改起始日期：XXXX年XX月XX日
* 修改完成日期：XXXX年XX月XX日
* 修改内容描述：简要描述对该文件的修改内容，如增加了XX方法、XX变量，修* 改了XX方法、XX变量。
*/

#ifndef IUIMANAGEINTERFACE_H
#define IUIMANAGEINTERFACE_H
#pragma once


#define IUIMANAGEINTERFACE_NAME "IUIManageInterface"   //界面管理插件接口名称

#include "IPlugInterface.h"
#include "IPlugBase.h"


//浮动窗体配置位置，1：左侧；2：右侧；3：下方
enum PopWndPos
{
    LeftWnd = 1,    //左侧窗体
    RightWnd,       //右侧窗体
    BelowWnd        //下方窗体
};

//浮动窗体信息，包括浮动窗体配置位置，分隔栏名称和Tab页名称
struct PopWndInfo
{
    PopWndPos wndPos;       //窗体位置
    QString strSepName;     //分隔栏名称
    QString strTabName;     //Tab页名称
};

//插件接口类，产生后将该文件拷贝到
class IUIManageInterface : public IPlugInterface  //界面管理插件接口
{
public:
    //在此处声明插件对外公布的接口函数，其他插件通过该接口函数调用接口功能，定义方式如下，它的具体实现在接口实现类中完成

    //-----------------------对话框管理-------------------
    /////////////////////////////////////////////////////////////////////////
    // 函数名:DialogStylePro：
    // 参数: 输入：str-对话框显示标题，dlg-设置的对话框对象
    // 返回值: 无
    // 函数说明: 对话框显示风格设置
    /////////////////////////////////////////////////////////////////////////
    virtual void DialogStylePro(const QString str,QDialog &dlg) = 0;

    /////////////////////////////////////////////////////////////////////////
    // 函数名:DialogDisPostion
    // 参数: 输入：pos-对话框显示位置，dlg-设置的对话框对象
    //           style-对话框显示类型，1：模态显示；2：非模态显示
    // 返回值: 无
    // 函数说明: 对话框显示位置设置；0:左上，1：右上，2：左下，3：右下，4：居中
    /////////////////////////////////////////////////////////////////////////
    virtual void DialogDisPostion(QDialog &dlg, const int pos,const int style) = 0;


    //-----------------------浮动窗体管理------------------

    ///////////////////////////////////////////////////////////////////////////
    //函数名：SetDockWndInfo
    //参数：
    //		QMap<QString,QDockWidget*>& mapDockWnd
    //          浮动窗体配置信息，窗体名称与窗体对象映射表
    //返回值：
    //函数说明：设置浮动窗体信息
    ///////////////////////////////////////////////////////////////////////////
    virtual void SetDockWndInfo(QMap<QString,QDockWidget*>& mapDockWnd) = 0;


    //----------------------------------------------------------------
    //2013-11-22 修改浮动窗体管理输入参数浮动窗体名称为浮动窗体类型
    //----------------------------------------------------------------

    ///////////////////////////////////////////////////////////////////////////
    //函数名：PopWndAddSeporator
    //参数：
    //		PopWndPos wndPos-浮动窗体位置
    //          LeftWnd：左侧；RightWnd：右侧；BelowWnd：下方
    //          const QString strSep-分隔栏名称
    //返回值：
    //函数说明：浮动窗体添加分隔栏-针对左侧和右侧浮动窗体添加
    //         最多支持添加6个分隔栏，超过不进行处理
    ///////////////////////////////////////////////////////////////////////////
    virtual void PopWndAddSeporator(PopWndPos wndPos, const QString strSep) = 0;

    ///////////////////////////////////////////////////////////////////////////
    //函数名：PopWndAddTabPage
    //参数：
    //		PopWndInfo &strWndInfo-浮动窗体信息参数
    //              对于左侧和右侧浮动窗体，需要指定正确的浮动窗体位置、分隔栏及Tab页名称
    //              对于下方浮动窗体分隔栏名称无限制，指定正确的窗体位置及tab页名称即可
    //返回值：
    //函数说明：浮动窗体添加Tab页
    ///////////////////////////////////////////////////////////////////////////
    virtual void PopWndAddTabPage(PopWndInfo &strWndInfo) = 0;

    ///////////////////////////////////////////////////////////////////////////
    //函数名：PopWndWidAddTab
    //参数：
    //          QWidget *wid-指定窗体对象指针
    //		PopWndInfo &strWndInfo-浮动窗体信息参数
    //              对于左侧和右侧浮动窗体，需要指定正确的浮动窗体类型、分隔栏及Tab页名称
    //              对于下方浮动窗体分隔栏名称无限制，指定正确的窗体类型及tab页名称即可
    //返回值：
    //函数说明：指定窗体加入Tab页；
    ///////////////////////////////////////////////////////////////////////////
    virtual void PopWndWidAddTab(QWidget *wid, PopWndInfo &strWndInfo) = 0;


    ///////////////////////////////////////////////////////////////////////////
    //函数名：PopWndSetActiveTabPage
    //参数：
    //		PopWndInfo &strWndInfo-浮动窗体信息参数
    //              对于左侧和右侧浮动窗体，需要指定正确的浮动窗体类型、分隔栏及Tab页名称
    //              对于下方浮动窗体分隔栏名称无限制，指定正确的窗体类型及tab页名称即可
    //返回值：
    //函数说明：浮动窗体设置激活分栏tab页
    ///////////////////////////////////////////////////////////////////////////
    virtual void PopWndSetActiveTabPage(PopWndInfo &strWndInfo) = 0;

    ///////////////////////////////////////////////////////////////////////////
    //函数名：PopWndGetActive
    //参数：
    //		PopWndPos wndPos-浮动窗体位置
    //          LeftWnd：左侧；RightWnd：右侧；BelowWnd：下方
    //返回值：PopWndInfo& 浮动窗体信息参数；
    //对于左侧及右侧浮动窗体,若存在分隔栏和Tab页，获得指定窗体中处于激活状态的分隔栏、及Tab页名称
    //若指定窗体中只有分隔栏，则获得指定窗体中处于激活状态的分隔栏名称，Tab页名称为空
    //若指定窗体中既无Tab页无分隔栏，则只获得窗体类型，其他参数为空
    //对于下方浮动窗体若存在Tab页获得窗体中处于激活状态的Tab页名称
    //若指定窗体中无Tab页，则只获得窗体类型，其他参数为空
    //若指定窗体名称有误，所有参数信息均为空
    //函数说明：获取激活窗体
    ///////////////////////////////////////////////////////////////////////////
    virtual PopWndInfo& PopWndGetActive(PopWndPos wndPos) = 0;

    ///////////////////////////////////////////////////////////////////////////
    //函数名：PopWndSetSepratorDis
    //参数：
    //		PopWndPos wndPos-浮动窗体位置
    //          LeftWnd：左侧；RightWnd：右侧；BelowWnd：下方
    //          const QString strSep-分隔栏名称
    //          bool flag - 显隐标志；true：显示，false：隐藏
    //返回值：bool：true:设置成功，false：设置失败
    //函数说明：分隔栏显示隐藏状态设置-针对左侧及右侧浮动窗体进行设置
    ///////////////////////////////////////////////////////////////////////////
    virtual bool PopWndSetSepratorDis(PopWndPos wndPos, const QString strSep, bool flag) = 0;

    ///////////////////////////////////////////////////////////////////////////
    //函数名：PopWndSetTabPageDis
    //参数：
    //		PopWndInfo &strWndInfo-浮动窗体信息参数
    //          bool flag - 显隐标志；true：显示，false：隐藏
    //返回值：bool：true:设置成功，false：设置失败
    //函数说明：Tab页显示隐藏状态设置-左右侧浮动窗体信息参数使用窗体类型、分隔栏、Tab页名称信息
    //        下方浮动窗体信息参数使用窗体类型、tab页名称信息即可
    ///////////////////////////////////////////////////////////////////////////
    virtual bool PopWndSetTabPageDis(PopWndInfo &strWndInfo, bool flag) = 0;

};

#endif // IUIMANAGEINTERFACE_H
