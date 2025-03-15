#include "header.h"
#include "StartupState.h"
#include "RunningState.h"
#include "Psydp3Engine.h"
#include "Slider.h"

#include <fstream>
#include <vector>
#include <string>

void StartupState::virtSetupBackgroundBuffer()
{
	ifstream file;

	SimpleImage interior = ImageManager::loadImage("interior.png");
	interior.renderImage(engine->getBackgroundSurface(), 0, 0, 0, 0, interior.getWidth(), interior.getHeight());
	engine->drawBackgroundString(475, 200, "PRESS ENTER TO BEGIN", 0xFFFFFF);

	file.open("HighScore.txt");
	file >> engine->highScore;
	file.close();

	file.open("Numbers.txt");
	file >> engine->numberTiles;
	file.close();
	
	engine->numberTiles.setTopLeftPositionOnScreen(390, 510);
	engine->numberTiles.drawAllTiles(engine, engine->getBackgroundSurface());

	engine->circuitTiles.setTopLeftPositionOnScreen(402, 440);
	engine->circuitTiles.drawAllTiles(engine, engine->getBackgroundSurface());
}

void StartupState::virtKeyDown(int iKeyCode)
{
	switch (iKeyCode)
	{
	case SDLK_LSHIFT:
	{
		DisplayableObject* slider = engine->getDisplayableObject(0);
		ofstream file;
		file.open("SliderPos.txt");
		file << slider->getDrawingRegionLeft() << std::endl;
		file << slider->getDrawingRegionTop();
		file.close();
		break;
	}
	case SDLK_LCTRL:
	{
		DisplayableObject* slider = engine->getDisplayableObject(0);
		ifstream file;
		int x, y;
		file.open("SliderPos.txt");
		file >> x;
		file >> y;
		file.close();
		slider->setPosition(x, y);
		break;
	}
	case 13:
	{
		ofstream file;
		file.open("Numbers.txt");
		file << engine->numberTiles;
		file.close();
		engine->setState(new RunningState(engine));
		break;
	}
	case SDLK_DELETE:
	{
		if (engine->name.length() > 0)
			engine->name.erase(engine->name.length() - 1);
		break;
	}
	}
	if (iKeyCode >= 32 && iKeyCode <= 126)
	{
		engine->name += iKeyCode;
	}
}

void StartupState::virtDrawStringsUnderneath()
{
	char buf[128];
	sprintf(buf, "HIGH SCORE: %05d", engine->highScore);
	engine->drawForegroundString(510, 325, buf, 0xFFFFFF);

	sprintf(buf, "NAME: %s", engine->name.c_str());
	engine->drawForegroundString(25, 36, buf, 0xFFFFFF);
}


void StartupState::virtMouseDown(int iButton, int iX, int iY)
{
	switch (iButton)
	{
	case SDL_BUTTON_LEFT:
		if (engine->numberTiles.isValidTilePosition(iX, iY))
		{
			int mapX = engine->numberTiles.getMapXForScreenX(iX);
			int mapY = engine->numberTiles.getMapYForScreenY(iY);
			int value = engine->numberTiles.getMapValue(mapX, mapY);
			engine->numberTiles.setAndRedrawMapValueAt(mapX, mapY, (value + 1) % 5, engine, engine->getBackgroundSurface());
			engine->redrawDisplay();
		}
		break;
	}

}

void StartupState::virtInitialiseObjects()
{
	engine->drawableObjectsChanged();

	engine->destroyOldObjects(true);

	engine->createObjectArray(1);

	engine->storeObjectInArray(0, new Slider(engine, &engine->circuitTiles));

	engine->setAllObjectsVisible(true);
}

void StartupState::copyAllBackgroundBuffer()
{
	engine->getForegroundSurface()->copyEntireSurface(engine->getBackgroundSurface());
}

void StartupState::virtCreateSurfaces()
{
	engine->getOForegroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
	engine->getOBackgroundSurface()->createSurface(engine->getWindowWidth(), engine->getWindowHeight());
}

ifstream& operator>>(ifstream& ifs, NumberTiles& t)
{
	vector<string> array;
	string row;
	while (ifs >> row)
		array.push_back(row);

	for (int i = 0; i < t.getMapHeight(); i++)
		for (int j = 0; j < t.getMapWidth(); j++)
			t.setMapValue(j, i, (int)(array[i][j] - '0'));

	return ifs;
}

ofstream& operator<<(ofstream& ofs, NumberTiles& t)
{
	for (int i = 0; i < t.getMapHeight(); i++)
	{
		if (i > 0)
			ofs << endl;
		for (int j = 0; j < t.getMapWidth(); j++)
			ofs << t.getMapValue(j, i);
	}
	return ofs;
}
