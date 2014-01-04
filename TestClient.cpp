#include "TestClient.h"
#include <QString>
#include "CUrlManager.h"
#include "CIDQueryFeature.h"
#include "CSQLQueryFeature.h"
#include "CBufferQueryFeature.h"
#include "CGeoPoint.h"
#include "CSpatialQueryFeature.h"
#include "CESpatialMode.h"
#include "CSpatialAttrQueryFeature.h"
#include "CBufferAttrQueryFeature.h"

TestClient::TestClient(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	CUrlManager *pManager = CUrlManager::getInstance();
	if (pManager == NULL)
	{
		return;
	}
	pManager->setHost(QString("localhost"),QString("8090"));
	setupUi(this);
	////this->setWindowOpacity(0.95);//设置半透明(0,1)
	//QList<double> scales;
	//scales.push_front(1.0/37040134.144789);
	//scales.push_front(1.0/7450580.59692382);
	//scales.push_front(1/3814697.26562499);
	////scales.push_front();
	////scales.push_front();
	////scales.push_front();
	////scales.push_front();
	//m_pMapControl = new CMapControl(centralWidget);
	//m_pMapControl->setObjectName(QString::fromUtf8("graphicsView"));
	//m_pMapControl->setEnabled(true);
	////m_pMapControl->setGeometry(QRect(0, 0, 641, 411));
	////m_pMapControl->setFixedScaleValue(scales);//固定比例尺
	//m_pMapControl->openMap(QString("世界地图"));
	
	///////////////////////////信号集合///////////////////////////////////////
	//connect(actionZoomIn,SIGNAL(triggered()),m_pMapControl,SLOT(ZoomIn()));
	//connect(actionZoomOut,SIGNAL(triggered()),m_pMapControl,SLOT(ZoomOut()));
	//connect(actionViewEntire,SIGNAL(triggered()),m_pMapControl,SLOT(ViewEntire()));
	//////////////////////////////////////////////////////////////////////////
	

	//m_pQueryService = new CQueryService();
	//m_pQueryService->setWorkSpaceName("world");
	//CIDQueryFeature *idQuery = new CIDQueryFeature;
	//idQuery->addDatasetName("World","OceanBoundary");
	//idQuery->addID(1);
	//idQuery->addID(2);
	//idQuery->addID(3);

	//CSQLQueryFeature *idQuery = new CSQLQueryFeature;
	//idQuery->addDatasetName("World","Capitals");
	//idQuery->setSQL("SMID<10");

	//CBufferQueryFeature *idQuery = new CBufferQueryFeature;
	//idQuery->addDatasetName("World","Capitals");
	//idQuery->setBufferDistance(10);
	//CGeoPoint *pGeo = new CGeoPoint();
	//pGeo->setGeoPoint(QPointF(21.5,42));
	//idQuery->setGeometry(pGeo);

	//CSpatialQueryFeature *idQuery = new CSpatialQueryFeature;
	//idQuery->addDatasetName("World","Ocean");
	//idQuery->setSpatialMode(WITHIN);
	//CGeoPoint *pGeo = new CGeoPoint();
	//pGeo->setGeoPoint(QPointF(21.5,42));
	//idQuery->setGeometry(pGeo);

	//CSpatialAttrQueryFeature *idQuery = new CSpatialAttrQueryFeature;
	//idQuery->addDatasetName("World","Ocean");
	//idQuery->setSpatialMode(WITHIN);
	//CGeoPoint *pGeo = new CGeoPoint();
	//pGeo->setGeoPoint(QPointF(21.5,42));
	//idQuery->setGeometry(pGeo);
	//idQuery->setSQL("SMID<1000");

	//CBufferAttrQueryFeatrue *idQuery = new CBufferAttrQueryFeatrue;
	//idQuery->addDatasetName("World","Ocean");
	//idQuery->setBufferDistance(10);
	//CGeoPoint *pGeo = new CGeoPoint();
	//pGeo->setGeoPoint(QPointF(21.5,42));
	//idQuery->setGeometry(pGeo);
	//idQuery->setSQL("SMID<1000");

	//m_pQueryService->query(idQuery);
	//delete idQuery;
	//delete pGeo;
}

TestClient::~TestClient()
{
//	if (m_pMapControl != NULL)
//	{
//		delete m_pMapControl;
//		m_pMapControl = NULL;
//	}
}

void TestClient::resizeEvent( QResizeEvent * event )
{
	m_pMapControl->setGeometry(QRect(0, 0, centralWidget->size().width(), centralWidget->size().height()));
}

void TestClient::setupUi(QMainWindow *mainWindow)
{
	mainWindow->setWindowTitle(tr("QT 范例程序"));
	mainWindow->resize(800, 600);
	addMeauBar(mainWindow);
	
} 

void TestClient::addMeauBar( QMainWindow *mainWindow )
{
	menuBar = new QMenuBar(mainWindow);
	mainWindow->setMenuBar(menuBar);
	toolBar = new QToolBar(mainWindow);
	mainWindow->addToolBar(toolBar);
	//statusBar = new QStatusBar(mainWindow);
	//mainWindow->setStatusBar(statusBar);
}

