#pragma once

#include "MenuState.h"
#include "Button.h"

class MenuState;

class MenuScene : public Scene {
private:
	std::unique_ptr<sf::View> camera;

	std::unique_ptr<sf::Texture> screenTexture;
	sf::Sprite screenSprite;

	sf::Music& sfMusic; // Game Music

	MenuState* state;

public:
	// -- CONSTRUCTOR --
	MenuScene(const std::string _sSceneName, const std::string _sNextScene,
		sf::Music& sceneMusic,
		const std::string sceneTexture);
	virtual ~MenuScene();

	// -- STATE PATTERN --
	void setState(MenuState* _state);

	// Functions
	char getCollision(const float x, const float y) { return ' '; }
	const bool checkCollision(const char& tile) const { return false; }
	void checkTrigger(const char& tile) {}

	void checkcamera() {}
	void getPlayerInput(bool input[4], const float& fElapsedTime) {}

	void setNextScene(const std::string& newScene);
	void setGameExit(const bool& exit = true);
	void setNewSettings(const bool& settings = true);

	sf::View& getCamera() const;

	std::string getSceneName() const;
	std::string getNextScene() const;
	const bool getEnd() const;

	void checkButtonClick(const int x, const int y);

	// Main Functions
	void update(const float& fElapsedTime);
	void awake();
	void end();
	void draw(sf::RenderTarget* sfTarget);
};