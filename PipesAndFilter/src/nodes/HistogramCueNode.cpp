/*
 * HistogramCueNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/HistogramCueNode.h>

HistogramCueNode::HistogramCueNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void HistogramCueNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += " HistogramCue ";
	objectStore->setString("demo", demo);
}
