/*
 * ObjectStore.h
 *
 *  Created on: 05.05.2014
 *      Author: tabuchte
 */

#ifndef OBJECTSTORE_H_
#define OBJECTSTORE_H_

#include <iostream>
#include <iosfwd>
#include <vector>
#include <map>

class ObjectStore {
private:
	std::map<std::string, std::string> strings;
	// typedef std::pair<std::string, std::string> MapPair;

public:
	void setString(std::string id, std::string value);
	std::string getString(std::string id);
};

#endif /* OBJECTSTORE_H_ */
