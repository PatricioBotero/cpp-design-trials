/*
 * TriggerNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef TRIGGERNODE_H_
#define TRIGGERNODE_H_

#include "Node.h"
#include "ObjectStore.h"

class TriggerNode : public Node {
private:
	ObjectStore *objectStore;
public:
	TriggerNode(ObjectStore &objectStore);
	void execute();
};

#endif /* TRIGGERNODE_H_ */
