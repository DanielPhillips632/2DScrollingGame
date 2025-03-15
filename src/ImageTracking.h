#pragma once
#include "DrawingSurface.h"
#include "ImagePixelMapping.h"

class ImageTracking :
    public ImagePixelMapping
{
protected:
    int sourceX;
    int sourceY;
    int destX;
    int destY;
public:
    ImageTracking(int sx, int sy, int dx, int dy) : sourceX(sx), sourceY(sy), destX(dx), destY(dy) {}
    bool mapCoordinates(double& x, double& y, const SimpleImage& image) override;
};

