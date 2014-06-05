#pragma once
#include "ImagePreprocessingFactory.h"
#include "ConcretePreprocessor2.h"

class ConcreteFactory2 :
	public ImagePreprocessingFactory
{
public:
	ImagePreprocessor *createImagePreprocessor();
};

