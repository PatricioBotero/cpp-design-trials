/*
 * BlackBoard.cpp
 *
 *  Created on: 15.05.2014
 *      Author: tabuchte
 */

#include "BlackBoard.h"

void BlackBoard::addResult(ResultIdentifier identifier, ImageProcessingResult* value) {
	this->results.insert(std::make_pair(identifier, value));
}

void BlackBoard::deleteResult(ResultIdentifier identifier, ImageProcessingResult* value) {
	this->results.erase(identifier);
}

void BlackBoard::deleteAllResult() {
	this->results.empty();
}

ImageProcessingResult* BlackBoard::getResult(ResultIdentifier identifier) {
	return this->results.at(identifier);
}
