#include "QListWidgetErrorItem.h"

QListWidgetErrorItem::QListWidgetErrorItem(int listErrorItemIndex, int itemBlockIndex, int itemCameraIndex, QWidget *parent)
 : listErrorItemIndex(listErrorItemIndex), itemBlockIndex(itemBlockIndex), itemCameraIndex(itemCameraIndex){
	if (layout == NULL) {
		layout = new QGridLayout();
		labelIndex = new QLabel();
		labelNorm = new QLabel();
		labelAbNorm = new QLabel();

		labelIndex->setText("[" + QString::fromStdString(std::to_string(listErrorItemIndex)) + "]\n"
			+ "Camera: " + QString::fromStdString(std::to_string(itemCameraIndex)) + "\n"
			+ "Block: " + QString::fromStdString(std::to_string(itemBlockIndex))
			);
		labelIndex->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

		layout->addWidget(labelIndex, 0, 0);
		layout->addWidget(labelNorm, 0, 1);
		layout->addWidget(labelAbNorm, 0, 2);

		this->setLayout(layout);
	}
}

void QListWidgetErrorItem::setErrorItemDisplayImage(QImage &qImageNormMat, QImage &qImageAbNormMat) {
	labelNorm->setPixmap(QPixmap::fromImage(qImageNormMat)
		.scaled(labelNorm->width(), labelNorm->height(), Qt::KeepAspectRatio));
	labelAbNorm->setPixmap(QPixmap::fromImage(qImageAbNormMat)
		.scaled(labelAbNorm->width(), labelAbNorm->height(), Qt::KeepAspectRatio));
}

void QListWidgetErrorItem::setErrorItemIndex(int errorItemIndex) {
	listErrorItemIndex = errorItemIndex;
	updateErrorItemContent();
}

void QListWidgetErrorItem::setErrorItemBlockIndex(int errorItemBlockIndex) {
	itemBlockIndex = errorItemBlockIndex;
	updateErrorItemContent();
}

void QListWidgetErrorItem::setErrorItemCameraIndex(int errorItemCameraIndex) {
	itemCameraIndex = errorItemCameraIndex;
	updateErrorItemContent();
}

void QListWidgetErrorItem::updateErrorItemContent() {
	labelIndex->setText("[" + QString::fromStdString(std::to_string(listErrorItemIndex)) + "]\n"
		+ "Camera: " + QString::fromStdString(std::to_string(itemCameraIndex)) + "\n"
		+ "Block: " + QString::fromStdString(std::to_string(itemBlockIndex))
		);
}

QListWidgetErrorItem::~QListWidgetErrorItem()
{

}