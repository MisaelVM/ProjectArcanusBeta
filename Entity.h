#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "AnimatorSystem.h"

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Entity {
private:

protected:
	sf::Texture *sfTexture; // Image that will be mapped to a 2D Entity
	sf::Sprite sfSprite; // Texturized Entity

	AnimatorSystem *animatorSystem; // Entity's Animator

	// Variables
	float fMovementSpeed;
	
	// Constructor's functions
	void constructSprite(sf::Texture *_sfTexture); // Constructs the Sprite using the Texture
	void constructAnimatorSystem(sf::Texture &sfTextureSheet); // Constructs the Animator

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	Entity();
	virtual ~Entity();

	// Transform
	virtual void setPosition(const float x, const float y);
	virtual void setRotation(const float angle);
	virtual void setScale(const float x, const float y);

	// Functions
	virtual void move(const float towardsX, const float towardsY, const float &fElapsedTime); // Moves our Entity

	// Main Functions
	virtual void update(const float &fElapsedTime) = 0; // Updates our Entity's data
	virtual void draw(sf::RenderTarget *sfTarget) = 0; // Draws our Entity
};