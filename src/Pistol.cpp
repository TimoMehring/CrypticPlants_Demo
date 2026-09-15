#include "Pistol.h"

Pistol::Pistol(){
    this->range = 300.0f;
    this->speed = 300.0f;
    this->energy = 100.0f;
    this->attack = 100.0f;

    LoadAbilities();
}

void Pistol::LoadAbilities(){
    this->abilities.push_back({"Ability1", "assets/Abilities/Icon01.png", "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt ut labore et\n dolore magna aliqua. Ut enim ad minim veniam, quis .", 0.0f, 0.0f});
    this->abilities.push_back({"Ability2", "assets/Abilities/Icon02.png", "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt ut labore et\n dolore magna aliqua. Ut enim ad minim veniam, quis .", 0.0f, 0.0f});
    this->abilities.push_back({"Ability3", "assets/Abilities/Icon03.png", "Lorem ipsum dolor sit amet, consectetur adipiscing\n elit, sed do eiusmod tempor incididunt ut labore et\n dolore magna aliqua. Ut enim ad minim veniam, quis .", 0.0f, 0.0f});
}

const std::vector<PistolAbility>& Pistol::GetAbilities(){
    return this->abilities;
}