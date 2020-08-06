#include "Scene.h"

Scene::Scene() {
	bEnabledInput = true;
	bSceneEnd = false;
	bGameExit = false;
	bSettingsChanged = false;
}

const bool Scene::checkEnabledInput() const {
	return bEnabledInput;
}

const bool Scene::checkGameExit() const {
	return bGameExit;
}

const bool Scene::checkSettingsChanged() const {
	return bSettingsChanged;
}