#pragma once

#include "Player.h"

class GameEngine {
private:
	sf::RenderWindow *sfWindow;
	sf::Event sfEvent;

	sf::Clock sfElapsedTimeClock;
	float fElapsedTime; // aka Delta Time

	Player *player;
	sf::Texture *sfResourcesTextures; // Textures that will be loaded in the game

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