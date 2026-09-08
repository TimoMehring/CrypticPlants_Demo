#pragma once
#include "raylib.h"
#include <string>

struct MonsterData{
    std::string name;

    float range;
    float speed;
    float health;
    float resistance;
    float attack;

    const char* frontSpritePath;
    const char* backSpritePath;
};

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
    // Constructor
    Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritePath, const char* backSpritePath);

    // Drawing
    void DrawFront(Vector2 position, float scale);
    void DrawBack(Vector2 position, float scale);

    void Unload();
};