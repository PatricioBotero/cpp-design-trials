#pragma once
#include "ImageProcessingResult.h"
#include <string>

class ConcreteResultC :
	public ImageProcessingResult
{
public:
	void dummy();
	std::string getStringResult();
};

