#include "header.h"
#include "StartupState.h"
#include "WinState.h"
#include "Psydp3Engine.h"
#include "Arrow.h"

void WinState::virtSetupBackgroundBuffer()
{
	SimpleImage celebration = ImageManager::loadImage("celebration.jpg");
	celebration.renderImage(engine->getBackgroundSurface(), 0, 0, 0, 0, celebration.getWidth(), celebration.getHeight());
	engine->drawBackgroundString(575, 300, "YOU WIN!", 0x000000);
	engine->drawBackgroundString(400, 400, "PRESS ENTER TO RETURN TO MENU", 0x000000);

	engine->uploadScore();
}

void WinState::virtKeyDown(int iKeyCode)
{
	switch (iKeyCode)
	{
	case 13:
		engine->setState(new StartupState(engine)); break;
	}
}

void WinState::copyAllBackgroundBuffer()
{
	engine->getForegroundSurface()->copyEntireSurface(engine->getBackgroundSurface());


	virtInitialiseObjects();
}

void WinState::virtCreateSurfaces()
{
	engine->getOForegroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	engine->getOBackgroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
}

void WinState::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();

	engine->destroyOldObjects(true);

	engine->createObjectArray(1);

	engine->storeObjectInArray(0, new Arrow(50, 50, engine));

	engine->appendObjectToArray(new Arrow(1150, 50, engine));

	engine->appendObjectToArray(new Arrow(50, 550, engine));

	engine->appendObjectToArray(new Arrow(1150, 550, engine));

	engine->setAllObjectsVisible(true);
}
