#pragma once
#include "raylib.h"
#include "Pistol.h"
#include "Boomerang.h"

enum class WeaponSelection{
    None,
    Pistol,
    Boommerang,
    ChooseAttackPistol,
    ChooseAttackBoomerang,
    ChooseTargetPistol,
    ChooseTargetBoomerang
};

class BattleUI{
    private:
    Texture2D noWeaponSelectedYet;
    Texture2D chooseWeaponBaseBorder;
    Texture2D pistolSelectedAnimation;
    Texture2D boomerangSelectedAnimation;
    Texture2D chooseAttack;
    Texture2D chooseAttackBorder;
    Texture2D returnArrow;
    Texture2D returnDead;
    Texture2D returnBorder;
    Texture2D playerSection;
    Texture2D lvlIcon;
    Texture2D hpIcon;
    Texture2D playerSectionXp;
    Texture2D xpIcon;
    Texture2D energySection;
    Texture2D playerBorderGreen;
    Texture2D healthBarBorder;

    WeaponSelection selectedWeapon;

    int currentFrame;
    float frameTimer;

    int abilityClicked;

    Texture2D pistolAbilityIcons[3];
    Texture2D boomerangAbilityIcons[3];
    Texture2D abilityTextField;
    Texture2D abilityIcon;
    Texture2D abilityBorderGreen;
    Texture2D abilityTextFieldNoText;

    Font battleUIFont;

    Texture2D upperUI;
    Texture2D chooseTargetPistolUI;
    Texture2D chooseTargetBoomerangUI;
    Texture2D monsterBattleBackground;
    Texture2D arrowLeft;
    Texture2D middleFight;
    Texture2D arrowRight;

    // Numbers
    Texture2D numberOne;
    Texture2D numberTwo;
    Texture2D numberThree;
    Texture2D numberFour;
    Texture2D numberFive;
    Texture2D numberSix;
    Texture2D numberSeven;
    Texture2D numberEight;
    Texture2D numberNine;
    Texture2D numberTen;

    // Numbers (HP) For the Craft System for bigger numbers than 9 (>9)

    Texture2D numberCraftingSystemZero;
    Texture2D numberCraftingSystemOne;
    Texture2D numberCraftingSystemTwo;
    Texture2D numberCraftingSystemThree;
    Texture2D numberCraftingSystemFour;
    Texture2D numberCraftingSystemFive;
    Texture2D numberCraftingSystemSix;
    Texture2D numberCraftingSystemSeven;
    Texture2D numberCraftingSystemEight;
    Texture2D numberCraftingSystemNine;
    Texture2D slashCraftingSystem;

    public:
    BattleUI();

    void UpdateWeaponSelection();
    void DrawWeaponSelection();

    void LoadPistolAbilityIcons(const std::vector<PistolAbility>& abilities);
    void LoadBoomerangAbilityIcons(const std::vector<BoomerangAbility>& abilities);
    void DrawPistolAbilities(const std::vector<PistolAbility>& abilities);
    void DrawBoomerangAbilities(const std::vector<BoomerangAbility>& abilities);

    void DrawPlayerUI(float currentHealth, float maxHealth, int currentLevel, float currentXp, float maxXp);
    void DrawMonsterUI();
    void DrawChooseTarget(const std::vector<Texture2D>& pistolBackSprites, const std::vector<Texture2D>& boomerangBackSprites);

    void Unload();

};