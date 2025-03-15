#pragma once
#include "FilterPoints.h"
#include "DrawingSurface.h"
class ZoomPoints : public FilterPoints
{
public:
	FilterPoints* pNextFilter;
	int xStretch = 1, yStretch = 1, xCompress = 1, yCompress = 1;

	ZoomPoints(int xFactor, int yFactor, FilterPoints* pNextFilter = nullptr)
		: pNextFilter(pNextFilter)
	{}
	bool filter(DrawingSurface* surface, int& xVirtual, int& yVirtual, unsigned int& uiColour) override;
	void handleXthenY(DrawingSurface*, int, int, unsigned int&);
	void handleY(DrawingSurface*, int, int, unsigned int&);
	void compress();
	void stretch();
	int filterConvertVirtualToRealXPosition(int xVirtual) override;

	// Calculate real from virtual position - apply the stretch then any following filter
	int filterConvertVirtualToRealYPosition(int yVirtual) override;

	// These convert from a clicked location to a virtual pixel position in a surface
	int filterConvertRealToVirtualXPosition(int xReal) override;

	// These convert from a clicked location to a virtual pixel position in a surface
	int filterConvertRealToVirtualYPosition(int yReal) override;
};

