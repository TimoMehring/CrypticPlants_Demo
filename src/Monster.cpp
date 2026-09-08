#include "Monster.h"

Monster::Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritePath, const char* backSpritePath){
    this->name = name;

    this->range = range;
    this->speed = speed;
    this->health = health;
    this->resistance = resistance;
    this->attack = attack;

    frontSprite = LoadTexture(frontSpritePath);
    backSprite = LoadTexture(backSpritePath);
}

void Monster::DrawFront(Vector2 position, float scale){
    DrawTextureEx(this->frontSprite, position, 0.0f, scale, WHITE);
}

void Monster::DrawBack(Vector2 position, float scale){
    DrawTextureEx(this->backSprite, position, 0.0f, scale, WHITE);
}

void Monster::Unload(){
    UnloadTexture(this->frontSprite);
    UnloadTexture(this->backSprite);
}