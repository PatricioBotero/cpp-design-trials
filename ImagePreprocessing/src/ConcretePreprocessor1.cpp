#include "ConcretePreprocessor1.h"


void ConcretePreprocessor1::compute() {
	blackBoard->addResult(HISTOGRAM_IMAGE, new ConcreteResultA());
}