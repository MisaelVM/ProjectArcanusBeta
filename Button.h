#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
class Button
{
private:
	sf::RectangleShape* button;
	sf::Font* font;
	sf::Text* txt;
public:
	Button(std::string identidad, std::string font, float width, float height);
	~Button();

	void setButtonPosition(float x, float y);
	void setTextSize(int s);
	void setTextColor(sf::Color color);
	sf::RectangleShape* getRectangle();
	std::string getText() const;
	bool GetClick(const int pos_mousex, const int pos_mousey, sf::View& camera);
	void draw(sf::RenderTarget* window);
};