#include "game/Game.h"

int main(void)
{
    Cannon cannon{};
    Bullet bullet{};
    Barrier shieldBarrier{100, {400, 60}, BLACK};
    std::list<Barrier> objectives = {Barrier{40, {450, 30}, YELLOW}, Barrier{70, {480, 100}, PURPLE}, Barrier{55, {750, 300}, GREEN}};

    Game game{cannon, bullet, shieldBarrier, objectives};
    game.startGame();

    return 0;
}
