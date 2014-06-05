/*
 * HelloWorldFactory.cpp
 *
 *  Created on: 06.05.2014
 *      Author: tabuchte
 */

#include <factory/HelloWorldFactory.h>

Node* HelloWorldFactory::createPipeline(ObjectStore &objectStore) {

	StringNode *helloNode = new StringNode(objectStore);
	helloNode->setText("Hello");
	StringNode *spaceNode1 = new StringNode(objectStore);
	spaceNode1->setText(" ");
	StringNode *worldNode = new StringNode(objectStore);
	worldNode->setText("World");
	StringNode *spaceNode2 = new StringNode(objectStore);
	spaceNode2->setText(" ");
	StringNode *bangNode1 = new StringNode(objectStore);
	bangNode1->setText("!!");

	StringNode *bangNode2 = new StringNode(objectStore);
	bangNode2->setText("??");

	Bundle *bundle = new Bundle(objectStore);
	bundle->addComputationElement(bangNode1);
	bundle->addComputationElement(bangNode2);
	bundle->setComputationMethod(REVERSE);

	helloNode->registerNode(spaceNode1)->registerNode(worldNode)->registerNode(
			spaceNode2)->registerNode(bundle);

	return helloNode;
}
