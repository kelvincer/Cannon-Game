#include "Game.h"

int main(void)
{
    Cannon cannon{};
    Bullet bullet{};

    Game game{cannon, bullet};
    game.startGame();

    return 0;
}
