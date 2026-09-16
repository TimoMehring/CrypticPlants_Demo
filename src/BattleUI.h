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
    Texture2D pistolSelectedAnimation;
    Texture2D boomerangSelectedAnimation;
    Texture2D chooseAttack;
    Texture2D chooseAttackBorder;
    Texture2D returnArrow;
    Texture2D returnBorder;
    Texture2D playerSection;

    WeaponSelection selectedWeapon;

    int currentFrame;
    float frameTimer;

    int abilityClicked;

    Texture2D pistolAbilityIcons[3];
    Texture2D boomerangAbilityIcons[3];
    Texture2D abilityTextField;
    Texture2D abilityIcon;
    Texture2D abilityTextFieldNoText;

    Font battleUIFont;

    Texture2D chooseTargetPistolUI;
    Texture2D chooseTargetBoomerangUI;
    Texture2D monsterBattleBackground;
    Texture2D arrowLeft;
    Texture2D middleFight;
    Texture2D arrowRight;

    public:
    BattleUI();

    void UpdateWeaponSelection();
    void DrawWeaponSelection();

    void LoadPistolAbilityIcons(const std::vector<PistolAbility>& abilities);
    void LoadBoomerangAbilityIcons(const std::vector<BoomerangAbility>& abilities);
    void DrawPistolAbilities(const std::vector<PistolAbility>& abilities);
    void DrawBoomerangAbilities(const std::vector<BoomerangAbility>& abilities);

    void DrawPlayerUI(float currentHealth, float maxHealth);
    void DrawMonsterUI();
    void DrawChooseTarget(const std::vector<Texture2D>& pistolBackSprites, const std::vector<Texture2D>& boomerangBackSprites);

    void Unload();

};