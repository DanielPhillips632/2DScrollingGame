#pragma once
#include "DisplayableObject.h"
#include "SimpleImage.h"

class GameObject :
    public DisplayableObject
{
protected:
    SimpleImage image;
public:
    GameObject(int xStart, int yStart, BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00 = true) : 
        DisplayableObject(xStart, yStart, pEngine, iWidth, iHeight, useTopLeftFor00) {}

    bool collidedWith(GameObject* pObject);

    bool nonEmptyPixel(int realX, int realY);

    void setTimeToAct(int iDelay);

    bool isTimeToAct();

    int targetTick;
};


