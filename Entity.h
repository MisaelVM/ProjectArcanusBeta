#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Entity {
private:

protected:
	sf::RectangleShape sfShape;
	sf::Texture *sfTexture; // Image that will be mapped to a 2D Entity
	sf::Sprite *sfSprite; // Texturized Entity

	// Variables
	float fMovementSpeed;

	// Constructor's functions
	void constructSprite(sf::Texture *sfTexture); // Constructs the Sprite using the Texture

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	Entity();
	virtual ~Entity();

	// Functions
	virtual void setPosition(const float x, const float y);
	virtual void move(const int towardsX, const int towardsY, const float &fElapsedTime); // Moves our Entity

	// Main Functions
	virtual void update(const float &fElapsedTime); // Updates our Entity's data
	virtual void draw(sf::RenderTarget *sfTarget); // Draws our Entity
};