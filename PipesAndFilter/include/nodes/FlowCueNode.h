/*
 * FlowCueNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef FLOWCUENODE_H_
#define FLOWCUENODE_H_

#include "Node.h"
#include "ObjectStore.h"

class FlowCueNode : public Node {
private:
	ObjectStore *objectStore;
public:
	FlowCueNode(ObjectStore &objectStore);
	void execute();
};

#endif /* FLOWCUENODE_H_ */
