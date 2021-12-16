#pragma once

#ifndef QLABELWITHMOUSEEVENT_H
#define QLABELWITHMOUSEEVENT_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QPen>
#include <QPainter>
#include <QEvent>

// �Զ�����Ӧ����¼�QLabel
class QLabelWithMouseEvent : public QLabel{
	Q_OBJECT
public:
	explicit QLabelWithMouseEvent(QWidget *parent = nullptr);
	~QLabelWithMouseEvent();
protected:
	void mouseReleaseEvent(QMouseEvent *ev);  //̧��
	void mousePressEvent(QMouseEvent *ev);    //����
	void mouseDoubleClickEvent(QMouseEvent *ev);  //˫��
	void mouseMoveEvent(QMouseEvent *ev);     //�϶�
	bool eventFilter(QObject *, QEvent *);	// �¼�������
signals:
	void released(QMouseEvent *ev);  //̧��
	void pressed(QMouseEvent *ev);  //����
	void doubled(QMouseEvent *ev);  //˫��
	void moved(QMouseEvent *ev);    //�϶�
	bool filter(QObject *, QEvent *);	// �¼�������
};

#endif