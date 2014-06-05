#include "ConcreteCue3.h"


void ConcreteCue3::compute() {
	ConcreteResultC *result = (ConcreteResultC*)blackBoard->getResult(EDGE_IMAGE);
	std::cout << result->getStringResult() << std::endl;
}