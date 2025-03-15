#pragma once
#include "DisplayableObject.h"

class PauseSymbol :
    public DisplayableObject
{
public:
    PauseSymbol(BaseEngine* pEngine) : DisplayableObject(200, 200, pEngine, 100, 200) {}
    void virtDraw() override;
};