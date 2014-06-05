#include "ImagePreprocessingFactory.h"


void ImagePreprocessingFactory::setBlackBoard(BlackBoard *blackBoard) {
	
}

void ImagePreprocessingFactory::createImagePreprocessor(PreprocessingTask preprocessingTask) {
	
	ImagePreprocessor *preprocessor;

	// how to make this nicer?
	//switch (preprocessingTask) {
	//case INTEGRAL_HISTOGRAM:
	//	preprocessor = new HistogramPreprocessor();
	//case INTEGRAL_KEYING:
	//	preprocessor = new KeyingPreprocessor();
	//case EDGE:
	//	preprocessor = new EdgePreprocessor();
	//}
	
}