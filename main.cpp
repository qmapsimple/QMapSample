#include <QtGui/QApplication>
#include <QTextCodec>
#include "testqtui.h"

int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
	QApplication a(argc, argv);
	TestQTUI w;
	w.showMaximized();
	w.show();
	return a.exec();
}
