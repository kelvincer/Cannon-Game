#pragma once

#include "../Constants.h"
#include "raylib.h"

class Cannon
{
    const float cannonRadius = 35;
    const float cannonWidth = CANNON_BARREL;
    const float cannonHeight = 20;
    float rotation;

public:
    void draw();
    float getCannonRadius() const;
    float getCannonHeight() const;
    float getCannonWidth() const;
    float getRotation() const;
    void setRotation(float rotation);
};
