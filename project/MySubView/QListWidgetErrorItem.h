#pragma once

#ifndef QLISTWIDGETERRORITEM_H
#define QLISTWIDGETERRORITEM_H

#include <iostream>

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include <QGridLayout>

class QListWidgetErrorItem : public QWidget {
	Q_OBJECT
public:
	explicit QListWidgetErrorItem(int listErrorItemIndex, int itemBlockIndex, int itemCameraIndex, QWidget *parent = nullptr);
	~QListWidgetErrorItem();

	void setErrorItemIndex(int);
	void setErrorItemBlockIndex(int);
	void setErrorItemCameraIndex(int);
	void setErrorItemDisplayImage(QImage &, QImage &);

private:
	int listErrorItemIndex = -1;	// 当前是第几个Item
	int itemBlockIndex = -1;	// 用于表示这个item是第几个block的
	int itemCameraIndex = -1;	// 用于表示这个item是表示的第几个相机的

	QLabel *labelIndex = NULL;	// blockIdx + cameraIdx
	QLabel *labelNorm = NULL;	// 正常图像
	QLabel *labelAbNorm = NULL;	// 异常图像
	QGridLayout *layout = NULL;	// 布局

	void updateErrorItemContent();
};

#endif