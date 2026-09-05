#include "Battle.h"

Battle::Battle(){
    LoadMonsters();
}

void Battle::LoadMonsters(){
    // Replace with true values
    monsters.emplace_back("Plant001", 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, "assetsFront", "assetsBack");
}