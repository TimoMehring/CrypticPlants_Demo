#include "Monster.h"

Monster::Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritepath, const char* backSpritePath){
    this->name = name;

    this->range = range;
    this->speed = speed;
    this->health = health;
    this->resistance = resistance;
    this->attack = attack;

    frontSprite = LoadTexture(frontSpritepath);
    backSprite = LoadTexture(backSpritePath);
}