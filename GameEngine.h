#pragma once

#include "GameState.h"

class GameEngine {
private:
	sf::RenderWindow *sfWindow;
	sf::Event sfEvent;

	sf::Clock sfElapsedTimeClock;
	float fElapsedTime; // aka Delta Time

	GameState *gameState;

	std::map<std::string, sf::Keyboard::Key> mGameInput;

	// Constructor's functions
	void constructWindow();
	void constructInput();

	// Private Functions
	void editWindow();
	void editInput();

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	GameEngine();
	virtual ~GameEngine();

	// Main Functions
	void start();
	void updateEvents();
	void updateElapsedTime();
	void checkUserInput();
	void update();
	void draw();
};