#include "ConcreteCue2.h"


void ConcreteCue2::compute() {
	ConcreteResultB *result = (ConcreteResultB*)blackBoard->getResult(KEYING_IMAGE);
	std::cout << result->getStringResult() << std::endl;
}