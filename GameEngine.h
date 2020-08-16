#pragma once

#include "GameState.h"

class GameEngine {
private:
	std::unique_ptr<sf::Image> sfImage;
	sf::RenderWindow* sfWindow;
	sf::Event sfEvent;

	sf::Clock sfElapsedTimeClock;
	float fElapsedTime; // aka Delta Time

	std::unique_ptr<GameState> gameState;

	std::map<std::string, sf::Keyboard::Key> mGameInput;

	// Constructor's functions
	void constructWindow();
	void constructInput();

	// Private Functions
	void checkCloseGame();
	void checkChangedSettings();

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