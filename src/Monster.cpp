#include "Monster.h"

Monster::Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritePath, const char* backSpritePath, const std::vector<WeakPointData>& weakPointData,const Vector2& targetArrowPosition){
    this->name = name;

    this->range = range;
    this->speed = speed;
    this->health = health;
    this->resistance = resistance;
    this->attack = attack;
    
    frontSprite = LoadTexture(frontSpritePath);
    backSprite = LoadTexture(backSpritePath);
    
    for(const WeakPointData& data : weakPointData){
        WeakPoints weakPoint;

        weakPoint.sprite = LoadTexture(data.spritePath);
        weakPoint.maxHealth = data.maxHealth;
        weakPoint.currentHealth = data.maxHealth;
        this->weakPoints.push_back(weakPoint);
    }
    this->targetArrowPosition = targetArrowPosition;
}

void Monster::DrawFront(Vector2 position, float scale){
    DrawTextureEx(this->frontSprite, position, 0.0f, scale, WHITE);
}

const std::vector<WeakPoints>& Monster::GetWeakPoints() const{
    return this->weakPoints;
}

const Vector2& Monster::GetTargetArrowPosition() const{
    return this->targetArrowPosition;
}

float Monster::GetRange() const{
    return this->range;
}

float Monster::GetSpeed() const{
    return this->speed;
}

void Monster::Unload(){
    UnloadTexture(this->frontSprite);
    UnloadTexture(this->backSprite);
    
    for(WeakPoints& weakPoint : this->weakPoints){
        UnloadTexture(weakPoint.sprite);
    }
}