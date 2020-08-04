#include "Player.h"

// -- INSTANCE GETTER -- SINGLETON PATTERN --
Player *Player::getInstance() {
	if (player_instance == nullptr)
		player_instance = new Player();
	return player_instance;
}

void Player::refresh(const float x, const float y, sf::Texture& sfTexture) {
	if (!animatorSystem) {
		// Constructs the animator
		constructAnimatorSystem(sfTexture);
		// Setting the animations
		animatorSystem->setNewAnimation("WALKING_RIGHT", 10.f, 35, 35, 0, 4, 5, 4);
		animatorSystem->setNewAnimation("IDLE_RIGHT", 10.f, 35, 35, 0, 0, 0, 0);
		animatorSystem->setNewAnimation("IDLE_LEFT", 10.f, 35, 35, 0, 1, 0, 1);
		animatorSystem->setNewAnimation("IDLE_UP", 10.f, 35, 35, 0, 2, 0, 2);
		animatorSystem->setNewAnimation("IDLE_DOWN", 10.f, 35, 35, 0, 3, 0, 3);
		animatorSystem->setNewAnimation("WALKING_RIGHT", 10.f, 35, 35, 0, 4, 5, 4);
		animatorSystem->setNewAnimation("WALKING_LEFT", 10.f, 35, 35, 0, 5, 5, 5);
		animatorSystem->setNewAnimation("WALKING_UP", 10.f, 35, 35, 0, 6, 5, 6);
		animatorSystem->setNewAnimation("WALKING_DOWN", 10.f, 35, 35, 0, 7, 5, 7);
	}

	vfVelocitySense = sf::Vector2f(1.f, 0.f);
	viLastSense = sf::Vector2i(1, 0);

	input[0] = false;
	input[1] = false;
	input[2] = false;
	input[3] = false;

	hitbox.setPosition(x + 8.f, y);
	hitbox.setSize(sf::Vector2f(20.f, 35.f));

	setPosition(x, y);
}

//Main functions

void Player::update(const float& fElapsedTime) {
	/*vfVelocitySense.x = 0.f; vfVelocitySense.y = 0.f;

	// Checks what keys are being pressed so it can move our Entity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { vfVelocitySense.x = -1.f; viLastSense.x = -1; viLastSense.y = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { vfVelocitySense.x = 1.f; viLastSense.x = 1; viLastSense.y = 0; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { vfVelocitySense.y = -1.f; viLastSense.x = 0; viLastSense.y = -1; }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { vfVelocitySense.y = 1.f; viLastSense.x = 0; viLastSense.y = 1; }*/

	// Plays the animation
	if (vfVelocitySense.x == 0.f && vfVelocitySense.y == 0.f) {
		if (viLastSense.x == 1) animatorSystem->playAnimation("IDLE_RIGHT", fElapsedTime);
		else if (viLastSense.x == -1) animatorSystem->playAnimation("IDLE_LEFT", fElapsedTime);
		else if (viLastSense.y == 1) animatorSystem->playAnimation("IDLE_DOWN", fElapsedTime);
		else if (viLastSense.y == -1) animatorSystem->playAnimation("IDLE_UP", fElapsedTime);
	}
	else {
		if (vfVelocitySense.x > 0)
			animatorSystem->playAnimation("WALKING_RIGHT", fElapsedTime);
		else if (vfVelocitySense.x < 0)
			animatorSystem->playAnimation("WALKING_LEFT", fElapsedTime);
		else {
			if (vfVelocitySense.y < 0)
				animatorSystem->playAnimation("WALKING_UP", fElapsedTime);
			else if (vfVelocitySense.y > 0)
				animatorSystem->playAnimation("WALKING_DOWN", fElapsedTime);
		}
	}
	// Sets the Velocity Sense Vector
	vfVelocitySense *= fMovementSpeed;

	if (!bInCinematic)
		// Moves the Entity
		move(vfVelocitySense.x, vfVelocitySense.y, fElapsedTime);
	bInCinematic = false;
	// sf::Vector2f thisposition = hitbox.getPosition();
	// this->setPosition(thisposition.x - 17.5f, thisposition.y - 15.5f);
	
	//move(vfVelocitySense.x, vfVelocitySense.y, fElapsedTime);
	//sf::Vector2f thisposition = hitbox.getPosition();
	//this->setPosition(thisposition.x - 17.5f, thisposition.y - 15.5f);
}
void Player::draw(sf::RenderTarget *sfTarget) { // Draws our Entity
	sfTarget->draw(sfSprite);
}

void Player::setPlayerInput(const sf::Vector2f& velocity, const sf::Vector2i& last) {
	vfVelocitySense = velocity;
	viLastSense = last;
}

void Player::setVelocity(const float x, const float y) {
	vfVelocitySense.x = x;
	vfVelocitySense.y = y;
	bInCinematic = true;
}

sf::Vector2f Player::getVelocitySense() const {
	return vfVelocitySense;
}

sf::Vector2i Player::getLastSense() const {
	return viLastSense;
}

/*sf::Vector2f Player::GetHitboxPosition() {
	return hitbox.getPosition();
}*/