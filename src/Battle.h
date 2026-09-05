#pragma once
#include "raylib.h"
#include "Monster.h"
#include <vector>

class Battle{
    private:

    std::vector<Monster> monsters;

    void LoadMonsters();

    public:
    // Constructor
    Battle();

};