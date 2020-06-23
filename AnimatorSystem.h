#pragma once

#include "Animation.h"

class AnimatorSystem {
private:
	sf::Texture sfTexture;
	sf::Sprite sfSprite;

	// Stores the animations
	std::vector<Animation*> vAnimations;

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	AnimatorSystem(sf::Sprite &_sfSprite, sf::Texture &_sfTexture);
	virtual ~AnimatorSystem();
};