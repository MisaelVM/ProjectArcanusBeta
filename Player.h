#pragma once

#include "Entity.h"

class Player : public Entity {
private:
	sf::Vector2f vfVelocitySense;
	sf::Vector2i viLastSense;

	bool input[4];

	// -- CONSTRUCTOR -- SINGLETON PATTERN --
	Player() {};

	// -- INSTANCE -- SINGLETON PATTERN --
	static Player* player_instance;

public:
	// -- INSTANCE GETTER -- SINGLETON PATTERN --
	static Player* getInstance();

	static void deleteInstance();

	// -- DELETED COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR -- SINGLETON PATTERN --
	Player(const Player& o) = delete;
	Player& operator = (const Player& o) = delete;

	// Functions
	void refresh(const float x, const float y, sf::Texture& sfTexture);

	void setPlayerInput(const sf::Vector2f& velocity, const sf::Vector2i& last);
	void setVelocity(const float x, const float y);

	sf::Vector2f getVelocitySense() const;
	sf::Vector2i getLastSense() const;

	// Main functions
	void update(const float& fElapsedTime);
	void draw(sf::RenderTarget* sfTarget);

	// sf::Vector2f GetHitboxPosition();
};