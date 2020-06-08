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

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	Entity();
	virtual ~Entity();

	// Main Functions
	virtual void update(const float &fElapsedTime); // Updates our Entity's data
	virtual void draw(sf::RenderTarget *sfTarget); // Draws our Entity
};