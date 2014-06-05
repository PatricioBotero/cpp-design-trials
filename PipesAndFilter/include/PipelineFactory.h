/*
 * PipelineFactory.h
 *
 *  Created on: 06.05.2014
 *      Author: tabuchte
 */

#ifndef PIPELINEFACTORY_H_
#define PIPELINEFACTORY_H_

#include "Node.h"
#include "Bundle.h"
#include "ObjectStore.h"

class PipelineFactory {
public:
	virtual Node* createPipeline(ObjectStore &objectStore) = 0;
};

#endif /* PIPELINEFACTORY_H_ */
