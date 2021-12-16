#pragma once

#ifndef QLABELWITHMOUSEEVENT_H
#define QLABELWITHMOUSEEVENT_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QPen>
#include <QPainter>
#include <QEvent>

// 自定义响应鼠标事件QLabel
class QLabelWithMouseEvent : public QLabel{
	Q_OBJECT
public:
	explicit QLabelWithMouseEvent(QWidget *parent = nullptr);
	~QLabelWithMouseEvent();
protected:
	void mouseReleaseEvent(QMouseEvent *ev);  //抬起
	void mousePressEvent(QMouseEvent *ev);    //按下
	void mouseDoubleClickEvent(QMouseEvent *ev);  //双击
	void mouseMoveEvent(QMouseEvent *ev);     //拖动
	bool eventFilter(QObject *, QEvent *);	// 事件过滤器
signals:
	void released(QMouseEvent *ev);  //抬起
	void pressed(QMouseEvent *ev);  //按下
	void doubled(QMouseEvent *ev);  //双击
	void moved(QMouseEvent *ev);    //拖动
	bool filter(QObject *, QEvent *);	// 事件过滤器
};

#endif