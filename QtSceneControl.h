#pragma once

#ifndef QTSCENECONTROL_H_
#define QTSCENECONTROL_H_



#include <QtGui/QWidget>



namespace UGC
{
	class UGWorkspace;
	class UGSceneEditorWnd;
	class UGRoot3D;
}

using namespace UGC;

class QtSceneControl: public QWidget
{
	Q_OBJECT

public:
	QtSceneControl(void);
	~QtSceneControl(void);

	void SetWorkspace(UGWorkspace* pWorkspace);

	void Init();

	virtual void paintEvent(QPaintEvent *event);

	virtual void destroy(bool destroyWindow /* = true */, bool destroySubWindows /* = true */);

	virtual void mouseMoveEvent(QMouseEvent * event);

	virtual void wheelEvent(QWheelEvent *event);

	virtual void mousePressEvent(QMouseEvent * event);

	virtual void mouseReleaseEvent(QMouseEvent * event);

	virtual void leaveEvent(QEvent *event);

	virtual void mouseDoubleClickEvent(QMouseEvent *event);

	virtual void resizeEvent(QResizeEvent *event);


	public slots:
		void render();

private:
	void ReviseCursor();

	UGWorkspace* m_pWorkspace;

	UGSceneEditorWnd* m_pSceneWnd;

	UGRoot3D* m_root3D;

	QTimer* m_timer;
};

#endif