#include "Barrier.h"

int Barrier::getHeight() const
{
    return height;
}

int Barrier::getWidth() const
{
    return width;
}

Vector2 Barrier::getPosition() const
{
    return position;
}

Color Barrier::getColor() const
{
    return color;
}

bool Barrier::operator==(const Barrier &b) const
{
    return this->getPosition().x == b.getPosition().x;
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
    position.y += displacement;
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

Rectangle Barrier::getRectangle()
{
    return Rectangle(position.x, position.y, width, height);
}

Direction Barrier::getDirection()
{
    return direction;
}
