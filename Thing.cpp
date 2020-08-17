#include "Thing.h"
Thing::Thing(std::string texture,float width, float height) {
	this->body = new sf::RectangleShape(sf::Vector2f(width,height));
	this->hitbox = new sf::RectangleShape(sf::Vector2f(35.0f, 35.0f));
	this->thingtexture = new sf::Texture;
	thingtexture->loadFromFile(texture);
	body->setTexture(thingtexture);
	//this->body->setScale(35.0f / 16.0f, 35.0f / (16.0f));
}
Thing::~Thing()
{
	delete body;
	delete thingtexture;
	delete hitbox;
}
void Thing::draw(sf::RenderTarget* window) {
	window->draw(*body);
}

void Thing::setPosition(const float x, const float y)
{
	this->body->setPosition(x, y);
	this->hitbox->setPosition(x+17.5f,y+15.0f);
}
void Thing::setHitboxposition(const int x, const int y)
{
	this->hitbox->setPosition(body->getPosition().x + (x * 35.0f) + 17.5, body->getPosition().y + (y * 35.0f) + 15.0f);
}
void Thing::setHitboxsize(const int width, const int height)
{
	this->hitbox->setSize(sf::Vector2f(35.0f*width,35.0f*height));
}
Collider Thing::GetCollider()
{
	this->hitbox->setOrigin(hitbox->getSize() / 2.0f);
	return Collider(*hitbox);
}