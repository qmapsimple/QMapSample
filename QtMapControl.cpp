#pragma once

#include "Base3D/UGWindowTypes3D.h"

#include "QtMapControl.h"


#include "MapEditor/UGMapEditorWnd.h"
#include "Workspace/UGWorkspace.h"
#include "Graphics/UGGraphicsManager.h"
#include "Graphics/UGGraphics.h"
#include "Graphics/UGImage.h"

#include "Geometry/UGGeoPoint.h"


#include "QtGui/QMessageBox.h"
#include <QPainter>
#include <QWheelEvent>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

using namespace UGC;

UGC::UGuint GetUGKeyflagMasks(QInputEvent * event)
{
	UGC::UGuint flag=0;
	if (event->modifiers()&Qt::ShiftModifier)
	{
		flag=flag|UG_MK_SHIFT;
	} 
	if ((event->modifiers()&Qt::ControlModifier))
	{
		flag=flag|UG_MK_CONTROL;
	}
	return flag;
}

QtMapControl::QtMapControl( QWidget *parent /*= 0*/, Qt::WFlags flags /*= 0*/ )
{
	m_width = this->width();
	m_height = this->height();
	m_workSpace = NULL;
	m_mapWnd = NULL;
	m_pMapImage = NULL;
	invalidate = FALSE;

	imageAPlane = QImage("Resources/Plane.png");
	imageBPalne = QImage("Resources/SelectPlane.png");
	imageAPlane = imageAPlane.scaled(imageAPlane.width(),imageAPlane.height());
	count = 0;

	this->Init();
	this->InitPlans();

	m_timer.setInterval(1000);
	m_timer.start();
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(showTime()));  
}

void QtMapControl::ViewEntire()
{
	m_mapWnd->ViewEntire();
}

QtMapControl::~QtMapControl()
{
	this->Release();
}

void QtMapControl::paintEvent( QPaintEvent * event )
{

	if (invalidate)
	{
		invalidate = FALSE;
		SetWaitCursor();
		UGGraphics* pGraphics= NULL;
		CreateUGGrpaphics(pGraphics);

		UGRect rcInvalid(0,0,m_width,m_height);
		m_mapWnd->OnDraw(pGraphics,rcInvalid,rcInvalid,false,false);

		ReleaseUGGraphics(pGraphics);

		ReviseCursor();
	}

	PaintToQPainter();
	
}

UGMap& QtMapControl::GetMap()
{
	return m_mapWnd->m_mapWnd.m_Map;
}

void QtMapControl::SetWaitCursor()
{
	static QCursor wait(Qt::WaitCursor);
	setCursor(wait);
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
			static QCursor arrow(Qt::ArrowCursor);
			setCursor(arrow);
			break;
		}
	case UGC::UGMapWnd::ecMarginPanLeft:
		{
			static QCursor panleft(QPixmap("Resources/pan_left.png"),0, 15);
			setCursor(panleft);
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
			static QCursor pan(QPixmap("Resources/pan.png"));
			setCursor(pan);
			break;
		}
	case UGC::UGMapWnd::ecPan2:
		{
			static QCursor pan2(QPixmap("Resources/pan2.png"));
			setCursor(pan2);
			break;
		}
	case UGC::UGMapWnd::ecZoomIn:
		{
			static QCursor zoomin(QPixmap("Resources/ZoomIn.png"),2,2);
			setCursor(zoomin);
			break;
		}
	case UGC::UGMapWnd::ecZoomOut:
		{
			static QCursor zoomout(QPixmap("Resources/ZoomOut.png"),2,2);
			setCursor(zoomout);
			break;
		}
	case UGC::UGMapWnd::ecPointModeSelect:
	case UGC::UGMapWnd::ecPointModeSelectTrue:
	case UGC::UGMapWnd::ecRectModeSelect:
	case UGC::UGMapWnd::ecLineModeSelect:
		{
			static QCursor select(QPixmap("Resources/select.png"),4,4);
			setCursor(select);
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
	this->Refresh();
}

void QtMapControl::mousePressEvent( QMouseEvent * event )
{
	QWidget::mousePressEvent(event);
	int nflag= 0;//GetUGKeyflagMasks(event);
	UGPoint location(event->x(),event->y());
	UGGraphics* pGraphics= NULL;

	if(event->button ()==Qt::LeftButton)
	{
		UGGraphics* pGraphics= NULL;
		CreateUGGrpaphics(pGraphics);
		m_mapWnd->OnLButtonDown(pGraphics, nflag, location);
		ReleaseUGGraphics(pGraphics);
	}   
	else if(event->button ()==Qt::RightButton)
	{	
		UGGraphics* pGraphics= NULL;
		CreateUGGrpaphics(pGraphics);
		m_mapWnd->OnRButtonDown(pGraphics, nflag, location);
		ReleaseUGGraphics(pGraphics);  
	}		
	
	this->repaint();
}

void QtMapControl::mouseReleaseEvent( QMouseEvent * event )
{
	QWidget::mousePressEvent(event);
	int nflag = 0; //GetUGKeyflagMasks(event);
	UGPoint location(event->x(),event->y());
	

	if(event->button ()==Qt::LeftButton)
	{
		UGGraphics* pGraphics= NULL;
		CreateUGGrpaphics(pGraphics);
		m_mapWnd->OnLButtonUp(pGraphics, nflag, location);
		ReleaseUGGraphics(pGraphics);
	}   
	else if(event->buttons ()==Qt::RightButton)
	{	
		UGGraphics* pGraphics= NULL;
		CreateUGGrpaphics(pGraphics);
		m_mapWnd->OnRButtonUp(pGraphics, nflag, location);  
		ReleaseUGGraphics(pGraphics);
	}		
	Invalidate();
}

void QtMapControl::mouseMoveEvent( QMouseEvent * event )
{
	Qt::MouseButtons button = event->buttons();
	if(button == Qt::LeftButton)
	{
		UGGraphics* pGraphics = NULL;
		CreateUGGrpaphics(pGraphics);
		m_mapWnd->OnMouseMove(pGraphics,0,UGPoint(event->x(),event->y()));

		PaintToQPainter();

		ReleaseUGGraphics(pGraphics);
		this->repaint();
	}
	
	ReviseCursor();
}

void QtMapControl::resizeEvent( QResizeEvent * event )
{
	QWidget::resizeEvent(event);
	m_width = this->width();
	m_height = this->height();

	m_mapWnd->OnSize(NULL,UGRect(0,0,m_width,m_height));

	delete m_pMapImage;
	m_pMapImage = UGGraphicsManager::NewImage();
	m_pMapImage->CreateCompatibleImage(NULL,m_width,m_height);
	Invalidate();
}

void QtMapControl::Refresh()
{
	m_mapWnd->Refresh();
	Invalidate();
}

void QtMapControl::Invalidate()
{
	invalidate = TRUE;
	this->update();
}

void QtMapControl::Wander()
{
	m_mapWnd->SetUserAction(UGC::UGDrawParamaters::uaPan);
}

void QtMapControl::Wander( RocMap_CDPoint dPt )
{
	// 设置中心点
	m_mapWnd->SetCenter(UGPoint2D(dPt.x,dPt.y));
}

void QtMapControl::ZoomIn()
{
	m_mapWnd->SetUserAction(UGDrawParamaters::uaZoomIn);
}

void QtMapControl::ZoomIn( float fZoomFactor )
{
	m_mapWnd->Zoom(fZoomFactor);
}

void QtMapControl::ZoomIn( float fZoomFactor,RocMap_CDPoint dPt )
{
	this->ZoomIn(fZoomFactor);
	this->Wander(dPt);
}

void QtMapControl::ZoomOut()
{
	m_mapWnd->SetUserAction(UGDrawParamaters::uaZoomOut);
}

void QtMapControl::ZoomOut( float fZoomFactor )
{
	m_mapWnd->Zoom(fZoomFactor);
}

void QtMapControl::ZoomOut( float fZoomFactor,RocMap_CDPoint dPt )
{
	this->ZoomOut(fZoomFactor);
	this->Wander(dPt);
}

void QtMapControl::Back()
{
	// 回复初始比例尺和中心点
	m_mapWnd->SetScale(defaultScale);
	m_mapWnd->SetCenter(defaultCenter);
	this->Refresh();
}

void QtMapControl::Pointer()
{
	//TODO： 恢复当前鼠标状态，什么意思
	m_mapWnd->SetUserAction(UGDrawParamaters::uaPointModeSelect);
}

void QtMapControl::GetMapLayerOrder( vector<RocMap_LayerOrderInfo> &vLayerOrderInfo )
{
	//TODO: 空实现，后续提供
}

void QtMapControl::SetMapLayerOrder( vector<RocMap_LayerOrderInfo> vLayerOrderInfo )
{
	//TODO: 空实现，后续提供
}

void QtMapControl::SetMapLayerVisible( QString csLayerName,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::CreateLayer( QString csLayerName )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetLayerVisible( QString csLayerName,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::GetLayerOrder( vector<RocMap_UserLayerInfo> &vLayerInfo )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetLayerOrder( vector<RocMap_UserLayerInfo> vLayerInfo )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowMapScaleBar( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawLine( const char* strID,vector<RocMap_CDPoint> vdPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetTextStyle( QFont font /*= QFont("Times", 10, QFont::Bold ) */,QColor color /*= QColor(255,0,0)*/,QColor bgcolor /*= QColor(-1,-1,-1)*/, float bgalpha /*= 0.5*/,QColor bgoutlinecolor /*= QColor(-1,-1,-1)*/ )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetTextStyle( const char* strID,QFont font /*= QFont("Times", 10, QFont::Bold ) */,QColor color /*= QColor(255,0,0)*/, QColor bgcolor /*= QColor(-1,-1,-1)*/,float bgalpha /*= 0.5*/,QColor bgoutlinecolor /*= QColor(-1,-1,-1)*/ )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DragText( BOOL bDrag )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawText( const char* strID,const char* strContent,RocMap_CDPoint dPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetPointStyle( int nSize,QColor color, unsigned char cStyle )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetPointStyle( const char* strID,int nSize,QColor color, unsigned char cStyle )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawPoint( const char* strID,RocMap_CDPoint dPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowPointLabel( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowPointLabel( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawPointLabel( const char* strID,QString sContent )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DragPointLabel( BOOL bDrag )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetLineStyle( int nWidth,QColor color,unsigned char cStyle )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetLineStyle( const char* strID,int nWidth,QColor color,unsigned char cStyle )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowLineLabel( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowLineLabel( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawLineLabel( const char* strID,QString sContent )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DragLineLabel( BOOL bDrag )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetRegionStyle( int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetRegionStyle( const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawRegion( const char* strID,vector<RocMap_CDPoint> vdPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowRegionLabel( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowRegionLabel( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawRegionLabel( const char* strID,QString sContent )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DragRegionLabel( BOOL bDrag )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetSectorStyle( int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetSectorStyle( const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawSector( const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawSectorbyXY( const char* strID,RocMap_CDPoint dPt,float fRadius,float fBeginAngle,float fAngleScope )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowSectorLabel( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowSectorLabel( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawSectorLabel( const char* strID,QString sContent )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DragSectorLabel( BOOL bDrag )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetEllipseStyle( int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetEllipseStyle( const char* strID,int outlinewidth,QColor outlinecolor,QColor fillcolor,float alpha )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawEllipse( const char* strID,RocMap_CDPoint dCenterPt,float fLRadius,float fSRadius,float fAngle )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowEllipseLabel( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ShowEllipseLabel( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawEllipseLabel( const char* strID,QString sContent )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DragEllipseLabel( BOOL bDrag )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DelObjectbyID( const char* strID, unsigned char cSort )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DelObjectbySort( unsigned char cSort )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::ClearAll()
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawMiliMark( const char* strID,const char* strName,int jbcode,RocMap_CDPoint dPt,QColor color )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkScale( float fScale )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkScale( const char* strID,float fScale )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkHJShow( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkHJShow( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetHJLength( int nLength )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetHJLength( const char* strID,int nLength )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkEdit( BOOL bEdit )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkShow( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkShow( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkLabelStyle( const char* strID,QFont font /*= QFont("Times", 10, QFont::Bold ) */,QColor color /*= QColor(255,0,0)*/,QColor bgcolor /*= QColor(-1,-1,-1)*/, QColor bgoutlinecolor /*= QColor(-1,-1,-1)*/,float bgalpha /*= 0.5*/ )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkLabelShow( BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkLabelShow( const char* strID,BOOL bShow )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::DrawMiliMarkLabel( const char* strID,QString sContent )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::SetMiliMarkAngle( const char* strID,float fAngle )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::GetMiliMarkInfo( vector<RocMap_JBAttr> &vJBAttr )
{
	throw std::exception("The method or operation is not implemented.");
}

float QtMapControl::GetMapScale()
{
	throw std::exception("The method or operation is not implemented.");
}

int QtMapControl::GetLodLevel()
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::GetDistance()
{
	throw std::exception("The method or operation is not implemented.");
}

float QtMapControl::GetDistance( vector<RocMap_CDPoint> vdPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::GetArea()
{
	throw std::exception("The method or operation is not implemented.");
}

float QtMapControl::GetArea( vector<RocMap_CDPoint> vdPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::GetAngle()
{
	throw std::exception("The method or operation is not implemented.");
}

float QtMapControl::GetAngle( RocMap_CDPoint dPt0,RocMap_CDPoint dPt1 )
{
	throw std::exception("The method or operation is not implemented.");
}

float QtMapControl::GetHeight( RocMap_CDPoint dPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::XYtoLB( QPoint pt,RocMap_CDPoint& dPt )
{
	UGPoint2D mapPoint = this->PixelToMap(pt);
	dPt.x = mapPoint.x;
	dPt.y = mapPoint.y;
}

QPoint QtMapControl::LBtoXY( RocMap_CDPoint dPt )
{
	return this->MapToPixel(UGPoint2D(dPt.x,dPt.y));
}

BOOL QtMapControl::GetGeoPoint( RocMap_CDPoint dSrcPt,float fAngle,float fDist,RocMap_CDPoint& dObjPt )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::Release()
{
	delete m_pMapImage;
	delete m_mapWnd;
	delete m_workSpace;
}

void QtMapControl::GetName( LPSTR sName )
{
	throw std::exception("The method or operation is not implemented.");
}

void QtMapControl::Init()
{
	

	this->setMouseTracking(true);

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
	}

	defaultCenter = pMap->GetCenter();
	defaultScale = pMap->GetScale();
}

void QtMapControl::CreateUGGrpaphics(UGGraphics* &pGraphics)
{
	pGraphics = UGC::UGGraphicsManager::NewGraphics();
	pGraphics->CreateCompatibleGraphics(NULL);
	

	m_pOldImage = pGraphics->SelectImage(m_pMapImage);
}

void QtMapControl::ReleaseUGGraphics(UGGraphics* &pGraphics)
{
	pGraphics->SelectImage(m_pOldImage);
	delete pGraphics;
	pGraphics = NULL;
}

void QtMapControl::PaintToQPainter()
{
	UGC::Window3D hWnd=this->winId();

	QImage *pQImage = NULL;

	pQImage = new QImage((UGC::UGbyte*)m_pMapImage->GetColors(),m_width,m_height,QImage::Format_ARGB32);

	DrawPlane(pQImage);

	QPainter paint;
	paint.begin(this);
	paint.drawImage(QRectF(0,0,m_width,m_height),*pQImage);
	paint.end();
	delete pQImage;
}

UGWorkspace* QtMapControl::GetWorkspace()
{
	return m_workSpace;
}



void QtMapControl::InitPlans()
{
	if (m_workSpace == NULL)
	{
		return;
	}
	UGDataSource* dataSource =  m_workSpace->GetDataSource(0);
	if (dataSource == NULL)
	{
		return;
	}
	UGDatasetVector *dataSet = (UGDatasetVector *)dataSource->GetDataset("Sdzzd_P");
	if (dataSet == NULL)
	{
		return;
	}
	UGQueryDef query;
	UGRecordset *recordset = dataSet->Query(query);
	if (recordset == NULL)
	{
		return;
	}
	std::vector<UGString> names ;
	std::vector<UGPoint2D> locations ;
	recordset->MoveFirst();
	UGString fieldName = "NAME";
	while (!recordset->IsEOF())
	{

		UGC::UGGeometry *pGeometry = NULL;
		recordset->GetGeometry(pGeometry);
		if (pGeometry != NULL)
		{
			locations.push_back(((UGGeoPoint*)pGeometry)->GetInnerPoint());
			UGC::UGVariant midvalue;
			recordset->GetFieldValue(fieldName,midvalue);
			names.push_back(midvalue.ToString());
		}

		recordset->MoveNext();
	}

	int count = names.size();

	int index = 0;
	srand((unsigned)time(0));
	while (planes.size() < 1000)
	{
		int i = rand()%count;
		int j = rand()%count;

		Plane plane(locations[i],locations[j],UGString::From(index),names[i],names[j]); 
		plane.AddControl(this,&m_mapWnd->m_mapWnd);
		planes.push_back(plane);
		index++;
	}
}

void QtMapControl::DrawPlane(QImage *pQImage)
{
	int planeCount = planes.size();
	QPainter painter(pQImage);
	for (int i = 0; i < planeCount;i++)
	{ 
		Plane plane = planes[i];
		plane.drawPlane(painter,imageAPlane,&m_mapWnd->m_mapWnd,count);
	}
}

void QtMapControl::showTime()
{
	count++;
	update();
}