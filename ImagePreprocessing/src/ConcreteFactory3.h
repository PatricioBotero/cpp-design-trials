#pragma once
#include "ImagePreprocessingFactory.h"
#include "ConcretePreprocessor3.h"

class ConcreteFactory3 :
	public ImagePreprocessingFactory
{
public:
	ImagePreprocessor *createImagePreprocessor();
};

