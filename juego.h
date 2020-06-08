#pragma once
#include<SFML/Graphics.hpp> 
#include<iostream>
#include<sstream>
#include<fstream>
#include"TileMap.h"
#include"Events.h"

class juego
{
private:
	sf::RenderWindow *window;
	TileMap* Map;
	sf::Clock sfElapsedTimeClock;
	float fElapsedTime;
	sf::View camera;	
	const float cameraspeed = 6.0f; //velocidad con la que la camara se desplaza
public:	
	juego(int width, int high, std::string title);
	void gameloop();
	void draw();
	void updateElapsedTime();
	void checkcamera();//funcion que tiene que ver con la camera
	
};

