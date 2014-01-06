#include "PlaneInfoControl.h"
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

PlaneInfoControl::PlaneInfoControl( QWidget *parent /*= 0*/, Qt::WFlags flags /*= 0*/ )
:QWidget(parent,flags)
{
	this->resize(120,60);
	QVBoxLayout *verticalLayout = new QVBoxLayout(this);
	verticalLayout->setContentsMargins(0, 0, 0, 0);
	label1 = new QLabel(this);
	QFont font;
	font.setPointSize(12);
	font.setBold(true);
	label1->setMaximumSize(QSize(16777215, 20));
	label1->setText("航线编号：");
	label1->setFont(font);
	label1->setAutoFillBackground(true);
	label1->setPalette(QColor(190,190,190,190));
	verticalLayout->addWidget(label1);
	label2 = new QLabel(this);
	verticalLayout->addWidget(label2);
	QString str = "出发地：\r\n目的地：";
	QFont font2;
	font2.setPointSize(12);
	label2->setText(str);
	label2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
	label2->setFont(font2);

	m_dpt = QPoint(0,0);
}

PlaneInfoControl::~PlaneInfoControl()
{

}

void PlaneInfoControl::SetPlaneID( UGString planeID )
{
	m_id = planeID;
	label1->setText(QString("航线编号：")+ (char*)m_id.Cstr());
}

UGString PlaneInfoControl::GetPlaneID()
{
	return m_id;
}

void PlaneInfoControl::SetAirport( UGString from,UGString to )
{
	QString str = QString("出发地：")+(char*)from.Cstr()+"\r\n目的地："+(char*)to.Cstr();
	label2->setText(str);
	m_from = from;
	m_to = to;
}

void PlaneInfoControl::mousePressEvent( QMouseEvent * event )
{
	m_pressPt = QPoint(event->x(),event->y());
}

void PlaneInfoControl::mouseReleaseEvent( QMouseEvent * event )
{
	QPoint pt(event->x(),event->y());
	QPoint dpt = pt - m_pressPt;
	m_dpt += dpt;
	int x = pt.x() + m_dpt.x();
	int y = pt.y() + m_dpt.y();
	this->setGeometry(x,y,120,60);
}

void PlaneInfoControl::mouseMoveEvent( QMouseEvent * event )
{
	/*QPoint pt(event->x(),event->y());
	QPoint dpt = pt - m_pressPt;
	int x = pt.x() + m_dpt.x() + dpt.x();
	int y = pt.y() + m_dpt.y() + dpt.y();
	this->setGeometry(x,y,120,60);*/
}

void PlaneInfoControl::SetPosition( QPoint pt )
{
	m_position = pt;
	int x = pt.x() + m_dpt.x();
	int y = pt.y() + m_dpt.y();
	this->setGeometry(x,y,120,60);
}
