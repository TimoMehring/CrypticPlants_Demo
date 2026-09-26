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
    Vector2 targetArrowPosition;
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
    Vector2 targetArrowPosition;

    public:
    Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritePath, const char* backSpritePath, const std::vector<const char*>& weakPointSpritePaths,const Vector2& targetArrowPosition);

    // Drawing
    void DrawFront(Vector2 position, float scale);
    //void DrawBack(Vector2 position, float scale);

    const std::vector<Texture2D>& GetWeakPointSprites() const;
    const Vector2& GetTargetArrowPosition() const;

    void Unload();
};