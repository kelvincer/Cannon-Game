#pragma once

#include "raylib.h"
#include "../Constants.h"
#include "../Direction.h"

class Barrier
{
    int getHeight() const;
    int getWidth() const;
    Vector2 getPosition() const;
    Color getColor() const;

    int height;
    int width = BARRIER_WIDTH;
    Vector2 position;
    Color color;
    bool isShield = false;
    float vertical_displacement = 0.0f;
    Direction direction = Direction::DOWN;

public:
    Barrier() = default;
    Barrier(int height, Vector2 position, Color color);
    void draw();
    void setYPosition(float y);
    bool hasReachedTopBorder();
    bool hasReachedBottomBorder();
    void setDirection(Direction direction);
    Rectangle getRectangle();
    Direction getDirection();
    bool operator==(const Barrier &b) const;
};
