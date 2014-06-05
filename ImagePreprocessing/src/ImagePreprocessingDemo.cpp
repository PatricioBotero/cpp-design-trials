//============================================================================
// Name        : ImagePreprocessingDemo.cpp
// Author      : Patrick Buchter
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Builder.h"
#include "Cue.h"
#include "DummyStringResult.h"

Builder builder;
ImagePreprocessingEngine *engine;
BlackBoard *blackBoard;

/*
 when the application is built.
*/
void build();
/*
 define which cues/preprocessors are used when a new tracker is initialized.
*/
void initialize();
/*
 during runtime, that is when the tracker us updated, we call the measure method.
*/
void measure();

int main() {
	build();
	initialize();
	measure();
	return 0;
}


void build() {
	builder.build();
	engine = builder.getImagePreprocessingEngine();
	blackBoard = builder.getBlackBoard();
}

void initialize() {
	// register interest
	engine->registerTask(INTEGRAL_HISTOGRAM);
	engine->registerTask(INTEGRAL_KEYING);
	engine->processTasks();

	//// showing that blackboard is working
	DummyStringResult *keyingResult = (DummyStringResult*)blackBoard->getResult(KEYING_IMAGE);
	std::cout << keyingResult->getString() << std::endl;
	DummyStringResult *histogramResult = (DummyStringResult*)blackBoard->getResult(HISTOGRAM_IMAGE);
	std::cout << histogramResult->getString() << std::endl;
}

void measure() {
	//// measureing cues
	std::vector<Cue*> cues = builder.getCues();
	for (int i = 0; i < cues.size(); i++) {
		cues[i]->compute();
	}
}