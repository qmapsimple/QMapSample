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


		// -----------------内部基础接口-------------------

		/*
		 *	屏幕坐标转成地图坐标
		 */
		UGPoint2D PixelToMap(const QPoint &point);

		/*
		 *	地图坐标转成屏幕坐标
		 */
		QPoint MapToPixel(const UGPoint2D &point2D);

		UGWorkspace* GetWorkspace(); 

		UGMapEditorWnd* GetUGMapWnd();
		
public:
	/************************************************************************/
	/* 实现IMap2DInterface对应的接口                                   */
	/************************************************************************/
	//函数功能：刷新地图
	//输入参数：无
	//输出参数：无
	//返回值：无
	virtual void Refresh();

	//函数功能: 地图漫游拖动
	//输入参数: 无
	//输出参数:无
	//返回值: 无
	virtual void Wander();

	//函数功能: 地图漫游到指定点
	//输入参数: dPt：预漫游位置(经纬度)
	//输出参数:无
	//返回值: 无
	virtual void Wander(QPointF dPt);

	//函数功能: 地图放大
	//输入参数: 无
	//输出参数:无
	//返回值: 无
	virtual void ZoomIn();

	//函数功能: 地图以指定系数放大（缩放点为屏幕中心点）
	//输入参数: fZoomFactor：缩放系数(必须大于1)
	//输出参数:无
	//返回值: 无
	virtual void ZoomIn(float fZoomFactor);

	//函数功能: 地图以指定系数、指定点放大
	//输入参数: fZoomFactor：缩放系数(必须大于1)；dPt：指定中心点(经纬度)
	//输出参数:无
	//返回值: 无
	virtual void ZoomIn(float fZoomFactor,QPointF dPt);

	//函数功能: 地图缩小
	//输入参数: 无
	//输出参数:无
	//返回值: 无
	virtual void ZoomOut();

	//函数功能: 地图以指定系数缩小（缩放点为屏幕中心点）
	//输入参数: fZoomFactor：缩放系数(必须小于1大于0)
	//输出参数:无
	//返回值: 无
	virtual void ZoomOut(float fZoomFactor);

	//函数功能: 地图以指定系数、指定点缩小
	//输入参数: fZoomFactor：缩放系数(必须小于1大于0)；dPt：指定中心点(经纬度)
	//输出参数:无
	//返回值: 无
	virtual void ZoomOut(float fZoomFactor,QPointF dPt);

	//函数功能: 地图恢复初始状态（初始位置和比例尺等）
	//输入参数: 无
	//输出参数:无
	//返回值: 无
	virtual void Back();

	//函数功能:鼠标指针状态，恢复当前鼠标操作
	//输入参数: 无
	//输出参数:无
	//返回值: 无
	virtual void Pointer();

	


	//////////////////////////////////////////////////////////////////////////
	//地图量算功能 begin
	//////////////////////////////////////////////////////////////////////////

	//函数功能: 获取当前地图比例尺
	//输入参数:无
	//输出参数:无
	//返回值: 比例尺
	virtual float GetMapScale();


	//函数功能: 获取多个点之间的距离，鼠标直接在屏幕上测距时使用
	//输入参数:无
	//输出参数:无
	//返回值: 无
	virtual void GetDistance();



	//函数功能: 屏幕坐标转经纬高
	//输入参数: pt：屏幕坐标
	//输出参数: 地理信息(经纬高)
	//返回值:无
	virtual void XYtoLB(QPoint pt,QPointF& dPt);

	//函数功能: 经纬度转屏幕坐标
	//输入参数: dPt 经纬度
	//输出参数: 无
	//返回值:屏幕坐标
	virtual QPoint LBtoXY(QPointF dPt);


	//////////////////////////////////////////////////////////////////////
	//函数名:Release
	//返回值：无
	//参数:无
	//函数说明:释放函数
	/////////////////////////////////////////////////////////////////////
	virtual void Release();



	//////////////////////////////////////////////////////////////////////
	//函数名:Init
	//返回值：无
	//参数:无
	//函数说明:初始化接口
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
	 *	标记为invalidate状态，并触发paintEvent
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