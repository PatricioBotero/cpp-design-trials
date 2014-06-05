#include "ConcreteFactory3.h"


ImagePreprocessor *ConcreteFactory3::createImagePreprocessor() {
	ConcretePreprocessor3 *preprocessor = new ConcretePreprocessor3();
	preprocessor->setAssociatedTask(EDGE);
	preprocessor->setBlackBoard(this->blackBoard);
	preprocessor->addDependency(INTEGRAL_KEYING);
	return preprocessor;
}