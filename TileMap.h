#pragma once

#include<iostream>
#include<fstream>
#include<sstream>

#include<SFML/Graphics.hpp>

#include<stdio.h>
#include<string.h>
#include<map>

// #include "Collider.h"
#include "Player.h"

class TileMap {
private:
	//Esta parte tiene que ver con todo lo que es propio del SFML los sprites y texturas y un mapa de estas
	std::map<std::string, sf::Sprite> ArrayTile;
	sf::Texture *image;
	sf::Sprite *Tile;
	// sf::RectangleShape *hitbox;
	//Esta parte sera la Matriz de chars para interpretar el notepad
	char **Mtile;
	int rows;
	int columns;
	float sizeoftile;
public:
	// -- CONSTRUCTORS/DESTRUCTOR --
	TileMap();
	TileMap(int rows, int columns, std::string archive, const char *tilemapArchive);
	virtual ~TileMap();

	void Displaytilemap(sf::RenderWindow *window, sf::Vector2f viewposition);

	sf::Sprite GetTile(int rows, int columns);
	char GetChar(int rows, int colums);

	/*sf::RectangleShape GetCaja(sf::Vector2f hitboxposition);
	Collider GetCollider(sf::Vector2f playerposition) {
		sf::RectangleShape caja = this->GetCaja(playerposition);
		return Collider(*hitbox);
	}*/
};