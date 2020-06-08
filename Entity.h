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
	sf::RectangleShape sfShape; // The entity will be shown as a Rectangle/Square
	float fMovementSpeed;

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	Entity();
	virtual ~Entity();

	virtual void move(const int towardsX, const int towardsY, const float &fElapsedTime); // Moves our Entity

	// Main Functions
	virtual void update(const float &fElapsedTime); // Updates our Entity's data
	virtual void draw(sf::RenderTarget *sfTarget); // Draws our Entity
};