#include "header.h"
#include "RunningState.h"
#include "WinState.h"
#include "LoseState.h"
#include "Player.h"
#include "Enemy.h"
#include "PauseSymbol.h"
#include "ExampleDragableObjects.h"
#include "Attack.h"
#include "MST.h"

void RunningState::virtSetupBackgroundBuffer()
{
	SimpleImage outdoors = ImageManager::loadImage("outdoors.png");
	outdoors.renderImage(engine->getBackgroundSurface(), 0, 0, 0, 0, outdoors.getWidth(), outdoors.getHeight());

	engine->score = 0;
	engine->offset = 0;
}


void RunningState::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();

	engine->destroyOldObjects(true);

	engine->createObjectArray(1);

	engine->storeObjectInArray(0, new Player(engine, lives));

	engine->appendObjectToArray(new Enemy(engine, level));

	engine->appendObjectToArray(new PauseSymbol(engine));

	MST* tree = new MST(engine);
	engine->appendObjectToArray(tree);

	engine->setAllObjectsVisible(true);

	tree->setVisible(false);
}

void RunningState::virtKeyDown(int iKeyCode)
{
	Attack* ufo;
	switch (iKeyCode)
	{
	case 13:
		if (!engine->isPaused())
			engine->pause();
		else
			engine->unpause();
		break; 
	case SDLK_LEFT:
		engine->scroll.xModifier -= engine->scrollAmount;
		engine->redrawDisplay();
		break;
	case SDLK_RIGHT:
		engine->scroll.xModifier += engine->scrollAmount;
		engine->redrawDisplay();
		break;
	case SDLK_UP:
		engine->scroll.yModifier -= engine->scrollAmount;
		engine->redrawDisplay();
		break;
	case SDLK_DOWN:
		engine->scroll.yModifier += engine->scrollAmount;
		engine->redrawDisplay();
		break;
	case SDLK_SPACE:
		engine->scroll.xModifier = 0;
		engine->scroll.yModifier = 0;
		engine->zoom.xStretch = 1;
		engine->zoom.yStretch = 1;
		engine->zoom.xCompress = 1;
		engine->zoom.yCompress = 1;
		engine->redrawDisplay();
		break;
	case SDLK_LSHIFT:
		engine->scrollAmount = 50;
		break;
	case SDLK_LCTRL:
		DisplayableObject* tree = dynamic_cast<DisplayableObject*>(engine->getDisplayableObject(3));
		tree->setVisible(!tree->isVisible());
	}
}

void RunningState::virtKeyUp(int iKeyCode)
{
	switch (iKeyCode)
	{
	case SDLK_LSHIFT:
		engine->scrollAmount = 10;
		break;
	}
}

void RunningState::virtMouseDown(int iButton, int iX, int iY)
{
	int iOldPosX = engine->convertClickedToVirtualPixelXPosition(iX);
	int iOldPosY = engine->convertClickedToVirtualPixelYPosition(iY);

	if (iButton == 1)
		engine->zoom.stretch();
	else if (iButton == 3)
		engine->zoom.compress();

	int iNewPosX = engine->convertClickedToVirtualPixelXPosition(iX);
	int iNewPosY = engine->convertClickedToVirtualPixelYPosition(iY);

	engine->scroll.xModifier += iNewPosX - iOldPosX;
	engine->scroll.yModifier += iNewPosY - iOldPosY;

	engine->redrawDisplay();
}

void RunningState::virtDrawStringsUnderneath()
{
	char buf[128];

	sprintf(buf, "SCORE: %d", engine->score);
	if (!engine->isPaused())
	{
		engine->score++;
		if (engine->score % 1000 == 0)
			level++;

		Enemy* enemy = dynamic_cast<Enemy*>(engine->getDisplayableObject(1));
		if (engine->score == 4000) // Level 5
		{
			enemy->spawnInterval = 800;
		}
		else if (engine->score == 5000) // Level 6
		{
			enemy->spawnInterval = 600;
		}
		else if (level == 7)
		{
			engine->setState(new WinState(engine));
			return;
		}
	}
	engine->drawForegroundString(1100, 25, buf, 0x000000, NULL);

	sprintf(buf, "LIVES: %d", lives);
	engine->drawForegroundString(30, 25, buf, 0x000000, NULL);

	sprintf(buf, "LEVEL: %d / 6", level);
	engine->drawForegroundString(550, 650, buf, 0xFFFFFF, NULL);
}

void RunningState::virtMainLoopDoBeforeUpdate()
{
	if (!engine->isPaused())
	{
		engine->offset = (engine->offset + level) % engine->getWindowWidth();
		engine->redrawDisplay();
	}
	if (lives <= 0)
	{
		engine->setState(new LoseState(engine));
	}
}

void RunningState::copyAllBackgroundBuffer()
{
	engine->getForegroundSurface()->copyRectangleFrom(engine->getBackgroundSurface(), 0, 0, engine->getWindowWidth(), engine->getWindowHeight(), engine->offset, 0);
	engine->getForegroundSurface()->copyRectangleFrom(engine->getBackgroundSurface(), engine->getWindowWidth() - engine->offset, 0, engine->getWindowWidth(), engine->getWindowHeight(), engine->offset - engine->getWindowWidth(), 0);
}

void RunningState::virtCreateSurfaces()
{
	engine->getOForegroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	engine->getOBackgroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
}

RunningState::~RunningState()
{
	engine->scroll.xModifier = 0;
	engine->scroll.yModifier = 0;
	engine->zoom.xStretch = 1;
	engine->zoom.yStretch = 1;
	engine->zoom.xCompress = 1;
	engine->zoom.yCompress = 1;
}
