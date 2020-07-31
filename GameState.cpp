#include "GameState.h"

GameState::GameState() {
    // Loading Game's textures
    mGameResourceTextures["MAIN_MENU_SCREEN"].loadFromFile("Resources/MainMenuScreen.jpg");
    mGameResourceTextures["ARIEL_SHEET"].loadFromFile("Resources/ARIEL_SHEET.png");

    // Loading Game's music
    mGameResourceMusic["TITLE_THEME"].openFromFile("Resources/TitleTheme.ogg");
    mGameResourceMusic["BACKGROUND_MUSIC"].openFromFile("Resources/BackgroundMusic.ogg");

    std::string lvl1[] = { "ARIEL_SHEET" };

    mGameScenes["MAIN_MENU"] = new MenuScene("MAIN_MENU", "MAIN_MENU_SCREEN", mGameResourceTextures, mGameResourceMusic.at("TITLE_THEME"));
    mGameScenes["LEVEL_1"] = new LevelScene("LEVEL_1", "LEVEL_2", lvl1, 1, mGameResourceTextures, mGameResourceMusic.at("BACKGROUND_MUSIC"), 1000, 1000, "ARIEL_SHEET", 80, 120, "Resources/1LEVELEDIT.png", "Resources/Tilemap1.ini");
    mGameScenes["LEVEL_2"] = new LevelScene("LEVEL_2", "LEVEL_1", lvl1, 1, mGameResourceTextures, mGameResourceMusic.at("BACKGROUND_MUSIC"), 1000, 1000, "ARIEL_SHEET", 80, 120, "Resources/1LEVELEDIT.png", "Resources/Tilemap2.ini");

    currentScene = mGameScenes["MAIN_MENU"];

    //Map = new TileMap(80, 120, "Resources/1LEVELEDIT.png"); //El string pasado es la imagen con todas las texturas
    
    // player = new Player(1000, 1000, mResourceTextures["ARIEL_SHEET"]); // Initializes player
    // sfMusic.openFromFile("Resources/BackgroundMusic.ogg");
    // sfMusic.play();
    //sfMusic.setVolume(50.f);
}

GameState::~GameState() {
    for (auto &ref : mGameScenes)
        delete ref.second;
}

// Functions
void GameState::getInput(bool input[4], const float &fElapsedTime) {
    currentScene->getPlayerInput(input, fElapsedTime);
}

void GameState::changeScene(std::string sName) {
    if (currentScene->getEnd()) {
        //currentScene->terminate();
        currentScene = mGameScenes[sName];
        currentScene->awake();
    }
}

// Main functions
void GameState::update(const float &fElapsedTime) {
    changeScene(currentScene->getNextScene());
    currentScene->update(fElapsedTime);
}

void GameState::draw(sf::RenderTarget *sfTarget) {
    currentScene->draw(sfTarget);
}