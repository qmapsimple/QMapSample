#ifndef PLANE_H_
#define PLANE_H_

#include "Stream/ugdefs.h"
#include "MapEditor/UGMapEditorWnd.h"
using namespace UGC;
#include <QPainter>
#include "PlaneInfoControl.h"
class Plane
{
public:
	Plane();
	Plane(UGPoint2D startLocation, UGPoint2D endLocation,UGString flightId,UGString startName,UGString endName);
	
	~Plane();

	void drawPlane(QPainter&paint,QImage& imageA,UGC::UGMapWnd *m_mapWnd,int count );

	void AddControl(QWidget*widget,UGC::UGMapWnd *m_mapWnd);

	void OffsetLabel(int xOffset,int yOffset);
private:
	UGPoint2D startPt;
	UGPoint2D endPt;
	UGString startCity;
	UGString endCity;
	UGString id;
	int currentIndex;
	double xOffset;
	double yOffset;
	int offsetTimes;

	PlaneInfoControl *control;
	QRect rect;
};

#endif