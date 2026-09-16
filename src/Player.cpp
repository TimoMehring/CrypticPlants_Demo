#include "Player.h"

Player::Player(){
    this->currentHealth = 100.0f;
    this->maxHealth = 100.0f;
    this->currentWeapon = WeaponType::None;
}

float Player::GetCurrentHealth() const{
    return this->currentHealth;
}

float Player::GetMaxHealth() const{
    return this->maxHealth;
}