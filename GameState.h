#pragma once

#include "MenuScene.h"
#include "LevelScene.h"

class GameState {
private:
	std::map<std::string, std::shared_ptr<Scene>> mGameScenes;
	std::shared_ptr<Scene> currentScene;

	bool bGameOpen;
	bool bSettingsChanged;

	std::map<std::string, sf::Texture> mGameResourceTextures; // Textures that will be loaded in the game
	std::map<std::string, sf::Music> mGameResourceMusic; // Game Music

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	GameState();

	// Functions
	const bool stillOpen() const;
	const bool checkNewSettings() const;

	void getInput(bool input[4], const float& fElapsedTime);
	void changeScene(std::string sName);

	const bool checkSceneInput() const;
	void checkClick(sf::Vector2i mousePos);

	// Main functions
	void update(const float& fElapsedTime);
	void draw(sf::RenderTarget* sfTarget);
};