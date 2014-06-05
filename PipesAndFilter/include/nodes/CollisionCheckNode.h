/*
 * CollisionCheckNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef COLLISIONCHECKNODE_H_
#define COLLISIONCHECKNODE_H_

#include "Node.h"
#include "ObjectStore.h"

class CollisionCheckNode : public Node {
private:
	ObjectStore *objectStore;
public:
	CollisionCheckNode(ObjectStore &objectStore);
	void execute();
};

#endif /* COLLISIONCHECKNODE_H_ */
