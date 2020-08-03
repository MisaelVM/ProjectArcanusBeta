#include "GameEngine.h"
GameEngine::GameEngine() { // Class' Constructor - Calls its functions
    constructWindow();
    constructInput();
    gameState = new GameState();
}

GameEngine::~GameEngine() { // Class' Destructor - Clears memory
    delete gameState;
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
void GameEngine::editWindow() {
    int input;

    // Config variables
    std::string resolution;
    std::string framerateLimit;
    std::string verticalSync;

    // Window resolution
    std::string window_resolutions[] =
    { "640 480", "800 600", "960 720", "1280 720", "1366 768", "1600 900", "1920 1080", "2560 1440", "3840 2160" };

    std::cout << "Choose resolution:\n";
    for (int i = 0; i < 9; i++)
        std::cout << i + 1 << ") " << window_resolutions[i] << "\n";
    std::cin >> input;
    resolution = window_resolutions[input - 1];

    // Framerate Limit
    std::string framerate_limits[] =
    { "30", "40", "50", "60", "100", "120", "144", "0" };
    std::cout << "Choose framerate limit:\n";
    for (int i = 0; i < 8 - 1; i++)
        std::cout << i + 1 << ") " << framerate_limits[i] << "\n";
    std::cout << "8) Unlimited\n";
    std::cin >> input;
    framerateLimit = framerate_limits[input - 1];

    // Vertical sync
    std::cout << "Enable Vertical Sync?:\n";
    std::cin >> input;
    input ? verticalSync = "1" : verticalSync = "0";

    // Saves configuration
    std::ofstream newConfiguration("Resources/BaseWindow.ini", std::ofstream::trunc);
    if (newConfiguration.is_open()) {
        newConfiguration << "[GameEngine.sfWindow]\n";
        newConfiguration << "windowTitle=TheHolyQuest\n";
        newConfiguration << "windowSize=" << resolution << "\n";
        newConfiguration << "framerateLimit=" << framerateLimit << "\n";
        newConfiguration << "verticalSyncEnabled=" << verticalSync << "\n";
    }
    newConfiguration.close();
}

void GameEngine::editInput() {
    std::string escape;
    std::string move_up;
    std::string move_down;
    std::string move_left;
    std::string move_right;

    std::cin >> escape >> move_up >> move_down >> move_left >> move_right;

    std::ofstream newInputConfiguration("Resources/BaseInput.ini", std::ofstream::trunc);
    if (newInputConfiguration.is_open()) {
        newInputConfiguration << "[GameEngine.gameInput]\n";
        newInputConfiguration << "ESCAPE=" << escape << "\n";
        newInputConfiguration << "MOVE_UP=" << move_up << "\n";
        newInputConfiguration << "MOVE_DOWN=" << move_down << "\n";
        newInputConfiguration << "MOVE_LEFT=" << move_left << "\n";
        newInputConfiguration << "MOVE_RIGHT=" << move_right << "\n";
    }
    newInputConfiguration.close();
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
        /*if (sfEvent.type == sf::Event::MouseWheelMoved)
        {
            camera->zoom(1.f + sfEvent.mouseWheel.delta * 0.1f);
        }*/
    }
}

void GameEngine::update() { // Updates data in general
    updateElapsedTime(); // Always updating the Elapsed Time
    updateEvents();
    checkUserInput();
    gameState->update(fElapsedTime);
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
    bool playerInput[4] = { false, false, false, false };

    if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_LEFT"])) playerInput[0] = true;
    if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_RIGHT"])) playerInput[1] = true;
    if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_UP"])) playerInput[2] = true;
    if (sf::Keyboard::isKeyPressed(mGameInput["MOVE_DOWN"])) playerInput[3] = true;
    // // player->setPlayerInput(playerHotkeys);
    gameState->getInput(playerInput, fElapsedTime);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) { editWindow(); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) { editInput(); }
}