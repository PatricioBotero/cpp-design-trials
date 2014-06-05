#include "ConcreteFactory2.h"


ImagePreprocessor *ConcreteFactory2::createImagePreprocessor() {
	ConcretePreprocessor2 *preprocessor = new ConcretePreprocessor2(); 
	preprocessor->setAssociatedTask(INTEGRAL_KEYING);
	preprocessor->setBlackBoard(this->blackBoard);
	// preprocessor->addDependency();
	return preprocessor;
}