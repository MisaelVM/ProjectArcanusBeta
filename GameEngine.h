#pragma once

#include "Entity.h"

class GameEngine {
private:
	sf::RenderWindow *sfWindow;
	sf::Event sfEvent;

	sf::Clock sfElapsedTimeClock;
	float fElapsedTime; // aka Delta Time

	Entity player;

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
	void draw();
	void updateElapsedTime();
};