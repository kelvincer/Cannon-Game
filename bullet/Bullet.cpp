#include "Bullet.h"

float Bullet::getRadius() const
{
    return radius;
}

Vector2 Bullet::getCenter()
{
    return center;
}

void Bullet::draw()
{
    DrawCircle(getCenter().x, getCenter().y, getRadius(), DARKBROWN);
}

void Bullet::setRotation(float rotation)
{
    this->rotation = rotation;
}

float Bullet::getRotation() const
{
    return rotation;
}

void Bullet::setCenter(float deltaR)
{
    float x = (getRadius() + CANNON_BARREL + deltaR) * cos(getRotation());
    float y = SCREEN_HEIGHT / 2 + (getRadius() + CANNON_BARREL + deltaR) * sin(getRotation());
    center = {x, y};
}

bool Bullet::isOutsideWindow()
{
    if (getCenter().y < -getRadius())
    {
        return true;
    }

    if (getCenter().y > getRadius() + SCREEN_HEIGHT)
    {
        return true;
    }

    if (getCenter().x > getRadius() + SCREEN_WIDTH)
    {
        return true;
    }
    
    return false;
}
