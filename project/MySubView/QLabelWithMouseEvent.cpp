#include "QLabelWithMouseEvent.h"

QLabelWithMouseEvent::QLabelWithMouseEvent(QWidget *parent)
: QLabel(parent)
{
	installEventFilter(this);
}
QLabelWithMouseEvent::~QLabelWithMouseEvent() {

}
void QLabelWithMouseEvent::mouseReleaseEvent(QMouseEvent *ev)
{
	emit released(ev);
}
void QLabelWithMouseEvent::mousePressEvent(QMouseEvent *ev)
{
	emit pressed(ev);
}
void QLabelWithMouseEvent::mouseDoubleClickEvent(QMouseEvent *ev)
{
	emit doubled(ev);
}
void QLabelWithMouseEvent::mouseMoveEvent(QMouseEvent *ev)
{
	emit moved(ev);
}
bool QLabelWithMouseEvent::eventFilter(QObject *obj, QEvent *ev) {
	if (obj == this && ev->type() == QEvent::Paint)
		emit filter(obj, ev);
	return QWidget::eventFilter(obj, ev);
}
