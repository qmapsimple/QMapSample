#ifndef QTMAPCONTROL_H_
#define QTMAPCONTROL_H_

#include <QtGui/QWidget>


#include "MapEditor/UGMapEditorWnd.h"
#include "Graphics/UGGraphicsManager.h"
#include "Graphics/UGGraphics.h"
#include "Workspace/UGResources.h"

using namespace UGC;
/**
 * 绘图控件类
 */
class QtMapControl : public QWidget
{
	Q_OBJECT

public:
	QtMapControl(QWidget *parent = 0, Qt::WFlags flags = 0);
	~QtMapControl();
//-------------------------------重写基类函数------------------------------------
		/**
		 * 重写绘制函数
		 */
		virtual void paintEvent( QPaintEvent * event );
		/**
		 * 重写鼠标滚轮函数
		 */
		virtual void wheelEvent( QWheelEvent * event );
		/**
		 * 重写鼠标按下函数
		 */
		virtual void mousePressEvent ( QMouseEvent * event );
		/**
		 * 重写鼠标弹起函数
		 */
		virtual void mouseReleaseEvent ( QMouseEvent * event );
		/**
		 * 重写鼠标移动函数
		 */
		virtual void mouseMoveEvent ( QMouseEvent * event );
		/**
		 * 重写当窗口大小发生改变时函数
		 */
		virtual void resizeEvent ( QResizeEvent * event );
		/**
		 * 全幅
		 */
		void ViewEntire();
		/**
		 * 放大
		 * @param pt 以该点为中心（像素）
		 * @param ratio 放大倍数，大于1放大，小于1缩小
		 */
		void Zoom(const QPoint& pt,double ratio);

		/**
		 * 平移
		 * @param dOffsetX X方向（像素）
		 * @param dOffsetY Y方向（像素）
		 */
		void Pan(UGdouble dOffsetX, UGdouble dOffsetY);

		/*
		 *	进入平移状态
		 */
		void Pan();

		// -----------------内部基础接口-------------------

		/*
		 *	屏幕坐标转成地图坐标
		 */
		UGPoint2D PixelToMap(const QPoint &point);

		/*
		 *	地图坐标转成屏幕坐标
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