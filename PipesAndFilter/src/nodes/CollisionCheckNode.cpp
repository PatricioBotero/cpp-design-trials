/*
 * CollisionCheckNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/CollisionCheckNode.h>

CollisionCheckNode::CollisionCheckNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void CollisionCheckNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += "CollisionCheck \n";
	objectStore->setString("demo", demo);
}
