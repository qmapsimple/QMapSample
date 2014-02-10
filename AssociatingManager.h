#pragma once

#include <QObject>
#include <qmath.h>
#include <QSizeF>
#include <QRectF>

class QtMapControl;
class QtSceneControl;



class AssociatingManager : public QObject
{	
	Q_OBJECT
public:
	AssociatingManager(QtMapControl* pMapControl,QtSceneControl* pSceneControl);
	~AssociatingManager(void);

	QSizeF CalculateSizeFromAltitude(qreal altitude);
	qreal CalculateAltitudeFromBounds(QRectF bounds);


	void Attach();
	void UnAttach();
	bool IsAttached();	

	void UpdateSceneView();
	void UpdateMapView();

	public slots:
		void renderTick();
private:
	

	QtMapControl* m_pMapControl;
	QtSceneControl* m_pSceneControl;
	bool m_isAttached;

	double preLatitude;
	double preLongitude;
	double preAltitude;
};
