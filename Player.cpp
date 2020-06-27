#include "Player.h"

Player::Player(const float x, const float y, sf::Texture &sfTexture) {
	setPosition(x, y);

	// Constructs the animator
	constructAnimatorSystem(sfTexture);
	// Setting the animations
	animatorSystem->setNewAnimation("WALKING_RIGHT", 10.f, 35, 35, 0, 4, 5, 4);

}

void Player::update(const float &fElapsedTime) {
	// Checks what keys are being pressed so it can move our Entity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move(-1, 0, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move(1, 0, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move(0, -1, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move(0, 1, fElapsedTime);
	// Plays the animation
	animatorSystem->playAnimation("WALKING_RIGHT", fElapsedTime);
}