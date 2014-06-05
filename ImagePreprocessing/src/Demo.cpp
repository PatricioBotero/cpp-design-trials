// Demo.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include <vector>
#include <algorithm>

#include "Builder.h"
#include "Cue.h"
#include "BlackBoard.h"
#include "ImagePreprocessingEngine.h"
#include "ImagePreprocessor.h"

#include "ConcreteCue1.h"
#include "ConcreteCue2.h"
#include "ConcreteCue3.h"

#include "ConcreteFactory1.h"
#include "ConcreteFactory2.h"
#include "ConcreteFactory3.h"

#include "ConcretePreprocessor1.h"
#include "ConcretePreprocessor2.h"
#include "ConcretePreprocessor3.h"

#include "ConcreteResultA.h"
#include "ConcreteResultB.h"
#include "ConcreteResultC.h"

ImagePreprocessingEngine *engine;
BlackBoard *blackBoard;
std::vector<Cue*> cues;

void registerCue(Cue *cue);
void doMeasurement(Cue *cue);

/*
when the application is built.
*/
void build();
/*
define which cues/preprocessors are used when a new tracker is initialized.
*/
void initialize();
/*
prepare the image: process the appropriate tasks
*/
void prepare();
/*
during runtime, that is when the tracker us updated, we call the measure method.
*/
void measure();

void showResults();

int main(int argc, char* argv[])
{
	std::cout << "build()" << std::endl;
	build();
	std::cout << "initialize()" << std::endl;
	initialize();
	std::cout << "prepare()" << std::endl;
	prepare();
	std::cout << "measure()" << std::endl;
	measure();
	std::cout << "showResults()" << std::endl;
	showResults();
	return 0;
}

void build() {
	Builder builder;

	// add every factory which exists (configuration via json/xml)
	ConcreteFactory1 *factory1 = new ConcreteFactory1();
	factory1->setBlackBoard(blackBoard);
	builder.addImagePreprocessorFactory(INTEGRAL_HISTOGRAM, factory1);

	ConcreteFactory2 *factory2 = new ConcreteFactory2();
	factory2->setBlackBoard(blackBoard);
	builder.addImagePreprocessorFactory(INTEGRAL_KEYING, factory2);

	ConcreteFactory3 *factory3 = new ConcreteFactory3();
	factory3->setBlackBoard(blackBoard);
	builder.addImagePreprocessorFactory(EDGE, factory3);
	
	// get the results
	engine = builder.getImagePreprocessingEngine();
	blackBoard = builder.getBlackBoard();
}

void initialize() {

	// create cues
	ConcreteCue1 *cue1 = new ConcreteCue1();
	cue1->setBlackBoard(blackBoard);
	cue1->setImageProcessingEngine(engine);
	cue1->addDependency(INTEGRAL_HISTOGRAM);
	cues.push_back(cue1);

	ConcreteCue2 *cue2 = new ConcreteCue2();
	cue2->setBlackBoard(blackBoard);
	cue2->setImageProcessingEngine(engine);
	cue2->addDependency(EDGE);
	cues.push_back(cue2);

	ConcreteCue3 *cue3 = new ConcreteCue3();
	cue3->setBlackBoard(blackBoard);
	cue3->setImageProcessingEngine(engine); 
	cue3->addDependency(INTEGRAL_HISTOGRAM);
	cues.push_back(cue3);

	std::cout << "register dependencies" << std::endl;

	// register interest
	std::for_each(cues.begin(), cues.end(), registerCue);

	std::cout << "prepare tasks" << std::endl;

	// create dependency tree
	engine->prepareTasks();
}
	
void registerCue(Cue *cue) {
	cue->registerDependencies();
}

void prepare() {
	engine->processTasks();
}

void measure() {
	std::for_each(cues.begin(), cues.end(), doMeasurement);
}

void doMeasurement(Cue *cue) {
	cue->compute();
}

void showResults() {
	//// showing that blackboard is working
	// DummyStringResult *keyingResult = (DummyStringResult*)blackBoard->getResult(KEYING_IMAGE);
	// std::cout << keyingResult->getString() << std::endl;
	// DummyStringResult *histogramResult = (DummyStringResult*)blackBoard->getResult(HISTOGRAM_IMAGE);
	// std::cout << histogramResult->getString() << std::endl;
}

