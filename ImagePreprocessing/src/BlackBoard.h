/*
 * BlackBoard.h
 *
 *  Created on: 15.05.2014
 *      Author: tabuchte
 */

#ifndef BLACKBOARD_H_
#define BLACKBOARD_H_

#include "ImageProcessingResult.h"
#include <map>

enum ResultIdentifier {
	EDGE_IMAGE,
	KEYING_IMAGE,
	HISTOGRAM_IMAGE
};

class BlackBoard {
private:
	std::map<ResultIdentifier, ImageProcessingResult*> results;
public:
	void addResult(ResultIdentifier identifier, ImageProcessingResult* result);
	void deleteResult(ResultIdentifier identifier, ImageProcessingResult*);
	void deleteAllResult();
	ImageProcessingResult* getResult(ResultIdentifier identifier);
};

#endif /* BLACKBOARD_H_ */
