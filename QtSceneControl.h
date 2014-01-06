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

	public slots:
		void render();

private:
	

	UGWorkspace* m_pWorkspace;

	UGSceneEditorWnd* m_pSceneWnd;

	UGRoot3D* m_root3D;

	QTimer* m_timer;
};

#endif