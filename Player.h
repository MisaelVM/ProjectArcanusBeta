#pragma once

#include "Entity.h"

class Player : public Entity {
private:
	sf::Vector2f vfVelocitySense;
	sf::Vector2i viLastSense;

	bool input[4];

public:
	// -- CONSTRUCTOR --
	Player(const float x, const float y, sf::Texture &sfTexture);

	// Functions
	void setPlayerInput(const sf::Vector2f &velocity, const sf::Vector2i &last);

	sf::Vector2f getVelocitySense() const;
	sf::Vector2i getLastSense() const;

	// Main functions
	void update(const float &fElapsedTime);
	void draw(sf::RenderTarget *sfTarget);
	
	// sf::Vector2f GetHitboxPosition();
};