#pragma once

#include "raylib.h"
#include "Cannon.h"
#include "Bullet.h"
#include "Constants.h"

class Game
{
    void initGame();
    void updateGame();
    void drawGame();
    void unloadGame();
    float shotAngle = -45.0f;
    float initialDeltaR = 0;  
    Cannon cannon;
    Bullet bullet;

public:
    void startGame();
    Game(Cannon cannon, Bullet bullet);
};