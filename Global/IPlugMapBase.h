/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：IPlugMapBase.h
* 摘    要：地图插件基类头文件
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

#ifndef IPLUGMAPBASE_H
#define IPLUGMAPBASE_H

#include "IPlugBase.h"

////////////////////////////////////////////////////////
//地图插件基类
////////////////////////////////////////////////////////
class IPlugMapBase : public IPlugBase
{

public:
    //////////////////////////////////////////////////////////////////////
    //函数名:ProWndMessage
    //返回值：无
    //参数:QEvent* pEvent-窗体对象指针
    //函数说明:窗体消息回调
    /////////////////////////////////////////////////////////////////////
    virtual LRESULT ProWndMessage(QEvent* pEvent)=0;//窗体消息回调

    //////////////////////////////////////////////////////////////////////
    //函数名:Init2DView
    //返回值：无
    //参数:QWidget* pWidget-窗体对象指针
    //函数说明:初始化二维窗口
    /////////////////////////////////////////////////////////////////////
    virtual void Init2DView(QWidget* pWidget)=0;

    //////////////////////////////////////////////////////////////////////
    //函数名:Init3DView
    //返回值：无
    //参数:QWidget* pWidget-窗体对象指针
    //函数说明:初始化三维窗口
    /////////////////////////////////////////////////////////////////////
    virtual void Init3DView(QWidget* pWidget)=0;
};

//地图插件结构
typedef struct{
        IPlugMapBase* pObj;
        QLibrary* hIns;
}PLUGMAP_ST,*LPPLUGMAP_ST;

#endif // IPLUGMAPBASE_H
