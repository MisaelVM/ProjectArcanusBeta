#pragma once
#include<SFML/Graphics.hpp>
#include "Collider.h"
class Thing
{
private:
	sf::RectangleShape* body;
	sf::RectangleShape* hitbox;
	sf::Texture* thingtexture;
public:
	Thing(std::string texture, float width, float height);
	~Thing();
	void setPosition(const float x, const float y);
	void setHitboxposition(const int x, const int y);
	void setHitboxsize(const int width, const int height);
	void draw(sf::RenderTarget* window);
	Collider GetCollider();
};

