#include "MenuScene.h"

MenuScene::MenuScene(const std::string _sSceneName, const std::string sceneTexture, const std::map<std::string, sf::Texture> sourceTextures, sf::Music& sceneMusic)
    : sfMusic(sceneMusic) {
    sSceneName = _sSceneName;
    sNextScene = "LEVEL_1";
    bSceneEnd = false;

    screenTexture = sourceTextures.at(sceneTexture);
    screenTexture.setSmooth(true);
    screenSprite.setTexture(screenTexture);
    screenSprite.setScale(sf::Vector2f(1.6, 2.1));

    sfMusic.play();

    //sfMusic.play();
    //sfMusic.setLoop(true);
    //sfMusic.setVolume(50.f);
}

std::string MenuScene::getNextScene() const {
    return sNextScene;
}

const bool MenuScene::getEnd() const {
    return bSceneEnd;
}

void MenuScene::update(const float& fElapsedTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
        bSceneEnd = true;
        sfMusic.stop();
    }
}

void MenuScene::awake() {
    bSceneEnd = false;
    sfMusic.play();
    sfMusic.setLoop(true);
    sfMusic.setVolume(50.f);
}

void MenuScene::draw(sf::RenderTarget* sfTarget) {
    sfTarget->draw(screenSprite);
}