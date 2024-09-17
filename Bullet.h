#pragma once

#include "raylib.h"
#include "raymath.h"
#include "Constants.h"

class Bullet
{
    float radius = 60.0f;
    Vector2 center;
    float rotation;

public:
    float getRadius() const;
    Vector2 getCenter();
    void draw();
    void setRotation(float rotation);
    float getRotation() const;
    void setCenter(float deltaR);
    bool isOutsideWindow();
};