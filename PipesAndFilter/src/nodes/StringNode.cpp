/*
 * StringNode.cpp
 *
 *  Created on: 05.05.2014
 *      Author: tabuchte
 */

#include <nodes/StringNode.h>

StringNode::StringNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void StringNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += this->text;
	objectStore->setString("demo", demo);
}

void StringNode::setText(std::string text) {
	this->text = text;
}
