#pragma once
#include "GameObject.h"
#include "SimpleImage.h"
#include "ImageTracking.h"

class Arrow :
    public DisplayableObject
{
public:
    Arrow(int x, int y, BaseEngine* pEngine) : DisplayableObject(x, y, pEngine, 100, 100) {}
    void virtDraw() override;
    void virtDoUpdate(int) override;
    ImageTracking* i;
};

