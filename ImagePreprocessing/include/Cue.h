/*
 * Cue.h
 *
 *  Created on: 12.05.2014
 *      Author: tabuchte
 */

#ifndef CUE_H_
#define CUE_H_

#include <vector>
#include "ImagePreprocessingEngine.h"
#include "ImagePreprocessor.h"
#include "BlackBoard.h"

class Cue {
protected:
	BlackBoard *blackBoard;
	ImagePreprocessingEngine *engine;
	std::vector<PreprocessingTask> dependencies;
public:
	virtual void setBlackBoard(BlackBoard *value) { this->blackBoard = value; }
	virtual void setImageProcessingEngine(ImagePreprocessingEngine *value) { this->engine = value; }
	virtual void addDependency(PreprocessingTask task) { this->dependencies.push_back(task); }
	virtual void registerDependencies() {
		for (int i = 0; i < dependencies.size(); i++) { this->engine->registerTask(dependencies[i]); }
	}
	virtual void compute() = 0;
};

#endif /* CUE_H_ */
