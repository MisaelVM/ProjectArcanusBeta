#pragma once
#include<iostream>
#include<iostream>
#include<fstream>
#include<sstream>
#include<SFML/Graphics.hpp>
#include<stdio.h>
#include<string.h>
#include<map>
class TileMap
{
private:
	//Esta parte tiene que ver con todo lo que es propio del SFML los sprites y texturas y un mapa de estas
	std::map<std::string, sf::Sprite> ArrayTile;
	sf::Texture *image;
	sf::Sprite* Tile;
	//Esta parte sera la Matriz de chars para interpretar el notepad
	char** Mtile;
	int rows;
	int columns;
public:
	TileMap();
	TileMap(int rows, int columns, std::string archive);
	void Displaytilemap(sf::RenderWindow *window);
	sf::Sprite GetTile(int rows,int columns);
};

