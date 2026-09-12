#include "Boomerang.h"

Boomerang::Boomerang(){
    this->range = 75.0f;
    this->speed = 75.0f;
    this->energy = 100.0f;
    this->attack = 100.0f;
}

void Boomerang::LoadAbilities(){
    this->abilities.push_back({"Ability1", "assets/Abilities/Icon01.png", 0.0f, 0.0f});
    this->abilities.push_back({"Ability2", "assets/Abilities/Icon02.png", 0.0f, 0.0f});
    this->abilities.push_back({"Ability3", "assets/Abilities/Icon03.png", 0.0f, 0.0f});
}

const std::vector<BoomerangAbility>& Boomerang::GetAbilities(){
    return this->abilities;
}