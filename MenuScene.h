#pragma once

#include "Scene.h"

class MenuScene : public Scene {
private:
	sf::Texture screenTexture;
	sf::Sprite screenSprite;

	sf::Music &sfMusic; // Game Music

public:
	// -- CONSTRUCTOR --
	MenuScene(const std::string _sLevelName,
		const std::string sceneTexture, const std::map<std::string, sf::Texture> sourceTextures,
		sf::Music& sceneMusic);

	char getCollision(const float x, const float y) { return ' '; }
	const bool checkCollision(const char &tile) const { return false; }
	void checkTrigger(const char &tile) {}

	void checkcamera() {}
	void getPlayerInput(bool input[4], const float &fElapsedTime) {}

	std::string getNextScene() const;
	const bool getEnd() const;

	// Main Functions
	void update(const float &fElapsedTime);
	void awake();
	void draw(sf::RenderTarget *sfTarget);
};