#pragma once
#include "raylib.h"
#include <string>
#include <vector>

struct MonsterData{
    std::string name;

    float range;
    float speed;
    float health;
    float resistance;
    float attack;

    const char* frontSpritePath;
    const char* backSpritePath;

    std::vector<const char*> weakPointSpritePaths;
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

    std::vector<Texture2D> weakPointSprites;

    public:
    Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritePath, const char* backSpritePath, const std::vector<const char*>& weakPointSpritePaths);

    // Drawing
    void DrawFront(Vector2 position, float scale);
    //void DrawBack(Vector2 position, float scale);

    void Unload();
};