#pragma once
#include "Player.h"
#include "SFML/Graphics.hpp"
#include<iostream>
#include "TileMap.h"
class GameEngine
{
	sf::RenderWindow* sfWindow;
	sf::Event sfEvent;

	sf::Clock sfElapsedTimeClock;
	float fElapsedTime; // aka Delta Time

	Player* player;
	std::map<std::string, sf::Texture> mResourceTextures; // Textures that will be loaded in the game

	TileMap* Map; // Map that will be displayed

	sf::View *camera;// 

	// Constructor's functions
	void constructWindow();

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	GameEngine();
	virtual ~GameEngine();

	// Main Functions
	void start();
	void updateEvents();
	void update();
	void checkcamera();
	void draw();
	void updateElapsedTime();
};

