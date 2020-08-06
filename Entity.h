#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "AnimatorSystem.h"
// #include "Collider.h"

class Entity {
private:

protected:
	sf::Texture* sfTexture; // Image that will be mapped to a 2D Entity
	sf::Sprite sfSprite; // Texturized Entity
	sf::RectangleShape hitbox;
	AnimatorSystem* animatorSystem; // Entity's Animator

	// Variables
	float fMovementSpeed;

	bool bInCinematic;

	// Constructor's functions
	void constructSprite(sf::Texture* _sfTexture); // Constructs the Sprite using the Texture
	void constructAnimatorSystem(sf::Texture& sfTextureSheet); // Constructs the Animator

public:
	// -- CONSTRUCTOR/DESTRUCTOR --
	Entity();
	virtual ~Entity();

	//Transform
	virtual void setPosition(const float x, const float y);
	virtual void setRotation(const float angle);
	virtual void setScale(const float x, const float y);

	virtual sf::Vector2f getPosition() const;
	virtual float getRotation() const;
	virtual sf::Vector2f getScale() const;

	virtual sf::Vector2f getHitboxPosition() const;

	// Functions
	float getMovementSpeed() const;

	virtual void move(const float towardsX, const float towardsY, const float& fElapsedTime); // Moves our Entity
	virtual void setVelocity(const float x, const float y) = 0;

	// Main Functions
	virtual void update(const float& fElapsedTime) = 0; // Updates our Entity's data
	virtual void draw(sf::RenderTarget* sfTarget) = 0; // Draws our Entity

	// sf::Vector2f GetPosition();
	// Collider GetCollider() {return Collider(hitbox);}
};