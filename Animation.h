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

	float fFrameChronometer;

public:
	Animation(sf::Sprite &_sfSprite, sf::Texture &_sfTexture, float fTime, int nWidth, int nHeight);
	void play(const float &fElapsedTime);
};