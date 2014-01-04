#ifndef QTMAPCONTROL_H_
#define QTMAPCONTROL_H_

#include <QtGui/QWidget>


#include "MapEditor/UGMapEditorWnd.h"
#include "Graphics/UGGraphicsManager.h"
#include "Graphics/UGGraphics.h"
#include "Workspace/UGResources.h"

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
		/**
		 * �Ŵ�
		 * @param pt �Ըõ�Ϊ���ģ����أ�
		 * @param ratio �Ŵ���������1�Ŵ�С��1��С
		 */
		void Zoom(const QPoint& pt,double ratio);

		/**
		 * ƽ��
		 * @param dOffsetX X�������أ�
		 * @param dOffsetY Y�������أ�
		 */
		void Pan(UGdouble dOffsetX, UGdouble dOffsetY);

		/*
		 *	����ƽ��״̬
		 */
		void Pan();

		// -----------------�ڲ������ӿ�-------------------

		/*
		 *	��Ļ����ת�ɵ�ͼ����
		 */
		UGPoint2D PixelToMap(const QPoint &point);

		/*
		 *	��ͼ����ת����Ļ����
		 */
		QPoint MapToPixel(const UGPoint2D &point2D);

private:

	UGC::UGWorkspace*loadDefaultWkSpace();
	
	UGMap& GetMap();

	void ReviseCursor();

	void SetWaitCursor();

	UGC::UGMapEditorWnd *m_mapWnd;   

	UGC::UGWorkspace *m_workSpace;

	int m_width;
	int m_height;

	QPoint m_pressPt;
};


#endif