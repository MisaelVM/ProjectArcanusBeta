#include "AnimatorSystem.h"

// -- CONSTRUCTOR/DESTRUCTOR --
AnimatorSystem::AnimatorSystem(sf::Sprite &_sfSprite, sf::Texture &_sfTexture)
	// Initializing references
	: sfSprite(_sfSprite), sfTexture(_sfTexture) {
	framePointer = nullptr;
}

// Functions
void AnimatorSystem::setNewAnimation(const std::string sAnimationKey, float fFrameTime, int nFrameWidth, int nFrameHeight, int nStartingFramePosX, int nStartingFramePosY, int nFinalFramePosX, int nFinalFramePosY) {
	mAnimations[sAnimationKey] = std::make_shared<Animation>(sfSprite, sfTexture, fFrameTime, nFrameWidth, nFrameHeight, nStartingFramePosX, nStartingFramePosY, nFinalFramePosX, nFinalFramePosY);
}

void AnimatorSystem::playAnimation(const std::string sAnimationKey, const float &fElapsedTime) {
	if (!framePointer)
		framePointer = mAnimations[sAnimationKey];

	if (framePointer != mAnimations[sAnimationKey]) {
		framePointer->restart();
		framePointer = mAnimations[sAnimationKey];
	}
	framePointer->play(fElapsedTime);
}