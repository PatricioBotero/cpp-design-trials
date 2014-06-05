/*
 * Node.h
 *
 *  Created on: 05.05.2014
 *      Author: tabuchte
 */

#ifndef NODE_H_
#define NODE_H_

#include <typeinfo>
#include <string>
#include <iostream>

class Node {
private:
	Node *next;
	bool hasNext = false;
public:
	virtual Node* registerNode(Node *next) {
		this->next = next;
		this->hasNext = true;
		return next;
	}
	;
	virtual bool getHasNext() {
		return hasNext;
	}
	virtual void run() {
		this->execute();
		if (hasNext) {
			this->next->run();
		}
	}
	virtual void execute() = 0;

};

#endif /* NODE_H_ */
