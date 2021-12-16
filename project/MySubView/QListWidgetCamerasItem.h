#pragma once

#ifndef QLISTWIDGETCAMERASITEM_H
#define QLISTWIDGETCAMERASITEM_H

#include <iostream>

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QGridLayout>

#include "QLabelWithMouseEvent.h"

class QListWidgetCamerasItem : public QWidget {
	Q_OBJECT
public:
	explicit QListWidgetCamerasItem(std::string &listWidgetItem, QWidget *parent = nullptr);
	~QListWidgetCamerasItem();

	void setSingleCameraItem(QImage &);
	std::string getItemName();
private:
	std::string listWidgetItem = "";
	QLabelWithMouseEvent *labelCameraDisplay = NULL;
	QGridLayout *layout = NULL;
private slots:
	void onLabelCameraDisplayPressed(QMouseEvent *);
signals:
	void itemPressed(int);
};

#endif