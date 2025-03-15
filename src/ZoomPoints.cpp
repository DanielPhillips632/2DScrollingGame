#include "header.h"
#include "ZoomPoints.h"

bool ZoomPoints::filter(DrawingSurface* surface, int& xVirtual, int& yVirtual, unsigned int& uiColour)
{
	handleXthenY(surface, xVirtual, yVirtual, uiColour);
	return false;
}

void ZoomPoints::handleXthenY(DrawingSurface* surface, int xVirtual, int yVirtual, unsigned int& uiColour)
{
	if (xStretch > 1)
	{
		xVirtual *= xStretch;
		for (int i = 0; i < xStretch; i++)
			handleY(surface, xVirtual + i, yVirtual, uiColour);
	}
	else
	{
		xVirtual /= xCompress;
		handleY(surface, xVirtual, yVirtual, uiColour);
	}
}

void ZoomPoints::handleY(DrawingSurface* surface, int xVirtual, int yVirtual, unsigned int& uiColour)
{
	if (yStretch > 1)
	{
		yVirtual *= yStretch;
		for (int i = 0; i < yStretch; i++)
		{
			int yTest = yVirtual + i;
			if (pNextFilter->filter(surface, xVirtual, yTest, uiColour))
				surface->rawSetPixel(xVirtual, yTest, uiColour);
		}
	}
	else
	{
		yVirtual /= yCompress;
		if (pNextFilter->filter(surface, xVirtual, yVirtual, uiColour))
			surface->rawSetPixel(xVirtual, yVirtual, uiColour);
	}
}

void ZoomPoints::compress() 
{ 
	if (xStretch > 1)
		--xStretch; 
	else 
		++xCompress;
	if (yStretch > 1) 
		--yStretch;
	else 
		++yCompress;
}
void ZoomPoints::stretch() 
{
	if (xCompress > 1) 
		--xCompress; 
	else 
		++xStretch;
	if (yCompress > 1) 
		--yCompress; 
	else 
		++yStretch;
}

int ZoomPoints::filterConvertVirtualToRealXPosition(int xVirtual)
{
	if (xStretch > 1)
		return pNextFilter->filterConvertVirtualToRealXPosition(xVirtual * xStretch);
	else
		return pNextFilter->filterConvertVirtualToRealXPosition(xVirtual / xCompress);
}

int ZoomPoints::filterConvertVirtualToRealYPosition(int yVirtual)
{
	if (yStretch > 1)
		return pNextFilter->filterConvertVirtualToRealYPosition(yVirtual * yStretch);
	else
		return pNextFilter->filterConvertVirtualToRealYPosition(yVirtual / yCompress);
}

int ZoomPoints::filterConvertRealToVirtualXPosition(int xReal)
{
	xReal = pNextFilter->filterConvertRealToVirtualXPosition(xReal);
	if (xStretch > 1)
		return xReal / xStretch;
	else
		return xReal * xCompress;
}

int ZoomPoints::filterConvertRealToVirtualYPosition(int yReal)
{
	yReal = pNextFilter->filterConvertRealToVirtualYPosition(yReal);
	if (yStretch > 1)
		return yReal / yStretch;
	else
		return yReal * yCompress;
}