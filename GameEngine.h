#pragma once

#include <iostream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class GameEngine {
private:
	sf::RenderWindow *sfWindow;
	sf::Event sfEvent;

	// Constructor's functions
	void constructWindow();

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	GameEngine();
	virtual ~GameEngine();

	// Main Functions
	void start();
	void updateEvents();
	void update();
	void render();

};

