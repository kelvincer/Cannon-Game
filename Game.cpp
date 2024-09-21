#include "Game.h"

void Game::initGame()
{
}

void Game::updateGame()
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
        barrier.setYPosition(-10);
        break;
    case Direction::DOWN:
        barrier.setYPosition(10);
        break;
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

    if (inShot)
    {
        if (bullet.isOutsideWindow())
        {
            inShot = false;
            bullet.setCenter(INITIAL_FLOAT_VALUE);
        }
        else
        {
            initialDeltaR += 10;
            bullet.setCenter(initialDeltaR);
        }
    }
}

void Game::drawGame()
{
    BeginDrawing();

    ClearBackground(WHITE);
    barrier.draw();
    cannon.draw();
    if (inShot)
    {
        bullet.draw();
    }
    EndDrawing();
}

void Game::unloadGame()
{
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

Game::Game(Cannon cannon, Bullet bullet, Barrier barrier) : cannon{cannon}, bullet{bullet}, barrier{barrier}
{
    (this->cannon).setRotation(shotAngle);
    (this->bullet).setRotation(shotAngle);
}
