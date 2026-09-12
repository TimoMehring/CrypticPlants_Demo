#include "BattleUI.h"

BattleUI::BattleUI(){
    this->selectedWeapon = WeaponSelection::None;
    this->currentFrame = 0;
    this->frameTimer = 0.0f;

    this->noWeaponSelectedYet = LoadTexture("assets/BattleUI/choose_weapon_base.png");
    this->pistolSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_pistol_spritesheet.png");
    this->boomerangSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_boomerang_spritesheet.png");
    this->chooseAttack = LoadTexture("assets/BattleUI/choose_attack.png");
    this->returnArrow = LoadTexture("assets/BattleUI/return.png");
    this->returnBorder = LoadTexture("assets/BattleUI/return_border.png");
}

void BattleUI::UpdateWeaponSelection(){
    float scale = 5.0f;
    float halfWidth = static_cast<float>(noWeaponSelectedYet.width) / 2.0f;
    Rectangle clickPistol = {50.0f, 600.0f, halfWidth*scale, static_cast<float>(noWeaponSelectedYet.height)*scale};
    Rectangle clickBoomerang = {50.0f + halfWidth*scale, 600.0f, halfWidth*scale, static_cast<float>(noWeaponSelectedYet.height)*scale};

    Vector2 mousePosition = GetMousePosition();

    switch(this->selectedWeapon){
        case WeaponSelection::None:{
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(mousePosition,clickPistol)){
                    this->selectedWeapon = WeaponSelection::Pistol;
                }
                else if(CheckCollisionPointRec(mousePosition,clickBoomerang)){
                    this->selectedWeapon = WeaponSelection::Boommerang;
                    this->currentFrame = 0;
                    this->frameTimer = 0;
                }
            
            }
            break;
        }
        case WeaponSelection::Pistol:{
            this->frameTimer += GetFrameTime();
            
            if(this->frameTimer >= 0.4f){
                this->currentFrame++;
                if(this->currentFrame >= 2){
                    this->currentFrame = 0;
            }
            this->frameTimer = 0.0f;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(mousePosition,clickPistol)){
                    this->selectedWeapon = WeaponSelection::ChooseAttackPistol;
                }
                else if(CheckCollisionPointRec(mousePosition,clickBoomerang)){
                    this->selectedWeapon = WeaponSelection::Boommerang;
                    this->currentFrame = 0;
                    this->frameTimer = 0;
                }
            }
            break;
        }

        case WeaponSelection::Boommerang:{
            this->frameTimer += GetFrameTime();
            
            if(this->frameTimer >= 0.4f){
                this->currentFrame++;
                if(this->currentFrame >= 2){
                    this->currentFrame = 0;
            }
            this->frameTimer = 0.0f;
            }
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(mousePosition,clickBoomerang)){
                    this->selectedWeapon = WeaponSelection::ChooseAttackBoomerang;
                }
                else if(CheckCollisionPointRec(mousePosition,clickPistol)){
                    this->selectedWeapon = WeaponSelection::Pistol;
                    this->currentFrame = 0;
                    this->frameTimer = 0;
                }
            }
            break;
        }

        case WeaponSelection::ChooseAttackPistol:
        case WeaponSelection::ChooseAttackBoomerang:{
            Rectangle returnArrowRec = {50.0f, 550.0f,static_cast<float>(this->returnArrow.width) * scale, static_cast<float>(this->returnArrow.height) * scale};
            if((CheckCollisionPointRec(mousePosition, returnArrowRec)) && (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))){
                this->selectedWeapon = WeaponSelection::None;
            }
        }
        break;
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
        
        case WeaponSelection::ChooseAttackPistol:
        case WeaponSelection::ChooseAttackBoomerang:{
            DrawTextureEx(this->chooseAttack, {50.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            DrawTextureEx(this->returnArrow, {50.0f, 550.0f}, 0.0f, 5.0f, WHITE);

            Vector2 mousePosition = GetMousePosition();
            Rectangle returnArrowRec = {50.0f, 550.0f,static_cast<float>(this->returnArrow.width) * scale, static_cast<float>(this->returnArrow.height) * scale};
            if(CheckCollisionPointRec(mousePosition, returnArrowRec)){
                DrawTextureEx(this->returnBorder,{50.0f, 550.0f}, 0.0f, 5.0f, WHITE);
            }
            break;
        }

    }
}

void BattleUI::LoadPistolAbilityIcons(const std::vector<PistolAbility>& abilities){
    if(abilities.size() < 3){
        return;
    }
    this->pistolAbilityIcons[0] = LoadTexture(abilities[0].iconPath);
    this->pistolAbilityIcons[1] = LoadTexture(abilities[1].iconPath);
    this->pistolAbilityIcons[2] = LoadTexture(abilities[2].iconPath);
}

void BattleUI::DrawPistolAbilities(){
    if(selectedWeapon == WeaponSelection::ChooseAttackPistol){
    DrawTextureEx(this->pistolAbilityIcons[0],{100.0f, 620.0f},0.0f,5.0f,WHITE);
    DrawTextureEx(this->pistolAbilityIcons[1],{300.0f, 620.0f},0.0f,5.0f,WHITE);
    DrawTextureEx(this->pistolAbilityIcons[2],{500.0f, 620.0f},0.0f,5.0f,WHITE);
    }
}

void BattleUI::Unload(){
    UnloadTexture(this->noWeaponSelectedYet);
    UnloadTexture(this->pistolSelectedAnimation);
    UnloadTexture(this->boomerangSelectedAnimation);

    UnloadTexture(this->chooseAttack);
    UnloadTexture(this->returnArrow);
    UnloadTexture(this->returnBorder);

    UnloadTexture(this->pistolAbilityIcons[0]);
    UnloadTexture(this->pistolAbilityIcons[1]);
    UnloadTexture(this->pistolAbilityIcons[2]);

}