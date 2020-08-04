#include "Boton.h"
Boton::Boton(std::string identidad, std::string font, float width, float height)
{
	this->button = new sf::RectangleShape(sf::Vector2f(width, height));
	this->font = new sf::Font;
	this->font->loadFromFile("Resources/Fonts/"+font);
	this->txt = new sf::Text(identidad, *this->font);
}
Boton::~Boton() 
{
	delete button;
}
void Boton::setBotonPosition(float x, float y) 
{
	this->button->setPosition(x, y);
	this->txt->setPosition(x, y);
}
void Boton::setTextSize(int s)
{
	this->txt->setCharacterSize(s);
}
sf::RectangleShape* Boton::getRectangle()
{
	return this->button;
}
bool Boton::GetClick(const int pos_mousex, const int pos_mousey, sf::View& camera)
{
	return button->getGlobalBounds().contains(pos_mousex + camera.getCenter().x - 400.0f, pos_mousey + camera.getCenter().y - 300.0f);
}
void Boton::draw(sf::RenderWindow& window)
{
	window.draw(*button);
	window.draw(*txt);
}