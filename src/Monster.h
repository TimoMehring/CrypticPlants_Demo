#pragma once
#include "raylib.h"
#include <string>

class Monster{
    private:
    
    std::string name;
    Texture2D frontSprite;
    Texture2D backSprite;

    // Stats
    float range;
    float speed;
    float health;
    float resistance;
    float attack;

    public:

    Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritepath, const char* backSpritePath);

    // Drawing
    void DrawFront(Vector2 position);
    void DrawBack(Vector2 position);

    void Unload();
};