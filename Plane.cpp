
#include <QCursor>
#include "Plane.h"
#include "PlaneInfoControl.h"


#include "Algorithm/UGOpPointLine.h"
#include "Algorithm/UGOpLines.h"
#include "Algorithm/UGOpPoints.h"
#include "Map/UGMap.h"
#include "Drawing/UGDrawing.h"
#include "MapWindow/UGMapWnd.h"

#include <QPoint>

Plane::Plane()
{
	offsetTimes= 100;
	xOffset= 0;
	yOffset= 0;
	currentIndex = -1;

	control = NULL;
}

Plane::Plane( UGPoint2D startLocation, UGPoint2D endLocation,UGString flightId,UGString startName,UGString endName )
{
	offsetTimes= 100;
	xOffset= 0;
	yOffset= 0;
	currentIndex = -1;

	control = NULL;
	{
		startPt = startLocation;
		endPt = endLocation;
		id = flightId;
		startCity = startName;
		endCity = endName;
		currentIndex = 0;

		xOffset = (endLocation.x - startLocation.x);
		yOffset = (endLocation.y - startLocation.y);


		xOffset = xOffset / offsetTimes;
		yOffset = yOffset / offsetTimes;
	}
}

Plane::~Plane()
{
}

QPoint MapToPixel(const UGPoint2D &point2D,UGMap *map)
{
	UGPoint pt(0,0);
	map->GetDrawing()->m_DrawParam.MPtoLP(point2D,pt);
	UGDrawCache &drawing = map->GetDrawing()->m_DrawCache;	
	drawing.LPtoDP(&pt,1);
	return QPoint(pt.x,pt.y);
}

void Plane::drawPlane(QPainter&paint,QImage& imageA,UGC::UGMapWnd *m_mapWnd,int count )
{
	int i = count%offsetTimes;
	double dRatio = ((double)i)/offsetTimes;
	UGPoint2D ptSrc = UGOpLines::FindPointOnLineByRatio(startPt,endPt,dRatio);
	UGMap *m_pMap = (UGMap*)&(m_mapWnd->m_Map);
	QPoint ptStart = MapToPixel(startPt,m_pMap);
	QPoint ptMid = MapToPixel(ptSrc,m_pMap);
	paint.drawLine(ptStart,ptMid);
	QImage imgRatate;
	QMatrix matrix;
	double angle = UGOpPoints::Angle(startPt,endPt);
	matrix.rotate(-angle+90);
	QImage img = imageA.transformed(matrix);
	int imgX = ptMid.x() - img.width()*0.5;
	int imgY = ptMid.y() - img.height()*0.5;
	paint.drawImage(QPoint(imgX,imgY),img);
	
	if (control != NULL)
	{
		control->SetPosition(QPoint(imgX,imgY));
		QRect rect = control->geometry();
		QPoint ptImage(rect.x(),rect.y());;
		paint.drawLine(ptImage,ptMid);
	}

	
}

void Plane::AddControl( QWidget*widget,UGC::UGMapWnd *m_mapWnd)
{
	if (control == NULL && id.ToInt()%100 == 0)
	{
		UGMap *m_pMap = (UGMap*)&(m_mapWnd->m_Map);

		control = new PlaneInfoControl(widget);
		control->SetPlaneID(id);
		control->SetAirport(startCity,endCity);


		control->setAutoFillBackground(true);
		control->setPalette(QColor(240,240,240,240));
		QPoint ptStart = MapToPixel(startPt,m_pMap);
		control->setGeometry(ptStart.x(),ptStart.y(),120,80);
	}
}

void Plane::OffsetLabel( int xOffset,int yOffset )
{
	if(control != NULL)
	{
		QPoint pos = control->GetPosition();
		int x = pos.x() + xOffset;
		int y = pos.y() + yOffset;
		QRect rect = control->geometry();
		rect.moveTo(x,y);
		control->setGeometry(rect);
	}
	
}
