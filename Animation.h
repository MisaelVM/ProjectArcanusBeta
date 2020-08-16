#pragma once

#include <map>
#include <list>
#include <string>
#include <memory>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Animation {
private:
	sf::Texture& sfTexture;
	sf::Sprite& sfSprite;

	sf::IntRect sfFrame;

	float fFrameChronometer;
	float fFrameTime;

	int nFrameWidth;
	int nFrameHeight;

	int nStartingFramePosX;
	int nStartingFramePosY;
	int nFinalFramePosX;
	int nFinalFramePosY;

public:
	// -- CONSTRUCTOR --
	Animation(sf::Sprite& _sfSprite, sf::Texture& _sfTexture, float fTime, int _nFrameWidth, int _nFrameHeight, int _nStartingFramePosX, int _nStartingFramePosY, int _nFinalFramePosX, int _nFinalFramePosY);

	// Functions
	void play(const float& fElapsedTime);
	void restart();
};