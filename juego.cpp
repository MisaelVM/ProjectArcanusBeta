#include "juego.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include<fstream>
#include"TileMap.h"

juego::juego(int width, int high, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, high), title);
	Map = new TileMap(20, 26, "TEXTURAS.jpg"); //El string pasado es la imagen con todas las texturas
	camera = sf::View(sf::FloatRect(0, 0, 800, 600)); //Instancia de la camara
	gameloop();
}
void juego::gameloop() 
{
	sf::Event sfEvent;
	while (window->isOpen())
	{
		updateElapsedTime();
		//Todo dentro del while deberia ir en una clase EVENTOS
		while (window->pollEvent(sfEvent)) { // Handles SFML's events
			if (sfEvent.type == sf::Event::Closed)
				window->close();
			if (sfEvent.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
				{

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
				{

				}
			}
			if (sfEvent.type == sf::Event::MouseWheelMoved)
			{
				camera.zoom(1.f+sfEvent.mouseWheel.delta* 0.1f);
			}
			
		}
		checkcamera();
		draw();
	}
}
void juego::draw()
{
	window->clear();
	Map->Displaytilemap(window);
	window->setView(camera);
	window->display();
}
void juego::updateElapsedTime() 
{
	fElapsedTime = sfElapsedTimeClock.restart().asSeconds();  
	system("cls");
	std::cout << fElapsedTime << "---" << 1 / fElapsedTime << "FPS/n";   //Esta parte muestra como van los fps
}
void juego::checkcamera() //Los movimientos de la camara, cambiar mouse getposition por player getposition
{
	if (window->hasFocus())
	{
		if (sf::Mouse::getPosition(*window).x < window->getSize().x && sf::Mouse::getPosition(*window).x >(window->getSize().x - 15))
		{
			camera.move(cameraspeed,0);
		}
		else if (sf::Mouse::getPosition(*window).x > 0 && sf::Mouse::getPosition(*window).x < 15)
		{
			camera.move(-cameraspeed, 0);
		}
		if (sf::Mouse::getPosition(*window).y < window->getSize().y && sf::Mouse::getPosition(*window).y >(window->getSize().y - 15))
		{
			camera.move(0, cameraspeed);
		}
		else if (sf::Mouse::getPosition(*window).y > 0 && sf::Mouse::getPosition(*window).y < 15)
		{
			camera.move(0, -cameraspeed);
		}

	}
}
