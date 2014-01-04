#ifndef TESTQTUI_H
#define TESTQTUI_H

#include <QtGui/QMainWindow>
#include <QtGui/QAction>
#include <QtGui/QMenuBar>
#include <QtGui/QMenu>
#include <QtGui/QToolBar>
#include <QtGui/QStatusBar>
#include <QtGui/QAction>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QTreeWidget>
#include <QtGui/QTextEdit>
#include <QList>
#include <QCheckBox>
#include <QTableWidget>

#include "QtMapControl.h"


class TestQTUI : public QMainWindow
{
	Q_OBJECT

public:
	TestQTUI(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestQTUI();
	void setupUI(QMainWindow *mainWindow);
	void addMapAction(QMainWindow *mainWindow);
	void addEditAction(QMainWindow *mainWindow);
	void setMainWidget(QWidget *centralWidget);
	void openMap(QString mapName);

public slots:
	void zoomIn();
	void zoomOut();
	void viewEntire();
	void select();
	void pan();
	void calcLength();
	void calcArea();

	void drawPoint();
	void drawPolyLine();
	void drawPolygon();
	void drawText();
	

private:
	void addConnect();
private:
	QWidget *centralWidget;
	QMenuBar *menuBar;
	QMenu *menuMap;
	QToolBar *mainToolBar;
	QStatusBar *statusBar;
	QAction *actionZoomout;
	QAction *actionZoomin;
	QAction *actionSelect;
	QAction *actionPan;
	QAction *actionLength;
	QAction *actionArea;
	QAction *actionDelete;
	QAction *actionViewEntire;
	QHBoxLayout *hBoxLayout;
	QVBoxLayout *leftvBoxLayout;
	QVBoxLayout *rightvBoxLayout;
	QTreeWidget *mapList;
	QTreeWidget *layerList;
	QTextEdit *textEdit;

	QMenu* menuEdit;
	QToolBar* editToolBar;
	QAction* actionDrawLine;
	QAction* actionDrawPoint;
	QAction* actionDrawPolygon;
	QAction* actionDrawText;

	QMenu* menuControl;
	QAction* actionMap;
	QAction* actionSence;

	QTableWidget* fieldTableWidget;

	QtMapControl * mapControl;
};

#endif // TESTQTUI_H
