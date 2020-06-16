#pragma once

#include "Entity.h"

class Player : public Entity {
private:

public:
	Player(const float x, const float y, sf::Texture *sfTexture);
};