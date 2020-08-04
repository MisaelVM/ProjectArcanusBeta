#pragma once
#include "SFML/Graphics.hpp"
#include<iostream>
class Boton
{
private:
	sf::RectangleShape* button;
	sf::Font* font;
	sf::Text* txt;
public:
	Boton(std::string identidad,std::string font, float width, float height);
	~Boton();
	void setBotonPosition(float x, float y);
	void setTextSize(int s);
	sf::RectangleShape* getRectangle();
	bool GetClick(const int pos_mousex,const int pos_mousey,sf::View& camera);
	void draw(sf::RenderWindow& window);
};

