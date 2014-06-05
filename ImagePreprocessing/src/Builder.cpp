/*
 * Builder.cpp
 *
 *  Created on: 12.05.2014
 *      Author: tabuchte
 */

#include "Builder.h"

Builder::Builder() {
	this->engine = new ImagePreprocessingEngine();
	this->blackBoard = new BlackBoard();
}

void Builder::addImagePreprocessorFactory(PreprocessingTask task, ImagePreprocessingFactory *factory) {
	factory->setBlackBoard(this->blackBoard);
	this->engine->addPreprocessor(task, factory);
}

ImagePreprocessingEngine* Builder::getImagePreprocessingEngine() {
	return this->engine;
}

BlackBoard* Builder::getBlackBoard() {
	return this->blackBoard;
}



void Builder::build() {
	/*
	// engine
	engine = new ImagePreprocessingEngine();


	// blackboard
	blackBoard = new BlackBoard();

	// cues
	HistogramCue *hCue = new HistogramCue();
	hCue->setImageProcessingEngine(engine);
	hCue->setBlackBoard(blackBoard);
	cues.push_back(hCue);

	KeyingCue *kCue = new KeyingCue();
	kCue->setImageProcessingEngine(engine);
	hCue->setBlackBoard(blackBoard);
	cues.push_back(kCue);

	// preprocessors
	HistogramPreprocessor *hPreprocessor = new HistogramPreprocessor();
	engine->addPreprocessor(INTEGRAL_HISTOGRAM, hPreprocessor);
	hPreprocessor->setBlackBoard(blackBoard);
	preprocessors.push_back(hPreprocessor);

	KeyingPreprocessor *kPreprocessor = new KeyingPreprocessor();
	engine->addPreprocessor(INTEGRAL_KEYING, kPreprocessor);
	kPreprocessor->addDependency(EDGE);
	kPreprocessor->setBlackBoard(blackBoard);
	preprocessors.push_back(kPreprocessor);

	EdgePreprocessor *ePreprocessor = new EdgePreprocessor();
	engine->addPreprocessor(EDGE, ePreprocessor);
	ePreprocessor->setBlackBoard(blackBoard);
	// ePreprocessor->addDependency(INTEGRAL_KEYING); // add circular dependency as a test
	preprocessors.push_back(ePreprocessor);
	*/
}

std::vector<Cue*> Builder::getCues() {
	return this->cues;
}

