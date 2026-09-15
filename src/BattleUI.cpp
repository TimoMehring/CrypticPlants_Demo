#include "BattleUI.h"

BattleUI::BattleUI(){
    this->selectedWeapon = WeaponSelection::None;
    this->currentFrame = 0;
    this->frameTimer = 0.0f;

    this->battleUIFont = LoadFont("assets/Fonts/PixelifySans-Regular.ttf");

    this->noWeaponSelectedYet = LoadTexture("assets/BattleUI/choose_weapon_base.png");
    this->pistolSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_pistol_spritesheet.png");
    this->boomerangSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_boomerang_spritesheet.png");
    this->chooseAttack = LoadTexture("assets/BattleUI/choose_attack.png");
    this->chooseAttackBorder = LoadTexture("assets/BattleUI/choose_attack_border.png");
    this->abilityTextField = LoadTexture("assets/BattleUI/ability_text_field.png");
    this->abilityIcon = LoadTexture("assets/BattleUI/ability_icon.png");
    this->abilityTextFieldNoText = LoadTexture("assets/BattleUI/ability_text_field_no_text.png");
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

    Vector2 mousePosition = GetMousePosition();
    Rectangle abilityTextFieldNoTextRec = {540.0f, 600.0f, static_cast<float>(this->abilityTextFieldNoText.width)* scale, static_cast<float>(this->abilityTextFieldNoText.height)*scale};

    //DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);

    switch(this->selectedWeapon){
        case WeaponSelection::None:{
            DrawTextureEx(this->noWeaponSelectedYet, {50.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            //Rectangle abilityTextFieldNoTextRec = {540.0f, 600.0f, static_cast<float>(this->abilityTextFieldNoText.width)* scale, static_cast<float>(this->abilityTextFieldNoText.height)*scale};
            if(CheckCollisionPointRec(mousePosition, abilityTextFieldNoTextRec)){
                DrawTextEx(this->battleUIFont, "Choose a Weapon", {685.0f, 610.0f}, 30.0f, 1.0f, BLACK);
            }
        }
            break;
        
        case WeaponSelection::Pistol:{
            Rectangle source = {this->currentFrame * frameWidth, 0.0f, frameWidth, frameHeight};
            Rectangle destination = {50.0f, 600.0f, frameWidth * scale, frameHeight * scale};
            DrawTexturePro(this->pistolSelectedAnimation, source, destination, {0.0f, 0.0f}, 0.0f, WHITE);
            DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);

            if(CheckCollisionPointRec(mousePosition, abilityTextFieldNoTextRec)){
                DrawTextEx(this->battleUIFont, "Choose a Weapon", {685.0f, 610.0f}, 30.0f, 1.0f, BLACK);
            }
        }
            break;

        case WeaponSelection::Boommerang:{
            Rectangle source = {this->currentFrame * frameWidth, 0.0f, frameWidth, frameHeight};
            Rectangle destination = {50.0f, 600.0f, frameWidth * scale, frameHeight * scale};
            DrawTexturePro(this->boomerangSelectedAnimation, source, destination, {0.0f, 0.0f}, 0.0f, WHITE);
            DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);

            if(CheckCollisionPointRec(mousePosition, abilityTextFieldNoTextRec)){
                DrawTextEx(this->battleUIFont, "Choose a Weapon", {685.0f, 610.0f}, 30.0f, 1.0f, BLACK);
            }
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

void BattleUI::DrawPistolAbilities(const std::vector<PistolAbility>& abilities){
    if(selectedWeapon == WeaponSelection::ChooseAttackPistol){
    float scale = 5.0f;
    DrawTextureEx(this->pistolAbilityIcons[0],{70.0f, 610.0f},0.0f,5.0f,WHITE);
    DrawTextureEx(this->pistolAbilityIcons[1],{230.0f, 610.0f},0.0f,5.0f,WHITE);
    DrawTextureEx(this->pistolAbilityIcons[2],{390.0f, 610.0f},0.0f,5.0f,WHITE);
    Rectangle Icon1 = {70.0f, 610.0f, static_cast<float>(this->pistolAbilityIcons[0].width)*scale, static_cast<float>(this->pistolAbilityIcons[0].height)*scale};
    Rectangle Icon2 = {230.0f, 610.0f, static_cast<float>(this->pistolAbilityIcons[1].width)*scale, static_cast<float>(this->pistolAbilityIcons[1].height)*scale};
    Rectangle Icon3 = {390.0f, 610.0f, static_cast<float>(this->pistolAbilityIcons[2].width)*scale, static_cast<float>(this->pistolAbilityIcons[2].height)*scale};
    Vector2 mousePosition = GetMousePosition();
    if(CheckCollisionPointRec(mousePosition, Icon1)){
        DrawTextureEx(chooseAttackBorder, {70.0f, 610.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityTextField, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityIcon, {560.0f, 620.0f}, 0.0f, 2.0f, WHITE);
        DrawTextEx(this->battleUIFont, abilities[0].name.c_str(), {610.0f, 620.0f}, 30.0f, 1.0f, BLACK);
        DrawTextEx(this->battleUIFont, abilities[0].description.c_str(), {560.0f, 660.0f}, 20.0f, 1.0f, BLACK);
    }
    else if(CheckCollisionPointRec(mousePosition, Icon2)){
        DrawTextureEx(chooseAttackBorder, {230.0f, 610.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityTextField, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityIcon, {560.0f, 620.0f}, 0.0f, 2.0f, WHITE);
        DrawTextEx(this->battleUIFont, abilities[1].name.c_str(), {610.0f, 620.0f}, 30.0f, 1.0f, BLACK);
        DrawTextEx(this->battleUIFont, abilities[1].description.c_str(), {560.0f, 660.0f}, 20.0f, 1.0f, BLACK);
    }
    else if(CheckCollisionPointRec(mousePosition, Icon3)){
        DrawTextureEx(chooseAttackBorder, {390.0f, 610.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityTextField, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityIcon, {560.0f, 620.0f}, 0.0f, 2.0f, WHITE);
        DrawTextEx(this->battleUIFont, abilities[2].name.c_str(), {610.0f, 620.0f}, 30.0f, 1.0f, BLACK);
        DrawTextEx(this->battleUIFont, abilities[2].description.c_str(), {560.0f, 660.0f}, 20.0f, 1.0f, BLACK);
    }
    else{
        DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextEx(this->battleUIFont, "Choose an Ability", {675.0f, 610.0f}, 30.0f, 1.0f, BLACK);
    }
    }
}

void BattleUI::LoadBoomerangAbilityIcons(const std::vector<BoomerangAbility>& abilities){
    if(abilities.size() < 3){
        return;
    }
    this->boomerangAbilityIcons[0] = LoadTexture(abilities[0].iconPath);
    this->boomerangAbilityIcons[1] = LoadTexture(abilities[1].iconPath);
    this->boomerangAbilityIcons[2] = LoadTexture(abilities[2].iconPath);

}

void BattleUI::DrawBoomerangAbilities(const std::vector<BoomerangAbility>& abilities){
    if(selectedWeapon == WeaponSelection::ChooseAttackBoomerang){
    float scale = 5.0f;
    DrawTextureEx(this->boomerangAbilityIcons[0],{70.0f, 610.0f},0.0f,5.0f,WHITE);
    DrawTextureEx(this->boomerangAbilityIcons[1],{230.0f, 610.0f},0.0f,5.0f,WHITE);
    DrawTextureEx(this->boomerangAbilityIcons[2],{390.0f, 610.0f},0.0f,5.0f,WHITE);

    Rectangle Icon1 = {70.0f, 610.0f, static_cast<float>(this->boomerangAbilityIcons[0].width)*scale, static_cast<float>(this->boomerangAbilityIcons[0].height)*scale};
    Rectangle Icon2 = {230.0f, 610.0f, static_cast<float>(this->boomerangAbilityIcons[1].width)*scale, static_cast<float>(this->boomerangAbilityIcons[1].height)*scale};
    Rectangle Icon3 = {390.0f, 610.0f, static_cast<float>(this->boomerangAbilityIcons[2].width)*scale, static_cast<float>(this->boomerangAbilityIcons[2].height)*scale};
    
    Vector2 mousePosition = GetMousePosition();
    if(CheckCollisionPointRec(mousePosition, Icon1)){
        DrawTextureEx(chooseAttackBorder, {70.0f, 610.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityTextField, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityIcon, {560.0f, 620.0f}, 0.0f, 2.0f, WHITE);
        DrawTextEx(this->battleUIFont, abilities[0].name.c_str(), {610.0f, 620.0f}, 30.0f, 1.0f, BLACK);
        DrawTextEx(this->battleUIFont, abilities[0].description.c_str(), {560.0f, 660.0f}, 20.0f, 1.0f, BLACK);
    }
    else if(CheckCollisionPointRec(mousePosition, Icon2)){
        DrawTextureEx(chooseAttackBorder, {230.0f, 610.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityTextField, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityIcon, {560.0f, 620.0f}, 0.0f, 2.0f, WHITE);
        DrawTextEx(this->battleUIFont, abilities[1].name.c_str(), {610.0f, 620.0f}, 30.0f, 1.0f, BLACK);
        DrawTextEx(this->battleUIFont, abilities[1].description.c_str(), {560.0f, 660.0f}, 20.0f, 1.0f, BLACK);
    }
    else if(CheckCollisionPointRec(mousePosition, Icon3)){
        DrawTextureEx(chooseAttackBorder, {390.0f, 610.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityTextField, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->abilityIcon, {560.0f, 620.0f}, 0.0f, 2.0f, WHITE);
        DrawTextEx(this->battleUIFont, abilities[2].name.c_str(), {610.0f, 620.0f}, 30.0f, 1.0f, BLACK);
        DrawTextEx(this->battleUIFont, abilities[2].description.c_str(), {560.0f, 660.0f}, 20.0f, 1.0f, BLACK);
    }
    else{
        DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextEx(this->battleUIFont, "Choose an Ability", {675.0f, 610.0f}, 30.0f, 1.0f, BLACK);
    }
    }
}

void BattleUI::Unload(){
    UnloadFont(this->battleUIFont);
    UnloadTexture(this->noWeaponSelectedYet);
    UnloadTexture(this->pistolSelectedAnimation);
    UnloadTexture(this->boomerangSelectedAnimation);

    UnloadTexture(this->chooseAttack);
    UnloadTexture(this->chooseAttackBorder);
    UnloadTexture(this->returnArrow);
    UnloadTexture(this->returnBorder);

    UnloadTexture(this->pistolAbilityIcons[0]);
    UnloadTexture(this->pistolAbilityIcons[1]);
    UnloadTexture(this->pistolAbilityIcons[2]);
    UnloadTexture(this->boomerangAbilityIcons[0]);
    UnloadTexture(this->boomerangAbilityIcons[1]);
    UnloadTexture(this->boomerangAbilityIcons[2]);
    UnloadTexture(this->abilityTextField);
    UnloadTexture(this->abilityIcon);
    UnloadTexture(this->abilityTextFieldNoText);

}