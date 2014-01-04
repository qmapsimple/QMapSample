/*
* Copyright (c) 2013,���ӿ�ѧ�о�Ժ
* All rights reserved.
*
* �ļ����ƣ�IMap2DInterface.h
* ժ    Ҫ����ά��ͼ�ӿ�ͷ�ļ�
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

#ifndef IMAP2DINTERFACE_H
#define IMAP2DINTERFACE_H

#include <IPlugInterface.h>
#include <RocMapDataDef.h>

class IMap2DInterface:public IPlugInterface
{
public:
    //////////////////////////////////////////////////////////////////////////
            //��ͼ�������� begin
    //////////////////////////////////////////////////////////////////////////
    //�������ܣ�ˢ�µ�ͼ
    //�����������
    //�����������
    //����ֵ����
    virtual void Refresh()=0;

    //��������: ��ͼ�����϶�
    //�������: ��
    //�������:��
    //����ֵ: ��
    virtual void Wander()=0;

    //��������: ��ͼ���ε�ָ����
    //�������: dPt��Ԥ����λ��(��γ��)
    //�������:��
    //����ֵ: ��
    virtual void Wander(RocMap_CDPoint dPt)=0;

    //��������: ��ͼ�Ŵ�
    //�������: ��
    //�������:��
    //����ֵ: ��
    virtual void ZoomIn()=0;

    //��������: ��ͼ��ָ��ϵ���Ŵ����ŵ�Ϊ��Ļ���ĵ㣩
    //�������: fZoomFactor������ϵ��(�������1)
    //�������:��
    //����ֵ: ��
    virtual void ZoomIn(float fZoomFactor)=0;

    //��������: ��ͼ��ָ��ϵ����ָ����Ŵ�
    //�������: fZoomFactor������ϵ��(�������1)��dPt��ָ�����ĵ�(��γ��)
    //�������:��
    //����ֵ: ��
    virtual void ZoomIn(float fZoomFactor,RocMap_CDPoint dPt)=0;

    //��������: ��ͼ��С
    //�������: ��
    //�������:��
    //����ֵ: ��
    virtual void ZoomOut()=0;

    //��������: ��ͼ��ָ��ϵ����С�����ŵ�Ϊ��Ļ���ĵ㣩
    //�������: fZoomFactor������ϵ��(����С��1����0)
    //�������:��
    //����ֵ: ��
    virtual void ZoomOut(float fZoomFactor)=0;

    //��������: ��ͼ��ָ��ϵ����ָ������С
    //�������: fZoomFactor������ϵ��(����С��1����0)��dPt��ָ�����ĵ�(��γ��)
    //�������:��
    //����ֵ: ��
    virtual void ZoomOut(float fZoomFactor,RocMap_CDPoint dPt)=0;

    //��������: ��ͼ�ָ���ʼ״̬����ʼλ�úͱ����ߵȣ�
    //�������: ��
    //�������:��
    //����ֵ: ��
    virtual void Back()=0;

    //��������:���ָ��״̬���ָ���ǰ������
    //�������: ��
    //�������:��
    //����ֵ: ��
    virtual void Pointer()=0;

    //��������:��ȡ��ͼͼ��˳��
    //�������: ��
    //�������:vLayerOrderInfo��ͼ��˳����Ϣ
    //����ֵ: ��
    virtual void GetMapLayerOrder(vector<RocMap_LayerOrderInfo> &vLayerOrderInfo)=0;

    //��������:���õ�ͼͼ��˳��(���õ�ͼͼ��֮ǰ�������GetLayerOrder()��ȡԭͼ��˳��������������)
    //�������: vLayerOrderInfo����ͼ����������
    //�������:��
    //����ֵ: ��
    virtual void SetMapLayerOrder(vector<RocMap_LayerOrderInfo> vLayerOrderInfo)=0;

    //��������:���õ�ͼ��ͼ������
    //�������: csLayerName��ͼ������; bShow��TRUE ��ʾ��FALSE ����
    //�������:��
    //����ֵ: ��
    virtual void SetMapLayerVisible(QString csLayerName,BOOL bShow)=0;

    //��������:�����û��Զ���ͼ�㣨������и�ͼ�㣬�򽫴�ͼ����Ϊ��ǰ��
    //�������: csLayerName��ͼ������
    //�������:��
    //����ֵ: ��
    virtual void CreateLayer(QString csLayerName)=0;

    //��������:�����û��Զ���ͼ������
    //�������: csLayerName��ͼ������; bShow��TRUE ��ʾ��FALSE ����
    //�������:��
    //����ֵ: ��
    virtual void SetLayerVisible(QString csLayerName,BOOL bShow)=0;

    //��������:��ȡ��ͼͼ��˳��
    //�������: ��
    //�������:vLayerInfo��ͼ��˳����Ϣ
    //����ֵ: ��
    virtual void GetLayerOrder(vector<RocMap_UserLayerInfo> &vLayerInfo)=0;

    //��������:���õ�ͼͼ��˳��(���õ�ͼͼ��֮ǰ�������GetLayerOrder()��ȡԭͼ��˳��������������)
    //�������: vLayerInfo����ͼ����������
    //�������:��
    //����ֵ: ��
    virtual void SetLayerOrder(vector<RocMap_UserLayerInfo> vLayerInfo)=0;

    //��������: �����Ƿ���ʾ�����߹�����
    //�������: bShow��TRUE ��ʾ�� FALSE ����(Ĭ��ΪTRUE)
    //�������:��
    //����ֵ: ��
    virtual void ShowMapScaleBar(BOOL bShow)=0;

    //////////////////////////////////////////////////////////////////////////
            //��ͼ�������� end
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
            //���ơ�ɾ��������Ҫ�� begin
    //////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////
    //��������: ������Ҫ��(Ĭ����ʽ���߿�Ϊ1�����أ���ʽΪʵ�ߣ���ɫ��ɫ)
    //�������: strID���ߵı�ʶ��vdPt�����ϵĵ����꣨��γ�ȣ�
    //�������:��
    //����ֵ: ��
    /////////////////////////////////////////////////////////////////////////////////////////////
    virtual void DrawLine(const char* strID,vector<RocMap_CDPoint> vdPt)=0;

    //��������: �����ı��������㡢�ߡ����Ҫ��label����ʽ(Ĭ��������ʽ������Ϊ���壬��СΪ14����ɫ��ɫ)
    //�������: font��������ʽ(����,����_GB2312��); color���ı���ɫ
    //�������: bgcolor��������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ�����); bgalpha��������ɫ͸����; bgoutlinecolor��������������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ������������)
    //�������:��
    //����ֵ: ��
    virtual void SetTextStyle(QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),QColor bgcolor = QColor(-1,-1,-1),
                                  float bgalpha = 0.5,QColor bgoutlinecolor = QColor(-1,-1,-1))=0;

    //��������: �����ı��Ƿ������϶�
    //�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
    //�������:��
    //����ֵ: ��
    virtual void DragText(BOOL bDrag)=0;

    //��������: �����ı�(Ĭ��������ʽ������Ϊ���壬��СΪ14����ɫ��ɫ)
    //�������: strID���ı�ID; strContent���ı�����; dPt��������(��γ��)
    //�������:��
    //����ֵ: ��
    virtual void DrawText(const char* strID,const char* strContent,RocMap_CDPoint dPt)=0;

    //��������: ����ָ���ı���ʽ(Ĭ��������ʽ������Ϊ���壬�߶�Ϊ12�����Ϊ6����ɫ��ɫ�����������õ㡢�ߡ����Ҫ��label��ʽ����)
    //�������: font��������ʽ(����,����_GB2312��)��color���ı���ɫ
    //�������: bgcolor��������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ�����)��bgalpha��������ɫ͸���ȣ�bgoutlinecolor��������������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ������������)
    //�������:��
    //����ֵ: ��
    virtual void SetTextStyle(const char* strID,QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),
                                                            QColor bgcolor = QColor(-1,-1,-1),float bgalpha = 0.5,QColor bgoutlinecolor = QColor(-1,-1,-1))=0;

    //��������: ���õ���ʽ(Ĭ����ʽ�����СΪ1�����أ���ʽΪ���㣬��ɫ��ɫ)
    //�������: nSize����Ĵ�С��color�������ɫ�� cStyle�������ʽ (0 Ϊ���㣬1ΪԲ��)
    //�������:��
    //����ֵ: ��
    virtual void SetPointStyle(int nSize,QColor color, unsigned char cStyle)=0;

    //��������: ���Ƶ�Ҫ��(Ĭ����ʽ�����СΪ1�����أ���ʽΪ���㣬��ɫ��ɫ)
    //�������: strID����ı�ʶ��dPt��������(��γ��)
    //�������:��
    //����ֵ: ��
    virtual void DrawPoint(const char* strID,RocMap_CDPoint dPt)=0;

    //��������: ����ָ������ʽ(Ĭ����ʽ�����СΪ1�����أ���ʽΪ���㣬��ɫ��ɫ)
    //�������: strID����ı�ʶ��nSize����Ĵ�С�� color�������ɫ�� cStyle�������ʽ (0 Ϊ���㣬1ΪԲ��)
    //�������:��
    //����ֵ: ��
    virtual void SetPointStyle(const char* strID,int nSize,QColor color, unsigned char cStyle)=0;

    //��������: �����Ƿ���ʾ��Ҫ�ر�ʶ
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
    //�������:��
    //����ֵ: ��
    virtual void ShowPointLabel(BOOL bShow)=0;

    //�������ܣ����Ƶ�Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
    //���������strID����Ҫ�ص�Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
    //�����������
    //����ֵ����
    virtual void DrawPointLabel(const char* strID,QString sContent)=0;

    //��������: ���Ƶ�Ҫ��label�Ƿ���������϶�
    //�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
    //�������:��
    //����ֵ: ��
    virtual void DragPointLabel(BOOL bDrag)=0;

    //��������: �Ƿ���ʾָ����Ҫ�����Ա�ʶ
    //�������: strID����Ҫ�ص�Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void ShowPointLabel(const char* strID,BOOL bShow)=0;

    //��������: ��������ʽ(Ĭ����ʽ���߿�Ϊ1�����أ���ʽΪʵ�ߣ���ɫ��ɫ)
    //�������: nWidth���ߵĴ�ϸ; color���ߵ���ɫ��cStyle���ߵ���ʽ(0 ʵ�ߣ�1 ���� 2 ����)
    //�������:��
    //����ֵ: ��
    virtual void SetLineStyle(int nWidth,QColor color,unsigned char cStyle)=0;


    //��������: ����ָ������ʽ(Ĭ����ʽ���߿�Ϊ1�����أ���ʽΪʵ�ߣ���ɫ��ɫ)
    //�������: strID���ߵı�ʶ��nWidth���ߵĴ�ϸ; color���ߵ���ɫ��cStyle���ߵ���ʽ(0 ʵ�ߣ�1 ���� 2 ����)
    //�������:��
    //����ֵ: ��
    virtual void SetLineStyle(const char* strID,int nWidth,QColor color,unsigned char cStyle)=0;

    //��������: �����Ƿ���ʾ��Ҫ�ر�ʶ
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
    //�������:��
    //����ֵ: ��
    virtual void ShowLineLabel(BOOL bShow)=0;

    //�������ܣ�������Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
    //���������strID��Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
    //�����������
    //����ֵ����
    virtual void DrawLineLabel(const char* strID,QString sContent)=0;

    //��������: ������Ҫ��label�Ƿ������϶�
    //�������: bDrag�� TRUE ����,FALSE ������(Ĭ��ΪFALSE)
    //�������:��
    //����ֵ: ��
    virtual void DragLineLabel(BOOL bDrag)=0;

    //��������: �Ƿ���ʾָ����Ҫ�����Ա�ʶ
    //�������: strID����Ҫ�ص�Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void ShowLineLabel(const char* strID,BOOL bShow)=0;

    //��������: ������Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ�������ɫ��ɫ����͸��)
    //�������: outlinecolor����������ɫ��fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����);
    //�������: outlinewidth�������߿�ȣ�alpha����͸����(ֵ��0.0-1.0֮��)
    //�������:��
    //����ֵ: ��
    virtual void SetRegionStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //��������: ������Ҫ��(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ�������ɫ��ɫ����͸��)
    //�������: strID����ID�� strName�������ƣ�vdPt�����ϵĵ����꣨��γ�ȣ�
    //�������:��
    //����ֵ: ��
    virtual void DrawRegion(const char* strID,vector<RocMap_CDPoint> vdPt)=0;

    //��������: ����ָ����Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ�������ɫ��ɫ����͸��)
    //�������: strID����ID��outlinecolor����������ɫ��fillcolor �������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
    //�������: outlinewidth�������߿��; alpha����͸����(ֵ��0.0-1.0֮��)
    //�������:��
    //����ֵ: ��
    virtual void SetRegionStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //��������: �����Ƿ���ʾ��Ҫ�ر�ʶ
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
    //�������:��
    //����ֵ: ��
    virtual void ShowRegionLabel(BOOL bShow)=0;

    //�������ܣ�������Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
    //���������strID��Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
    //�����������
    //����ֵ����
    virtual void DrawRegionLabel(const char* strID,QString sContent)=0;

    //��������: ������Ҫ��label�Ƿ������϶�
    //�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
    //�������:��
    //����ֵ: ��
    virtual void DragRegionLabel(BOOL bDrag)=0;

    //��������: �Ƿ���ʾָ����Ҫ�����Ա�ʶ
    //�������: strID��Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void ShowRegionLabel(const char* strID,BOOL bShow)=0;

    //��������: ��������Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
    //�������: outlinewidth�������߿�ȣ�outlinecolor����������ɫ��fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
    //�������: alpha����͸����(ֵ��0.0-1.0֮��)
    //�������:��
    //����ֵ: ��
    virtual void SetSectorStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //�������ܣ���������(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
    //���������strID������ID��dPt��Բ�ľ�γ������(��γ��)��fRadius���뾶����λ�����
    //���������fBeginAngle����ʼ�Ƕȣ�����Ϊ�㣬˳ʱ��Ϊ������fAngleScope�����νǶȷ�Χ(�����360�ȣ����ǻ���Բ��)
    //�����������
    //����ֵ����
    virtual void DrawSector(const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope)=0;

    //�������ܣ���������(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��),������ͶӰ
    //���������strID������ID��dPt��Բ�ľ�γ������(��γ��)��fRadius���뾶����λ�����
    //���������fBeginAngle����ʼ�Ƕȣ�����Ϊ�㣬˳ʱ��Ϊ������fAngleScope�����νǶȷ�Χ(�����360�ȣ����ǻ���Բ��)
    //�����������
    //����ֵ����
    virtual void DrawSectorbyXY(const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope)=0;

    //��������: ����ָ������Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
    //�������: strID������ID��outlinewidth�������߿�ȣ�outlinecolor����������ɫ��fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
    //�������: alpha����͸����(ֵ��0.0-1.0֮��)
    //�������:��
    //����ֵ: ��
    virtual void SetSectorStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //��������: �����Ƿ���ʾ����Ҫ�ر�ʶ
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
    //�������:��
    //����ֵ: ��
    virtual void ShowSectorLabel(BOOL bShow)=0;

    //�������ܣ���������Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
    //���������strID��Ψһ��ʶ��sContent����ʶ����(������"\n"��ʾ����)
    //�����������
    //����ֵ����
    virtual void DrawSectorLabel(const char* strID,QString sContent)=0;

    //��������: ��������Ҫ��label�Ƿ������϶�
    //�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
    //�������:��
    //����ֵ: ��
    virtual void DragSectorLabel(BOOL bDrag)=0;

    //��������: �Ƿ���ʾָ������Ҫ�����Ա�ʶ
    //�������: strID��Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void ShowSectorLabel(const char* strID,BOOL bShow)=0;

    //��������: ������ԲҪ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
    //�������: outlinewidth�������߿��; outlinecolor����������ɫ; fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
    //�������: alpha����͸����(ֵ��0.0-1.0֮��)
    //�������:��
    //����ֵ: ��
    virtual void SetEllipseStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //�������ܣ�������Բ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
    //���������strID����ԲID��dCenterPt����Բ���ĵ㾭γ������(��γ��)
    //���������fLRadius�������᳤�ȣ���λ�������fSRadius���̰��᳤�ȣ���λ�������fAngle����ת�Ƕȣ�����������˳ʱ��нǣ�
    //�����������
    //����ֵ����
    virtual void DrawEllipse(const char* strID,RocMap_CDPoint dCenterPt,float fLRadius,float fSRadius,float fAngle)=0;

    //��������: ����ָ����ԲҪ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
    //�������: strID����ԲID��outlinewidth�������߿��; outlinecolor����������ɫ; fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
    //�������: alpha����͸����(ֵ��0.0-1.0֮��)
    //�������:��
    //����ֵ: ��
    virtual void SetEllipseStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha)=0;

    //��������: �����Ƿ���ʾ��ԲҪ�ر�ʶ
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
    //�������:��
    //����ֵ: ��
    virtual void ShowEllipseLabel(BOOL bShow)=0;

    //�������ܣ�������ԲҪ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
    //���������strID��Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
    //�����������
    //����ֵ����
    virtual void DrawEllipseLabel(const char* strID,QString sContent)=0;

    //��������: ������ԲҪ��label�Ƿ������϶�
    //�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
    //�������:��
    //����ֵ: ��
    virtual void DragEllipseLabel(BOOL bDrag)=0;

    //��������: �Ƿ���ʾָ����ԲҪ�����Ա�ʶ
    //�������: strID��Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void ShowEllipseLabel(const char* strID,BOOL bShow)=0;

    //�������ܣ�ͨ��ʵ��IDɾ��ʵ�壨Ԥ���ӿڣ����޹��ܣ�
    //���������strID��Ҫɾ����ʵ���ID��cSort��Ҫɾ����ʵ������࣬0�����ꣻ1�����Σ�2�������/���ߣ�3���ߣ� 4���㣻5���ı���6����Բ
    //�����������
    //����ֵ����
    virtual void  DelObjectbyID( const char* strID, unsigned char cSort)=0;

    //�������ܣ�ɾ��ָ����������ʵ�壨Ԥ���ӿڣ����޹��ܣ�
    //���������cSort��Ҫɾ����ʵ������࣬0�����ꣻ1�����Σ�2�������/���ߣ�3���ߣ� 4���㣻5���ı���6����Բ
    //�����������
    //����ֵ����
    virtual void  DelObjectbySort( unsigned char cSort)=0;

    //�������ܣ�������ɾ������ʵ��,Ԥ���ӿڣ����޹��ܣ�
    //�����������
    //�����������
    //����ֵ����
    virtual void  ClearAll()=0;

    //////////////////////////////////////////////////////////////////////////
            //���ơ�ɾ��������Ҫ�� end
    //////////////////////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////////////////////////
    //����������� begin
    //////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////////////
    //��������: ���ƾ���
    //�������: strID�� �����Ψһ��ʶ��strName�� �������ƣ�color�� ������ɫ
    //�������: jbcode�� ������룻dPt�� ����λ�ã���γ�ȣ�
    //�������:��
    //����ֵ: ��
    ////////////////////////////////////////////////////////////////////////////////////////////
    virtual void DrawMiliMark(const char* strID,const char* strName,int jbcode,RocMap_CDPoint dPt,QColor color)=0;

    //���ܣ��趨���о����С(�ڻ��ƾ���ǰ���ô˽ӿ�)
    //���������fScale�����ű���������1 ��ʾ�Ŵ�С��1 ��ʾ��С��
    //�����������
    //����ֵ����
    virtual void SetMiliMarkScale(float fScale)=0;

    //��������: �Ƿ���ʾ���о��꺽��(Ĭ�ϲ���ʾ)
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkHJShow(BOOL bShow)=0;


    //��������: �������о��꺽����󳤶�(�ڻ��ƾ���ǰ���ô˽ӿ�)
    //�������: strID������ı�ʶ��nLength����󳤶�(Ĭ��Ϊ500��)
    //�������:��
    //����ֵ: ��
    virtual void SetHJLength(int nLength)=0;

    //��������: ���þ����Ƿ���Ա༭
    //�������: bEdit��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkEdit(BOOL bEdit)=0;

    //��������: ���ƾ�������
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkShow(BOOL bShow)=0;


    //��������: ����ָ���������������ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
    //�������: strID�������Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkShow(const char* strID,BOOL bShow)=0;


    //��������: ���þ������Ա�ʶ������ʽ
    //�������: strID������ID; font��������ʽ(����,����_GB2312��); color���ı���ɫ
    //�������: bgcolor��������ɫ(RGB(-1,-1,-1)��ʾ�����)��bgalpha��������ɫ͸���ȣ�bgoutlinecolor��������������ɫ(RGB(-1,-1,-1)��ʾ������������)
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkLabelStyle(const char* strID,QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),QColor bgcolor = QColor(-1,-1,-1),
                                              QColor bgoutlinecolor = QColor(-1,-1,-1),float bgalpha = 0.5)=0;

    //��������: �����Ƿ���ʾ�����ʶ���ڻ��ƾ����ʶ����ǰ���ô˽ӿڣ�
    //�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkLabelShow(BOOL bShow)=0;

    //�������ܣ�����IDΪstrID��������Ա�ʶ���ݣ����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
    //���������strID������ID��sContent�������ʶ����(������"\n"��ʾ����)
    //�����������
    //����ֵ����
    virtual void DrawMiliMarkLabel(const char* strID,QString sContent)=0;

    //��������: �Ƿ���ʾָ���������Ա�ʶ�����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
    //�������: strID�������Ψһ��ʶ��bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkLabelShow(const char* strID,BOOL bShow)=0;

    //��������: ����ָ�����꺽����󳤶ȣ����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
    //�������: strID������ı�ʶ��nLength����󳤶�(Ĭ��Ϊ500��)
    //�������:��
    //����ֵ: ��
    virtual void SetHJLength(const char* strID,int nLength)=0;

    //��������: �����Ƿ���ʾ���꺽��(Ĭ�ϲ���ʾ)�����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
    //�������: strID������ı�ʶ��bShow��TRUE ��ʾ��FALSE ����ʾ
    //�������:��
    //����ֵ: ��
    virtual void SetMiliMarkHJShow(const char* strID,BOOL bShow)=0;

    //���ܣ��趨������ת�Ƕȣ����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
    //���������strID������ID�� fAngle����ת�Ƕȣ�����������н�,��ʱ����ת��
    //�����������
    //����ֵ����
    virtual void SetMiliMarkAngle(const char* strID,float fAngle)=0;

    //���ܣ��趨�����С�����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
    //���������strID������ID�� fScale�����ű�����>1 ��ʾ�Ŵ�<1 ��ʾ��С��
    //�����������
    //����ֵ����
    virtual void SetMiliMarkScale(const char* strID,float fScale)=0;

    //�������ܣ���ȡ�������ƺ;������
    //�����������
    //�����������������
    //����ֵ����
    virtual void GetMiliMarkInfo(vector<RocMap_JBAttr> &vJBAttr)=0;


    //////////////////////////////////////////////////////////////////////////
    //��ͼ���㹦�� begin
    //////////////////////////////////////////////////////////////////////////

    //��������: ��ȡ��ǰ��ͼ������
    //�������:��
    //�������:��
    //����ֵ: ������
    virtual float GetMapScale()=0;

    //��������: ��ȡ��ǰӰ���LOD�ȼ�
    //�������:��
    //�������:��
    //����ֵ: LOD�ȼ�
    virtual int GetLodLevel()=0;

    //��������: ��ȡ�����֮��ľ��룬���ֱ������Ļ�ϲ��ʱʹ��
    //�������:��
    //�������:��
    //����ֵ: ��
    virtual void GetDistance()=0;

    //��������: ��ȡ���֮�����
    //�������:vdPt���㼯����γ�ȣ�
    //�������:��
    //����ֵ: ����ֵ(��λ������)
    virtual float GetDistance(vector<RocMap_CDPoint> vdPt)=0;

    //��������: ����������������ֱ������Ļ�ϲ����ʱʹ��
    //�������: ��
    //�������:��
    //����ֵ: ��
    virtual void GetArea()=0;

    //��������: ��ȡ�������������
    //�������:vdPt���㼯����γ�ȣ�
    //�������:��
    //����ֵ: ���(��λ��ƽ������)
    virtual float GetArea(vector<RocMap_CDPoint> vdPt)=0;

    //��������: �����������߽Ƕ�����������нǣ����ֱ������Ļ�ϲ�Ƕ�ʱʹ��
    //�������: ��
    //�������:��
    //����ֵ: ��
    virtual void GetAngle()=0;

    //��������: �����������߽Ƕ�����������н�
    //�������: dPt0�� ��㾭γ�ȣ� dPt1�� �յ㾭γ�ȣ�
    //�������:��
    //����ֵ: �Ƕ�ֵ(��)
    virtual float GetAngle(RocMap_CDPoint dPt0,RocMap_CDPoint dPt1)=0;

    //��������: ���ݾ�γ�Ȼ�ȡ�߶�
    //�������: dPt����γ��
    //�������: ��
    //����ֵ:�߶�ֵ
    virtual float GetHeight(RocMap_CDPoint dPt)=0;

    //��������: ��Ļ����ת��γ��
    //�������: pt����Ļ����
    //�������: ������Ϣ(��γ��)
    //����ֵ:��
    virtual void XYtoLB(QPoint pt,RocMap_CDPoint& dPt)=0;

    //��������: ��γ��ת��Ļ����
    //�������: dPt ��γ��
    //�������: ��
    //����ֵ:��Ļ����
    virtual QPoint LBtoXY(RocMap_CDPoint dPt)=0;

    //�������ܣ�������һ��������
    //���������dSrcPt���ο��������ꣻfAngle���������ο���������н� (��λ:��)��fDist�������Ͳο���ľ��룬��λ������
    //���������dObjPt�������ĵ�������
    //����ֵ��TRUE���ɹ���FALSE��ʧ��
    virtual BOOL GetGeoPoint(RocMap_CDPoint dSrcPt,float fAngle,float fDist,RocMap_CDPoint& dObjPt)=0;
};


#endif // IMAP2DINTERFACE_H
