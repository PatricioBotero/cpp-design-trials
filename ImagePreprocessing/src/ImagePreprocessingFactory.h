#ifndef IMAGEPREPROCESSORFACTORY_H_
#define IMAGEPREPROCESSORFACTORY_H_

#include "ImagePreprocessor.h"
#include "BlackBoard.h"
#include <map>

class ImagePreprocessingFactory
{
protected:
	BlackBoard *blackBoard;
public:
	virtual void setBlackBoard(BlackBoard *blackBoard) { this->blackBoard = blackBoard; }
	virtual ImagePreprocessor *createImagePreprocessor() = 0;
};

#endif /* IMAGEPREPROCESSORFACTORY_H_ */