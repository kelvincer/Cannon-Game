#include "game/Game.h"

int main(void)
{
    Cannon cannon{};
    Bullet bullet{};
    Barrier shieldBarrier{100, {400, 60}, BLACK};
    std::list<Barrier> objectives = {Barrier{40, {450, 30}, YELLOW}, Barrier{70, {480, 100}, PURPLE}, Barrier{20, {510, 30}, GRAY}, Barrier{15, {540, 300}, DARKBROWN}, Barrier{30, {560, 320}, DARKGREEN}, Barrier{60, {580, 300}, DARKBLUE}, Barrier{70, {520, 100}, DARKPURPLE}, Barrier{80, {550, 200}, DARKGRAY}, Barrier{60, {600, 200}, YELLOW}, Barrier{100, {650, 100}, GRAY}, Barrier{80, {700, 100}, RED}, Barrier{50, {725, 299}, PURPLE}, Barrier{55, {750, 300}, GREEN}};

    Game game{cannon, bullet, shieldBarrier, objectives};
    game.startGame();

    return 0;
}
