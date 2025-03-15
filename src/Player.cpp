#include "header.h"
#include "Player.h"
#include "Enemy.h"
#include "BaseEngine.h"

void Player::virtDraw()
{
	std::string imageString;
	switch (getEngine()->getModifiedTime() / 100 % 4)
	{
	case 0:
		imageString = "rocket1.png";
		break;
	case 1:
		imageString = "rocket2.png";
		break;
	case 2:
		imageString = "rocket3.png";
		break;
	case 3:
		imageString = "rocket4.png";
		break;
	}
	image = ImageManager::loadImage(imageString);
	setSize(image.getWidth(), image.getHeight());
	if (isVisible())
		image.renderImageWithMask(getEngine()->getForegroundSurface(), 0, 0, m_iCurrentScreenX + m_iStartDrawPosX, m_iCurrentScreenY + m_iStartDrawPosY, m_iDrawWidth, m_iDrawHeight, 0);
}

void Player::virtDoUpdate(int)
{
	if (!getEngine()->isPaused())
	{
		// Change position if player presses a key
		if (getEngine()->isKeyPressed('w') && m_iCurrentScreenY > 0)
		{
			m_iCurrentScreenY -= 3;
			movingUp = true;
		}
		else
			movingUp = false;
		if (getEngine()->isKeyPressed('s') && m_iCurrentScreenY < getEngine()->getWindowHeight() - m_iDrawHeight - 158)
		{
			m_iCurrentScreenY += 3;
			movingDown = true;
		}
		else
			movingDown = false;
		if (getEngine()->isKeyPressed('a') && m_iCurrentScreenX > 0)
			m_iCurrentScreenX -= 3;
		if (getEngine()->isKeyPressed('d') && m_iCurrentScreenX < getEngine()->getWindowWidth() - m_iDrawWidth)
			m_iCurrentScreenX += 3;

		GameObject* enemy = dynamic_cast<GameObject*>(getEngine()->getDisplayableObject(1));
		if (collidedWith(enemy))
		{
			lives--;
			enemy->setVisible(false);
			setTimeToAct(1000);
		}
	}
	this->redrawDisplay();
}
