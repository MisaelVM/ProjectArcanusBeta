#include "Entity.h"
// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
Entity::Entity() { // Entity's Constructor - Initializes the shape
	sfTexture = nullptr;
	animatorSystem = nullptr;
	fMovementSpeed = 100.0f;
	hitbox.setSize(sf::Vector2f(35.0f, 35.0f));
	hitbox.setOrigin(hitbox.getSize() / 2.0f);
}

Entity::~Entity() {
	delete animatorSystem;
}

// Constructor's functions
void Entity::constructSprite(sf::Texture* _sfTexture) { // Constructs the Sprite using the Texture
	sfTexture = _sfTexture;
}

void Entity::constructAnimatorSystem(sf::Texture& sfTextureSheet) {  // Constructs the Animator
	animatorSystem = new AnimatorSystem(sfSprite, sfTextureSheet);
}

//Transform
void Entity::setPosition(const float x, const float y) {
	sfSprite.setPosition(x, y);
	hitbox.setPosition(x+17.5f, y+15.5f);
}
void Entity::setRotation(const float angle) {
	sfSprite.setRotation(angle);
}

void Entity::setScale(const float x, const float y) {
	sfSprite.setScale(x, y);
}

// Functions
void Entity::move(const float towardsX, const float towardsY, const float& fElapsedTime) { // Moves our Entity
	sfSprite.move(towardsX * fElapsedTime, towardsY * fElapsedTime);
	hitbox.move(towardsX * fElapsedTime, towardsY * fElapsedTime);
}

// Main Functions
void Entity::draw(sf::RenderTarget* sfTarget) { // Draws our Entity
	
	sfTarget->draw(hitbox);
	sfTarget->draw(sfSprite);
}
sf::Vector2f Entity::GetPosition() {
	return sfSprite.getPosition();
}