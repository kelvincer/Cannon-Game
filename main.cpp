#include "game/Game.h"

int main(void)
{
    Cannon cannon{};
    Bullet bullet{};
    Barrier shieldBarrier{100, {400, 60}, BLACK};

    Game game{cannon, bullet, shieldBarrier};
    game.startGame();

    return 0;
}
