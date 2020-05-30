#include "GameEngine.h"

// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
GameEngine::GameEngine() { // Class' Constructor - Calls its functions
    constructWindow();
}

GameEngine::~GameEngine() { // Class' Destructor - Clears memory
	delete sfWindow;
}

// Constructor's Functions
void GameEngine::constructWindow() { // Constructs game's window and initializes it
	sfWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "ArcanusBeta");
}

// Main Functions - for handling our game
void GameEngine::start() { // Starts/Launches the game
    while (sfWindow->isOpen()) { // Game Loop
        update(); // Always updating the window
        render(); // Always rendering items
    }
}

void GameEngine::updateEvents() {
    while (sfWindow->pollEvent(sfEvent)) { // Handles SFML's events
        if (sfEvent.type == sf::Event::Closed)
            sfWindow->close();
    }
}

void GameEngine::update() {
    updateEvents();
}

void GameEngine::render() { // Renders Items
    sfWindow->clear();
    sfWindow->display();
}
