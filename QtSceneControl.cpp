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
}

QtSceneControl::~QtSceneControl(void)
{
	
}

void QtSceneControl::SetWorkspace( UGWorkspace* pWorkspace )
{
	m_pWorkspace = pWorkspace;
	//Init();
}

void QtSceneControl::Init()
{	
	this->setMouseTracking(true);
	QWidget::setAttribute(Qt::WA_DeleteOnClose);
}

void QtSceneControl::render()
{
	m_root3D->Render();
	ReviseCursor();
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

		}

		m_timer = new QTimer(this);
		m_timer->connect(m_timer, SIGNAL(timeout()), this, SLOT(render()));
		m_timer->start(50);
	}
	QWidget::paintEvent(event);
}

void QtSceneControl::destroy( bool destroyWindow /* = true */, bool destroySubWindows /* = true */ )
{
	m_timer->stop();
	delete m_timer;

	delete m_pSceneWnd;
	m_pSceneWnd = NULL;
	m_pWorkspace= NULL;

	m_root3D->DestoryScene((Window3D)this->winId());

	delete m_root3D;
	m_root3D = NULL;
	
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

