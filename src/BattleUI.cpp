#include "BattleUI.h"

BattleUI::BattleUI(){
    this->selectedWeapon = WeaponSelection::Boommerang;
    this->currentFrame = 0;
    this->frameTimer = 0.0f;

    this->noWeaponSelectedYet = LoadTexture("assets/BattleUI/choose_weapon_base.png");

    this->pistolSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_pistol_spritesheet.png");

    this->boomerangSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_boomerang_spritesheet.png");
}

void BattleUI::UpdateWeaponSelection(){
    float scale = 5.0f;
    float halfWidth = static_cast<float>(noWeaponSelectedYet.width) / 2.0f;
    Rectangle clickPistol = {50.0f, 600.0f, halfWidth*scale, static_cast<float>(noWeaponSelectedYet.height)*scale};
    Rectangle clickBoomerang = {50.0f + halfWidth*scale, 600.0f, halfWidth*scale, static_cast<float>(noWeaponSelectedYet.height)*scale};
    if(this->selectedWeapon == WeaponSelection::Pistol || this->selectedWeapon == WeaponSelection::Boommerang){
        this->frameTimer += GetFrameTime();

        if(this->frameTimer >= 0.4f){
            this->currentFrame++;
            if(this->currentFrame >= 2){
                this->currentFrame = 0;
            }
            this->frameTimer = 0.0f;
        }
    }

    Vector2 mousePosition = GetMousePosition();
    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(CheckCollisionPointRec(mousePosition,clickPistol)){
            this->selectedWeapon = WeaponSelection::Pistol;
        }
        else if(CheckCollisionPointRec(mousePosition,clickBoomerang)){
            this->selectedWeapon = WeaponSelection::Boommerang;
        }
    }
}

void BattleUI::DrawWeaponSelection(){
    float frameWidth = 100.0f;
    float frameHeight = 33.0f;
    float scale = 5.0f;

    switch(this->selectedWeapon){
        case WeaponSelection::None:{
            DrawTextureEx(this->noWeaponSelectedYet, {50.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
            break;
        
        case WeaponSelection::Pistol:{
            Rectangle source = {this->currentFrame * frameWidth, 0.0f, frameWidth, frameHeight};
            Rectangle destination = {50.0f, 600.0f, frameWidth * scale, frameHeight * scale};
            DrawTexturePro(pistolSelectedAnimation, source, destination, {0.0f, 0.0f}, 0.0f, WHITE);
        }
            break;

        case WeaponSelection::Boommerang:{
            Rectangle source = {this->currentFrame * frameWidth, 0.0f, frameWidth, frameHeight};
            Rectangle destination = {50.0f, 600.0f, frameWidth * scale, frameHeight * scale};
            DrawTexturePro(boomerangSelectedAnimation, source, destination, {0.0f, 0.0f}, 0.0f, WHITE);
        }
            break;

    }
}

void BattleUI::Unload(){
    UnloadTexture(this->noWeaponSelectedYet);
    UnloadTexture(this->pistolSelectedAnimation);
    UnloadTexture(this->boomerangSelectedAnimation);
}