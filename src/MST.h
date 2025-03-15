#pragma once
#include "GameObject.h"
#include "DisplayableObject.h"
class MST :
    public GameObject
{
public:
    MST(BaseEngine* pEngine) : GameObject(100, 100, pEngine, 100, 100) {}
    void virtDraw() override;
};

