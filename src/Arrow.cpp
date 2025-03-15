#include "header.h"
#include "Arrow.h"
#include "BaseEngine.h"
#include "Psydp3Engine.h"

void Arrow::virtDraw()
{
	i = new ImageTracking(getXCentre(), getYCentre(), getEngine()->getCurrentMouseX(), getEngine()->getCurrentMouseY());

	SimpleImage image = ImageManager::loadImage("arrow.png");
	setSize(image.getWidth(), image.getHeight());
	if (isVisible())
	{
		image.renderImageApplyingMapping(getEngine(), getEngine()->getForegroundSurface(),
			m_iCurrentScreenX + m_iStartDrawPosX, m_iCurrentScreenY + m_iStartDrawPosY, m_iDrawWidth, m_iDrawHeight, i);
	}
	delete i;
}

void Arrow::virtDoUpdate(int)
{
	this->redrawDisplay();
}
