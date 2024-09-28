#pragma once

#include "../cannon/Cannon.h"
#include "../bullet/Bullet.h"
#include "../barrier/Barrier.h"
#include <list>

class Game
{
    void initGame();
    void updateGame();
    void drawGame();
    void unloadGame();
    void moveBarrier(Barrier &barrier, float deltaY);
    void relocateBullet();
    float shotAngle = INITIAL_FLOAT_VALUE;
    float initialDeltaR = INITIAL_FLOAT_VALUE;
    Cannon cannon;
    Bullet bullet;
    Barrier shieldBarrier;
    std::list<Barrier> objectives;
    bool inShot = false;
    const float bulletDeltaR = 15;

public:
    Game(Cannon cannon, Bullet bullet, Barrier barrier, std::list<Barrier> objectives);
    void startGame();
};