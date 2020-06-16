#include "Entity.h"

// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
Entity::Entity() { // Entity's Constructor - Initializes the shape
	sfShape.setSize(sf::Vector2f(50.f, 50.f));
	sfShape.setFillColor(sf::Color::Blue);
	sfTexture = nullptr;
	sfSprite = nullptr;

	fMovementSpeed = 100.f;
}

Entity::~Entity() {
	delete sfTexture;
	delete sfSprite;
}

// Constructor's functions
void Entity::constructSprite(sf::Texture *sfTexture) { // Constructs the Sprite using the Texture
	this->sfTexture = sfTexture;
	sfSprite = new sf::Sprite(*this->sfTexture);
}

// Functions
void Entity::setPosition(const float x, const float y) {
	sfSprite->setPosition(x, y);
}

void Entity::move(const int towardsX, const int towardsY, const float &fElapsedTime) { // Moves our Entity
	sfShape.move(towardsX * fMovementSpeed * fElapsedTime, towardsY * fMovementSpeed * fElapsedTime); /* REMINDER: Use a sf::Vector2f with this function instead of this way */
}

// Main Functions
void Entity::update(const float &fElapsedTime) {
	// Checks what keys are being pressed so it can move our Entity
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move(-1, 0, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move(1, 0, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move(0, -1, fElapsedTime);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move(0, 1, fElapsedTime);
}

void Entity::draw(sf::RenderTarget *sfTarget) { // Draws our Entity
	sfTarget->draw(*sfSprite);
}