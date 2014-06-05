#pragma once
#include "ImageProcessingResult.h"
#include <string>

class ConcreteResultB :
	public ImageProcessingResult
{
public:
	void dummy();
	std::string getStringResult();
};

