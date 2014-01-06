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

QtSceneControl::QtSceneControl(void)
{
	m_pSceneWnd = NULL;
	m_pWorkspace = NULL;
}

QtSceneControl::~QtSceneControl(void)
{
	delete m_pSceneWnd;
	m_pSceneWnd = NULL;
	m_pWorkspace= NULL;
}

void QtSceneControl::SetWorkspace( UGWorkspace* pWorkspace )
{
	m_pWorkspace = pWorkspace;
	Init();
}

void QtSceneControl::Init()
{	
	setFocusPolicy(Qt::StrongFocus);
	setMouseTracking (true);

	this->setAcceptDrops(true);
	//刷新下窗体，防止场景绘制于QWorkspace
	this->repaint();
	
	UGC::Window3D hWnd=this->winId();

	m_root3D =new UGC::UGRoot3D();
	m_root3D->SetGraphics3DType(UGC::RST_OGL);
	m_root3D->Initialize(hWnd);

#if defined _WIN32
	UGScene3D *pScene =m_root3D->CreateScene(hWnd);
#else
	UGC::Display3D hDisplay = ui.label->x11Info().display();
	UGScene3D* pScene=m_root3D->CreateScene(hWnd, hDisplay);
#endif

	if(pScene != NULL)
	{	
		QDesktopWidget *mydesk = QApplication::desktop();

		UGC::UGString strFilePath = UGC::UGFile::GetModulePath("SuBase");
		strFilePath = strFilePath + "Resource/";
		pScene->InitializeScene(strFilePath,mydesk->physicalDpiX(),mydesk->physicalDpiY());

		 m_pSceneWnd=new UGC::UGSceneEditorWnd(pScene);

		UGCameraWorld *pCamera = pScene->CreateCamera("Camera");
		pScene->GetRenderTarget()->AddViewport((UGC::UGCamera*)pCamera, 0);

		

		//设置关联数据源集合
		pScene->m_Layers.SetDataSources(&m_pWorkspace->m_DataSources);
		
	}
	
	m_timer = new QTimer(this);
	m_timer->connect(m_timer, SIGNAL(timeout()), this, SLOT(render()));
	m_timer->start(50);

	QWidget::setAttribute(Qt::WA_DeleteOnClose);
}

void QtSceneControl::render()
{
	m_root3D->Render();
}


