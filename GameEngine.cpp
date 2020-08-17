#include "GameEngine.h"

GameEngine::GameEngine() { // Class' Constructor - Calls its functions
    constructWindow();
    constructInput();
    gameState = std::make_unique<GameState>();
}

GameEngine::~GameEngine() { // Class' Destructor - Clears memory
    delete sfWindow;
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
    if (windowInitializer.is_open()) {
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

    sfImage = std::make_unique<sf::Image>();
    sfImage->loadFromFile("Resources/THQ.png");
    sfWindow->setIcon(256, 256, sfImage->getPixelsPtr());
}

void GameEngine::constructInput() {
    std::string stream;

    std::ifstream inputInitializer("Resources/BaseInput.ini");

    inputInitializer.ignore(32, ']');
    while (inputInitializer >> stream) {
        int pos = stream.find("=");
        std::string keyBind = stream.substr(0, pos);
        stream.erase(0, pos + 1);
        char key;
        if (stream == "Escape")
            key = 36;
        else {
            std::stringstream parse(stream);
            parse >> key;
            key -= 65;
        }
        mGameInput[keyBind] = sf::Keyboard::Key(key);
    }
    inputInitializer.close();
}

// Private Functions
void GameEngine::checkCloseGame() {
    if (!gameState->stillOpen()) {
        Player::deleteInstance();
        sfWindow->close();
    }
}

void GameEngine::checkChangedSettings() {
    if (gameState->checkNewSettings())
        constructInput();
}

// Main Functions - for handling our game
void GameEngine::start() { // Starts/Launches the game
    while (sfWindow->isOpen()) { // Game Loop
        update(); // Always updating the data
        draw(); // Always drawing items
    }
}

void GameEngine::updateEvents() {
    while (sfWindow->pollEvent(sfEvent)) { // Handles SFML's events
        if (sfEvent.type == sf::Event::Closed) {
            sfWindow->close();
        }
        if (sfEvent.type == sf::Event::MouseButtonReleased) {
            sf::Vector2i mouse_pos;
            mouse_pos = sf::Mouse::getPosition(*sfWindow);
            gameState->checkClick(mouse_pos);
        }
    }
}

void GameEngine::update() { // Updates data in general
    std::thread t1(&GameEngine::updateElapsedTime, this);
    std::thread t2(&GameEngine::checkUserInput, this);
    std::thread t3(&GameEngine::checkCloseGame, this);
    updateEvents();
    t1.join(); t2.join(); t3.join();
    gameState->update(fElapsedTime);
    checkChangedSettings();

}

void GameEngine::draw() { // Draws Items 
    sfWindow->clear();

    //camera->setCenter(player->GetPosition());
    gameState->draw(sfWindow);
    sfWindow->display();

}

void GameEngine::updateElapsedTime() { // Updates the value of the Elapsed Time
    fElapsedTime = sfElapsedTimeClock.restart().asSeconds();
    system("cls");
    std::cout << fElapsedTime << " --- " << 1 / fElapsedTime << " FPS\n"; // This way we'll test how the FPS are doing
    // std::cout << ceil(player->GetPosition().x/35) << " " <<ceil( player->GetPosition().y/35)<<"\n";
    // std::cout<<ceil(camera->getCenter().x/35)<<" "<<ceil(camera->getCenter().y/35)-10;
}

void GameEngine::checkUserInput() {
    if (sfWindow->hasFocus()) {
        bool playerInput[4] = { false, false, false, false };

        if (gameState->checkSceneInput()) {
            if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_LEFT"])) playerInput[0] = true;
            if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_RIGHT"])) playerInput[1] = true;
            if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_UP"])) playerInput[2] = true;
            if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_DOWN"])) playerInput[3] = true;
            // // player->setPlayerInput(playerHotkeys);
            gameState->getInput(playerInput, fElapsedTime);
        }

        if (sf::Keyboard::isKeyPressed(mGameInput["ESCAPE"]))
            gameState->changeScene("PAUSE_MENU");
    }
}