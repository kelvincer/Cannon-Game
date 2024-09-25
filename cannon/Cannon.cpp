#include "Cannon.h"

void Cannon::draw()
{
    // DrawCircle(0, SCREEN_HEIGHT / 2, 40, YELLOW);
    DrawCircleSector({0, SCREEN_HEIGHT / 2}, getCannonRadius(), -90, 90, 6, GREEN);
    // DrawRectangle(0, SCREEN_HEIGHT / 2 - getCannonHeight() / 2, getCannonWidth(), getCannonHeight(), GRAY);

    Rectangle rec = {0, SCREEN_HEIGHT / 2, getCannonWidth(), getCannonHeight()};

    DrawRectanglePro(rec, {0, getCannonHeight() / 2}, getRotation() * 180 / PI, GREEN); // Set origin to 0,0
}

float Cannon::getCannonRadius() const
{
    return cannonRadius;
}

float Cannon::getCannonHeight() const
{
    return cannonHeight;
}

float Cannon::getCannonWidth() const
{
    return cannonWidth;
}

float Cannon::getRotation() const
{
    return rotation;
}

void Cannon::setRotation(float rotation)
{
    this->rotation = rotation;
}
