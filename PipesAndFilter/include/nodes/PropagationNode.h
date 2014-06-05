/*
 * PropagationNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef PROPAGATIONNODE_H_
#define PROPAGATIONNODE_H_

#include "Node.h"
#include "ObjectStore.h"

class PropagationNode : public Node {
private:
	ObjectStore *objectStore;
public:
	PropagationNode(ObjectStore &objectStore);
	void execute();
};

#endif /* PROPAGATIONNODE_H_ */
