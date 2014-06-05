/*
 * JoinMeasurementsNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef JOINMEASUREMENTSNODE_H_
#define JOINMEASUREMENTSNODE_H_

#include "Node.h"
#include "ObjectStore.h"

class JoinMeasurementsNode : public Node {
private:
	ObjectStore *objectStore;
public:
	JoinMeasurementsNode(ObjectStore &objectStore);
	void execute();
};

#endif /* JOINMEASUREMENTSNODE_H_ */
