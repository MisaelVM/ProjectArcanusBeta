#include "GameEngine.h"

Player *Player::player_instance = nullptr;

int main()
{
    GameEngine ArcanusBeta;
    ArcanusBeta.start();
    return 0;
}