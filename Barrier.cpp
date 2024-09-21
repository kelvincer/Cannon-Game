#include "Barrier.h"

int Barrier::getHeight()
{
    return height;
}

int Barrier::getWidth()
{
    return width;
}

Vector2 Barrier::getPosition()
{
    return position;
}

Color Barrier::getColor()
{
    return color;
}

Barrier::Barrier(int height, Vector2 position, Color color) : height{height}, position{position}, color{color}
{
}

void Barrier::draw()
{
    DrawRectangle(position.x, position.y, width, height, color);
}

void Barrier::setYPosition(float displacement)
{
    position.y += displacement ;
}

bool Barrier::hasReachedTopBorder()
{
    if (position.y <= 0)
    {
        return true;
    }

    return false;
}

bool Barrier::hasReachedBottomBorder()
{
    if (position.y + height >= SCREEN_HEIGHT)
    {
        return true;
    }

    return false;
}

void Barrier::setDirection(Direction direction)
{
    this->direction = direction;
}

Direction Barrier::getDirection()
{
    return direction;
}
