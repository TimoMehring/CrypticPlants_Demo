#include "Pistol.h"

Pistol::Pistol(){
    this->range = 300.0f;
    this->speed = 300.0f;
    this->energy = 100.0f;
    this->attack = 100.0f;

    LoadAbilities();
    LoadAbilityBackSprites();
}

void Pistol::LoadAbilities(){
    this->abilities.push_back({"Ability1", "assets/Abilities/Icon01.png", "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt ut labore et\n dolore magna aliqua. Ut enim ad minim veniam, quis .", 0.0f, 0.0f});
    this->abilities.push_back({"Ability2", "assets/Abilities/Icon02.png", "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt ut labore et\n dolore magna aliqua. Ut enim ad minim veniam, quis .", 0.0f, 0.0f});
    this->abilities.push_back({"Ability3", "assets/Abilities/Icon03.png", "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt ut labore et\n dolore magna aliqua. Ut enim ad minim veniam, quis .", 0.0f, 0.0f});
}

void Pistol::LoadAbilityBackSprites(){
    this->abilityBackSprites.push_back(LoadTexture("assets/Abilities/icon01_backsprite.png"));
    this->abilityBackSprites.push_back(LoadTexture("assets/Abilities/icon02_backsprite.png"));
    this->abilityBackSprites.push_back(LoadTexture("assets/Abilities/icon03_backsprite.png"));
}

const std::vector<PistolAbility>& Pistol::GetAbilities(){
    return this->abilities;
}

const std::vector<Texture2D>& Pistol::GetAbilityBackSprite(){
    return this->abilityBackSprites;
}

void Pistol::Unload(){
    for(Texture2D texture : this->abilityBackSprites){
        UnloadTexture(texture);
    }
}