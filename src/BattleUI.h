#pragma once
#include "raylib.h"

enum class WeaponSelection{
    None,
    Pistol,
    Boommerang,
    ChooseAttack
};

class BattleUI{
    private:
    Texture2D noWeaponSelectedYet;
    Texture2D pistolSelectedAnimation;
    Texture2D boomerangSelectedAnimation;
    Texture2D chooseAttack;
    Texture2D returnArrow;

    WeaponSelection selectedWeapon;

    int currentFrame;
    float frameTimer;

    public:
    BattleUI();

    void UpdateWeaponSelection();
    void DrawWeaponSelection();

    void Unload();

};