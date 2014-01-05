#include "TestQTUI.h"

#include <QMessageBox>
#include <QFont>

#include "QtMapControl.h"


TestQTUI::TestQTUI(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	setupUI(this);
	addConnect();
}


void TestQTUI::addConnect()
{
	//connect(mapList,SIGNAL(itemPressed(QTreeWidgetItem *,int)),this,SLOT(mapItemPress(QTreeWidgetItem *)));
	//��ͼ�����ź�
	connect(actionSelect,SIGNAL(triggered()),this,SLOT(select()));
	connect(actionViewEntire,SIGNAL(triggered()),this,SLOT(viewEntire()));
	connect(actionZoomin,SIGNAL(triggered()),this,SLOT(zoomIn()));
	connect(actionZoomout,SIGNAL(triggered()),this,SLOT(zoomOut()));
	connect(actionPan,SIGNAL(triggered()),this,SLOT(pan()));
	connect(actionLength,SIGNAL(triggered()),this,SLOT(calcLength()));
	connect(actionArea,SIGNAL(triggered()),this,SLOT(calcArea()));
	//connect(actionDelete,SIGNAL(triggered()),m_pMapControl,SLOT(clearGeometry()));
	//connect(m_pMapControl,SIGNAL(sendMeasure(double,QString)),this,SLOT(addMeasureMessage(double,QString)));

	connect(actionDrawPoint,SIGNAL(triggered()),this,SLOT(drawPoint()));
	connect(actionDrawLine,SIGNAL(triggered()),this,SLOT(drawPolyLine()));
	connect(actionDrawPolygon,SIGNAL(triggered()),this,SLOT(drawPolygon()));
	connect(actionDrawText,SIGNAL(triggered()),this,SLOT(drawText()));

	//connect(actionQuery,SIGNAL(triggered()),this,SLOT(showDialog()));
	//connect(queryDialog,SIGNAL(pressOk()),this,SLOT(mapQuery()));

	//connect(fieldTableWidget,SIGNAL(cellClicked(int,int)),this,SLOT(highLightGeometry(int,int)));
}

TestQTUI::~TestQTUI()
{

}

void TestQTUI::setupUI( QMainWindow *mainWindow )
{
	mainWindow->setWindowTitle(tr("QT ��������"));
	mainWindow->resize(800,600);

	mapControl = new QtMapControl(centralWidget);
	QWidget* control = dynamic_cast<QWidget*>(mapControl);
	mainWindow->setCentralWidget(control);
	//setMainWidget(centralWidget);

	menuBar = new QMenuBar(mainWindow);
	mainWindow->setMenuBar(menuBar);

 	mainToolBar = new QToolBar(mainWindow);
 	mainWindow->addToolBar(Qt::TopToolBarArea,mainToolBar);

 	statusBar = new QStatusBar(mainWindow);
 	mainWindow->setStatusBar(statusBar);

	menuMap = new QMenu(menuBar);
	menuMap->setTitle("��ͼ����");
	menuBar->addMenu(menuMap);
	addMapAction(mainWindow);

	editToolBar = new QToolBar(mainWindow);
	mainWindow->addToolBar(Qt::TopToolBarArea,editToolBar);

	menuEdit = new QMenu(menuBar);
	menuEdit->setTitle("�༭����");
	menuBar->addMenu(menuEdit);
	addEditAction(mainWindow);

	menuControl = new QMenu(menuBar);
	menuControl->setTitle("��ͼģʽ");
	menuBar->addMenu(menuControl);

	actionMap = new QAction("��ά��ͼ",mainWindow);
	menuControl->addAction(actionMap);

	actionSence = new QAction("��ά��ͼ",mainWindow);
	menuControl->addAction(actionSence);

}

void TestQTUI::addEditAction( QMainWindow *mainWindow )
{
	actionDrawPoint = new QAction(QIcon("Resources/Point.png"),"���Ƶ�",this);
	menuEdit->addAction(actionDrawPoint);
	editToolBar->addAction(actionDrawPoint);

	actionDrawLine = new QAction(QIcon("Resources/Polyline.png"),"������",this);
	menuEdit->addAction(actionDrawLine);
	editToolBar->addAction(actionDrawLine);

	actionDrawPolygon = new QAction(QIcon("Resources/Polygon.png"),"������",this);
	menuEdit->addAction(actionDrawPolygon);
	editToolBar->addAction(actionDrawPolygon);

	actionDrawText = new QAction(QIcon("Resources/Text.png"),"�����ı�",this);
	menuEdit->addAction(actionDrawText);
	editToolBar->addAction(actionDrawText);

	menuEdit->addAction(actionDelete);
	editToolBar->addAction(actionDelete);
}


void TestQTUI::addMapAction( QMainWindow *mainWindow )
{
	actionSelect= new QAction(QIcon("Resources/Select.png"),"ѡ��",this);
	menuMap->addAction(actionSelect);
	mainToolBar->addAction(actionSelect);

	actionViewEntire= new QAction(QIcon("Resources/Entire.png"),"ȫ��",this);
	menuMap->addAction(actionViewEntire);
	mainToolBar->addAction(actionViewEntire);

	actionZoomin= new QAction(QIcon("Resources/Zoomin.png"),"�Ŵ�",this);
	menuMap->addAction(actionZoomin);
	mainToolBar->addAction(actionZoomin);

	actionZoomout = new QAction(QIcon("Resources/Zoomout.png"),"��С",this);
	menuMap->addAction(actionZoomout);
	mainToolBar->addAction(actionZoomout);

	actionPan = new QAction(QIcon("Resources/Pan.png"),"����",this);
	menuMap->addAction(actionPan);
	mainToolBar->addAction(actionPan);

	actionLength = new QAction(QIcon("Resources/Length.png"),"����",this);
	menuMap->addAction(actionLength);
	mainToolBar->addAction(actionLength);

	actionArea = new QAction(QIcon("Resources/Area.png"),"���",this);
	menuMap->addAction(actionArea);
	mainToolBar->addAction(actionArea);

	actionDelete = new QAction(QIcon("Resources/Delete.png"),"���",this);
	menuMap->addAction(actionDelete);
	mainToolBar->addAction(actionDelete);
}

void TestQTUI::setMainWidget( QWidget *centralWidget)
{
	/*hBoxLayout = new QHBoxLayout(centralWidget);

	leftvBoxLayout = new QVBoxLayout(centralWidget);
	hBoxLayout->addLayout(leftvBoxLayout);

	QFont font;
	font.setPixelSize(14);
	
	mapList = new QTreeWidget(centralWidget);
	QTreeWidgetItem *mapHeadItem = new QTreeWidgetItem();
	mapHeadItem->setText(0, "��ͼ�б�");
	mapList->setHeaderItem(mapHeadItem);

	mapList->setMaximumWidth(300);
	mapList->setFont(font);
	leftvBoxLayout->addWidget(mapList);
	
	layerList = new QTreeWidget(centralWidget);
	QTreeWidgetItem *layerHeadItem = layerList->headerItem();
	layerHeadItem->setText(0,"ͼ���б�");
	layerHeadItem->setText(1,"�Ƿ�ɼ�");
	layerList->setColumnWidth(0,180);
	layerList->setLineWidth(30);
	layerList->setFont(font);
	layerList->setMaximumWidth(300);
	leftvBoxLayout->addWidget(layerList);

	rightvBoxLayout = new QVBoxLayout(centralWidget);
	
	rightvBoxLayout->addWidget(m_pMapControl);
	textEdit = new QTextEdit(centralWidget);
	rightvBoxLayout->addWidget(textEdit);
	rightvBoxLayout->setStretch(0,40);
	rightvBoxLayout->setStretch(1,10);
	hBoxLayout->addLayout(rightvBoxLayout);

 	hBoxLayout->setStretch(0,10);
 	hBoxLayout->setStretch(1,30);
	centralWidget->setLayout(hBoxLayout);*/
}

void TestQTUI::zoomIn()
{
	mapControl->ZoomIn();
}

void TestQTUI::zoomOut()
{
	mapControl->ZoomOut();
}

void TestQTUI::viewEntire()
{
	mapControl->Back();
}

void TestQTUI::select()
{
	mapControl->Pointer();
}

void TestQTUI::pan()
{
	mapControl->Wander();
}

void TestQTUI::calcLength()
{
	
}

void TestQTUI::calcArea()
{
	
}

void TestQTUI::openMap( QString mapName )
{
	
}



void TestQTUI::drawPoint()
{
	
}

void TestQTUI::drawPolyLine()
{
	
}

void TestQTUI::drawPolygon()
{
	
}

void TestQTUI::drawText()
{
	
}


