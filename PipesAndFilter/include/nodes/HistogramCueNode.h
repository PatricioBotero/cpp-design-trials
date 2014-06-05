/*
 * HistogramCueNode.h
 *
 *  Created on: 07.05.2014
 *      Author: tabuchte
 */

#ifndef HISTOGRAMCUENODE_H_
#define HISTOGRAMCUENODE_H_

#include "Node.h"
#include "ObjectStore.h"

class HistogramCueNode : public Node {
private:
	ObjectStore *objectStore;
public:
	HistogramCueNode(ObjectStore &objectStore);
	void execute();
};

#endif /* HISTOGRAMCUENODE_H_ */
