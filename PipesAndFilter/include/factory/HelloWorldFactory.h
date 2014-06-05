/*
 * HELLOWORLDFactory.h
 *
 *  Created on: 06.05.2014
 *      Author: tabuchte
 */

#ifndef HELLOWORLDFACTORY_H_
#define HELLOWORLDFACTORY_H_

#include "PipelineFactory.h"
#include "nodes/StringNode.h"

class HelloWorldFactory : PipelineFactory {
public:
	Node* createPipeline(ObjectStore &objectStore);
};

#endif /* HELLOWORLDFACTORY_H_ */
