#include "GameEngine.h"
GameEngine::GameEngine() { // Class' Constructor - Calls its functions
    camera = new sf::View(sf::FloatRect(0, 0, 800, 600));
    constructWindow();
    Map = new TileMap(80, 120, "Resources/1LEVELEDIT.png"); //El string pasado es la imagen con todas las texturas
    mResourceTextures["ARIEL_SHEET"].loadFromFile("Resources/ARIEL_SHEET.png"); // Loads textures
    player = new Player(1000, 1000, mResourceTextures["ARIEL_SHEET"]); // Initializes player
    sfMusic.openFromFile("Resources/BackgroundMusic.ogg");
    sfMusic.play();
    sfMusic.setVolume(50.f);
}

GameEngine::~GameEngine() { // Class' Destructor - Clears memory
    delete player;
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

// Main Functions - for handling our game
void GameEngine::start() { // Starts/Launches the game
    while (sfWindow->isOpen()) { // Game Loop
        update(); // Always updating the window
        draw(); // Always drawing items
    }
}

void GameEngine::updateEvents() {
    while (sfWindow->pollEvent(sfEvent)) { // Handles SFML's events
        if (sfEvent.type == sf::Event::Closed) {
            sfMusic.stop();
            sfWindow->close();
        }
        if (sfEvent.type == sf::Event::MouseWheelMoved)
        {
            camera->zoom(1.f + sfEvent.mouseWheel.delta * 0.1f);
        }
    }
}

void GameEngine::update() { // Updates data in general
    updateElapsedTime(); // Always updating the Elapsed Time
    updateEvents();
    player->update(fElapsedTime); // Control/Movement
    checkcamera();// Set of camera position by the player position
    Collider* hitboxplayer = new Collider(player->GetCollider());
    Map->GetCollider(player->GetHitboxPosition()).Checkcollision(*hitboxplayer, 1.0f);
    delete hitboxplayer;
}
void GameEngine::checkcamera() {
    if (ceil(player->GetPosition().x/35) <= 12 && ceil(player->GetPosition().y/35)<=10) {
        camera->setCenter(sf::Vector2f(400.0f, 335.0f));
    }
    else if (ceil(player->GetPosition().x / 35) >= 109 && ceil(player->GetPosition().y / 35) >= 70) {
        camera->setCenter(sf::Vector2f(3800.0f, 2430.0f));
    }
    else if (ceil(player->GetPosition().x / 35) >= 109 && ceil(player->GetPosition().y / 35) <= 10) {
        camera->setCenter(sf::Vector2f(3800.0f, 335.0f));
    }
    else if (ceil(player->GetPosition().x / 35) <= 109 && ceil(player->GetPosition().y / 35) >= 70) {
        camera->setCenter(sf::Vector2f(400.0f, 2430.0f));
    }
    else if (ceil(player->GetPosition().x / 35) >= 109) {
        camera->setCenter(sf::Vector2f(3800.0f, player->GetPosition().y));
    }
    else if (ceil(player->GetPosition().y / 35) >= 70) {
        camera->setCenter(sf::Vector2f(player->GetPosition().x,2430.0f));
    }
    else if (ceil(player->GetPosition().x / 35) <= 12) {
        camera->setCenter(sf::Vector2f(400.0f,player->GetPosition().y));
    }
    else if (ceil(player->GetPosition().y / 35) <= 10) {
        camera->setCenter(sf::Vector2f(player->GetPosition().x, 335.0f));
    }
    else {
        camera->setCenter(player->GetPosition());
    }
}
void GameEngine::draw() { // Draws Items 
    sfWindow->clear();
    
    //camera->setCenter(player->GetPosition());
    Map->Displaytilemap(sfWindow,camera->getCenter());
    player->draw(sfWindow);
    sfWindow->setView(*camera);
    sfWindow->display();
   
}

void GameEngine::updateElapsedTime() { // Updates the value of the Elapsed Time
    fElapsedTime = sfElapsedTimeClock.restart().asSeconds();
    system("cls");
    std::cout << fElapsedTime << " --- " << 1 / fElapsedTime << " FPS\n"; // This way we'll test how the FPS are doing
    std::cout << ceil(player->GetPosition().x/35) << " " <<ceil( player->GetPosition().y/35)<<"\n";
    std::cout<<ceil(camera->getCenter().x/35)<<" "<<ceil(camera->getCenter().y/35)-10;
}