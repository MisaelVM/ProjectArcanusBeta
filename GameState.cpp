#include "GameState.h"

GameState::GameState() {
    bGameOpen = true;
    bSettingsChanged = false;
    // Loading Game's textures
    mGameResourceTextures["MAIN_MENU_SCREEN"].loadFromFile("Resources/MainMenuScreen.jpg");
    mGameResourceTextures["ARIEL_SHEET"].loadFromFile("Resources/ARIEL_SHEET.png");

    // Loading Game's music
    mGameResourceMusic["TITLE_THEME"].openFromFile("Resources/TitleTheme.ogg");
    mGameResourceMusic["PAUSE_THEME"].openFromFile("Resources/PauseMenuMusic.ogg");
    mGameResourceMusic["BACKGROUND_MUSIC"].openFromFile("Resources/BackgroundMusic.ogg");

    std::string lvl1[] = { "ARIEL_SHEET" };

    mGameScenes["MAIN_MENU"] = std::make_shared<MenuScene>("MAIN_MENU", "LEVEL_2", mGameResourceMusic.at("TITLE_THEME"), "Resources/MainMenuScreen.jpg");
    mGameScenes["PAUSE_MENU"] = std::make_shared<MenuScene>("PAUSE_MENU", "LEVEL_1", mGameResourceMusic.at("PAUSE_THEME"), "Resources/PauseMenu.jpg");
    mGameScenes["LEVEL_1"] = std::make_shared<LevelScene>("LEVEL_1", "LEVEL_2", lvl1, 1, mGameResourceTextures, mGameResourceMusic.at("BACKGROUND_MUSIC"), 1000, 1000, "ARIEL_SHEET", 80, 120, "Resources/1LEVELEDIT.png", "Resources/Tilemap1.ini");
    mGameScenes["LEVEL_2"] = std::make_shared<LevelScene>("LEVEL_2", "LEVEL_1", lvl1, 1, mGameResourceTextures, mGameResourceMusic.at("BACKGROUND_MUSIC"), 1000, 1000, "ARIEL_SHEET", 80, 120, "Resources/1LEVELEDIT.png", "Resources/Tilemap2.ini");

    currentScene = mGameScenes["MAIN_MENU"];
}

// Functions
const bool GameState::stillOpen() const {
    return bGameOpen;
}

const bool GameState::checkNewSettings() const {
    return bSettingsChanged;
}

void GameState::getInput(bool input[4], const float& fElapsedTime) {
    currentScene->getPlayerInput(input, fElapsedTime);
}

void GameState::changeScene(std::string sName) {
    currentScene->end();
    currentScene = mGameScenes[sName];
    currentScene->awake();
}

const bool GameState::checkSceneInput() const {
    return currentScene->checkEnabledInput();
}

void GameState::checkClick(sf::Vector2i mousePos) {
    currentScene->checkButtonClick(mousePos.x, mousePos.y);
}

// Main functions
void GameState::update(const float& fElapsedTime) {
    if (currentScene->checkGameExit())
        bGameOpen = false;
    if (currentScene->checkSettingsChanged())
        bSettingsChanged = true;
    if (currentScene->getEnd())
        changeScene(currentScene->getNextScene());
    currentScene->update(fElapsedTime);
}

void GameState::draw(sf::RenderTarget* sfTarget) {
    currentScene->draw(sfTarget);
}