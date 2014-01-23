#include "QtSceneControl.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QtGui>

#include "Workspace/UGWorkspace.h"
#include "Engine/UGDataSources.h"
#include "Scene/UGRoot3D.h"
#include "Scene/UGScene3D.h"
#include "SceneEditor/UGSceneEditorWnd.h"
#include "Graphics3D/UGRenderTarget.h"

#include "Geometry3D/UGGeoText3D.h"
#include "Geometry3D/UGGeoRegion3D.h"
#include "Render/UGModel.h"
#include "Layer3DTree/UGLayer3DTree.h"
#include "Render/UGKmlFeature3D.h"
#include "Render/UGRenderPoint3D.h"

#include "Geometry3D/UGGeoLine3D.h"

using namespace UGC;

UGC::UGuint GetMasks(QInputEvent * event)
{
	UGC::UGuint flag=0;
	if (event->modifiers()&Qt::ShiftModifier)
	{
		flag=flag|UG_VK_SHIFT;
	} 
	if ((event->modifiers()&Qt::ControlModifier))
	{
		flag=flag|UG_VK_CONTROL;
	}
	if (event->modifiers()&Qt::MetaModifier)
	{
		flag=flag|UG_VK_MENU;
	}
	return flag;
}

QtSceneControl::QtSceneControl(void)
{
	m_pSceneWnd = NULL;
	m_pWorkspace = NULL;
	m_root3D = NULL;
	m_timer = NULL;

	m_pKmlContainer = NULL;
}

QtSceneControl::~QtSceneControl(void)
{
	destroy(TRUE,TRUE);
}

void QtSceneControl::SetWorkspace( UGWorkspace* pWorkspace )
{
	m_pWorkspace = pWorkspace;	
}

void QtSceneControl::Init()
{	
	this->setMouseTracking(true);
	QWidget::setAttribute(Qt::WA_DeleteOnClose);
}

int times=0;
UGPoint3D linePos;
void QtSceneControl::render()
{
	if (m_pKmlContainer != NULL)
	{
		times++;
		//if(times < 100)
		{


			UGPoint3D newPos;
			UGKmlFeature3D* pJ10 = (UGKmlFeature3D*)m_pKmlContainer->GetAt("J10");
			if (pJ10 != NULL)
			{
				UGModel* pModel = (UGModel*)pJ10->GetRenderFeature();
				pModel->GetGeoStyle3D()->SetFixedPixelSize(FALSE);

				
				UGPoint3D pos = pModel->GetPosition();
				if (m_arrPoint3D.GetSize() == 0)
				{
					UGGeoModel* pGeoModel = (UGGeoModel*) pModel->GetGeometry();
					
					UGBoundingBox box = pGeoModel->GetBoundingBox();
					const UGVector3d& lower = box.GetMin();
					const UGVector3d& uper = box.GetMax();
					
					UGPoint3D weiyan(pos.x,pos.y,pos.z +10);
					
					//UGPoint3D weiyan(pos.x,pos.y,pos.z +1);
					linePos = weiyan;
					m_arrPoint3D.Add(weiyan);
				}

				newPos = UGPoint3D(pos.x + 0.01,pos.y + 0.01,pos.z);
				pModel->SetPosition(newPos);
				pModel->SetRotation(0,0,-45);
				pModel->SetScale(2);
			}	

			UGKmlFeature3D* pDaodan = (UGKmlFeature3D*)m_pKmlContainer->GetAt("导弹A");
			if (pDaodan != NULL)
			{
				UGModel* pModel = (UGModel*)pDaodan->GetRenderFeature();
				pModel->GetGeoStyle3D()->SetFixedPixelSize(FALSE);

				pModel->SetPosition(UGPoint3D(newPos.x + 0.01,newPos.y + 0.01,newPos.z));
				pModel->SetRotation(0,0,-45);
				pModel->SetScale(5);
			}

			linePos = UGPoint3D(linePos.x + 0.01,linePos.y + 0.01,linePos.z);
			m_arrPoint3D.Add(linePos);

			UGGeoLine3D *pGeoLine3D = new UGGeoLine3D();
			UGStyle3D* pStyle3D = new UGStyle3D();
			pStyle3D->SetAltitudeMode(UGC::Absolute);
			pGeoLine3D->SetStyle3D(pStyle3D);
			pGeoLine3D->MakeWithPoints(m_arrPoint3D.GetData(),m_arrPoint3D.GetSize());

			m_pSceneWnd->GetScene3D()->m_TrackingLayer3D.RemoveAll();
			m_pSceneWnd->GetScene3D()->m_TrackingLayer3D.Add(pGeoLine3D,"Line3D");
		}
	}
	m_root3D->Render();
	ReviseCursor();

	emit renderTick();
}

void QtSceneControl::paintEvent( QPaintEvent *event )
{
	if (m_root3D == NULL)
	{
		m_root3D =new UGC::UGRoot3D();
		m_root3D->Initialize(NULL);
		m_root3D->SetGraphics3DType(UGC::RST_OGL);


#if defined _WIN32
		UGC::Window3D hWnd=this->winId();
		m_root3D->Initialize(hWnd);
		UGScene3D *pScene =m_root3D->CreateScene(hWnd);
#else
		UGC::Display3D hDisplay = ui.label->x11Info().display();
		UGScene3D* pScene=m_root3D->CreateScene(hWnd, hDisplay);
#endif

		if(pScene != NULL)
		{	

			UGCameraWorld *pCamera = pScene->CreateCamera("Camera");
			pScene->GetRenderTarget()->AddViewport(pCamera, 0);
			m_root3D->SetActiveScene(pScene);

			m_pSceneWnd=new UGC::UGSceneEditorWnd(pScene);
			m_pSceneWnd->SetUserAction(UGC::suaPanSelect);
			m_pSceneWnd->SetOpenEditMode(TRUE);

			QDesktopWidget *mydesk = QApplication::desktop();
			pScene->InitializeScene("",mydesk->physicalDpiX(),mydesk->physicalDpiY());

			pScene->SetDrawMode(REAL_TIME_RASTER);

			//设置关联数据源集合
			pScene->m_Layers.SetDataSources(&m_pWorkspace->m_DataSources);
			pScene->m_TerrainLayer3Ds.SetDataSources(&m_pWorkspace->m_DataSources);
			pScene->m_Layers.SetWorkspace(m_pWorkspace);

			// 打开场景
			int count = m_pWorkspace->m_SceneStorages.GetCount();
			if(count > 0)
			{
				const UGSceneStorage* pSceneStorage = m_pWorkspace->m_SceneStorages.GetSceneAt(0);
				UGString sceneXML = pSceneStorage->GetXML();
				pScene->FromXML(sceneXML);

				UGLayer3DTree* pLayer3DKml = (UGLayer3DTree*)pScene->m_Layers.AddLayer("F:\\Learning\\Code\\C++\\QT\\QMapSimple\\QtMap_Data\\kml和模型\\模型图层.kml");//(UGLayer3DTree*)pScene->m_Layers.FindName("模型图层");
				if (pLayer3DKml != NULL)
				{
					m_pKmlContainer = (UGKmlContainer3D*)pLayer3DKml->GetRenderObjectList();
//					UGKmlContainer3D* pKmlContainer = (UGKmlContainer3D*)pLayer3DKml->GetRenderObjectList();
// 					if (pKmlContainer != NULL)
// 					{
// 						UGKmlFeature3D* pKmlFeature3D = (UGKmlFeature3D*)pKmlContainer->GetAt("J10");
// 						if (pKmlFeature3D != NULL)
// 						{
// 							m_pModel = (UGModel*)pKmlFeature3D->GetRenderFeature();
// 							m_pModel->GetGeoStyle3D()->SetFixedPixelSize(FALSE);
// 						}
// 					}
				}				
			}
		}

		m_timer = new QTimer(this);
		m_timer->connect(m_timer, SIGNAL(timeout()), this, SLOT(render()));
		m_timer->start(50);
	}
	QWidget::paintEvent(event);
}
void QtSceneControl::keyPressEvent(QKeyEvent *event)
{
	UGGeoText3D* pGeoText3D = new UGGeoText3D();
	if (pGeoText3D != NULL)
	{
		UGString strText = "警告警告警告警告警告警告警告！";
		UGdouble dWidth = m_pSceneWnd->GetScene3D()->GetRenderTarget()->GetWidth();
		UGint nNum = 14 * 0.5;
		UGdouble dXOffset = nNum * 16 * 1.0 / dWidth;
		pGeoText3D->Make(strText,UGPoint3D(0.5 - dXOffset,0.0,0));

		UGTextStyle textStyle;

		UGColorValue3D color3D = UGColorValue3D(1.0,1.0,0.0,1.0);
		textStyle.SetForeColor(color3D.GetValue());
		textStyle.SetHalo(TRUE);
		pGeoText3D->SetTextStyle(textStyle);

		m_pSceneWnd->GetScene3D()->m_ScreenLayer3D.Add(pGeoText3D,"warning");
	}

	UGGeoRegion3D* pGeoRegion = new UGGeoRegion3D();
	if (pGeoRegion != NULL)
	{
		UGArray<UGPoint3D> arrPoint3D;
		arrPoint3D.Add(UGPoint3D(0.3,0.0,0));
		arrPoint3D.Add(UGPoint3D(0.3,0.05,0));
		arrPoint3D.Add(UGPoint3D(0.7,0.05,0));
		arrPoint3D.Add(UGPoint3D(0.7,0.0,0));
		arrPoint3D.Add(UGPoint3D(0.3,0.0,0));

		UGStyle3D* pStyle3D = new UGStyle3D();

		UGColorValue3D color3D = UGColorValue3D(1.0,0,0,0.5);
		pStyle3D->SetFillForeColor(color3D.GetValue());
		pStyle3D->SetFillColor(color3D);
		pGeoRegion->SetStyle3D(pStyle3D);

		pGeoRegion->MakeWithPoints(arrPoint3D.GetData(),5);

		m_pSceneWnd->GetScene3D()->m_ScreenLayer3D.Add(pGeoRegion,"region");
	}
	QWidget::keyPressEvent(event);
}
void QtSceneControl::destroy( bool destroyWindow /* = true */, bool destroySubWindows /* = true */ )
{
	if(m_timer != NULL)
	{
		m_timer->stop();
	}
	delete m_timer;
	m_timer = NULL;
		

	if(m_pSceneWnd != NULL)
	{
		delete m_pSceneWnd;
		m_pSceneWnd = NULL;
		m_pWorkspace= NULL;

		m_root3D->DestoryScene((Window3D)this->winId());

		delete m_root3D;
		m_root3D = NULL;
	}
}

void QtSceneControl::mouseMoveEvent( QMouseEvent * event )
{
	Qt::MouseButtons button = event->buttons();
	if(button != Qt::NoButton)
	{
		UGuint nflag= GetMasks(event);
		UGC::UGPoint pntTmp(event->x(), event->y());

		m_pSceneWnd->OnMouseMove(nflag, pntTmp);
	}

	

	QWidget::mouseMoveEvent(event);
}

void QtSceneControl::ReviseCursor()
{
	switch (m_pSceneWnd->m_SceneWindow.GetUserAction())
	{
	case UGC::suaNull :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaPan :
		{
			setCursor(QCursor(QPixmap("Resources/pan.png")));
		}
		break;
	case UGC::suaZoomIn :
		{
			setCursor(QCursor(QPixmap("Resources/ZoomIn.png"),2,2));
		}
		break;
	case UGC::suaZoomOut :
		{
			setCursor(QCursor(QPixmap("Resources/ZoomOut.png"),2,2));
		}
		break;
	case UGC::suaZoomFree :
		{
			setCursor(QCursor(QPixmap("Resources/ZoomFree.png")));
		}
		break;
	case UGC::suaPointSelect :
	case UGC::suaRectSelect :
	case UGC::suaLineSelect :
		{
			setCursor(QCursor(QPixmap("Resources/select.png"),4,4));
		}
		break;
	case UGC::suaCircleSelect :
		{
			setCursor(QCursor(QPixmap("Resources/select_circle.png"),64,64));
		}
		break;
	case UGC::suaRegionSelect :
		{
			setCursor(QCursor(QPixmap("Resources/select_region.png"),64,64));
		}
		break;
	case UGC::suaEdit :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaTrack :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaMeasureDistance :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaMeasureArea :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaMeasureHeight :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaMoveThemeLabel :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaMoveThemeGraph :
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	case UGC::suaMoveThemeGraduatedSymbol :
	default:
		{
			setCursor(QCursor(Qt::ArrowCursor));
		}
		break;
	}
}

void QtSceneControl::wheelEvent( QWheelEvent *event )
{
	UGuint nflag= ::GetMasks(event);

	UGC::UGPoint pntTmp(event->x(), event->y());
	m_pSceneWnd->OnMouseWheel(nflag, event->delta(), pntTmp);
	QWidget::wheelEvent(event);
	event->accept();
}

void QtSceneControl::mousePressEvent( QMouseEvent * event )
{
	UGuint nflag=GetMasks(event);
	if(event->button ()==Qt::LeftButton)
	{
		UGC::UGPoint pntTmp(event->x(), event->y());
		m_pSceneWnd->OnLButtonDown(nflag, pntTmp);
	}
	else if(event->button ()==Qt::RightButton)
	{
		UGC::UGPoint pntTmp(event->x(), event->y());
		m_pSceneWnd->OnRButtonDown(nflag, pntTmp);
	}
	else if (event->button()==Qt::MidButton)
	{
		UGC::UGPoint pntTem(event->x(),event->y());
		m_pSceneWnd->OnMButtonDown(nflag,pntTem);
	}
	QWidget::mousePressEvent(event);
	event->accept();
}

void QtSceneControl::mouseReleaseEvent( QMouseEvent * event )
{
	UGPoint pt(event->x(),event->y());
	UGuint flags = ::GetMasks(event);
	
	if (event->button() == Qt::LeftButton)
	{
		m_pSceneWnd->OnLButtonUp(flags,pt);
	} 
	else if(event->button() == Qt::MiddleButton)
	{
		m_pSceneWnd->OnMButtonUp(flags,pt);
	}
	else if(event->button() == Qt::RightButton)
	{
		m_pSceneWnd->OnRButtonUp(flags,pt);
	}
	
	QWidget::mouseReleaseEvent(event);
}

void QtSceneControl::leaveEvent( QEvent *event )
{
	UGC::UGPoint pntTmp(0, 0);
	int nflag=0;

	m_pSceneWnd->OnMouseLeave(nflag,pntTmp);
	QWidget::leaveEvent(event);
}

void QtSceneControl::mouseDoubleClickEvent( QMouseEvent *event )
{
	UGuint nflag= GetMasks(event);
	UGC::UGPoint pntTmp(event->x(), event->y());

	if (event->button ()==Qt::LeftButton)
	{
		
		m_pSceneWnd->OnLButtonDblClk(nflag, pntTmp);
	} 
	if(event->button ()==Qt::RightButton)
	{
		m_pSceneWnd->OnRButtonDblClk(nflag, pntTmp);
	}
	QWidget::mouseDoubleClickEvent(event);
}

void QtSceneControl::resizeEvent( QResizeEvent *event )
{
	if(m_pSceneWnd != NULL)
	{
		m_pSceneWnd->OnSize(event->size().width(), event->size().height());
	}
	
	QWidget::resizeEvent(event);
}

UGSceneEditorWnd* QtSceneControl::GetUGSecneWnd()
{
	return m_pSceneWnd;
}

