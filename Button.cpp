#include "Button.h"
Button::Button(std::string identidad, std::string font, float width, float height)
{
	this->button = std::make_shared<sf::RectangleShape>(sf::Vector2f(width, height));
	this->font = std::make_unique<sf::Font>();
	this->font->loadFromFile("Resources/Fonts/" + font);
	this->txt = std::make_unique<sf::Text>(identidad, *this->font);
}
void Button::setButtonPosition(float x, float y)
{
	this->button->setPosition(x, y);
	this->txt->setPosition(x, y);
}
void Button::setTextSize(int s)
{
	this->txt->setCharacterSize(s);
}
void Button::setTextColor(sf::Color color)
{
	this->txt->setFillColor(color);
}
std::shared_ptr<sf::RectangleShape> Button::getRectangle()
{
	return this->button;
}
std::string Button::getText() const
{
	return txt->getString();
}
bool Button::GetClick(const int pos_mousex, const int pos_mousey, sf::View& camera)
{
	return button->getGlobalBounds().contains(pos_mousex + camera.getCenter().x - 400.0f, pos_mousey + camera.getCenter().y - 300.0f);
}
void Button::draw(sf::RenderTarget* window)
{
	window->draw(*button);
	window->draw(*txt);
}