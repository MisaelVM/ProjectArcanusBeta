#include "Entity.h"

// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
Entity::Entity() { // Class' Constructor - Initializes the shape
	sfShape.setSize(sf::Vector2f(50.f, 50.f));
	sfShape.setFillColor(sf::Color::Blue);

	fMovementSpeed = 100.f;
}

Entity::~Entity() {
	// DESTRUCTOR
}

void Entity::move(const int towardsX, const int towardsY, const float &fElapsedTime) { // Moves our Entity
	sfShape.move(towardsX * fMovementSpeed * fElapsedTime, towardsY * fMovementSpeed * fElapsedTime); /* REMINDER: Use a sf::Vector2f with this function instead of this way */
}

void Entity::update(const float &fElapsedTime) {
	// Checks what keys are being pressed so it can move our Entity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move(-1, 0, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move(1, 0, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move(0, -1, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move(0, 1, fElapsedTime);
}

void Entity::draw(sf::RenderTarget *sfTarget) { // Draws our Entity
	sfTarget->draw(sfShape);
}
