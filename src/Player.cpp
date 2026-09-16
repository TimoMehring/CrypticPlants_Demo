#include "Player.h"

Player::Player(){
    this->currentHealth = 100.0f;
    this->maxHealth = 100.0f;
    this->currentLevel = 1;
    this->currentXp = 0.0f;
    this->maxXP = 1000.0f;
    this->currentWeapon = WeaponType::None;
}

float Player::GetCurrentHealth() const{
    return this->currentHealth;
}

float Player::GetMaxHealth() const{
    return this->maxHealth;
}

float Player::GetLevel() const{
    return this->currentLevel;
}

float Player::GetCurrentXp() const{
    return this->currentXp;
}

float Player::GetMaxXP() const{
    return this->maxXP;
}