#pragma once
#include "GameObject.h"
#include "ImageManager.h"
class Enemy :
    public GameObject
{
public:
    Enemy(BaseEngine* pEngine, int& l) : GameObject(1000, 225, pEngine, 100, 100), level(l)
    {
        image = ImageManager::loadImage("ship1.png"); 
        setTimeToAct(1000);
    }
    void virtDraw() override;
    void virtDoUpdate(int) override;
    int spawnInterval = 1000;
    int& level;
};