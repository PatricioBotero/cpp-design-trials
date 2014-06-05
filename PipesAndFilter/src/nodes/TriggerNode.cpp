/*
 * TriggerNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/TriggerNode.h>

TriggerNode::TriggerNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void TriggerNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += "TRIGGER \n";
	objectStore->setString("demo", demo);
}
