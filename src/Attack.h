#pragma once
#include "GameObject.h"
#include "ImageManager.h"
class Attack :
    public GameObject
{
protected:
    double waveX = 0;
    double waveY;
public:
    Attack(BaseEngine* pEngine, int xStart, int yStart, int m) : GameObject(xStart, yStart, pEngine, 100, 100)
    { 
        image = ImageManager::loadImage("ufo1.png"); 
        mode = m;
        waveY = yStart;
    }
    void virtDraw() override;
    void virtDoUpdate(int) override;
    int mode = 1;
};

