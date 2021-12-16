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
	int listErrorItemIndex = -1;	// ��ǰ�ǵڼ���Item
	int itemBlockIndex = -1;	// ���ڱ�ʾ���item�ǵڼ���block��
	int itemCameraIndex = -1;	// ���ڱ�ʾ���item�Ǳ�ʾ�ĵڼ��������

	QLabel *labelIndex = NULL;	// blockIdx + cameraIdx
	QLabel *labelNorm = NULL;	// ����ͼ��
	QLabel *labelAbNorm = NULL;	// �쳣ͼ��
	QGridLayout *layout = NULL;	// ����

	void updateErrorItemContent();
};

#endif