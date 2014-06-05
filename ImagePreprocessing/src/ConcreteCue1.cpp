#include "ConcreteCue1.h"

void ConcreteCue1::compute() {
	ConcreteResultA *result = (ConcreteResultA*)blackBoard->getResult(HISTOGRAM_IMAGE);
	std::cout << result->getStringResult() << std::endl;
}