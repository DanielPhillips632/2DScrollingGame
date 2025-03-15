#include "header.h"
#include "CircuitTiles.h"

void CircuitTiles::virtDrawTileAt(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	unsigned int iColour = 0;
	int iMapValue = getMapValue(iMapX, iMapY);
	if (iMapValue == 0)
		iColour = 0x5E500D;
	else
		iColour = 0xFFFF00;

	if (iMapX == 0)
	{
		pSurface->drawRectangle(
			iStartPositionScreenX, // Left
			iStartPositionScreenY, // Top
			iStartPositionScreenX + getTileWidth() - 1, // Right
			iStartPositionScreenY + getTileHeight() - 1, // Bottom
			0x808080);
		pSurface->drawRectangle(
			iStartPositionScreenX + 10, // Left
			iStartPositionScreenY + 10, // Top
			iStartPositionScreenX + getTileWidth() - 11, // Right
			iStartPositionScreenY + getTileHeight() - 11, // Bottom
			0xFF0000);
	}
	else if (iMapX < 7)
	{
		pSurface->drawLine(iStartPositionScreenX,
			iStartPositionScreenY + (getTileHeight() / 2),
			iStartPositionScreenX + getTileWidth() - 1,
			iStartPositionScreenY + (getTileHeight() / 2), 0x808080);
	}
	else
	{
		pSurface->drawRectangle(
			iStartPositionScreenX, // Left
			iStartPositionScreenY, // Top
			iStartPositionScreenX + getTileWidth() - 1, // Right
			iStartPositionScreenY + getTileHeight() - 1, // Bottom
			iColour);
	}
}
