/*
 * ImagePreprocessingEngine.h
 *
 *  Created on: 12.05.2014
 *      Author: tabuchte
 */

#ifndef IMAGEPREPROCESSINGENGINE_H_
#define IMAGEPREPROCESSINGENGINE_H_

#include "ImagePreprocessor.h"
#include "ImagePreprocessingFactory.h"
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

class ImagePreprocessingEngine {
private:
	std::vector<PreprocessingTask> path;
	std::vector<ImagePreprocessor*> orderedPreprocessors;
	std::map<PreprocessingTask, ImagePreprocessor*> preprocessors;
	std::map<PreprocessingTask, ImagePreprocessingFactory*> preprocessorFactories;

	void createOrderedPreprocessorList(ImagePreprocessor *preprocessor);

public:
	void addPreprocessor(PreprocessingTask task, ImagePreprocessingFactory *factory);
	void registerTask(PreprocessingTask preprocessingTask);
	void prepareTasks();
	void processTasks();
};

#endif /* IMAGEPREPROCESSINGENGINE_H_ */
