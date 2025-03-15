#pragma once
#include "GameObject.h"
#include "SimpleImage.h"
#include "BaseEngine.h"

class Player :
    public GameObject
{
public:
    Player(BaseEngine* pEngine, int& l) : GameObject(200, 225, pEngine, 100, 100), lives(l) { image = ImageManager::loadImage("rocket1.png"); }
    void virtDraw() override;
    void virtDoUpdate(int) override;
    bool movingUp = false;
    bool movingDown = false;
    int& lives;
};

