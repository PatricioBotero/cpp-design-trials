/*
 * TrackingFactory.cpp
 *
 *  Created on: 06.05.2014
 *      Author: tabuchte
 */

#include <factory/TrackingFactory.h>
#include "nodes/ImagePreparationNode.h"
#include "nodes/TriggerNode.h"
#include "nodes/PropagationNode.h"
#include "nodes/HistogramCueNode.h"
#include "nodes/KeyingCueNode.h"
#include "nodes/FlowCueNode.h"
#include "nodes/JoinMeasurementsNode.h"
#include "nodes/ResamplingNode.h"
#include "nodes/CollisionCheckNode.h"

Node* TrackingFactory::createPipeline(ObjectStore &objectStore) {

	// image preparation
	TriggerNode* imagePreparationTrigger = new TriggerNode(objectStore);
	Bundle* imagePreparationBundle = new Bundle(objectStore);
	ImagePreparationNode* imagePreparation = new ImagePreparationNode(objectStore);
	imagePreparationBundle->addComputationElement(imagePreparation);
	imagePreparationBundle->setComputationMethod(SERIAL);

	// propagation
	TriggerNode* propagationTrigger = new TriggerNode(objectStore);
	Bundle* propagationBundle = new Bundle(objectStore);
	PropagationNode* propagationNode = new PropagationNode(objectStore);
	propagationBundle->addComputationElement(propagationNode);
	propagationBundle->setComputationMethod(SERIAL);

	// collision check
	CollisionCheckNode* collisionCheckNode = new CollisionCheckNode(
			objectStore);

	// particle operations
	TriggerNode* particleOperationsTrigger = new TriggerNode(objectStore);
	Bundle* particleOperationsBundle = new Bundle(objectStore);
	Bundle* measurementBundle = new Bundle(objectStore);
	HistogramCueNode* histogramCueNode = new HistogramCueNode(objectStore);
	KeyingCueNode* keyingCueNode = new KeyingCueNode(objectStore);
	FlowCueNode* flowCueNode = new FlowCueNode(objectStore);
	measurementBundle->addComputationElement(histogramCueNode);
	measurementBundle->addComputationElement(keyingCueNode);
	measurementBundle->addComputationElement(flowCueNode);
	measurementBundle->setComputationMethod(SERIAL);
	JoinMeasurementsNode* joinMeasurementsNode = new JoinMeasurementsNode(
			objectStore);
	ResamplingNode* resamplingNode = new ResamplingNode(objectStore);
	particleOperationsBundle->addComputationElement(measurementBundle);
	particleOperationsBundle->addComputationElement(joinMeasurementsNode);
	particleOperationsBundle->addComputationElement(resamplingNode);
	particleOperationsBundle->setComputationMethod(SERIAL);

	// put everything together
	imagePreparationTrigger->registerNode(imagePreparationBundle)->registerNode(
			propagationTrigger)->registerNode(propagationBundle)->registerNode(
			collisionCheckNode)->registerNode(particleOperationsTrigger)->registerNode(particleOperationsBundle);
	return imagePreparationTrigger;
}
