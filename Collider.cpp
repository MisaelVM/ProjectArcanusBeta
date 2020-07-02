#include "Collider.h"
Collider::Collider(sf::RectangleShape& body):body(body) {

}
Collider::~Collider() {

}

bool Collider::Checkcollision(Collider &other, float state) {
	sf::Vector2f otherposition = other.GetPosition();
	sf::Vector2f otherhalfsize = other.GetHalfSize();
	sf::Vector2f thisposition = GetPosition();
	sf::Vector2f thishalfsize = GetHalfSize();
	
	float deltaX = otherposition.x - thisposition.x;
	float deltaY = otherposition.y - thisposition.y;

	float intersectX = abs(deltaX) - (otherhalfsize.x + thishalfsize.x);
	float intersectY = abs(deltaY) - (otherhalfsize.y + thishalfsize.y);
	if (intersectX < 0.0f && intersectY < 0.0f) {
		state = std::min(std::max(state, 0.0f), 1.0f);
		if (abs(intersectX) < abs(intersectY)) {
			if (deltaX > 0.0f){
				Move(intersectX * (1.0f - state), 0.0f);
				other.Move(-intersectX * state, 0.0f);
			}
			else {
				Move(-intersectX * (1.0f - state), 0.0f);
				other.Move(intersectX * state, 0.0f);
			}
		}
		else {
			if (deltaY > 0.0f) {
				Move(0.0f,intersectY * (1.0f - state));
				other.Move(0.0f ,-intersectY * state);
			}
			else {
				Move(0.0f ,-intersectY * (1.0f - state));
				other.Move(0.0f,intersectY * state);
			}
		}
		return true;
	}
	return false;
}
