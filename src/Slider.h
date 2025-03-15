#pragma once
#include "DisplayableObject.h"
#include "TileManager.h"
class Slider :
    public DisplayableObject
{
protected:
    bool beginning = true;
public:
    Slider(BaseEngine* pEngine, TileManager* pTileManager) : DisplayableObject(619, 440, pEngine, 62, 57), circuitTiles(pTileManager) {}
    void virtDraw() override;
    void virtDoUpdate(int) override;
    TileManager* circuitTiles;
};

