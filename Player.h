#pragma once

#include "Entity.h"

class Player : public Entity {
private:

public:
	// -- CONSTRUCTOR --
	Player(const float x, const float y, sf::Texture &sfTexture);

	// Main functions
	void update(const float &fElapsedTime);
};