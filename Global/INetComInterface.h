///////////////////////////////////////////////////////////////////////
// Copyright (c) 2013,电子科学研究院
// All rights reserved.
// 
// 文件名称：INetComInterface.h
// 摘    要：interface for the INetComInterface class
// 
// 创建者：秦永刚
// 创建日期：2013年8月1日
// 完成日期：2013年8月20日
///////////////////////////////////////////////////////////////////////

#if !defined(AFX_INetComInterface_H__A1CA0566_9D2D_4903_80E6_69C0B591B3B0__INCLUDED_)
#define AFX_INetComInterface_H__A1CA0566_9D2D_4903_80E6_69C0B591B3B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IPlugInterface.h"
#include "IPlugBase.h"

#define INETCOMINTERFACE_NAME "NetComInterface"

//插件接口类，产生后将该文件拷贝到
class INetComInterface : public IPlugInterface  //网络通信接口
{
public:
    //在此处声明插件对外公布的接口函数，其他插件通过该接口函数调用接口功能，定义方式如下，它的具体实现在接口实现类中完成
    ///////////////////////////////////////////////////////////////////
    //接口名：DeclareToBePublished
    //参数：usInfoCategory-消息类型
    //返回值：bool-返回结果标识 true-成功 false-失败
    //接口说明：公布消息,只有公布的类型消息才能成功发送
    ///////////////////////////////////////////////////////////////////
    virtual bool DeclareToBePublished(unsigned short usInfoCategory)=0;

    ///////////////////////////////////////////////////////////////////
    //接口名:DeclareToBeSubscribed
    //参数:usInfoCategory-消息类型 pIPlugBase-订购插件对象
    //返回: bool-返回结果标识 true-成功 false-失败
    //接口说明:订购消息，只有订购的类型消息才能成功接收
    ////////////////////////////////////////////////////////////////////
    virtual bool DeclareToBeSubscribed(unsigned short usInfoCategory, IPlugBase* pIPlugBase)=0;

    ///////////////////////////////////////////////////////////////////
    //接口名: UnPublished
    //参数: usInfoCategory-消息类型
    //返回: bool-返回结果标识 true-成功 false-失败
    //接口说明: 取消消息公布，取消后就不能发送该类型消息
    ///////////////////////////////////////////////////////////////////
    virtual bool UnPublished(unsigned short usInfoCategory)=0;

    ///////////////////////////////////////////////////////////////////
    //接口名: UnSubscribed
    //参数:usInfoCategory-消息类型 pIPlugBase-订购插件对象
    //返回: bool-返回结果标识 true-成功 false-失败
    //接口说明: 取消消息订购，取消后就不能接收该类型消息
    ///////////////////////////////////////////////////////////////////
    virtual bool UnSubscribed(unsigned short usInfoCategory, IPlugBase* pIPlugBase)=0;

    ///////////////////////////////////////////////////////////////////
    //接口名: SendMsg
    //参数:nType-消息类型  strContent-消息内容
    //返回: bool-返回结果标识 true-成功 false-失败
    //接口说明: 发送消息，发送前必须先公布该消息类型
    ///////////////////////////////////////////////////////////////////
    virtual bool SendMsg(int nType, const string strContent)=0;
};

#endif // !defined(AFX_INetComINTERFACE_H__A1CA0566_9D2D_4903_80E6_69C0B591B3B0__INCLUDED_)
