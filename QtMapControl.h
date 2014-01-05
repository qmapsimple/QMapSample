#ifndef QTMAPCONTROL_H_
#define QTMAPCONTROL_H_

#include "Global/IMap2DInterface.h"

#include <QtGui/QWidget>


#include "MapEditor/UGMapEditorWnd.h"
#include "Graphics/UGGraphicsManager.h"
#include "Graphics/UGGraphics.h"
#include "Workspace/UGResources.h"


using namespace UGC;

namespace UGC
{
	class UGGraphics;
}
/**
 * ��ͼ�ؼ���
 */
class QtMapControl : public QWidget, public IMap2DInterface
{
	Q_OBJECT

public:
	QtMapControl(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtMapControl();
//-------------------------------��д���ຯ��------------------------------------
		/**
		 * ��д���ƺ���
		 */
		virtual void paintEvent( QPaintEvent * event );

		

		

		/**
		 * ��д�����ֺ���
		 */
		virtual void wheelEvent( QWheelEvent * event );
		/**
		 * ��д��갴�º���
		 */
		virtual void mousePressEvent ( QMouseEvent * event );
		/**
		 * ��д��굯����
		 */
		virtual void mouseReleaseEvent ( QMouseEvent * event );
		/**
		 * ��д����ƶ�����
		 */
		virtual void mouseMoveEvent ( QMouseEvent * event );
		/**
		 * ��д�����ڴ�С�����ı�ʱ����
		 */
		virtual void resizeEvent ( QResizeEvent * event );
		/**
		 * ȫ��
		 */
		void ViewEntire();


		// -----------------�ڲ������ӿ�-------------------

		/*
		 *	��Ļ����ת�ɵ�ͼ����
		 */
		UGPoint2D PixelToMap(const QPoint &point);

		/*
		 *	��ͼ����ת����Ļ����
		 */
		QPoint MapToPixel(const UGPoint2D &point2D);

public:
	/************************************************************************/
	/* ʵ��IMap2DInterface��Ӧ�Ľӿ�                                   */
	/************************************************************************/
	//�������ܣ�ˢ�µ�ͼ
	//�����������
	//�����������
	//����ֵ����
	virtual void Refresh();

	//��������: ��ͼ�����϶�
	//�������: ��
	//�������:��
	//����ֵ: ��
	virtual void Wander();

	//��������: ��ͼ���ε�ָ����
	//�������: dPt��Ԥ����λ��(��γ��)
	//�������:��
	//����ֵ: ��
	virtual void Wander(RocMap_CDPoint dPt);

	//��������: ��ͼ�Ŵ�
	//�������: ��
	//�������:��
	//����ֵ: ��
	virtual void ZoomIn();

	//��������: ��ͼ��ָ��ϵ���Ŵ����ŵ�Ϊ��Ļ���ĵ㣩
	//�������: fZoomFactor������ϵ��(�������1)
	//�������:��
	//����ֵ: ��
	virtual void ZoomIn(float fZoomFactor);

	//��������: ��ͼ��ָ��ϵ����ָ����Ŵ�
	//�������: fZoomFactor������ϵ��(�������1)��dPt��ָ�����ĵ�(��γ��)
	//�������:��
	//����ֵ: ��
	virtual void ZoomIn(float fZoomFactor,RocMap_CDPoint dPt);

	//��������: ��ͼ��С
	//�������: ��
	//�������:��
	//����ֵ: ��
	virtual void ZoomOut();

	//��������: ��ͼ��ָ��ϵ����С�����ŵ�Ϊ��Ļ���ĵ㣩
	//�������: fZoomFactor������ϵ��(����С��1����0)
	//�������:��
	//����ֵ: ��
	virtual void ZoomOut(float fZoomFactor);

	//��������: ��ͼ��ָ��ϵ����ָ������С
	//�������: fZoomFactor������ϵ��(����С��1����0)��dPt��ָ�����ĵ�(��γ��)
	//�������:��
	//����ֵ: ��
	virtual void ZoomOut(float fZoomFactor,RocMap_CDPoint dPt);

	//��������: ��ͼ�ָ���ʼ״̬����ʼλ�úͱ����ߵȣ�
	//�������: ��
	//�������:��
	//����ֵ: ��
	virtual void Back();

	//��������:���ָ��״̬���ָ���ǰ������
	//�������: ��
	//�������:��
	//����ֵ: ��
	virtual void Pointer();

	//��������:��ȡ��ͼͼ��˳��
	//�������: ��
	//�������:vLayerOrderInfo��ͼ��˳����Ϣ
	//����ֵ: ��
	virtual void GetMapLayerOrder(vector<RocMap_LayerOrderInfo> &vLayerOrderInfo);

	//��������:���õ�ͼͼ��˳��(���õ�ͼͼ��֮ǰ�������GetLayerOrder()��ȡԭͼ��˳��������������)
	//�������: vLayerOrderInfo����ͼ����������
	//�������:��
	//����ֵ: ��
	virtual void SetMapLayerOrder(vector<RocMap_LayerOrderInfo> vLayerOrderInfo);

	//��������:���õ�ͼ��ͼ������
	//�������: csLayerName��ͼ������; bShow��TRUE ��ʾ��FALSE ����
	//�������:��
	//����ֵ: ��
	virtual void SetMapLayerVisible(QString csLayerName,BOOL bShow);

	//��������:�����û��Զ���ͼ�㣨������и�ͼ�㣬�򽫴�ͼ����Ϊ��ǰ��
	//�������: csLayerName��ͼ������
	//�������:��
	//����ֵ: ��
	virtual void CreateLayer(QString csLayerName);

	//��������:�����û��Զ���ͼ������
	//�������: csLayerName��ͼ������; bShow��TRUE ��ʾ��FALSE ����
	//�������:��
	//����ֵ: ��
	virtual void SetLayerVisible(QString csLayerName,BOOL bShow);

	//��������:��ȡ��ͼͼ��˳��
	//�������: ��
	//�������:vLayerInfo��ͼ��˳����Ϣ
	//����ֵ: ��
	virtual void GetLayerOrder(vector<RocMap_UserLayerInfo> &vLayerInfo);

	//��������:���õ�ͼͼ��˳��(���õ�ͼͼ��֮ǰ�������GetLayerOrder()��ȡԭͼ��˳��������������)
	//�������: vLayerInfo����ͼ����������
	//�������:��
	//����ֵ: ��
	virtual void SetLayerOrder(vector<RocMap_UserLayerInfo> vLayerInfo);

	//��������: �����Ƿ���ʾ�����߹�����
	//�������: bShow��TRUE ��ʾ�� FALSE ����(Ĭ��ΪTRUE)
	//�������:��
	//����ֵ: ��
	virtual void ShowMapScaleBar(BOOL bShow);

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
	virtual void DrawLine(const char* strID,vector<RocMap_CDPoint> vdPt);

	//��������: �����ı��������㡢�ߡ����Ҫ��label����ʽ(Ĭ��������ʽ������Ϊ���壬��СΪ14����ɫ��ɫ)
	//�������: font��������ʽ(����,����_GB2312��); color���ı���ɫ
	//�������: bgcolor��������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ�����); bgalpha��������ɫ͸����; bgoutlinecolor��������������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ������������)
	//�������:��
	//����ֵ: ��
	virtual void SetTextStyle(QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),QColor bgcolor = QColor(-1,-1,-1),
		float bgalpha = 0.5,QColor bgoutlinecolor = QColor(-1,-1,-1));

	//��������: �����ı��Ƿ������϶�
	//�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
	//�������:��
	//����ֵ: ��
	virtual void DragText(BOOL bDrag);

	//��������: �����ı�(Ĭ��������ʽ������Ϊ���壬��СΪ14����ɫ��ɫ)
	//�������: strID���ı�ID; strContent���ı�����; dPt��������(��γ��)
	//�������:��
	//����ֵ: ��
	virtual void DrawText(const char* strID,const char* strContent,RocMap_CDPoint dPt);

	//��������: ����ָ���ı���ʽ(Ĭ��������ʽ������Ϊ���壬�߶�Ϊ12�����Ϊ6����ɫ��ɫ�����������õ㡢�ߡ����Ҫ��label��ʽ����)
	//�������: font��������ʽ(����,����_GB2312��)��color���ı���ɫ
	//�������: bgcolor��������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ�����)��bgalpha��������ɫ͸���ȣ�bgoutlinecolor��������������ɫ(Ĭ��RGB(-1,-1,-1)��ʾ������������)
	//�������:��
	//����ֵ: ��
	virtual void SetTextStyle(const char* strID,QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),
		QColor bgcolor = QColor(-1,-1,-1),float bgalpha = 0.5,QColor bgoutlinecolor = QColor(-1,-1,-1));

	//��������: ���õ���ʽ(Ĭ����ʽ�����СΪ1�����أ���ʽΪ���㣬��ɫ��ɫ)
	//�������: nSize����Ĵ�С��color�������ɫ�� cStyle�������ʽ (0 Ϊ���㣬1ΪԲ��)
	//�������:��
	//����ֵ: ��
	virtual void SetPointStyle(int nSize,QColor color, unsigned char cStyle);

	//��������: ���Ƶ�Ҫ��(Ĭ����ʽ�����СΪ1�����أ���ʽΪ���㣬��ɫ��ɫ)
	//�������: strID����ı�ʶ��dPt��������(��γ��)
	//�������:��
	//����ֵ: ��
	virtual void DrawPoint(const char* strID,RocMap_CDPoint dPt);

	//��������: ����ָ������ʽ(Ĭ����ʽ�����СΪ1�����أ���ʽΪ���㣬��ɫ��ɫ)
	//�������: strID����ı�ʶ��nSize����Ĵ�С�� color�������ɫ�� cStyle�������ʽ (0 Ϊ���㣬1ΪԲ��)
	//�������:��
	//����ֵ: ��
	virtual void SetPointStyle(const char* strID,int nSize,QColor color, unsigned char cStyle);

	//��������: �����Ƿ���ʾ��Ҫ�ر�ʶ
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
	//�������:��
	//����ֵ: ��
	virtual void ShowPointLabel(BOOL bShow);

	//�������ܣ����Ƶ�Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
	//���������strID����Ҫ�ص�Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
	//�����������
	//����ֵ����
	virtual void DrawPointLabel(const char* strID,QString sContent);

	//��������: ���Ƶ�Ҫ��label�Ƿ���������϶�
	//�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
	//�������:��
	//����ֵ: ��
	virtual void DragPointLabel(BOOL bDrag);

	//��������: �Ƿ���ʾָ����Ҫ�����Ա�ʶ
	//�������: strID����Ҫ�ص�Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void ShowPointLabel(const char* strID,BOOL bShow);

	//��������: ��������ʽ(Ĭ����ʽ���߿�Ϊ1�����أ���ʽΪʵ�ߣ���ɫ��ɫ)
	//�������: nWidth���ߵĴ�ϸ; color���ߵ���ɫ��cStyle���ߵ���ʽ(0 ʵ�ߣ�1 ���� 2 ����)
	//�������:��
	//����ֵ: ��
	virtual void SetLineStyle(int nWidth,QColor color,unsigned char cStyle);


	//��������: ����ָ������ʽ(Ĭ����ʽ���߿�Ϊ1�����أ���ʽΪʵ�ߣ���ɫ��ɫ)
	//�������: strID���ߵı�ʶ��nWidth���ߵĴ�ϸ; color���ߵ���ɫ��cStyle���ߵ���ʽ(0 ʵ�ߣ�1 ���� 2 ����)
	//�������:��
	//����ֵ: ��
	virtual void SetLineStyle(const char* strID,int nWidth,QColor color,unsigned char cStyle);

	//��������: �����Ƿ���ʾ��Ҫ�ر�ʶ
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
	//�������:��
	//����ֵ: ��
	virtual void ShowLineLabel(BOOL bShow);

	//�������ܣ�������Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
	//���������strID��Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
	//�����������
	//����ֵ����
	virtual void DrawLineLabel(const char* strID,QString sContent);

	//��������: ������Ҫ��label�Ƿ������϶�
	//�������: bDrag�� TRUE ����,FALSE ������(Ĭ��ΪFALSE)
	//�������:��
	//����ֵ: ��
	virtual void DragLineLabel(BOOL bDrag);

	//��������: �Ƿ���ʾָ����Ҫ�����Ա�ʶ
	//�������: strID����Ҫ�ص�Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void ShowLineLabel(const char* strID,BOOL bShow);

	//��������: ������Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ�������ɫ��ɫ����͸��)
	//�������: outlinecolor����������ɫ��fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����);
	//�������: outlinewidth�������߿�ȣ�alpha����͸����(ֵ��0.0-1.0֮��)
	//�������:��
	//����ֵ: ��
	virtual void SetRegionStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha);

	//��������: ������Ҫ��(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ�������ɫ��ɫ����͸��)
	//�������: strID����ID�� strName�������ƣ�vdPt�����ϵĵ����꣨��γ�ȣ�
	//�������:��
	//����ֵ: ��
	virtual void DrawRegion(const char* strID,vector<RocMap_CDPoint> vdPt);

	//��������: ����ָ����Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ�������ɫ��ɫ����͸��)
	//�������: strID����ID��outlinecolor����������ɫ��fillcolor �������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
	//�������: outlinewidth�������߿��; alpha����͸����(ֵ��0.0-1.0֮��)
	//�������:��
	//����ֵ: ��
	virtual void SetRegionStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha);

	//��������: �����Ƿ���ʾ��Ҫ�ر�ʶ
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
	//�������:��
	//����ֵ: ��
	virtual void ShowRegionLabel(BOOL bShow);

	//�������ܣ�������Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
	//���������strID��Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
	//�����������
	//����ֵ����
	virtual void DrawRegionLabel(const char* strID,QString sContent);

	//��������: ������Ҫ��label�Ƿ������϶�
	//�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
	//�������:��
	//����ֵ: ��
	virtual void DragRegionLabel(BOOL bDrag);

	//��������: �Ƿ���ʾָ����Ҫ�����Ա�ʶ
	//�������: strID��Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void ShowRegionLabel(const char* strID,BOOL bShow);

	//��������: ��������Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
	//�������: outlinewidth�������߿�ȣ�outlinecolor����������ɫ��fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
	//�������: alpha����͸����(ֵ��0.0-1.0֮��)
	//�������:��
	//����ֵ: ��
	virtual void SetSectorStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha);

	//�������ܣ���������(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
	//���������strID������ID��dPt��Բ�ľ�γ������(��γ��)��fRadius���뾶����λ�����
	//���������fBeginAngle����ʼ�Ƕȣ�����Ϊ�㣬˳ʱ��Ϊ������fAngleScope�����νǶȷ�Χ(�����360�ȣ����ǻ���Բ��)
	//�����������
	//����ֵ����
	virtual void DrawSector(const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope);

	//�������ܣ���������(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��),������ͶӰ
	//���������strID������ID��dPt��Բ�ľ�γ������(��γ��)��fRadius���뾶����λ�����
	//���������fBeginAngle����ʼ�Ƕȣ�����Ϊ�㣬˳ʱ��Ϊ������fAngleScope�����νǶȷ�Χ(�����360�ȣ����ǻ���Բ��)
	//�����������
	//����ֵ����
	virtual void DrawSectorbyXY(const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope);

	//��������: ����ָ������Ҫ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
	//�������: strID������ID��outlinewidth�������߿�ȣ�outlinecolor����������ɫ��fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
	//�������: alpha����͸����(ֵ��0.0-1.0֮��)
	//�������:��
	//����ֵ: ��
	virtual void SetSectorStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha);

	//��������: �����Ƿ���ʾ����Ҫ�ر�ʶ
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
	//�������:��
	//����ֵ: ��
	virtual void ShowSectorLabel(BOOL bShow);

	//�������ܣ���������Ҫ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
	//���������strID��Ψһ��ʶ��sContent����ʶ����(������"\n"��ʾ����)
	//�����������
	//����ֵ����
	virtual void DrawSectorLabel(const char* strID,QString sContent);

	//��������: ��������Ҫ��label�Ƿ������϶�
	//�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
	//�������:��
	//����ֵ: ��
	virtual void DragSectorLabel(BOOL bDrag);

	//��������: �Ƿ���ʾָ������Ҫ�����Ա�ʶ
	//�������: strID��Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void ShowSectorLabel(const char* strID,BOOL bShow);

	//��������: ������ԲҪ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
	//�������: outlinewidth�������߿��; outlinecolor����������ɫ; fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
	//�������: alpha����͸����(ֵ��0.0-1.0֮��)
	//�������:��
	//����ֵ: ��
	virtual void SetEllipseStyle(int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha);

	//�������ܣ�������Բ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
	//���������strID����ԲID��dCenterPt����Բ���ĵ㾭γ������(��γ��)
	//���������fLRadius�������᳤�ȣ���λ�������fSRadius���̰��᳤�ȣ���λ�������fAngle����ת�Ƕȣ�����������˳ʱ��нǣ�
	//�����������
	//����ֵ����
	virtual void DrawEllipse(const char* strID,RocMap_CDPoint dCenterPt,float fLRadius,float fSRadius,float fAngle);

	//��������: ����ָ����ԲҪ����ʽ(Ĭ����ʽ�������߿�1�����أ���������ɫ��ɫ������䣬��͸��)
	//�������: strID����ԲID��outlinewidth�������߿��; outlinecolor����������ɫ; fillcolor���������ɫ(���ΪRGB(-1,-1,-1)���ʾ�����)
	//�������: alpha����͸����(ֵ��0.0-1.0֮��)
	//�������:��
	//����ֵ: ��
	virtual void SetEllipseStyle(const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha);

	//��������: �����Ƿ���ʾ��ԲҪ�ر�ʶ
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
	//�������:��
	//����ֵ: ��
	virtual void ShowEllipseLabel(BOOL bShow);

	//�������ܣ�������ԲҪ�����Ա�ʶ���ݣ������Ҫ�ı�label��ʽͨ��SetTextStyle()�����޸ģ�
	//���������strID��Ψһ��ʶ; sContent����ʶ����(������"\n"��ʾ����)
	//�����������
	//����ֵ����
	virtual void DrawEllipseLabel(const char* strID,QString sContent);

	//��������: ������ԲҪ��label�Ƿ������϶�
	//�������: bDrag��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
	//�������:��
	//����ֵ: ��
	virtual void DragEllipseLabel(BOOL bDrag);

	//��������: �Ƿ���ʾָ����ԲҪ�����Ա�ʶ
	//�������: strID��Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void ShowEllipseLabel(const char* strID,BOOL bShow);

	//�������ܣ�ͨ��ʵ��IDɾ��ʵ�壨Ԥ���ӿڣ����޹��ܣ�
	//���������strID��Ҫɾ����ʵ���ID��cSort��Ҫɾ����ʵ������࣬0�����ꣻ1�����Σ�2�������/���ߣ�3���ߣ� 4���㣻5���ı���6����Բ
	//�����������
	//����ֵ����
	virtual void  DelObjectbyID( const char* strID, unsigned char cSort);

	//�������ܣ�ɾ��ָ����������ʵ�壨Ԥ���ӿڣ����޹��ܣ�
	//���������cSort��Ҫɾ����ʵ������࣬0�����ꣻ1�����Σ�2�������/���ߣ�3���ߣ� 4���㣻5���ı���6����Բ
	//�����������
	//����ֵ����
	virtual void  DelObjectbySort( unsigned char cSort);

	//�������ܣ�������ɾ������ʵ��,Ԥ���ӿڣ����޹��ܣ�
	//�����������
	//�����������
	//����ֵ����
	virtual void  ClearAll();

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
	virtual void DrawMiliMark(const char* strID,const char* strName,int jbcode,RocMap_CDPoint dPt,QColor color);

	//���ܣ��趨���о����С(�ڻ��ƾ���ǰ���ô˽ӿ�)
	//���������fScale�����ű���������1 ��ʾ�Ŵ�С��1 ��ʾ��С��
	//�����������
	//����ֵ����
	virtual void SetMiliMarkScale(float fScale);

	//��������: �Ƿ���ʾ���о��꺽��(Ĭ�ϲ���ʾ)
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkHJShow(BOOL bShow);


	//��������: �������о��꺽����󳤶�(�ڻ��ƾ���ǰ���ô˽ӿ�)
	//�������: strID������ı�ʶ��nLength����󳤶�(Ĭ��Ϊ500��)
	//�������:��
	//����ֵ: ��
	virtual void SetHJLength(int nLength);

	//��������: ���þ����Ƿ���Ա༭
	//�������: bEdit��TRUE ����,FALSE ������(Ĭ��ΪFALSE)
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkEdit(BOOL bEdit);

	//��������: ���ƾ�������
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkShow(BOOL bShow);


	//��������: ����ָ���������������ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
	//�������: strID�������Ψһ��ʶ; bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkShow(const char* strID,BOOL bShow);


	//��������: ���þ������Ա�ʶ������ʽ
	//�������: strID������ID; font��������ʽ(����,����_GB2312��); color���ı���ɫ
	//�������: bgcolor��������ɫ(RGB(-1,-1,-1)��ʾ�����)��bgalpha��������ɫ͸���ȣ�bgoutlinecolor��������������ɫ(RGB(-1,-1,-1)��ʾ������������)
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkLabelStyle(const char* strID,QFont font = QFont("Times", 10, QFont::Bold),QColor color = QColor(255,0,0),QColor bgcolor = QColor(-1,-1,-1),
		QColor bgoutlinecolor = QColor(-1,-1,-1),float bgalpha = 0.5);

	//��������: �����Ƿ���ʾ�����ʶ���ڻ��ƾ����ʶ����ǰ���ô˽ӿڣ�
	//�������: bShow��TRUE ��ʾ��FALSE ����ʾ;
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkLabelShow(BOOL bShow);

	//�������ܣ�����IDΪstrID��������Ա�ʶ���ݣ����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
	//���������strID������ID��sContent�������ʶ����(������"\n"��ʾ����)
	//�����������
	//����ֵ����
	virtual void DrawMiliMarkLabel(const char* strID,QString sContent);

	//��������: �Ƿ���ʾָ���������Ա�ʶ�����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
	//�������: strID�������Ψһ��ʶ��bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkLabelShow(const char* strID,BOOL bShow);

	//��������: ����ָ�����꺽����󳤶ȣ����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
	//�������: strID������ı�ʶ��nLength����󳤶�(Ĭ��Ϊ500��)
	//�������:��
	//����ֵ: ��
	virtual void SetHJLength(const char* strID,int nLength);

	//��������: �����Ƿ���ʾ���꺽��(Ĭ�ϲ���ʾ)�����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
	//�������: strID������ı�ʶ��bShow��TRUE ��ʾ��FALSE ����ʾ
	//�������:��
	//����ֵ: ��
	virtual void SetMiliMarkHJShow(const char* strID,BOOL bShow);

	//���ܣ��趨������ת�Ƕȣ����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
	//���������strID������ID�� fAngle����ת�Ƕȣ�����������н�,��ʱ����ת��
	//�����������
	//����ֵ����
	virtual void SetMiliMarkAngle(const char* strID,float fAngle);

	//���ܣ��趨�����С�����ô˽ӿ�ʱ�����Ѿ�����IDΪstrID�ľ��꣩
	//���������strID������ID�� fScale�����ű�����>1 ��ʾ�Ŵ�<1 ��ʾ��С��
	//�����������
	//����ֵ����
	virtual void SetMiliMarkScale(const char* strID,float fScale);

	//�������ܣ���ȡ�������ƺ;������
	//�����������
	//�����������������
	//����ֵ����
	virtual void GetMiliMarkInfo(vector<RocMap_JBAttr> &vJBAttr);


	//////////////////////////////////////////////////////////////////////////
	//��ͼ���㹦�� begin
	//////////////////////////////////////////////////////////////////////////

	//��������: ��ȡ��ǰ��ͼ������
	//�������:��
	//�������:��
	//����ֵ: ������
	virtual float GetMapScale();

	//��������: ��ȡ��ǰӰ���LOD�ȼ�
	//�������:��
	//�������:��
	//����ֵ: LOD�ȼ�
	virtual int GetLodLevel();

	//��������: ��ȡ�����֮��ľ��룬���ֱ������Ļ�ϲ��ʱʹ��
	//�������:��
	//�������:��
	//����ֵ: ��
	virtual void GetDistance();

	//��������: ��ȡ���֮�����
	//�������:vdPt���㼯����γ�ȣ�
	//�������:��
	//����ֵ: ����ֵ(��λ������)
	virtual float GetDistance(vector<RocMap_CDPoint> vdPt);

	//��������: ����������������ֱ������Ļ�ϲ����ʱʹ��
	//�������: ��
	//�������:��
	//����ֵ: ��
	virtual void GetArea();

	//��������: ��ȡ�������������
	//�������:vdPt���㼯����γ�ȣ�
	//�������:��
	//����ֵ: ���(��λ��ƽ������)
	virtual float GetArea(vector<RocMap_CDPoint> vdPt);

	//��������: �����������߽Ƕ�����������нǣ����ֱ������Ļ�ϲ�Ƕ�ʱʹ��
	//�������: ��
	//�������:��
	//����ֵ: ��
	virtual void GetAngle();

	//��������: �����������߽Ƕ�����������н�
	//�������: dPt0�� ��㾭γ�ȣ� dPt1�� �յ㾭γ�ȣ�
	//�������:��
	//����ֵ: �Ƕ�ֵ(��)
	virtual float GetAngle(RocMap_CDPoint dPt0,RocMap_CDPoint dPt1);

	//��������: ���ݾ�γ�Ȼ�ȡ�߶�
	//�������: dPt����γ��
	//�������: ��
	//����ֵ:�߶�ֵ
	virtual float GetHeight(RocMap_CDPoint dPt);

	//��������: ��Ļ����ת��γ��
	//�������: pt����Ļ����
	//�������: ������Ϣ(��γ��)
	//����ֵ:��
	virtual void XYtoLB(QPoint pt,RocMap_CDPoint& dPt);

	//��������: ��γ��ת��Ļ����
	//�������: dPt ��γ��
	//�������: ��
	//����ֵ:��Ļ����
	virtual QPoint LBtoXY(RocMap_CDPoint dPt);

	//�������ܣ�������һ��������
	//���������dSrcPt���ο��������ꣻfAngle���������ο���������н� (��λ:��)��fDist�������Ͳο���ľ��룬��λ������
	//���������dObjPt�������ĵ�������
	//����ֵ��TRUE���ɹ���FALSE��ʧ��
	virtual BOOL GetGeoPoint(RocMap_CDPoint dSrcPt,float fAngle,float fDist,RocMap_CDPoint& dObjPt);


	//////////////////////////////////////////////////////////////////////
	//������:Release
	//����ֵ����
	//����:��
	//����˵��:�ͷź���
	/////////////////////////////////////////////////////////////////////
	virtual void Release();

	//////////////////////////////////////////////////////////////////////
	//������:GetName
	//����ֵ����
	//����:LPSTR sName-��ȡ�ӿ�����
	//����˵��:�ӿ�����
	/////////////////////////////////////////////////////////////////////
	virtual void GetName(LPSTR sName);

	//////////////////////////////////////////////////////////////////////
	//������:Init
	//����ֵ����
	//����:��
	//����˵��:��ʼ���ӿ�
	/////////////////////////////////////////////////////////////////////
	virtual void Init();

private:	
	UGMap& GetMap();

	void ReviseCursor();

	void SetWaitCursor();

	void CreateUGGrpaphics(UGGraphics* &pGraphics);

	void ReleaseUGGraphics(UGGraphics* &pGraphics);

	void PaintToQPainter();

	/*
	 *	���Ϊinvalidate״̬��������paintEvent
	 */
	void Invalidate();

	UGC::UGMapEditorWnd *m_mapWnd;   

	UGC::UGWorkspace *m_workSpace;

	UGImage* m_pMapImage;
	UGImage* m_pOldImage;

	int m_width;
	int m_height;

	QPoint m_pressPt;
	UGdouble defaultScale;
	UGPoint2D defaultCenter;

	BOOL invalidate;
};


#endif