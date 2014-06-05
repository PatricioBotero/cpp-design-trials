#include "ConcreteFactory1.h"


ImagePreprocessor *ConcreteFactory1::createImagePreprocessor() {
	ConcretePreprocessor1 *preprocessor = new ConcretePreprocessor1();
	preprocessor->setAssociatedTask(INTEGRAL_HISTOGRAM);
	preprocessor->setBlackBoard(this->blackBoard);
	// preprocessor->addDependency();
	return preprocessor;
}