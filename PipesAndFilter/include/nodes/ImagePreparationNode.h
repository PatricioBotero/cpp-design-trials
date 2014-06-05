/*
 * ImagePreparation.h
 *
 *  Created on: 06.05.2014
 *      Author: tabuchte
 */

#ifndef IMAGEPREPARATION_H_
#define IMAGEPREPARATION_H_

#include "Node.h"
#include "ObjectStore.h"

class ImagePreparationNode : public Node {
private:
	ObjectStore *objectStore;
public:
	ImagePreparationNode(ObjectStore &objectStore);
	void execute();
};

#endif /* IMAGEPREPARATION_H_ */
