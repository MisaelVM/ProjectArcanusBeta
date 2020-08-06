#pragma once

#include "Cutscene.h"
#include "Player.h"
#include "TileMap.h"

class Scene {
protected:
	std::string sSceneName;

	std::map<std::string, sf::Texture> mSceneResourceTextures; // Textures that will be loaded in the scene

	bool bEnabledInput;
	bool bSceneEnd;
	bool bGameExit;
	bool bSettingsChanged;

	std::string sNextScene;

public:
	// -- CONSTRUCTOR --
	Scene();

	const bool checkEnabledInput() const;
	const bool checkGameExit() const;
	const bool checkSettingsChanged() const;

	virtual void checkButtonClick(const int x, const int y) {}

	virtual char getCollision(const float x, const float y) = 0;
	virtual const bool checkCollision(const char& tile) const = 0;
	virtual void checkTrigger(const char& tile) = 0;

	virtual void checkcamera() = 0;
	virtual void getPlayerInput(bool input[4], const float& fElapsedTime) = 0;

	virtual std::string getNextScene() const = 0;
	virtual const bool getEnd() const = 0;

	virtual void update(const float& fElapsedTime) = 0;
	virtual void awake() = 0;
	virtual void end() = 0;
	virtual void draw(sf::RenderTarget* sfTarget) = 0;
};