/*
 * ImagePreprocessingEngine.cpp
 *
 *  Created on: 12.05.2014
 *      Author: tabuchte
 */

#include "ImagePreprocessingEngine.h"

void ImagePreprocessingEngine::addPreprocessor(PreprocessingTask task, ImagePreprocessingFactory *factory) {
	this->preprocessorFactories.insert(std::make_pair(task, factory));
}

void ImagePreprocessingEngine::registerTask(PreprocessingTask task) {
	this->preprocessors.insert(std::make_pair(task, preprocessorFactories.at(task)->createImagePreprocessor()));
}

void ImagePreprocessingEngine::prepareTasks() {
	// prepare
	int counter = 0;

	// iterate through all preprocessors associated to a task which is requested by a cue
	for (std::map<PreprocessingTask, ImagePreprocessor*>::iterator iter = preprocessors.begin(); iter != preprocessors.end(); ++iter) {
		ImagePreprocessor *preprocessor = iter->second;

		createOrderedPreprocessorList(preprocessor);
	}
}

void ImagePreprocessingEngine::createOrderedPreprocessorList(
		ImagePreprocessor* preprocessor) {

	path.push_back(preprocessor->getAssociatedTask());

	std::vector<PreprocessingTask> dependencyTasks = preprocessor->getNeededPreprocessingTasks();
	if (!dependencyTasks.empty()) {
		for (int i = 0; i < dependencyTasks.size(); i++) {
			// the task is already in the path
			if (std::find(path.begin(), path.end(), dependencyTasks[i]) != path.end()) {
				std::cout << "ERROR: there is a circle in the dependencies!" << std::endl;
				exit(0);
			}
			else {
				// the dependency task we got from the preprocessor isn't necessarily in the preprocessor list.
				// then we have to instanciate the appropriate preprocessor first.
				bool found = false;
				for (std::map<PreprocessingTask, ImagePreprocessor*>::iterator iter = preprocessors.begin(); iter != preprocessors.end(); ++iter) {
					if (dependencyTasks[i] == iter->first) {
						found = true;
						break;
					}
				}

				if (!found) {
					this->preprocessors.insert(std::make_pair(dependencyTasks[i], preprocessorFactories.at(dependencyTasks[i])->createImagePreprocessor()));
				}

				createOrderedPreprocessorList(preprocessors.at(dependencyTasks[i]));
			}
		}
	}
	if (std::find(orderedPreprocessors.begin(), orderedPreprocessors.end(), preprocessor) == orderedPreprocessors.end()) {
		orderedPreprocessors.push_back(preprocessor);
	}
	path.erase(std::remove(path.begin(), path.end(), preprocessor->getAssociatedTask()), path.end());
}

void ImagePreprocessingEngine::processTasks() {
	// compute
	for (int i = 0; i<orderedPreprocessors.size(); i++) {
		orderedPreprocessors[i]->compute();
	}
}