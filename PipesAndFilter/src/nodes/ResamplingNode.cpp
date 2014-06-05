/*
 * ResamplingNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/ResamplingNode.h>

ResamplingNode::ResamplingNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void ResamplingNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += "Resampling \n";
	objectStore->setString("demo", demo);
}
