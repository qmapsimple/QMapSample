/*
* Copyright (c) 2013,电子科学研究院
* All rights reserved.
*
* 文件名称：IInterfaceManager.h
* 摘    要：接口管理类接口头文件
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

#ifndef IINTERFACEMANAGER_H
#define IINTERFACEMANAGER_H

#include "QtCore"

class IPlugInterface;

//接口管理类接口
class IInterfaceManager
{
public:
        ///////////////////////////////////////////////
        //函数名称：RegisterInterface
        //返回值:无
        //参数：strName-接口名称
        //      pInterface-接口
        //函数说明：注册插件接口
    ///////////////////////////////////////////////
        virtual bool RegisterInterface(QString strName,IPlugInterface* pInterface)=0;

        ///////////////////////////////////////////////
        //函数名称：GetInterface
        //返回值:无
        //参数：strName-接口名称
        //      pInterface-接口（输出）
        //函数说明：获取插件接口
    ///////////////////////////////////////////////
        virtual void GetInterface(QString strName,IPlugInterface** pInterface)=0;

};

#endif // INTERFACEMANAGER_H
