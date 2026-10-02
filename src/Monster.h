#pragma once
#include "raylib.h"
#include <string>
#include <vector>

struct WeakPoints{
    Texture2D sprite;
    float currentHealth;
    float maxHealth;
};

struct WeakPointData{
    const char* spritePath;
    float maxHealth;
};

struct MonsterData{
    std::string name;

    float range;
    float speed;
    float health;
    float resistance;
    float attack;

    const char* frontSpritePath;
    const char* backSpritePath;

    std::vector<WeakPointData> weakPointData;
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

    std::vector<WeakPoints> weakPoints;
    Vector2 targetArrowPosition;

    public:
    Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritePath, const char* backSpritePath, const std::vector<WeakPointData>& weakPointData,const Vector2& targetArrowPosition);

    // Drawing
    void DrawFront(Vector2 position, float scale);
    //void DrawBack(Vector2 position, float scale);

    const std::vector<WeakPoints>& GetWeakPoints() const;
    const Vector2& GetTargetArrowPosition() const;

    float GetRange() const;
    float GetSpeed() const;
    float GetWeakPointHealth(int index) const;
    void DamageWeakPoint(int index, float damage);

    void Unload();
};