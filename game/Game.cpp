#include "Game.h"

void Game::initGame()
{
    SetTraceLogLevel(LOG_DEBUG);
}

void Game::updateGame()
{
    moveBarrier(shieldBarrier, 25);

    for (auto it = objectives.begin(); it != objectives.end(); it++)
    {
        moveBarrier(*it, 13);
    }

    if (CheckCollisionCircleRec(bullet.getCenter(), BULLET_RADIUS, shieldBarrier.getRectangle()))
    {
        relocateBullet();
    }

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Vector2 clickPosition = GetMousePosition();
        shotAngle = atan((clickPosition.y - SCREEN_HEIGHT / 2) / clickPosition.x);
        inShot = true;
        initialDeltaR = INITIAL_FLOAT_VALUE;
        bullet.setRotation(shotAngle);
        cannon.setRotation(shotAngle);
    }

    for (auto &barrier : objectives)
    {
        if (CheckCollisionCircleRec(bullet.getCenter(), BULLET_RADIUS, barrier.getRectangle()))
        {
            objectives.remove(barrier);
            relocateBullet();
            break;
        }
    }

    if (inShot)
    {
        if (bullet.isOutsideWindow())
        {
            relocateBullet();
        }
        else
        {
            initialDeltaR += bulletDeltaR;
            bullet.setCenter(initialDeltaR);
        }
    }
}

void Game::drawGame()
{
    BeginDrawing();

    ClearBackground(WHITE);
    shieldBarrier.draw();
    cannon.draw();

    for (auto it = objectives.begin(); it != objectives.end(); it++)
        (*it).draw();

    if (inShot)
    {
        bullet.draw();
    }

    EndDrawing();
}

void Game::unloadGame()
{
}

void Game::moveBarrier(Barrier &barrier, float deltaY)
{
    if (barrier.hasReachedBottomBorder())
    {
        barrier.setDirection(Direction::UP);
    }
    else if (barrier.hasReachedTopBorder())
    {
        barrier.setDirection(Direction::DOWN);
    }

    switch (barrier.getDirection())
    {
    case Direction::UP:
        barrier.setYPosition(-deltaY);
        break;
    case Direction::DOWN:
        barrier.setYPosition(deltaY);
        break;
    }
}

void Game::relocateBullet()
{
    inShot = false;
    bullet.setCenter(INITIAL_FLOAT_VALUE);
}

void Game::startGame()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE); // prepare window
    initGame();                                            // load sounds and initialize game elements and variables
    SetTargetFPS(60);
    // target animation frame rate

    // main game loop
    while (!WindowShouldClose())
    {                 // loop until user closes window
        updateGame(); // update game element positions
        drawGame();   // draw next animation frame
    }

    unloadGame(); // release game resources
    CloseWindow();
}

Game::Game(Cannon cannon, Bullet bullet, Barrier barrier, std::list<Barrier> objectives) : cannon{cannon}, bullet{bullet}, shieldBarrier{barrier}, objectives{objectives}
{
    (this->cannon).setRotation(shotAngle);
    (this->bullet).setRotation(shotAngle);
}
