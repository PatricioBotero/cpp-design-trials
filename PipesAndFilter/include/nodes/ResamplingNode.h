/*
 * ResamplingNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef RESAMPLINGNODE_H_
#define RESAMPLINGNODE_H_

#include "Node.h"
#include "ObjectStore.h"

class ResamplingNode : public Node {
private:
	ObjectStore *objectStore;
public:
	ResamplingNode(ObjectStore &objectStore);
	void execute();
};

#endif /* RESAMPLINGNODE_H_ */
