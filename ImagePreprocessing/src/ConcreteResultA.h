#pragma once
#include "ImageProcessingResult.h"
#include <string>

class ConcreteResultA :
	public ImageProcessingResult
{
public:
	void dummy();
	std::string getStringResult();
};

