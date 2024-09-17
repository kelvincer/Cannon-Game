#include "Game.h"

void Game::initGame()
{
}

void Game::updateGame()
{
    if (bullet.isOutsideWindow())
    {
        initialDeltaR = 0.0f;
    }
    else
    {
        initialDeltaR += 10;
    }

    (this->bullet).setCenter(initialDeltaR);
}

void Game::drawGame()
{
    BeginDrawing();

    ClearBackground(WHITE);

    cannon.draw();
    bullet.draw();

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

Game::Game(Cannon cannon, Bullet bullet) : cannon{cannon}, bullet{bullet}
{
    (this->cannon).setRotation(0);
    (this->bullet).setRotation(0);
}
