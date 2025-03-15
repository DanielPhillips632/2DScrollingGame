#pragma once
#include "TileManager.h"
class CircuitTiles :
    public TileManager
{
public:
    CircuitTiles() : TileManager(57, 62, 8, 1) {}

    virtual void virtDrawTileAt(
        BaseEngine* pEngine,
        DrawingSurface* pSurface,
        int iMapX, int iMapY,
        int iStartPositionScreenX, int iStartPositionScreenY) const override;
};

