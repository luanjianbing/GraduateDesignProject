#include "QListWidgetCamerasItem.h"

QListWidgetCamerasItem::QListWidgetCamerasItem(std::string &listWidgetItem, QWidget *parent)
	: listWidgetItem(listWidgetItem)
{
	if (labelCameraDisplay == NULL) {
		labelCameraDisplay = new QLabelWithMouseEvent();
		layout = new QGridLayout(this);

		labelCameraDisplay->setText(QString::fromStdString(listWidgetItem));
		labelCameraDisplay->setStyleSheet("background:gray");
		labelCameraDisplay->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		layout->addWidget(labelCameraDisplay, 0, Qt::AlignCenter);
		this->setLayout(layout);

		connect(labelCameraDisplay, SIGNAL(pressed(QMouseEvent *)), this, SLOT(onLabelCameraDisplayPressed(QMouseEvent *)));
	}
}

std::string QListWidgetCamerasItem::getItemName() {
	return listWidgetItem;
}

void QListWidgetCamerasItem::setSingleCameraItem(QImage &imgForDrawQImage) {
	labelCameraDisplay->setPixmap(QPixmap::fromImage(imgForDrawQImage)
		.scaled(labelCameraDisplay->width(), labelCameraDisplay->height(), Qt::KeepAspectRatio));
}

void QListWidgetCamerasItem::onLabelCameraDisplayPressed(QMouseEvent *) {
	std::cout << "listWidgetCamerasItem " + listWidgetItem + " pressed" << std::endl;
	emit itemPressed(atoi(listWidgetItem.c_str()));
}

QListWidgetCamerasItem::~QListWidgetCamerasItem() {

}