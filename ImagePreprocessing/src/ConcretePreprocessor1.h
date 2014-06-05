#pragma once
#include "ImagePreprocessor.h"
#include "ConcreteResultA.h"

class ConcretePreprocessor1 :
	public ImagePreprocessor
{
public:
	void compute();
};

