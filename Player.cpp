#include "Player.h"

Player::Player(const float x, const float y, sf::Texture *sfTexture) {
	constructSprite(sfTexture);
	setPosition(x, y);
}