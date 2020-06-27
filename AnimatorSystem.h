#pragma once

#include <map>
#include <string>

#include "Animation.h"

class AnimatorSystem {
private:
	sf::Texture &sfTexture;
	sf::Sprite &sfSprite;

	// Stores the animations
	std::map<std::string, Animation*> mAnimations;

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	AnimatorSystem(sf::Sprite &_sfSprite, sf::Texture &_sfTexture);
	virtual ~AnimatorSystem();

	// Functions
	void setNewAnimation(const std::string sAnimationKey, float fFrameTime, int nFrameWidth, int nFrameHeight, int nStartingFramePosX, int nStartingFramePosY, int nFinalFramePosX, int nFinalFramePosY);
	void playAnimation(const std::string sAnimationKey, const float &fElapsedTime);
};