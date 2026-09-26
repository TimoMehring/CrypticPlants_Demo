#include "Monster.h"

Monster::Monster(const std::string& name, float range, float speed, float health, float resistance, float attack, const char* frontSpritePath, const char* backSpritePath, const std::vector<const char*>& weakPointSpritePaths,const Vector2& targetArrowPosition){
    this->name = name;

    this->range = range;
    this->speed = speed;
    this->health = health;
    this->resistance = resistance;
    this->attack = attack;
    
    frontSprite = LoadTexture(frontSpritePath);
    backSprite = LoadTexture(backSpritePath);

    for(const char* path : weakPointSpritePaths){
        this->weakPointSprites.push_back(LoadTexture(path));
    }
    this->targetArrowPosition = targetArrowPosition;
}

void Monster::DrawFront(Vector2 position, float scale){
    DrawTextureEx(this->frontSprite, position, 0.0f, scale, WHITE);
}

const std::vector<Texture2D>& Monster::GetWeakPointSprites() const{
    return this->weakPointSprites;
}

const Vector2& Monster::GetTargetArrowPosition() const{
    return this->targetArrowPosition;
}


void Monster::Unload(){
    UnloadTexture(this->frontSprite);
    UnloadTexture(this->backSprite);

    for(Texture2D& weakPointSprite : this->weakPointSprites){
        UnloadTexture(weakPointSprite);
    }
}