#include "Scene.h"

Scene::Scene() {
	bSceneEnd = false;
}

const bool Scene::checkEnabledInput() const {
	return bEnabledInput;
}
