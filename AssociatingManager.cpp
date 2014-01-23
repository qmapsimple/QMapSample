#include "AssociatingManager.h"
#include "QtMapControl.h"
#include "QtSceneControl.h"
#include "MapWindow/UGMapWnd.h"



void UGSTDCALL MapDrawnCallBack(UGlong pWnd,UGGraphics* pGraphics)
{
	
}

AssociatingManager::AssociatingManager( QtMapControl* pMapControl,QtSceneControl* pSceneControl )
	:m_pMapControl(pMapControl),m_pSceneControl(pSceneControl)
{
	m_isAttached = false;
}

AssociatingManager::~AssociatingManager(void)
{
	m_pMapControl = NULL;
	m_pSceneControl = NULL;
}

QSizeF AssociatingManager::CalculateSizeFromAltitude( qreal altitude )
{
	QSizeF size(0, 0);

	//�������߶ȴ��ڿ�ȫ����ʾ����ĸ߶�ʱ
	if (altitude >= EarthRadius)
	{
		qreal ratio = (altitude + EarthRadius) / 2;
		qreal longitudeWidth = 120 * ratio / EarthRadius;
		qreal latitudeWidth = 120 * ratio / EarthRadius;

		size = QSizeF(longitudeWidth, latitudeWidth);
	}
	//�������߶�С�ڿ�ȫ����ʾ����ĸ߶�ʱ�����޷���������ʱ
	else
	{
		qreal tan30 = qTan(3.1415926 / 6);
		//���ö�Ԫһ�η������a��b��cֵ
		qreal a = (qPow(tan30, 2) + 1) * qPow(EarthRadius, 2);
		qreal b = -2 * (EarthRadius + altitude) * EarthRadius * qPow(tan30, 2);
		qreal c = qPow(tan30, 2) * qPow((EarthRadius + altitude), 2) - qPow(EarthRadius, 2.0);
		//��һԪ���η��̣�ȡ��ǣ��������ֵ�ϴ�
		qreal cosd = (-b + qSqrt(qPow(b, 2) - 4 * a * c)) / 2 / a;
		qreal d = qAcos(cosd);
		qreal widthd = 2 * d * EarthRadius;
		qreal width = (widthd / 3.1415926 / EarthRadius) * 180;

		size = QSizeF(width, width);
	}

	return size;
}

qreal AssociatingManager::CalculateAltitudeFromBounds( QRectF bounds )
{
	qreal altitude = EarthRadius;
	qreal width = bounds.width();

	if (width >= 120)
	{
		altitude = EarthRadius * width / 60 - EarthRadius;
	}
	else if (width != 0)
	{
		qreal angle1 = width / 2 / 180 * 3.1415926;
		qreal height =  qSin(angle1) * EarthRadius;
		qreal a = height / qTan(angle1);
		qreal b = height / qTan(3.1415926 / 6);
		altitude = a + b - EarthRadius;
	}

	return altitude;
}

// ����MapDraw�¼����Ա����
void AssociatingManager::Attach()
{
	// �¼�ע��
	UGMapEditorWnd* mapWnd = m_pMapControl->GetUGMapWnd();

	UGSceneEditorWnd* sceneWnd = m_pSceneControl->GetUGSecneWnd();

	// ��һ��Ϊ���򷵻�
	if(mapWnd == NULL || sceneWnd == NULL)
		return;

	mapWnd->m_mapWnd.SetAfterMapDrawFunc(MapDrawnCallBack,(UGlong)m_pSceneControl);



	m_isAttached = true;
}

bool AssociatingManager::IsAttached()
{
	return m_isAttached;
}

void AssociatingManager::UnAttach()
{
	// ��ע��

	m_isAttached = false;
}
