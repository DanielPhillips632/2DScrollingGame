#include "header.h"
#include "GameObject.h"
#include "BaseEngine.h"
#include "UtilCollisionDetection.h"

bool GameObject::collidedWith(GameObject* pObject)
{
	if (pObject->isVisible() && CollisionDetection::checkRectangles(getDrawingRegionLeft(), getDrawingRegionRight(), getDrawingRegionTop(), getDrawingRegionBottom(),
		pObject->getDrawingRegionLeft(), pObject->getDrawingRegionRight(), pObject->getDrawingRegionTop(), pObject->getDrawingRegionBottom()))
	{
		for (int virtX = 0; virtX < image.getWidth(); virtX++)
		{
			for (int virtY = 0; virtY < image.getHeight(); virtY++)
			{
				if (image.getPixelColour(virtX, virtY) != 0)
				{
					int realX = m_iCurrentScreenX + virtX;
					int realY = m_iCurrentScreenY + virtY;
					if (pObject->nonEmptyPixel(realX, realY))
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool GameObject::nonEmptyPixel(int realX, int realY)
{
	int virtX = realX - m_iCurrentScreenX;
	int virtY = realY - m_iCurrentScreenY;

	if (virtX >= 0 && virtY >= 0 && virtX < image.getWidth() && virtY < image.getHeight() && image.getPixelColour(virtX, virtY) != 0)
		return true;
	return false;
}

void GameObject::setTimeToAct(int iDelay)
{
	targetTick = getEngine()->getModifiedTime() + iDelay;
}

bool GameObject::isTimeToAct()
{
	return getEngine()->getModifiedTime() >= targetTick;
}

