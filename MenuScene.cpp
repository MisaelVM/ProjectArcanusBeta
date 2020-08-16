#include "MenuScene.h"

MenuScene::MenuScene(const std::string _sSceneName, const std::string _sNextScene,
	sf::Music& sceneMusic,
	const std::string sceneTexture)
	: sfMusic(sceneMusic) {
	bSceneEnd = false;
	sNextScene = _sNextScene;

	sSceneName = _sSceneName;

	camera = std::make_unique<sf::View>(sf::FloatRect(0, 0, 800, 600));

	screenTexture = std::make_unique<sf::Texture>();
	screenTexture->loadFromFile(sceneTexture);
	screenTexture->setSmooth(true);

	screenSprite.setTexture(*screenTexture);

	if (sSceneName == "MAIN_MENU") {
		screenSprite.setScale(0.625f, 0.825f);
		state = new MainMenu(this);
	}
	else {
		screenSprite.setScale(1.11f, 1.365f);
		state = new PauseMenu(this);
	}

	screenSprite.setPosition(0, 0);
}

MenuScene::~MenuScene() {
	delete state;
}

void MenuScene::setState(MenuState* _state) {
	state = _state;
}

void MenuScene::setNextScene(const std::string& newScene) {
	sNextScene = newScene;
}

void MenuScene::setGameExit(const bool& exit) {
	bGameExit = exit;
}

void MenuScene::setNewSettings(const bool& settings) {
	bSettingsChanged = settings;
}

sf::View& MenuScene::getCamera() const {
	return *camera;
}

std::string MenuScene::getSceneName() const {
	return sSceneName;
}

std::string MenuScene::getNextScene() const {
	return sNextScene;
}

const bool MenuScene::getEnd() const {
	return bSceneEnd;
}

void MenuScene::checkButtonClick(const int x, const int y) {
	state->checkButtonClick(x, y);
}

void MenuScene::update(const float& fElapsedTime) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
		sNextScene = "LEVEL_1";
		end();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
		sNextScene = "PAUSE_MENU";
		end();
	}
	checkcamera();
}

void MenuScene::awake() {
	bSceneEnd = false;
	sfMusic.play();
	sfMusic.setLoop(true);
	sfMusic.setVolume(50.f);
}

void MenuScene::end() {
	bSceneEnd = true;
	sfMusic.stop();
}

void MenuScene::draw(sf::RenderTarget* sfTarget) {
	sfTarget->draw(screenSprite);
	state->draw(sfTarget);
	sfTarget->setView(*camera);
}