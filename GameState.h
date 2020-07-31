#pragma once

#include "MenuScene.h"
#include "LevelScene.h"

class GameState {
private:
	std::map<std::string, Scene*> mGameScenes;
	Scene *currentScene;

	std::map<std::string, sf::Texture> mGameResourceTextures; // Textures that will be loaded in the game
	std::map<std::string, sf::Music> mGameResourceMusic; // Game Music

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	GameState();
	virtual ~GameState();

	// Functions
	void getInput(bool input[4], const float& fElapsedTime);
	void changeScene(std::string sName);

	// Main functions
	void update(const float &fElapsedTime);
	void draw(sf::RenderTarget *sfTarget);
};