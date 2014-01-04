///////////////////////////////////////////////////////////////////////
// Copyright (c) 2013,���ӿ�ѧ�о�Ժ
// All rights reserved.
// 
// �ļ����ƣ�INetComInterface.h
// ժ    Ҫ��interface for the INetComInterface class
// 
// �����ߣ�������
// �������ڣ�2013��8��1��
// ������ڣ�2013��8��20��
///////////////////////////////////////////////////////////////////////

#if !defined(AFX_INetComInterface_H__A1CA0566_9D2D_4903_80E6_69C0B591B3B0__INCLUDED_)
#define AFX_INetComInterface_H__A1CA0566_9D2D_4903_80E6_69C0B591B3B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IPlugInterface.h"
#include "IPlugBase.h"

#define INETCOMINTERFACE_NAME "NetComInterface"

//����ӿ��࣬�����󽫸��ļ�������
class INetComInterface : public IPlugInterface  //����ͨ�Žӿ�
{
public:
    //�ڴ˴�����������⹫���Ľӿں������������ͨ���ýӿں������ýӿڹ��ܣ����巽ʽ���£����ľ���ʵ���ڽӿ�ʵ���������
    ///////////////////////////////////////////////////////////////////
    //�ӿ�����DeclareToBePublished
    //������usInfoCategory-��Ϣ����
    //����ֵ��bool-���ؽ����ʶ true-�ɹ� false-ʧ��
    //�ӿ�˵����������Ϣ,ֻ�й�����������Ϣ���ܳɹ�����
    ///////////////////////////////////////////////////////////////////
    virtual bool DeclareToBePublished(unsigned short usInfoCategory)=0;

    ///////////////////////////////////////////////////////////////////
    //�ӿ���:DeclareToBeSubscribed
    //����:usInfoCategory-��Ϣ���� pIPlugBase-�����������
    //����: bool-���ؽ����ʶ true-�ɹ� false-ʧ��
    //�ӿ�˵��:������Ϣ��ֻ�ж�����������Ϣ���ܳɹ�����
    ////////////////////////////////////////////////////////////////////
    virtual bool DeclareToBeSubscribed(unsigned short usInfoCategory, IPlugBase* pIPlugBase)=0;

    ///////////////////////////////////////////////////////////////////
    //�ӿ���: UnPublished
    //����: usInfoCategory-��Ϣ����
    //����: bool-���ؽ����ʶ true-�ɹ� false-ʧ��
    //�ӿ�˵��: ȡ����Ϣ������ȡ����Ͳ��ܷ��͸�������Ϣ
    ///////////////////////////////////////////////////////////////////
    virtual bool UnPublished(unsigned short usInfoCategory)=0;

    ///////////////////////////////////////////////////////////////////
    //�ӿ���: UnSubscribed
    //����:usInfoCategory-��Ϣ���� pIPlugBase-�����������
    //����: bool-���ؽ����ʶ true-�ɹ� false-ʧ��
    //�ӿ�˵��: ȡ����Ϣ������ȡ����Ͳ��ܽ��ո�������Ϣ
    ///////////////////////////////////////////////////////////////////
    virtual bool UnSubscribed(unsigned short usInfoCategory, IPlugBase* pIPlugBase)=0;

    ///////////////////////////////////////////////////////////////////
    //�ӿ���: SendMsg
    //����:nType-��Ϣ����  strContent-��Ϣ����
    //����: bool-���ؽ����ʶ true-�ɹ� false-ʧ��
    //�ӿ�˵��: ������Ϣ������ǰ�����ȹ�������Ϣ����
    ///////////////////////////////////////////////////////////////////
    virtual bool SendMsg(int nType, const string strContent)=0;
};

#endif // !defined(AFX_INetComINTERFACE_H__A1CA0566_9D2D_4903_80E6_69C0B591B3B0__INCLUDED_)
