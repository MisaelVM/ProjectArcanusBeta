#pragma once

#include "Entity.h"

class Player : public Entity {
private:

public:
	Player(float x, float y, sf::Texture *sfTexture);
};