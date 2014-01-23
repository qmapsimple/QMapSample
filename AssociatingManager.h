#pragma once

#include <qmath.h>
#include <QSizeF>
#include <QRectF>

class QtMapControl;
class QtSceneControl;

static const qreal EarthRadius = 6378137;
static const qreal RTOD = 57.295779513082320876798154814;
static const qreal  DTOR  =  0.0174532925199432957692369077;

class AssociatingManager
{
public:
	AssociatingManager(QtMapControl* pMapControl,QtSceneControl* pSceneControl);
	~AssociatingManager(void);

	QSizeF CalculateSizeFromAltitude(qreal altitude);
	qreal CalculateAltitudeFromBounds(QRectF bounds);


	void Attach();
	void UnAttach();
	bool IsAttached();
	

private:
	QtMapControl* m_pMapControl;
	QtSceneControl* m_pSceneControl;
	bool m_isAttached;
};
