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

// Functions
void Entity::setPosition(const float x, const float y) {
	sfSprite.setPosition(x, y);
}

void Entity::move(const int towardsX, const int towardsY, const float &fElapsedTime) { // Moves our Entity
	sfSprite.move(towardsX * fMovementSpeed * fElapsedTime, towardsY * fMovementSpeed * fElapsedTime); /* REMINDER: Use a sf::Vector2f with this function instead of this way */
}

// Main Functions
void Entity::draw(sf::RenderTarget *sfTarget) { // Draws our Entity
	sfTarget->draw(sfSprite);
}