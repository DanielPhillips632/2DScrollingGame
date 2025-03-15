#include "header.h"
#include "Attack.h"
#include "BaseEngine.h"
#include "Player.h"

void Attack::virtDraw()
{
	std::string imageString;
	switch (getEngine()->getModifiedTime() / 100 % 4)
	{
	case 0:
		imageString = "ufo1.png";
		break;
	case 1:
		imageString = "ufo2.png";
		break;
	case 2:
		imageString = "ufo3.png";
		break;
	case 3:
		imageString = "ufo4.png";
		break;
	}
	image = ImageManager::loadImage(imageString);
	setSize(image.getWidth(), image.getHeight());
	if (isVisible())
		image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX + m_iStartDrawPosX, m_iCurrentScreenY + m_iStartDrawPosY, m_iDrawWidth, m_iDrawHeight, 0);
}

void Attack::virtDoUpdate(int)
{
	if (!getEngine()->isPaused())
	{
		Player* player = dynamic_cast<Player*>(getEngine()->getDisplayableObject(0));

		if (mode > 3)
			mode = (rand() % 3) + 1;

		switch (mode)
		{
		case 1:
			m_iCurrentScreenX -= 8;
			break;
		case 2:
			m_iCurrentScreenX -= 5;
			if (m_iCurrentScreenX > player->getDrawingRegionLeft() + 60)
			{
				if (m_iCurrentScreenY < player->getDrawingRegionTop() + 35)
					m_iCurrentScreenY++;
				else if (m_iCurrentScreenY > player->getDrawingRegionTop() + 35)
					m_iCurrentScreenY--;
			}
			break;
		case 3:
			m_iCurrentScreenX -= 2;

			const double PI = 3.14159265358979323846;
			const double amplitude = 100.0;
			const double frequency = 0.05;

			m_iCurrentScreenY = (int)(waveY + amplitude * sin(2 * PI * frequency * waveX));
			waveX += 0.13;
			break;
		}	

		if (collidedWith(player))
		{
			player->lives--;
			getEngine()->removeDisplayableObject(this);
			delete this;
			return;
		}
		if (m_iCurrentScreenX <= -m_iDrawWidth)
		{
			getEngine()->removeDisplayableObject(this);
			delete this;
			return;
		}
	}
}
