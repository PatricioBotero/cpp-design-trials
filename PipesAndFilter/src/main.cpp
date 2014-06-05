#include <iostream>
#include "Node.h"
#include "factory/HelloWorldFactory.h"
#include "factory/TrackingFactory.h"
#include "ObjectStore.h"

using namespace std;

void testHelloWorld();
void testTracking();

int main(int arc, char** argv) {
	// testHelloWorld();
	testTracking();
	return 0;
}

void testHelloWorld() {
	ObjectStore objectStore;
	objectStore.setString("demo", "");

	HelloWorldFactory factory;
	Node* firstNode = factory.createPipeline(objectStore);

	firstNode->run();

	std::cout << objectStore.getString("demo") << std::endl;
}

void testTracking() {
	ObjectStore objectStore;

	TrackingFactory factory;
	Node* firstNode = factory.createPipeline(objectStore);

	firstNode->run();

	std::cout << objectStore.getString("demo") << std::endl;
}
