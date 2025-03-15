#pragma once
#include "FilterPoints.h"
#include "ZoomPoints.h"
class ScrollPoints :
    public FilterPoints
{
protected:
    ZoomPoints* zoom;
public:
    ScrollPoints(ZoomPoints* pZoom) : zoom(pZoom) {}
    bool filter(DrawingSurface* surface, int& xVirtual, int& yVirtual, unsigned int& uiColour) override;
    int xModifier = 0;
    int yModifier = 0;
    int filterConvertRealToVirtualYPosition(int y) override;
    int filterConvertRealToVirtualXPosition(int x) override;
    int filterConvertVirtualToRealYPosition(int yVirtual) override;
    int filterConvertVirtualToRealXPosition(int xVirtual) override;
};

