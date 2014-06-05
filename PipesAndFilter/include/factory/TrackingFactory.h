/*
 * TrackingFactory.h
 *
 *  Created on: 06.05.2014
 *      Author: tabuchte
 */

#ifndef TRACKINGFACTORY_H_
#define TRACKINGFACTORY_H_

#include "PipelineFactory.h"

class TrackingFactory : PipelineFactory {
public:
	Node* createPipeline(ObjectStore &objectStore);
};

#endif /* TRACKINGFACTORY_H_ */
