#ifndef PLANEINFOCONTROL_H_
#define PLANEINFOCONTROL_H_

#include <string>
#include "Geometry/UGGeoLine.h"
#include <QWidget>
#include <QLabel>
#include <QPoint>
#include <QMouseEvent>
using namespace UGC;
/**
 * ��ͼ�ؼ���
 */
class PlaneInfoControl : public QWidget
{
	Q_OBJECT

public:
	PlaneInfoControl(QWidget *parent = 0, Qt::WFlags flags = 0);
	~PlaneInfoControl();


	void SetPlaneID(UGString planeID);
	UGString GetPlaneID();

	void SetAirport(UGString from,UGString to);

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

	void SetPosition(QPoint pt);

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