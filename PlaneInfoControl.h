#ifndef PLANEINFOCONTROL_H_
#define PLANEINFOCONTROL_H_

#include <QLabel>
#include <QWidget>



#include "Stream/ugdefs.h"
using namespace UGC;
/**
 * 绘图控件类
 */
class PlaneInfoControl : public QWidget
{
	Q_OBJECT

public:
    PlaneInfoControl(QWidget *parent = 0);
	~PlaneInfoControl();


	void SetPlaneID(UGString planeID);
	UGString GetPlaneID();

	void SetAirport(UGString from,UGString to);

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

	void SetPosition(QPoint pt);
	QPoint GetPosition();

private:
	UGString m_from;
	UGString m_to;
	UGString m_id;
	QLabel* label1;
	QLabel* label2;
	QPoint m_pressPt;
	QPoint m_dpt;
	QPoint m_position;
};

#endif