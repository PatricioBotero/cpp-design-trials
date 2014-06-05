/*
 * JoinMeasurementsNode.cpp
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#include <nodes/JoinMeasurementsNode.h>

JoinMeasurementsNode::JoinMeasurementsNode(ObjectStore &objectStore) {
	this->objectStore = &objectStore;
}

void JoinMeasurementsNode::execute() {
	std::string demo = objectStore->getString("demo");
	demo += "JoinMeasurements \n";
	objectStore->setString("demo", demo);
}
