#include "AnimatorSystem.h"

// -- CONSTRUCTOR/DESTRUCTOR --
AnimatorSystem::AnimatorSystem(sf::Sprite &_sfSprite, sf::Texture &_sfTexture) {
	sfSprite = _sfSprite;
	sfTexture = _sfTexture;
}

AnimatorSystem::~AnimatorSystem() {
	for (auto &ref : vAnimations)
		delete ref;
}