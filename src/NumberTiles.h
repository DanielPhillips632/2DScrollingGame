#pragma once
#include "TileManager.h"
class NumberTiles :
    public TileManager
{
public:
    NumberTiles() : TileManager(26, 26, 20, 3) {}

    virtual void virtDrawTileAt(
        BaseEngine* pEngine,
        DrawingSurface* pSurface,
        int iMapX, int iMapY,
        int iStartPositionScreenX, int iStartPositionScreenY) const override;
};

