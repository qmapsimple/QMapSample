#include "QtMapControl.h"

#include "QtGui/QMessageBox.h"
#include <QPainter>
#include <QWheelEvent>

using namespace UGC;

UGC::UGWorkspace *QtMapControl::loadDefaultWkSpace()
{
#ifdef _WIN32
	UGGraphicsManager::SetCurGraphicsType(UGGraphics::GT_Windows);	
#else
	UGGraphicsManager::SetCurGraphicsType(UGGraphics::GT_MEM);
#endif

	m_mapWnd = new UGMapEditorWnd();

	//这里UGC也把UGMapWnd初始化了，所以不用再初始化UGMapWnd
	m_mapWnd->Initialize();
	m_mapWnd->SetUserAction(UGDrawParamaters::uaPan);

	m_workSpace = new UGWorkspace;


	UGString path = "../Data/";

	UGString strFileName = path + "China400_6.0.smwu";

	UGbool isOpen = m_workSpace->Open(strFileName);

	if(!isOpen)
	{
		delete m_workSpace;
		m_workSpace = NULL;
		return NULL;
	}

	UGMap *pMap = (UGMap*)&(m_mapWnd->m_mapWnd.m_Map);
	pMap->SetWorkspace(m_workSpace);

	pMap->m_TrackingLayer.SetVisible(TRUE);
	pMap->m_TrackingLayer.SetEditable(TRUE);
	pMap->m_TrackingLayer.SetSelectable(TRUE);
	pMap->m_TrackingLayer.SetLineSmoothingMode(true);


	int nMapCount = m_workSpace->m_MapStorages.GetCount();
	UGString str = m_workSpace->m_MapStorages.GetMapAt(0)->GetName();
	pMap->SetRefreshFlag(TRUE);
	if(!pMap->Open(str))
	{
		delete m_workSpace;
		m_workSpace = NULL;
		return NULL;
	}
	return m_workSpace;
}
QtMapControl::QtMapControl( QWidget *parent /*= 0*/, Qt::WFlags flags /*= 0*/ )
{
	m_width = this->width();
	m_height = this->height();
	m_workSpace = NULL;
	m_mapWnd = NULL;
	loadDefaultWkSpace();
}

QtMapControl::~QtMapControl()
{
	delete m_mapWnd;
	delete m_workSpace;
}

void QtMapControl::paintEvent( QPaintEvent * event )
{
	SetWaitCursor();
	UGC::UGGraphics* pGraphics = UGC::UGGraphicsManager::NewGraphics();
	pGraphics->CreateCompatibleGraphics(NULL);
	UGImage* pMemImage = UGGraphicsManager::NewImage();
	pMemImage->CreateCompatibleImage(NULL,m_width,m_height);
	
	
	pGraphics->SelectImage(pMemImage);
	UGRect rcInvalid(0,0,m_width,m_height);
	m_mapWnd->OnDraw(pGraphics,rcInvalid,rcInvalid,false,false);

	QImage *pQImage = NULL;
	UGC::UGImageData imageData;
	pMemImage->GetImageData(imageData);
	int w = imageData.nWidth;
	int h = imageData.nHeight;
	pQImage = new QImage((UGC::UGbyte*)pMemImage->GetColors(),w,h,QImage::Format_ARGB32);
	QPainter paint(this);
	paint.drawImage(QRectF(0,0,m_width,m_height),*pQImage);
	delete pQImage;
	ReviseCursor();
}

UGMap& QtMapControl::GetMap()
{
	return m_mapWnd->m_mapWnd.m_Map;
}

void QtMapControl::SetWaitCursor()
{
	setCursor(QCursor(Qt::WaitCursor));
}

void QtMapControl::ReviseCursor()
{
	switch(m_mapWnd->m_mapWnd.GetCursorShape())
	{
	case UGC::UGMapWnd::ecBusy :
		{
			SetWaitCursor();
			break;
		}
	case UGC::UGMapWnd::ecArrow:
		{
			setCursor(QCursor(Qt::ArrowCursor));
			break;
		}
	case UGC::UGMapWnd::ecMarginPanLeft:
		{
			setCursor(QCursor(QPixmap("Resources/pan_left.png"),0, 15));
			break;
		}
	case UGC::UGMapWnd::ecMarginPanRight:
		{
			setCursor(QCursor(QPixmap("Resources/pan_right.png"),30, 10));
			break;
		}
	case UGC::UGMapWnd::ecMarginPanTop:
		{
			setCursor(QCursor(QPixmap("Resources/pan_top.png"),10, 0));	
			break;
		}
	case UGC::UGMapWnd::ecMarginPanBottom:
		{
			setCursor(QCursor(QPixmap("Resources/pan_bottom.png"),10, 30));
			break;
		}
	case UGC::UGMapWnd::ecMarginPanTopLeft:
		{
			setCursor(QCursor(QPixmap("Resources/pan_topleft.png"),0,0));
			break;
		}
	case UGC::UGMapWnd::ecMarginPanTopRight:
		{
			setCursor(QCursor(QPixmap("Resources/pan_topright.png"),30, 0));
			break;
		}
	case UGC::UGMapWnd::ecMarginPanBottomRight:
		{
			setCursor(QCursor(QPixmap("Resources/pan_bottomright.png"),30, 30));
			break;
		}
	case UGC::UGMapWnd::ecMarginPanBottomLeft:
		{
			setCursor(QCursor(QPixmap("Resources/pan_bottomleft.png"),0, 30));
			break;
		}
	case UGC::UGMapWnd::ecZoomFree:
	case UGC::UGMapWnd::ecZoomFree2:
		{
			setCursor(QCursor(QPixmap("Resources/ZoomFree.png")));
			break;
		}
	case UGC::UGMapWnd::ecPan:
		{
			setCursor(QCursor(QPixmap("Resources/pan.png")));
			break;
		}
	case UGC::UGMapWnd::ecPan2:
		{
			setCursor(QCursor(QPixmap("Resources/pan2.png")));
			break;
		}
	case UGC::UGMapWnd::ecZoomIn:
		{
			setCursor(QCursor(QPixmap("Resources/ZoomIn.png"),2,2));
			break;
		}
	case UGC::UGMapWnd::ecZoomOut:
		{
			setCursor(QCursor(QPixmap("Resources/ZoomOut.png"),2,2));
			break;
		}
	case UGC::UGMapWnd::ecPointModeSelect:
	case UGC::UGMapWnd::ecPointModeSelectTrue:
	case UGC::UGMapWnd::ecRectModeSelect:
	case UGC::UGMapWnd::ecLineModeSelect:
		{
			setCursor(QCursor(QPixmap("Resources/select.png"),4,4));
			break;
		}
	case UGC::UGMapWnd::ecCircleModeSelect:
		{
			setCursor(QCursor(QPixmap("Resources/select_circle.png"),64,64));
			break;
		}
	case UGC::UGMapWnd::ecRegionModeSelect:
		{
			setCursor(QCursor(QPixmap("Resources/select_region.png"),64,64));
			break;
		}
	case UGC::UGMapWnd::ecDrawPoint:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editpoint.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawLineSect:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editlinesect.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawPolyLine:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editpolygonline.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawEllipseArc:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editarc.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawArc3P:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editarc3d.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawCurve:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editbeziercurve.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawRectangle:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editrectangle.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawRoundRect:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editroundrect.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawCircle:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editcircle.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawCircle3P:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editcircle3p.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawCircle2P:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editcircle2p.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawEllipse:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editellipse.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawObliqueEllipse:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editskewellipse.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawPolyGon:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editpolygon.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawText:
		{
			setCursor(QCursor(Qt::IBeamCursor));
			break;
		}
	case UGC::UGMapWnd::ecDrawStreamText:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editstreamtext.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawParallel:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editparallel.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawPie:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editPie.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecDrawParallelogram:
		{
			setCursor(QCursor(QPixmap("Resources/cur_editskew.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecCross:
		{
			setCursor(QCursor(Qt::CrossCursor));
			break;
		}
	case UGC::UGMapWnd::ecRotation:
		{
			setCursor(QCursor(QPixmap("Resources/cur_rotate.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecBeam:
		{
			setCursor(QCursor(QPixmap("Resources/cur_Beam.png")));
			break;
		}
	case UGC::UGMapWnd::ecMove:
		{
			setCursor(QCursor(QPixmap("Resources/cur_move.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecNorthSouth:
		{
			setCursor(QCursor(Qt::SizeVerCursor));
			break;
		}
	case UGC::UGMapWnd::ecWestEast:
		{
			setCursor(QCursor(Qt::SizeHorCursor));
			break;
		}
	case UGC::UGMapWnd::ecNorthwestSoutheast:
		{
			setCursor(QCursor(Qt::SizeFDiagCursor));
			break;
		}
	case UGC::UGMapWnd::ecNortheastSoutnwest:
		{
			setCursor(QCursor(Qt::SizeBDiagCursor));
			break;
		}
	case UGC::UGMapWnd::ecCrossSnapPoint:
		{
			setCursor(QCursor(QPixmap("Resources/cursor_e.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecCrossSnapVertex:
		{
			setCursor(QCursor(QPixmap("Resources/ecCrossSnapVertex.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecCrossSnapMidpoint:
		{
			setCursor(QCursor(QPixmap("Resources/ecCrossSnapMidpoint.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecCrossSnapLine:
		{
			setCursor(QCursor(QPixmap("Resources/ecCrossSnapLine.png"),8,8));
			break;
		}
	case UGC::UGMapWnd::ecCrossSnapVertical:
		{
			setCursor(QCursor(Qt::SplitVCursor));
			break;
		}
	case UGC::UGMapWnd::ecCrossSnapParallel:
		{
			setCursor(QCursor(Qt::SplitHCursor));
			break;
		}
	case UGC::UGMapWnd::ecMoveRotateBase:
		{
			setCursor(QCursor(QPixmap("Resources/cur_moverotatebase.png")));
			break;
		}
	default:
		break;
	}
}

QPoint QtMapControl::MapToPixel(const UGPoint2D &point2D)
{
	UGMap& map = this->GetMap();
	UGPoint pt(0,0);

	map.GetDrawing()->m_DrawParam.MPtoLP(point2D,pt);

	UGDrawCache &drawing = map.GetDrawing()->m_DrawCache;	
	
	drawing.LPtoDP(&pt,1);

	return QPoint(pt.x,pt.y);
}

UGPoint2D QtMapControl::PixelToMap(const QPoint &point)
{
	UGMap& map = this->GetMap();

	UGDrawCache &drawing = map.GetDrawing()->m_DrawCache;	
	UGPoint pt(point.x(),point.y());
	drawing.DPtoLP(&pt,1);

	UGPoint2D pt2D(0,0);

	map.GetDrawing()->m_DrawParam.LPtoMP(pt,pt2D);

	
	return pt2D;
}
void QtMapControl::wheelEvent( QWheelEvent * event )
{
	
	double dScale = 1;
	if(event->delta() < 0)//缩小
	{
		dScale = 0.7;
	}
	else
	{
		dScale = 1.3;
	}
	int x = event->x();
	int y = event->y();
	UGPoint2D preLoction = this->PixelToMap(event->pos());
	m_mapWnd->Zoom(dScale);

	UGPoint2D curLoction = this->PixelToMap(event->pos());

	this->GetMap().Pan(curLoction.x-preLoction.x,curLoction.y-preLoction.y);
	m_mapWnd->Refresh();

	this->update();
}

void QtMapControl::mousePressEvent( QMouseEvent * event )
{

}

void QtMapControl::mouseReleaseEvent( QMouseEvent * event )
{

}

void QtMapControl::mouseMoveEvent( QMouseEvent * event )
{

}

void QtMapControl::resizeEvent( QResizeEvent * event )
{
	QWidget::resizeEvent(event);
	m_width = this->width();
	m_height = this->height();
	update();
}

