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
    float shotAngle = INITIAL_FLOAT_VALUE;
    float initialDeltaR = INITIAL_FLOAT_VALUE;  
    Cannon cannon;
    Bullet bullet;
    bool inShot = false;

public:
    void startGame();
    Game(Cannon cannon, Bullet bullet);
};