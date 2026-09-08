#include "Game.h"

Game::Game(){
}

void Game::Update(){
    battle.Update();
}

void Game::Draw(){
    battle.Draw();
}

void Game::Unload(){
    battle.Unload();
}