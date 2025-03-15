#include "header.h"
#include "Slider.h"
#include "BaseEngine.h"

void Slider::virtDraw()
{
	getEngine()->drawForegroundOval(
		m_iCurrentScreenX, m_iCurrentScreenY,
		m_iCurrentScreenX + m_iDrawWidth - 1,
		m_iCurrentScreenY + m_iDrawHeight - 1,
		0x631483);
}

void Slider::virtDoUpdate(int)
{
	if (getEngine()->isKeyPressed(SDLK_LEFT) && m_iCurrentScreenX > 402)
		m_iCurrentScreenX -= 2;
	if (getEngine()->isKeyPressed(SDLK_RIGHT) && m_iCurrentScreenX < 836)
		m_iCurrentScreenX += 2;

	int iTileX = circuitTiles->getMapXForScreenX(getXCentre());
	if (iTileX == 0)
		circuitTiles->setAndRedrawMapValueAt(7, 0, 1, getEngine(), getEngine()->getBackgroundSurface());
	else
		circuitTiles->setAndRedrawMapValueAt(7, 0, 0, getEngine(), getEngine()->getBackgroundSurface());

	this->redrawDisplay();
}
