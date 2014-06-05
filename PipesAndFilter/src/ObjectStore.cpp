/*
 * ObjectStore.cpp
 *
 *  Created on: 05.05.2014
 *      Author: tabuchte
 */

#include "ObjectStore.h"

void ObjectStore::setString(std::string id, std::string value) {

	strings[id] = value;

//	std::map<std::string, std::string>::iterator it = strings.find(id);
//	if (it != strings.end()) {
//		it->second = value;
//	} else {
//		strings.insert(MapPair(id, value));
//	}
}

std::string ObjectStore::getString(std::string id) {

	return strings[id];

//	std::map<std::string, std::string>::iterator it = strings.find(id);
//	if (it != strings.end()) {
//		return it->second;
//	} else {
//		std::cout << "not found" << std::endl;
//		return "ERROR";
//	}
}
