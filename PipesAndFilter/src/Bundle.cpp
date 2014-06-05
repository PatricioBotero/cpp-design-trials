/*
 * Bundle.cpp
 *
 *  Created on: 05.05.2014
 *      Author: tabuchte
 */

#include "Bundle.h"

Bundle::Bundle(ObjectStore &value) {
	objectStore = &value;
}

void Bundle::execute() {
	switch (computationMethod) {
	case SERIAL:
		for (int i = 0; i < nodes.size(); i++) {
			std::string text = objectStore->getString("demo");
			text += " ";
			objectStore->setString("demo", text);
			nodes[i]->execute();
		}
		break;
	case REVERSE:
		for (int i = nodes.size() - 1; i >= 0; i--) {
			std::string text = objectStore->getString("demo");
			text += " ";
			objectStore->setString("demo", text);
			nodes[i]->execute();
		}
		break;
	}

	std::string text = objectStore->getString("demo");
	text += "\n";
	objectStore->setString("demo", text);
}

void Bundle::addComputationElement(Node *node) {
	nodes.push_back(node);
}

void Bundle::setComputationMethod(ComputationMethod method) {
	this->computationMethod = method;
}
