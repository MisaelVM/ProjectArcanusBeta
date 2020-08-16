#include "Entity.h"

// -- CONSTRUCTOR/DESTRUCTOR'S DEFINITIONS --
Entity::Entity() { // Entity's Constructor - Initializes the shape
	sfTexture = nullptr;
	animatorSystem = nullptr;
	fMovementSpeed = 100.0f;
	// hitbox.setSize(sf::Vector2f(35.0f, 35.0f));
	// hitbox.setOrigin(hitbox.getSize() / 2.0f);
}

// Constructor's functions
void Entity::constructSprite(sf::Texture *_sfTexture) { // Constructs the Sprite using the Texture
	sfTexture = _sfTexture;
}

void Entity::constructAnimatorSystem(sf::Texture &sfTextureSheet) {  // Constructs the Animator
	animatorSystem = std::make_unique<AnimatorSystem>(sfSprite, sfTextureSheet);
}

//Transform
void Entity::setPosition(const float x, const float y) {
	sfSprite.setPosition(x, y);
	// hitbox.setPosition(x+17.5f, y+15.5f);
	hitbox.setPosition(x + 8.f, y);
}
void Entity::setRotation(const float angle) {
	sfSprite.setRotation(angle);
}

void Entity::setScale(const float x, const float y) {
	sfSprite.setScale(x, y);
}

sf::Vector2f Entity::getPosition() const {
	return sfSprite.getPosition();
}

float Entity::getRotation() const {
	return sfSprite.getRotation();
}

sf::Vector2f Entity::getScale() const {
	return sfSprite.getScale();
}

sf::Vector2f Entity::getHitboxPosition() const {
	return hitbox.getPosition();
}

// Functions
float Entity::getMovementSpeed() const {
	return fMovementSpeed;
}

void Entity::move(const float towardsX, const float towardsY, const float &fElapsedTime) { // Moves our Entity
	sfSprite.move(towardsX * fElapsedTime, towardsY * fElapsedTime);
	hitbox.move(towardsX * fElapsedTime, towardsY * fElapsedTime);
}

// Main Functions
void Entity::draw(sf::RenderTarget *sfTarget) { // Draws our Entity
	// sfTarget->draw(hitbox);
	sfTarget->draw(sfSprite);
}

/*sf::Vector2f Entity::GetPosition() {
	return sfSprite.getPosition();
}*/