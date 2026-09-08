#include "Battle.h"

Battle::Battle(){
    LoadMonsterData();
    StartTestEncounter();
}

void Battle::LoadMonsterData(){
    monsterData.push_back({"Plant001", 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, "assets/MonsterSprites/plant001_front.png", "assets/MonsterSprites/plant001_back.png"});
    monsterData.push_back({"Plant002", 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, "assets/MonsterSprites/plant002_front.png", "assets/MonsterSprites/plant002_back.png"});
}

void Battle::StartTestEncounter(){
    if(currentMonster != nullptr){
        currentMonster->Unload();
        delete currentMonster;
        currentMonster = nullptr;
    }
    int randomIndex = GetRandomValue(0, static_cast<int>(monsterData.size()) -1);


    MonsterData& data = monsterData[randomIndex];
    currentMonster = new Monster(data.name, data.range, data.speed, data.health, data.resistance, data.attack, data.frontSpritePath, data.backSpritePath);
}

void Battle::Update(){
    if(IsKeyPressed(KEY_ENTER)){
        StartTestEncounter();
    }
}

void Battle::Draw(){
        currentMonster->DrawFront({300.0f, 20.0f}, 4.0f);
        currentMonster->DrawBack({300.0f, 300.0f}, 4.0f);
}

void Battle::Unload(){
        if(currentMonster != nullptr){
            currentMonster->Unload();
            delete currentMonster;
            currentMonster = nullptr;
        }
   
}