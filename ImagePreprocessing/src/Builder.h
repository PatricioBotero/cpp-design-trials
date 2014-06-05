/*
 * Builder.h
 *
 *  Created on: 12.05.2014
 *      Author: tabuchte
 */

#ifndef BUILDER_H_
#define BUILDER_H_

#include "Cue.h"
/*
#include "HistogramCue.h"
#include "KeyingCue.h"

#include "ImagePreprocessor.h"
#include "HistogramPreprocessor.h"
#include "KeyingPreprocessor.h"
#include "EdgePreprocessor.h"

*/

#include "ImagePreprocessingEngine.h"
#include "ImagePreprocessingFactory.h"
#include "BlackBoard.h"

class Builder {
private:
	std::vector<Cue*> cues;
	std::vector<ImagePreprocessor*> preprocessors;
	ImagePreprocessingEngine *engine;
	BlackBoard *blackBoard;
public:
	Builder();
	void addImagePreprocessorFactory(PreprocessingTask task, ImagePreprocessingFactory *factory);

	void build();
	std::vector<Cue*> getCues();
	ImagePreprocessingEngine* getImagePreprocessingEngine();
	BlackBoard* getBlackBoard();
};

#endif /* BUILDER_H_ */
