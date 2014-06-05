/*
 * KeyingCueNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/KeyingCueNode.h>

KeyingCueNode::KeyingCueNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void KeyingCueNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += " KeyingCue ";
	objectStore->setString("demo", demo);
}
