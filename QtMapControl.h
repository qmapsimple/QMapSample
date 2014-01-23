#ifndef QTMAPCONTROL_H_
#define QTMAPCONTROL_H_

#include <QtGui/QWidget>
#include "Plane.h"
#include <vector>
#include <QTimer>
#include <QPointF>

#include "Stream/ugdefs.h"

namespace UGC
{
	class UGGraphics;
	class UGImage;
	class UGWorkspace;
	class UGMapEditorWnd;
	class UGMap;
}
using namespace UGC;

/**
 * ��ͼ�ؼ���
 */
class QtMapControl : public QWidget
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

		UGWorkspace* GetWorkspace(); 

		UGMapEditorWnd* GetUGMapWnd();
		
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
	virtual void Wander(QPointF dPt);

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
	virtual void ZoomIn(float fZoomFactor,QPointF dPt);

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
	virtual void ZoomOut(float fZoomFactor,QPointF dPt);

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

	


	//////////////////////////////////////////////////////////////////////////
	//��ͼ���㹦�� begin
	//////////////////////////////////////////////////////////////////////////

	//��������: ��ȡ��ǰ��ͼ������
	//�������:��
	//�������:��
	//����ֵ: ������
	virtual float GetMapScale();


	//��������: ��ȡ�����֮��ľ��룬���ֱ������Ļ�ϲ��ʱʹ��
	//�������:��
	//�������:��
	//����ֵ: ��
	virtual void GetDistance();



	//��������: ��Ļ����ת��γ��
	//�������: pt����Ļ����
	//�������: ������Ϣ(��γ��)
	//����ֵ:��
	virtual void XYtoLB(QPoint pt,QPointF& dPt);

	//��������: ��γ��ת��Ļ����
	//�������: dPt ��γ��
	//�������: ��
	//����ֵ:��Ļ����
	virtual QPoint LBtoXY(QPointF dPt);


	//////////////////////////////////////////////////////////////////////
	//������:Release
	//����ֵ����
	//����:��
	//����˵��:�ͷź���
	/////////////////////////////////////////////////////////////////////
	virtual void Release();



	//////////////////////////////////////////////////////////////////////
	//������:Init
	//����ֵ����
	//����:��
	//����˵��:��ʼ���ӿ�
	/////////////////////////////////////////////////////////////////////
	virtual void Init();



	public slots:
		void showTime();
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

	void InitPlans();

	void DrawPlane(QImage *pQImage);



	UGC::UGMapEditorWnd *m_mapWnd;   

	UGC::UGWorkspace *m_workSpace;

	UGImage* m_pMapImage;
	UGImage* m_pOldImage;

	int m_width;
	int m_height;

	QPoint m_pressPoint;
	QPoint m_dragPoint;
	bool draging;

	UGdouble defaultScale;
	UGPoint2D defaultCenter;

	bool invalidate;

	std::vector<Plane> planes;
	QImage imageAPlane;
	QImage imageBPalne;
	QTimer m_timer;
	QImage *m_pQimage;
	int count;
};


#endif