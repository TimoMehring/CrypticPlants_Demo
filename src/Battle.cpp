#include "Battle.h"

Battle::Battle(){
    LoadMonsterData();
    StartTestEncounter();

    battleUI.LoadPistolAbilityIcons(this->pistol.GetAbilities());
    battleUI.LoadBoomerangAbilityIcons(this->boomerang.GetAbilities());
}

void Battle::LoadMonsterData(){
    monsterData.push_back({"Plant001", 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, "assets/MonsterSprites/plant001_front.png", "assets/MonsterSprites/plant001_back.png", {"assets/WeakPoints/plant001MinusOne.png", "assets/WeakPoints/plant001PlusOne.png"},{350.0f, 50.0f}});
    monsterData.push_back({"Plant002", 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, "assets/MonsterSprites/plant002_front.png", "assets/MonsterSprites/plant002_back.png", {"assets/WeakPoints/plant001MinusOne.png", "assets/WeakPoints/plant001PlusOne.png"},{350.0f, 50.0f}});
}

void Battle::StartTestEncounter(){
    if(currentMonster != nullptr){
        currentMonster->Unload();
        delete currentMonster;
        currentMonster = nullptr;
    }
    int randomIndex = GetRandomValue(0, static_cast<int>(monsterData.size()) -1);


    MonsterData& data = monsterData[randomIndex];
    currentMonster = new Monster(data.name, data.range, data.speed, data.health, data.resistance, data.attack, data.frontSpritePath, data.backSpritePath, data.weakPointSpritePaths, data.targetArrowPosition);
}

void Battle::Update(){
    battleUI.UpdateWeaponSelection();
    if(IsKeyPressed(KEY_ENTER)){
        StartTestEncounter();
    }
}

void Battle::Draw(){
    battleUI.DrawWeaponSelection();
    battleUI.DrawPistolAbilities(this->pistol.GetAbilities());
    battleUI.DrawBoomerangAbilities(this->boomerang.GetAbilities());
    battleUI.DrawMonsterUI();
    battleUI.DrawChooseTarget(this->pistol.GetAbilityBackSprite(), this->boomerang.GetAbilityBackSprite());
    battleUI.DrawPlayerUI(this->player.GetCurrentHealth(), this->player.GetMaxHealth(), this->player.GetLevel(), this->player.GetCurrentXp(), this->player.GetMaxXP());
    battleUI.DrawChooseTarget(this->pistol.GetAbilityBackSprite(), this->boomerang.GetAbilityBackSprite());
    if(currentMonster != nullptr){
        currentMonster->DrawFront({350.0f, 130.0f}, 8.0f);
    }
    
    this->battleUI.DrawWeakPoints(this->currentMonster->GetWeakPointSprites(), this->currentMonster->GetTargetArrowPosition());
}

void Battle::Unload(){
    battleUI.Unload();
    pistol.Unload();
    boomerang.Unload();
    if(currentMonster != nullptr){
        currentMonster->Unload();
        delete currentMonster;
        currentMonster = nullptr;
        }
   
}