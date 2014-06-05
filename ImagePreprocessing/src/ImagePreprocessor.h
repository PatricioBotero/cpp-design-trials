/*
 * ImagePreprocessor.h
 *
 *  Created on: 12.05.2014
 *      Author: tabuchte
 */

#ifndef IMAGEPREPROCESSOR_H_
#define IMAGEPREPROCESSOR_H_

#include <vector>
#include <iostream>
#include <string>
#include "BlackBoard.h"

enum PreprocessingTask {
	INTEGRAL_KEYING,
	INTEGRAL_HISTOGRAM,
	EDGE
};

class ImagePreprocessor {
protected:
	BlackBoard *blackBoard;
	PreprocessingTask task;
	std::vector<PreprocessingTask> neededTasks;
public:
	virtual void compute() = 0;
	virtual void setBlackBoard(BlackBoard *value) { this->blackBoard = value; }
	virtual void setAssociatedTask(PreprocessingTask value) { this->task = value; }
	virtual PreprocessingTask getAssociatedTask() { return this->task; }
	virtual void addDependency(PreprocessingTask dependency) { this->neededTasks.push_back(dependency); }
	virtual std::vector<PreprocessingTask> getNeededPreprocessingTasks() {
		return this->neededTasks;
	}
};

#endif /* IMAGEPREPROCESSOR_H_ */
