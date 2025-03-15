#include "header.h"
#include "NumberTiles.h"

void NumberTiles::virtDrawTileAt(
	BaseEngine* pEngine,
	DrawingSurface* pSurface,
	int iMapX, int iMapY,
	int iStartPositionScreenX, int iStartPositionScreenY) const
{
	int iMapValue = getMapValue(iMapX, iMapY);
	
	std::string imagePath = "";

	switch (iMapValue) {
	case 0: imagePath = "1.png"; break;
	case 1: imagePath = "2.png"; break;
	case 2: imagePath = "3.png"; break;
	case 3: imagePath = "4.png"; break;
	case 4: imagePath = "5.png"; break;
	}

	SimpleImage image = ImageManager::loadImage(imagePath);
	image.renderImage(pEngine->getBackgroundSurface(), 0, 0, iStartPositionScreenX, iStartPositionScreenY,
		image.getWidth(), image.getHeight());
}
