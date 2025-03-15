#include "header.h"
#include "StartupState.h"
#include "LoseState.h"
#include "Psydp3Engine.h"

void LoseState::virtSetupBackgroundBuffer()
{;
	surface2.mySDLLockSurface();
	surface3.mySDLLockSurface();
	surface4.mySDLLockSurface();
	surface5.mySDLLockSurface();

	SimpleImage apocalypse = ImageManager::loadImage("apocalypse.jpg");
	SimpleImage fire;

	apocalypse.renderImage(engine->getBackgroundSurface(), 0, 0, 0, 0, apocalypse.getWidth(), apocalypse.getHeight());
	fire = ImageManager::loadImage("fire1.png");
	fire.renderImageWithMask(engine->getBackgroundSurface(), 0, 0, 150, 390, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(engine->getBackgroundSurface(), 0, 0, 610, 450, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(engine->getBackgroundSurface(), 0, 0, 1100, 310, fire.getWidth(), fire.getHeight());
	
	apocalypse.renderImage(&surface2, 0, 0, 0, 0, apocalypse.getWidth(), apocalypse.getHeight());
	fire = ImageManager::loadImage("fire2.png");
	fire.renderImageWithMask(&surface2, 0, 0, 150, 390, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface2, 0, 0, 610, 450, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface2, 0, 0, 1100, 310, fire.getWidth(), fire.getHeight());

	apocalypse.renderImage(&surface3, 0, 0, 0, 0, apocalypse.getWidth(), apocalypse.getHeight());
	fire = ImageManager::loadImage("fire3.png");
	fire.renderImageWithMask(&surface3, 0, 0, 150, 390, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface3, 0, 0, 610, 450, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface3, 0, 0, 1100, 310, fire.getWidth(), fire.getHeight());

	apocalypse.renderImage(&surface4, 0, 0, 0, 0, apocalypse.getWidth(), apocalypse.getHeight());
	fire = ImageManager::loadImage("fire4.png");
	fire.renderImageWithMask(&surface4, 0, 0, 150, 390, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface4, 0, 0, 610, 450, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface4, 0, 0, 1100, 310, fire.getWidth(), fire.getHeight());

	apocalypse.renderImage(&surface5, 0, 0, 0, 0, apocalypse.getWidth(), apocalypse.getHeight());
	fire = ImageManager::loadImage("fire5.png");
	fire.renderImageWithMask(&surface5, 0, 0, 150, 390, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface5, 0, 0, 610, 450, fire.getWidth(), fire.getHeight());
	fire.renderImageWithMask(&surface5, 0, 0, 1100, 310, fire.getWidth(), fire.getHeight());


	surface2.mySDLUnlockSurface();
	surface3.mySDLUnlockSurface();
	surface4.mySDLUnlockSurface();
	surface5.mySDLUnlockSurface();
}

void LoseState::virtKeyDown(int iKeyCode)
{
	switch (iKeyCode)
	{
	case 13:
		engine->setState(new StartupState(engine)); break;
	}
}

void LoseState::copyAllBackgroundBuffer()
{
	engine->getForegroundSurface()->copyEntireSurface(engine->getBackgroundSurface());
}

void LoseState::virtMainLoopDoBeforeUpdate()
{
	surfaceNum = (surfaceNum + 1) % 5;
	switch (surfaceNum)
	{
	case 0: engine->setBackgroundSurface(engine->getOBackgroundSurface()); break;
	case 1: engine->setBackgroundSurface(&surface2); break;
	case 2: engine->setBackgroundSurface(&surface3); break;
	case 3: engine->setBackgroundSurface(&surface4); break;
	case 4: engine->setBackgroundSurface(&surface5); break;
	}
	engine->redrawDisplay();
}

void LoseState::virtCreateSurfaces()
{
	engine->getOForegroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	engine->getOBackgroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	surface2.createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	surface3.createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	surface4.createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	surface5.createSurface(engine->getWindowWidth(), engine->getWindowHeight());
}

void LoseState::virtDrawStringsUnderneath()
{
	engine->drawForegroundString(575, 100, "YOU LOSE!", 0);
	engine->drawForegroundString(400, 175, "PRESS ENTER TO RETURN TO MENU", 0);
}

LoseState::~LoseState()
{
	engine->setBackgroundSurface(engine->getOBackgroundSurface());
	engine->setUpdateperiod(10);
}
