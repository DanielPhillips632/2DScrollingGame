#include "header.h"
#include "Enemy.h"
#include "Attack.h"
#include "Player.h"
#include "BaseEngine.h"

void Enemy::virtDraw()
{
	std::string imageString;
	switch (getEngine()->getModifiedTime() / 100 % 4)
	{
	case 0:
		imageString = "ship1.png";
		break;
	case 1:
		imageString = "ship2.png";
		break;
	case 2:
		imageString = "ship3.png";
		break;
	case 3:
		imageString = "ship4.png";
		break;
	}
	image = ImageManager::loadImage(imageString);
	setSize(image.getWidth(), image.getHeight());
	if (isVisible())
		image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX + m_iStartDrawPosX, m_iCurrentScreenY + m_iStartDrawPosY, m_iDrawWidth, m_iDrawHeight, 0);
	else
	{
		GameObject* player = dynamic_cast<GameObject*>(getEngine()->getDisplayableObject(0));
		if (player->isTimeToAct())
			setVisible(true);
	}
}

void Enemy::virtDoUpdate(int)
{
	if (isVisible() && isTimeToAct())
	{
		Player* player = dynamic_cast<Player*>(getEngine()->getDisplayableObject(0));
		int yPos;

		int xDistance = getXCentre() - player->getXCentre();

		if (player->getXCentre() > getEngine()->getWindowWidth() / 2)
		{
			if (player->movingUp)
				yPos = player->getDrawingRegionTop() - (xDistance / 3);
			else if (player->movingDown)
				yPos = player->getDrawingRegionTop() + (xDistance / 3);
			else
				yPos = player->getDrawingRegionTop();
			if (yPos < 0)
				yPos = 0;
			else if (yPos > getEngine()->getWindowHeight() - m_iDrawHeight - 155)
				yPos = getEngine()->getWindowHeight() - m_iDrawHeight - 155;
		}
		else
			yPos = rand() % (getEngine()->getWindowHeight() - m_iDrawHeight - 155);

		setPosition(m_iCurrentScreenX, yPos);
		getEngine()->appendObjectToArray(new Attack(getEngine(), getDrawingRegionLeft() - 55, getDrawingRegionTop() + 35, level));
		setTimeToAct(spawnInterval);
	}
	this->redrawDisplay();
}
