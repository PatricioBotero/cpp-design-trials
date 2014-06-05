/*
 * FlowCueNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/FlowCueNode.h>

FlowCueNode::FlowCueNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void FlowCueNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += " FlowCue ";
	objectStore->setString("demo", demo);
}
