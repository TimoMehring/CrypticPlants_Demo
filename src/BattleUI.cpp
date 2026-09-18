#include "BattleUI.h"

BattleUI::BattleUI(){
    this->selectedWeapon = WeaponSelection::None;
    this->currentFrame = 0;
    this->frameTimer = 0.0f;

    this->battleUIFont = LoadFont("assets/Fonts/PixelifySans-Regular.ttf");

    this->noWeaponSelectedYet = LoadTexture("assets/BattleUI/choose_weapon_base.png");
    this->chooseWeaponBaseBorder = LoadTexture("assets/BattleUI/chooseWeaponBaseBorder.png");
    this->pistolSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_pistol_spritesheet.png");
    this->boomerangSelectedAnimation = LoadTexture("assets/BattleUI/choose_weapon_boomerang_spritesheet.png");
    this->chooseAttack = LoadTexture("assets/BattleUI/choose_attack.png");
    this->chooseAttackBorder = LoadTexture("assets/BattleUI/choose_attack_border.png");
    this->abilityTextField = LoadTexture("assets/BattleUI/ability_text_field.png");
    this->abilityIcon = LoadTexture("assets/BattleUI/ability_icon.png");
    this->abilityBorderGreen = LoadTexture("assets/BattleUI/ability_border_green.png");
    this->abilityTextFieldNoText = LoadTexture("assets/BattleUI/ability_text_field_no_text.png");
    this->returnArrow = LoadTexture("assets/BattleUI/return.png");
    this->returnDead = LoadTexture("assets/BattleUI/returnDead.png");
    this->returnBorder = LoadTexture("assets/BattleUI/return_border.png");
    this->playerSection = LoadTexture("assets/BattleUI/player_section.png");
    this->lvlIcon = LoadTexture("assets/BattleUI/lvl.png");
    this->hpIcon = LoadTexture("assets/BattleUI/hp.png");
    this->playerSectionXp = LoadTexture("assets/BattleUI/player_section_xp.png");
    this->xpIcon = LoadTexture("assets/BattleUI/xp.png");
    this->playerBorderGreen = LoadTexture("assets/BattleUI/player_border_green.png");
    this->healthBarBorder = LoadTexture("assets/BattleUI/healthbar_border.png");

    this->upperUI = LoadTexture("assets/BattleUI/upper_ui.png");
    this->chooseTargetPistolUI = LoadTexture("assets/BattleUI/ui_choosetarget_pistol.png");
    this->chooseTargetBoomerangUI = LoadTexture("assets/BattleUI/ui_choosetarget_boomerang.png");
    this->monsterBattleBackground = LoadTexture("assets/BattleUI/battle_monster_background.png");
    this->arrowLeft = LoadTexture("assets/BattleUI/arrow_left.png");
    this->middleFight = LoadTexture("assets/BattleUI/middle_fight.png");
    this->arrowRight = LoadTexture("assets/BattleUI/arrow_right.png");

    //Numbers
    this->numberOne = LoadTexture("assets/BattleUI//Numbers/lvl01.png");
    this->numberTwo = LoadTexture("assets/BattleUI//Numbers/lvl02.png");
    this->numberThree = LoadTexture("assets/BattleUI//Numbers/lvl03.png");
    this->numberFour = LoadTexture("assets/BattleUI//Numbers/lvl04.png");
    this->numberFive = LoadTexture("assets/BattleUI//Numbers/lvl05.png");
    this->numberSix = LoadTexture("assets/BattleUI//Numbers/lvl06.png");
    this->numberSeven = LoadTexture("assets/BattleUI//Numbers/lvl07.png");
    this->numberEight = LoadTexture("assets/BattleUI//Numbers/lvl08.png");
    this->numberNine = LoadTexture("assets/BattleUI//Numbers/lvl09.png");
    this->numberTen = LoadTexture("assets/BattleUI//Numbers/lvl10.png");

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
            Rectangle Icon1 = {70.0f, 610.0f, static_cast<float>(this->boomerangAbilityIcons[0].width)*scale, static_cast<float>(this->boomerangAbilityIcons[0].height)*scale};
            Rectangle Icon2 = {230.0f, 610.0f, static_cast<float>(this->boomerangAbilityIcons[1].width)*scale, static_cast<float>(this->boomerangAbilityIcons[1].height)*scale};
            Rectangle Icon3 = {390.0f, 610.0f, static_cast<float>(this->boomerangAbilityIcons[2].width)*scale, static_cast<float>(this->boomerangAbilityIcons[2].height)*scale};
            Vector2 mousePosition = GetMousePosition();
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                if(CheckCollisionPointRec(mousePosition, Icon1)){
                    this->abilityClicked = 0;
                    if(selectedWeapon == WeaponSelection::ChooseAttackPistol){
                        this->selectedWeapon = WeaponSelection::ChooseTargetPistol;
                    }
                    else{
                        this->selectedWeapon = WeaponSelection::ChooseTargetBoomerang;
                    }
                }
                else if(CheckCollisionPointRec(mousePosition, Icon2)){
                    this->abilityClicked = 1;
                    if(selectedWeapon == WeaponSelection::ChooseAttackPistol){
                        this->selectedWeapon = WeaponSelection::ChooseTargetPistol;
                    }
                    else{
                        this->selectedWeapon = WeaponSelection::ChooseTargetBoomerang;
                    }
                }
                else if(CheckCollisionPointRec(mousePosition, Icon3)){
                    this->abilityClicked = 2;
                    if(selectedWeapon == WeaponSelection::ChooseAttackPistol){
                        this->selectedWeapon = WeaponSelection::ChooseTargetPistol;
                    }
                    else{
                        this->selectedWeapon = WeaponSelection::ChooseTargetBoomerang;
                    }
                }
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
    Rectangle chooseWeaponBaseRec = {50.0f, 600.0f, static_cast<float>(this->noWeaponSelectedYet.width)*scale, static_cast<float>(this->noWeaponSelectedYet.height)*scale};

    
    DrawTextureEx(this->playerSection, {110.0f, 550.0f}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(this->lvlIcon, {120.0f, 562.0f}, 0.0f, 3.0f, WHITE);
    // SAMPLE WHERE TO PLACE NUMBERS LATER
    DrawTextureEx(this->numberTen, {180.0f, 562.0f}, 0.0f, 3.0f, WHITE);
    DrawTextureEx(this->hpIcon, {490.0f, 562.0f}, 0.0f, 3.0f, WHITE);
    DrawTextureEx(this->upperUI, {50.0f, 395.0f}, 0.0f, 5.0f, WHITE); 

    switch(this->selectedWeapon){
        case WeaponSelection::None:{
            DrawTextureEx(this->returnDead, {50.0f, 550.0f}, 0.0f, 5.0f, WHITE);
            DrawTextureEx(this->noWeaponSelectedYet, {50.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
            break;
        
        case WeaponSelection::Pistol:{
            DrawTextureEx(this->returnDead, {50.0f, 550.0f}, 0.0f, 5.0f, WHITE);
            Rectangle source = {this->currentFrame * frameWidth, 0.0f, frameWidth, frameHeight};
            Rectangle destination = {50.0f, 600.0f, frameWidth * scale, frameHeight * scale};
            DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            DrawTexturePro(this->pistolSelectedAnimation, source, destination, {0.0f, 0.0f}, 0.0f, WHITE);

            if(CheckCollisionPointRec(mousePosition, abilityTextFieldNoTextRec)){
                DrawTextEx(this->battleUIFont, "Choose a Weapon", {685.0f, 610.0f}, 30.0f, 1.0f, BLACK);
            }

        }
            break;

        case WeaponSelection::Boommerang:{
            DrawTextureEx(this->returnDead, {50.0f, 550.0f}, 0.0f, 5.0f, WHITE);
            Rectangle source = {this->currentFrame * frameWidth, 0.0f, frameWidth, frameHeight};
            Rectangle destination = {50.0f, 600.0f, frameWidth * scale, frameHeight * scale};
            DrawTextureEx(this->abilityTextFieldNoText, {540.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            DrawTexturePro(this->boomerangSelectedAnimation, source, destination, {0.0f, 0.0f}, 0.0f, WHITE);

            if(CheckCollisionPointRec(mousePosition, abilityTextFieldNoTextRec)){
                DrawTextEx(this->battleUIFont, "Choose a Weapon", {685.0f, 610.0f}, 30.0f, 1.0f, BLACK);
            }
            float scaleRec = 5.0f;
            Rectangle playerSectionRec = {110.0f, 550.0f, static_cast<float>(playerSection.width)*scaleRec, static_cast<float>(playerSection.height)*scaleRec};

            if(CheckCollisionPointRec(mousePosition, playerSectionRec)){
                DrawTextureEx(this->playerBorderGreen, {45.0f, 550.0f}, 0.0f, 5.0f, WHITE);
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

    float scaleRec = 5.0f;
    Rectangle playerSectionRec = {110.0f, 550.0f, static_cast<float>(playerSection.width)*scaleRec, static_cast<float>(playerSection.height)*scaleRec};
    if(CheckCollisionPointRec(mousePosition, playerSectionRec)){
        DrawTextureEx(this->playerBorderGreen, {45.0f, 550.0f}, 0.0f, 5.0f, WHITE);
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
    float scaleRec = 5.0f;
    Rectangle playerSectionRec = {110.0f, 550.0f, static_cast<float>(playerSection.width)*scaleRec, static_cast<float>(playerSection.height)*scaleRec};
    if(CheckCollisionPointRec(mousePosition, playerSectionRec)){
        DrawTextureEx(this->playerBorderGreen, {45.0f, 550.0f}, 0.0f, 5.0f, WHITE);
    }
    }
}

void BattleUI::DrawPlayerUI(float currentHealth, float maxHealth, int currentLevel, float currentXp, float maxXp){
    Vector2 mousePosition = GetMousePosition();
    float scaleRec = 5.0f;
    Rectangle playerSectionRec = {110.0f, 550.0f, static_cast<float>(playerSection.width)*scaleRec, static_cast<float>(playerSection.height)*scaleRec};

    //currentHealth = 10.0f; // TO TEST HEALTH BAR COLOR CHANGE [DELETE LATER]
    currentXp = 1000.0f;

    float healthPercent = currentHealth / maxHealth;
    float xpPercent = currentXp / maxXp;

    float barX = 220.0f; 
    float barY = 565.0f;
    float barWidth = 150.0f;
    float barHeight = 20.0f;
    
    Vector2 playerSectionXpPosition = {540.0f, 550.0f};
    float xpBarX = 545.0f; //115, 595, 350, 5
    float xpBarY = 595.0f;
    float xpBarWidth = 350.0f;
    float xpBarHeight = 5.0f;

    Color currentColor = DARKGREEN;

    if(healthPercent <= 0.25f){
        currentColor = MAROON;
    }
    else if(healthPercent <= 0.5f){
        currentColor = GOLD;
    }

    DrawTextureEx(this->healthBarBorder,{215.0f, 560.0f}, 0.0f, 5.0f, WHITE);  
    DrawRectangle(barX, barY, barWidth * healthPercent, barHeight, currentColor);

    const char* healthText = TextFormat("%.0f/%.0f", currentHealth, maxHealth);
    DrawTextEx(this->battleUIFont, healthText, {390.0f, 560.0f}, 30.0f, 1.0f, BLACK);

/*     const char* levelText = TextFormat("%i", currentLevel); // "Lvl %i"
    DrawTextEx(this->battleUIFont, levelText, {180.0f, 560.0f}, 30.0f, 1.0f, BLACK); */

    //DrawTextureEx(this->playerSectionXp, {110.f, 550.0f}, 0.0f, 5.0f, WHITE); // PLACED IN PLAYERUI
    DrawTextureEx(this->playerSectionXp, {540.f, 550.0f}, 0.0f, 5.0f, WHITE);
    DrawTextureEx(this->xpIcon, {1010.0f, 585.0f}, 0.0f, 2.0f, WHITE);
    DrawRectangle(xpBarX, xpBarY, xpBarWidth * xpPercent, xpBarHeight, ORANGE);

    // Moved from DrawWeaponSelection due to draw order issues
    float scale = 5.0f;
    Rectangle chooseWeaponBaseRec = {50.0f, 600.0f, static_cast<float>(this->noWeaponSelectedYet.width)*scale, static_cast<float>(this->noWeaponSelectedYet.height)*scale};
    Rectangle abilityTextFieldNoTextRec = {540.0f, 600.0f, static_cast<float>(this->abilityTextFieldNoText.width)* scale, static_cast<float>(this->abilityTextFieldNoText.height)*scale};
    switch(this->selectedWeapon){
        case WeaponSelection::None:{
            if(CheckCollisionPointRec(mousePosition, abilityTextFieldNoTextRec)){
                DrawTextEx(this->battleUIFont, "Choose a Weapon", {685.0f, 610.0f}, 30.0f, 1.0f, BLACK);
                DrawTextureEx(this->abilityBorderGreen, {45.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            }
            if(CheckCollisionPointRec(mousePosition, chooseWeaponBaseRec)){
                DrawTextureEx(this->chooseWeaponBaseBorder, {45.0f, 600.0f}, 0.0f, 5.0f, WHITE);
            }

            Rectangle playerSectionRec = {110.0f, 550.0f, static_cast<float>(playerSection.width)*scaleRec, static_cast<float>(playerSection.height)*scaleRec};
            if(CheckCollisionPointRec(mousePosition, playerSectionRec)){
                DrawTextureEx(this->playerBorderGreen, {45.0f, 550.0f}, 0.0f, 5.0f, WHITE);
            }
        }
            break;
        
        case WeaponSelection::Boommerang:
        case WeaponSelection::Pistol:
        case WeaponSelection::ChooseAttackPistol:
        case WeaponSelection::ChooseAttackBoomerang:{

            Rectangle playerSectionRec = {110.0f, 550.0f, static_cast<float>(playerSection.width)*scaleRec, static_cast<float>(playerSection.height)*scaleRec};
            if(CheckCollisionPointRec(mousePosition, playerSectionRec)){
                DrawTextureEx(this->playerBorderGreen, {45.0f, 550.0f}, 0.0f, 5.0f, WHITE);
            }
        }
        break;
            

    }

}

void BattleUI::DrawMonsterUI(){
    DrawTextureEx(this->monsterBattleBackground, {0.0f, 0.0f}, 0.0f, 8.0f, WHITE);
}

void BattleUI::DrawChooseTarget(const std::vector<Texture2D>& pistolBackSprites, const std::vector<Texture2D>& boomerangBackSprites){
    if(selectedWeapon == WeaponSelection::ChooseTargetPistol){
        DrawTextureEx(this->returnDead, {50.0f, 550.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->chooseTargetPistolUI, {50.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->middleFight, {510.0f, 420.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->arrowLeft, {440.0f, 420.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->arrowRight, {580.0f, 420.0f}, 0.0f, 5.0f, WHITE);
        if(abilityClicked == 0){
            DrawTextureEx(pistolBackSprites[this->abilityClicked], {650.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
        else if(abilityClicked == 1){
            DrawTextureEx(pistolBackSprites[this->abilityClicked], {650.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
        else if(abilityClicked == 2){
            DrawTextureEx(pistolBackSprites[this->abilityClicked], {650.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
    }
    else if(selectedWeapon == WeaponSelection::ChooseTargetBoomerang){
        DrawTextureEx(this->returnDead, {50.0f, 550.0f}, 0.0f, 5.0f, WHITE);
        DrawTextureEx(this->chooseTargetBoomerangUI, {50.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        if(abilityClicked == 0){
            DrawTextureEx(boomerangBackSprites[this->abilityClicked], {650.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
        else if(abilityClicked == 1){
            DrawTextureEx(boomerangBackSprites[this->abilityClicked], {650.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
        else if(abilityClicked == 2){
            DrawTextureEx(boomerangBackSprites[this->abilityClicked], {650.0f, 600.0f}, 0.0f, 5.0f, WHITE);
        }
    }
}

void BattleUI::Unload(){
    UnloadFont(this->battleUIFont);
    UnloadTexture(this->noWeaponSelectedYet);
    UnloadTexture(this->chooseWeaponBaseBorder);
    UnloadTexture(this->pistolSelectedAnimation);
    UnloadTexture(this->boomerangSelectedAnimation);

    UnloadTexture(this->chooseAttack);
    UnloadTexture(this->chooseAttackBorder);
    UnloadTexture(this->returnArrow);
    UnloadTexture(this->returnDead);
    UnloadTexture(this->returnBorder);
    UnloadTexture(this->playerSection);
    UnloadTexture(this->lvlIcon);
    UnloadTexture(this->hpIcon);
    UnloadTexture(this->playerSectionXp);
    UnloadTexture(this->xpIcon);
    UnloadTexture(this->playerBorderGreen);
    UnloadTexture(this->healthBarBorder);

    UnloadTexture(this->pistolAbilityIcons[0]);
    UnloadTexture(this->pistolAbilityIcons[1]);
    UnloadTexture(this->pistolAbilityIcons[2]);
    UnloadTexture(this->boomerangAbilityIcons[0]);
    UnloadTexture(this->boomerangAbilityIcons[1]);
    UnloadTexture(this->boomerangAbilityIcons[2]);
    UnloadTexture(this->abilityTextField);
    UnloadTexture(this->abilityIcon);
    UnloadTexture(this->abilityBorderGreen);
    UnloadTexture(this->abilityTextFieldNoText);

    UnloadTexture(this->upperUI);
    UnloadTexture(this->chooseTargetPistolUI);
    UnloadTexture(this->chooseTargetBoomerangUI);
    UnloadTexture(this->monsterBattleBackground);
    UnloadTexture(this->arrowLeft);
    UnloadTexture(this->middleFight);
    UnloadTexture(this->arrowRight);

    //Numbers
    UnloadTexture(this->numberOne);
    UnloadTexture(this->numberTwo);
    UnloadTexture(this->numberThree);
    UnloadTexture(this->numberFour);
    UnloadTexture(this->numberFive);
    UnloadTexture(this->numberSix);
    UnloadTexture(this->numberSeven);
    UnloadTexture(this->numberEight);
    UnloadTexture(this->numberNine);
    UnloadTexture(this->numberTen);


}