#include "Entity.h"

// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
Entity::Entity() { // Class' Constructor - Initializes the shape
	sfShape.setSize(sf::Vector2f(50.f, 50.f));
	sfShape.setFillColor(sf::Color::Blue);
}

Entity::~Entity() {
	// DESTRUCTOR
}

void Entity::update(const float &fElapsedTime) {
	// Updates our Entity's data
}

void Entity::draw(sf::RenderTarget *sfTarget) { // Draws our Entity
	sfTarget->draw(sfShape);
}
