/*
 * PropagationNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/PropagationNode.h>

PropagationNode::PropagationNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void PropagationNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += "Propagation \n";
	objectStore->setString("demo", demo);
}
