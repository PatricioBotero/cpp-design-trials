/*
 * Bundle.h
 *
 *  Created on: 05.05.2014
 *      Author: tabuchte
 */

#ifndef BUNDLE_H_
#define BUNDLE_H_

#include "Node.h"
#include "ObjectStore.h"
#include <vector>

enum ComputationMethod {
	SERIAL,
	REVERSE
};

class Bundle : public Node {
private:
	ObjectStore *objectStore;
	std::vector<Node*> nodes;
	ComputationMethod computationMethod;
public:
	Bundle(ObjectStore &objectStore);
	void registerNode(Node &node);
	void execute();
	void addComputationElement(Node *node);
	void setComputationMethod(ComputationMethod method);
};

#endif /* BUNDLE_H_ */
