#pragma once
#include "ImagePreprocessingFactory.h"
#include "ConcretePreprocessor1.h"

class ConcreteFactory1 :
	public ImagePreprocessingFactory
{
public:
	ImagePreprocessor *createImagePreprocessor();
};

