#pragma once
#include "raylib.h"
#include "Pistol.h"
#include "Boomerang.h"

enum class WeaponSelection{
    None,
    Pistol,
    Boommerang,
    ChooseAttackPistol,
    ChooseAttackBoomerang
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

    WeaponSelection selectedWeapon;

    int currentFrame;
    float frameTimer;

    Texture2D pistolAbilityIcons[3];
    Texture2D boomerangAbilityIcons[3];
    Texture2D abilityTextField;

    public:
    BattleUI();

    void UpdateWeaponSelection();
    void DrawWeaponSelection();

    void LoadPistolAbilityIcons(const std::vector<PistolAbility>& abilities);
    void LoadBoomerangAbilityIcons(const std::vector<BoomerangAbility>& abilities);
    void DrawPistolAbilities(const std::vector<PistolAbility>& abilities);
    void DrawBoomerangAbilities();

    void Unload();

};