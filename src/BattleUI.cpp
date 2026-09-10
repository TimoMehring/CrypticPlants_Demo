#include "BattleUI.h"

BattleUI::BattleUI(){
    this->selectedWeapon = WeaponSelection::None;
    this->currentFrame = 0;
    this->frameTimer = 0.0f;

    this->noWeaponSelectedYet = LoadTexture("assets/BattleUI/choose_weapon_base.png");

    this->pistolSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_pistol_spritesheet.png");

    this->boomerangSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_boommerang_spritesheet.png");
}

void BattleUI::DrawWeaponSelection(){
    switch(this->selectedWeapon){
        case WeaponSelection::None:
            DrawTextureEx(this->noWeaponSelectedYet, {50.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            break;
        
        case WeaponSelection::Pistol:
            break;

        case WeaponSelection::Boommerang:
            break;

    }
}

void BattleUI::Unload(){
    UnloadTexture(this->noWeaponSelectedYet);
    UnloadTexture(this->pistolSelectedAnimation);
    UnloadTexture(this->boomerangSelectedAnimation);
}