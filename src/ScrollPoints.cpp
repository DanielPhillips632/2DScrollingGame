#include "header.h"
#include "ScrollPoints.h"

bool ScrollPoints::filter(DrawingSurface* surface, int& xVirtual, int& yVirtual, unsigned int& uiColour)
{
	xVirtual += xModifier;
	yVirtual += yModifier;
	return zoom->filter(surface, xVirtual, yVirtual, uiColour);
}

int ScrollPoints::filterConvertVirtualToRealXPosition(int xVirtual)
{
	return zoom->filterConvertVirtualToRealXPosition(xVirtual + xModifier);
}

int ScrollPoints::filterConvertVirtualToRealYPosition(int yVirtual)
{
	return zoom->filterConvertVirtualToRealYPosition(yVirtual + yModifier);
}

int ScrollPoints::filterConvertRealToVirtualXPosition(int x)
{
	return zoom->filterConvertRealToVirtualXPosition(x) - xModifier;
}

int ScrollPoints::filterConvertRealToVirtualYPosition(int y)
{
	return zoom->filterConvertRealToVirtualYPosition(y) - yModifier;
}