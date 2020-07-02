#pragma once
#include <SFML/Graphics.hpp>
class Collider
{
private:
	sf::RectangleShape& body; 
public:
	Collider(sf::RectangleShape& body);
	~Collider();

	void Move(float dx, float dy) { 
		body.move(dx, dy); 
	}

	bool Checkcollision(Collider &other, float state);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }
};

