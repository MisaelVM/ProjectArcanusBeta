#include "Player.h"

Player::Player(float x, float y, sf::Texture *sfTexture) {
	constructSprite(sfTexture);
	setPosition(x, y);
}