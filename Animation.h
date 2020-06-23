#pragma once

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Animation {
private:
	sf::Sprite sfSprite;
	sf::Texture sfTexture;

	sf::IntRect sfFrame;

	float fFrameChronometer;
	float fFrameTime;

	int nFrameWidth;
	int nFrameHeight;

	int nStartingFramePos;
	int nFinalFramePos;

public:
	Animation(sf::Sprite &_sfSprite, sf::Texture &_sfTexture, float fTime, int _nFrameWidth, int _nFrameHeight, int _nStartingFramePos, int _nFinalFramePos);
	void play(const float &fElapsedTime);
};