#include "Entity.h"

// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
Entity::Entity() { // Entity's Constructor - Initializes the shape
	sfTexture = nullptr;
	animatorSystem = nullptr;
	fMovementSpeed = 100.f;
}

Entity::~Entity() {
	delete animatorSystem;
}

// Constructor's functions
void Entity::constructSprite(sf::Texture *_sfTexture) { // Constructs the Sprite using the Texture
	sfTexture = _sfTexture;
}

void Entity::constructAnimatorSystem(sf::Texture &sfTextureSheet) {  // Constructs the Animator
	animatorSystem = new AnimatorSystem(sfSprite, sfTextureSheet);
}

// Transform
void Entity::setPosition(const float x, const float y) {
	sfSprite.setPosition(x, y);
}

void Entity::setRotation(const float angle) {
	sfSprite.setRotation(angle);
}

void Entity::setScale(const float x, const float y) {
	sfSprite.setScale(x, y);
}

// Functions
void Entity::move(const float towardsX, const float towardsY, const float &fElapsedTime) { // Moves our Entity
	sfSprite.move(towardsX * fElapsedTime, towardsY * fElapsedTime);
}