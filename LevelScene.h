#pragma once

#include "Scene.h"
#include "DialogDisplayer.h"

class LevelScene : public Scene {
private:
	float startingPosX;
	float startingPosY;

	Player* player;
	TileMap* sceneMap;
	sf::View* camera;

	Cutscene cutscene;
	DialogDisplayer* dialogDisplayer;

	sf::Music& sfMusic; // Game Music


public:
	LevelScene(const std::string _sSceneName, const std::string _sNextScene, // Level Name
		const std::string sceneTextures[], const int nTextures, const std::map<std::string, sf::Texture> sourceTextures, // Initialize Textures
		sf::Music& sceneMusic, // Initialize Music
		const float playerPosX, const float playerPosY, const std::string playerTexture, // Initialize player
		const int rows, const int columns, const std::string textureArchive, const char* tilemapArchive); // Initialize TileMap
	virtual ~LevelScene();

	char getCollision(const float x, const float y);
	const bool checkCollision(const char& tile) const;
	void checkTrigger(const char& tile);

	void checkcamera();
	void getPlayerInput(bool input[4], const float& fElapsedTime);

	std::string getNextScene() const;
	const bool getEnd() const;

	void save(const float x = 0, const float y = 0);

	void update(const float& fElapsedTime);
	void awake();
	void end();
	void end(const float x, const float y);
	void draw(sf::RenderTarget* sfTarget);
};