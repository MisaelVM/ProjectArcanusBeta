#pragma once

#include "Animation.h"

class AnimatorSystem {
private:
	sf::Texture& sfTexture;
	sf::Sprite& sfSprite;

	std::shared_ptr<Animation> framePointer;

	// Stores the animations
	std::map<std::string, std::shared_ptr<Animation>> mAnimations;

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	AnimatorSystem(sf::Sprite& _sfSprite, sf::Texture& _sfTexture);

	// Functions
	void setNewAnimation(const std::string sAnimationKey, float fFrameTime, int nFrameWidth, int nFrameHeight, int nStartingFramePosX, int nStartingFramePosY, int nFinalFramePosX, int nFinalFramePosY);
	void playAnimation(const std::string sAnimationKey, const float& fElapsedTime);
};