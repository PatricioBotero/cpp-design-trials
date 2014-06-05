/*
 * ImagePreparationNode.cpp
 *
 *  Created on: 06.05.2014
 *      Author: tabuchte
 */

#include "nodes/ImagePreparationNode.h"

ImagePreparationNode::ImagePreparationNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void ImagePreparationNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += "ImagePreparation \n";
	objectStore->setString("demo", demo);
}
