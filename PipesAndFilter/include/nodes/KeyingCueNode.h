/*
 * KeyingCueNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef KEYINGCUENODE_H_
#define KEYINGCUENODE_H_

#include "Node.h"
#include "ObjectStore.h"

class KeyingCueNode : public Node {
private:
	ObjectStore *objectStore;
public:
	KeyingCueNode(ObjectStore &objectStore);
	void execute();
};

#endif /* KEYINGCUENODE_H_ */
