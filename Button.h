#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
class Button
{
private:
	std::shared_ptr<sf::RectangleShape> button;
	std::unique_ptr<sf::Font> font;
	std::unique_ptr<sf::Text> txt;
public:
	Button(std::string identidad, std::string font, float width, float height);

	void setButtonPosition(float x, float y);
	void setTextSize(int s);
	void setTextColor(sf::Color color);
	std::shared_ptr<sf::RectangleShape> getRectangle();
	std::string getText() const;
	bool GetClick(const int pos_mousex, const int pos_mousey, sf::View& camera);
	void draw(sf::RenderTarget* window);
};