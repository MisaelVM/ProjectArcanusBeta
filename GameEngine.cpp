#include "GameEngine.h"

// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
GameEngine::GameEngine() { // Class' Constructor - Calls its functions
    constructWindow();

    sfResourcesTextures.loadFromFile("Resources/texture1.png"); // Loads textures
    player = new Player(25, 25, &sfResourcesTextures); // Initializes player
}

GameEngine::~GameEngine() { // Class' Destructor - Clears memory
	delete sfWindow;
    delete player;
}

// Constructor's Functions
void GameEngine::constructWindow() { // Constructs game's window and initializes it
    // Default initialization values
    std::string windowTitle = "Default";
    sf::VideoMode windowSize(0, 0);
    int framerateLimit = 0;
    bool verticalSyncEnabled = false;

    std::ifstream windowInitializer("Resources/BaseWindow.ini"); // Reads the initialization values from an .ini file

    // So it can initialize its values correctly
    if(windowInitializer.is_open()) {
        windowInitializer.ignore(64, '=');
        std::getline(windowInitializer, windowTitle);
        windowInitializer.ignore(16, '=');
        windowInitializer >> windowSize.width >> windowSize.height;
        windowInitializer.ignore(16, '=');
        windowInitializer >> framerateLimit;
        windowInitializer.ignore(32, '=');
        windowInitializer >> verticalSyncEnabled;
    }
    windowInitializer.close();

    sfWindow = new sf::RenderWindow(windowSize, windowTitle);
    sfWindow->setFramerateLimit(framerateLimit);
    sfWindow->setVerticalSyncEnabled(verticalSyncEnabled);
}

// Main Functions - for handling our game
void GameEngine::start() { // Starts/Launches the game
    while (sfWindow->isOpen()) { // Game Loop
        updateElapsedTime(); // Always updating the Elapsed Time
        update(); // Always updating the window
        draw(); // Always drawing items
    }
}

void GameEngine::updateEvents() {
    while (sfWindow->pollEvent(sfEvent)) { // Handles SFML's events
        if (sfEvent.type == sf::Event::Closed)
            sfWindow->close();
    }
}

void GameEngine::update() { // Updates data in general
    updateEvents();
    player->update(fElapsedTime); // Control/Movement
}

void GameEngine::draw() { // Draws Items
    sfWindow->clear();
    player->draw(sfWindow);
    sfWindow->display();
}

void GameEngine::updateElapsedTime() { // Updates the value of the Elapsed Time
    fElapsedTime = sfElapsedTimeClock.restart().asSeconds();

    system("cls");
    std::cout << fElapsedTime << " --- " << 1 / fElapsedTime << " FPS\n"; // This way we'll test how the FPS are doing
}