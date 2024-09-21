#pragma once

#include "Cannon.h"
#include "Bullet.h"
#include "Barrier.h"

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
    Barrier barrier;
    bool inShot = false;

public:
    Game(Cannon cannon, Bullet bullet, Barrier barrier);
    void startGame();
};