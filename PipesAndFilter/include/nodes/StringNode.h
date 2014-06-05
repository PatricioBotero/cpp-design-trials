/*
 * StringNode.h
 *
 *  Created on: 05.05.2014
 *      Author: tabuchte
 */

#ifndef STRINGNODE_H_
#define STRINGNODE_H_

#include "ObjectStore.h"
#include "Node.h"
#include <string.h>

class StringNode : public Node {
private:
	ObjectStore *objectStore;
	std::string text;
public:
	StringNode(ObjectStore &objectStore);
	virtual ~StringNode() {}
	void execute();
	void setText(std::string text);
};


#endif /* STRINGNODE_H_ */
