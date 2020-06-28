#pragma once

#include "Entity.h"

class Player : public Entity {
private:
	sf::Vector2f vfVelocitySense;
	sf::Vector2i viLastSense;

public:
	// -- CONSTRUCTOR --
	Player(const float x, const float y, sf::Texture &sfTexture);

	// Main functions
	void update(const float &fElapsedTime);
	void draw(sf::RenderTarget *sfTarget);
};