#include "TileMap.h"
TileMap::TileMap(int rows, int columns, std::string archive)
{
	//Leer un archivo
	char aux; //esto me servira para leer el archivo para poder sacar los char del archivo
	FILE** TilemapArchive; //Doble puntero porque VS no me deja abrirlo si no es con la funcion fopen_s(abrir de forma segura) que recibe como argumento un puntero a puntero
	TilemapArchive = new  FILE*;
	fopen_s(TilemapArchive, "Tilemap1.txt", "r");
	if (TilemapArchive == NULL)
	{
		std::cout << "Archivo no encontrado";
		exit(1);
	}
	this->rows = rows;
	this->columns = columns;
	image = new sf::Texture;
	image->loadFromFile(archive);
	Tile = new sf::Sprite;
	Mtile = new char* [this->rows];
	for (int i = 0;i < this->rows;i++)
	{
		Mtile[i] = new char[this->columns];
	}
	for (int i = 0;i < this->rows;i++)
	{
		for (int j = 0;j < this->columns;j++)
		{
			aux = fgetc(*TilemapArchive);
			if ( aux!=' ' && aux!='\n')
				Mtile[i][j] = aux;
			else
				Mtile[i][j]=fgetc(*TilemapArchive);
		}
	}
	fclose(*TilemapArchive);
	//Iniciando el arreglo de tiles, ponerlo en orden y con su respectiva letra, el map se ordena por orden alfabetico
	ArrayTile["a_roca"];
	ArrayTile["b_piedra"];
	ArrayTile["c_tierra"];
	ArrayTile["d_pasto"];
	ArrayTile["e_madera"];
	ArrayTile["f_lozas"];
	ArrayTile["g_loza"];
	ArrayTile["h_ladrillos"];
	ArrayTile["i_tnt"];
	ArrayTile["j_tnt1"];
	ArrayTile["k_tnt2"];
	ArrayTile["l_telaraña"];
	ArrayTile["m_florroja"];
	ArrayTile["n_floramarilla"];
	ArrayTile["p_cielo"];
	std::map<std::string, sf::Sprite>::iterator i; //Se declara "i" como iterador de nuestro map
	int f=0, c=0;
	for (i = ArrayTile.begin();i != ArrayTile.end();i++) 
	{
		i->second.setTexture(*image);
		i->second.setTextureRect(sf::IntRect(f*40,c*40,40,40)); //Los numeros dependeran de cuantos pixeles ocupa su textura en la imagen y de igual modo el escalado
		i->second.setScale(0.75f, 0.75f);
		f++;
		if (f == 15) //Este numero 15 ya depende de cuantas texturas hay en la fila de su imagen que contiene las texturas
		{
			c++;
			f = 0;
		}
	}
}
TileMap::TileMap() {
	rows = 0;
	columns = 0;
	image = new sf::Texture;
	image->loadFromFile("Texturadefault.jpg");
	Tile = new sf::Sprite;
	Mtile = new char* [1];
	for (int i = 0;i < 1;i++)
	{
		Mtile[i] = new char[1];
	}
}
sf::Sprite TileMap::GetTile(int row,int column) 
{
	switch (*(*(Mtile+row)+column)) 
	{
		case 'a':
			*Tile = ArrayTile["a_roca"];
			Tile->setPosition(30 * column, 30 * row);
			break;
		case 'b':
			*Tile = ArrayTile["b_piedra"];
			Tile->setPosition(30 * column, 30 * row);
			break;
		case 'c':
			*Tile = ArrayTile["c_tierra"];
			Tile->setPosition(30 * column, 30 * row);
			break;
		case 'd':
			*Tile = ArrayTile["d_pasto"];
			Tile->setPosition(30 * column, 30 * row);
			break;
		case 'p':
			*Tile = ArrayTile["p_cielo"];
			Tile->setPosition(30 * column, 30 * row);
			break;
	}
	return *Tile;
}
void TileMap::Displaytilemap(sf::RenderWindow *window) 
{
	for (int i = 0;i < rows;i++)
	{
		for (int j = 0;j < columns;j++)
		{
			window->draw(this->GetTile(i, j));
		}
	}
}