#include "header.h"
#include "Psydp3Engine.h"
#include "StartupState.h"
#include "RunningState.h"
#include "PauseSymbol.h"
#include "Player.h"

#include <fstream>

Psydp3Engine::Psydp3Engine() : zoom(0, 0, this), scroll(&zoom)
{
	state = new StartupState(this);
}

int Psydp3Engine::virtInitialise()
{
	getForegroundSurface()->setDrawPointsFilter(&scroll);

	return BaseEngine::virtInitialise();
}

void Psydp3Engine::virtSetupBackgroundBuffer()
{	
	state->virtSetupBackgroundBuffer();
}

int Psydp3Engine::virtInitialiseObjects()
{
	state->virtInitialiseObjects();

	return 0;
}

void Psydp3Engine::setState(State* s)
{
	destroyOldObjects(true);
	delete state;
	state = s;
	virtCreateSurfaces();
	lockAndSetupBackground();
	virtInitialiseObjects();
}

void Psydp3Engine::virtKeyDown(int iKeyCode)
{
	state->virtKeyDown(iKeyCode);
}

void Psydp3Engine::virtKeyUp(int iKeyCode)
{
	state->virtKeyUp(iKeyCode);
}

Psydp3Engine::~Psydp3Engine()
{
	delete state;
}


void Psydp3Engine::virtDrawStringsUnderneath()
{
	state->virtDrawStringsUnderneath();
}


void Psydp3Engine::uploadScore()
{
	std::ofstream file;
	if (score > highScore)
	{
		file.open("HighScore.txt");
		file << score;
		file.close();
	}
}


void Psydp3Engine::virtMouseDown(int iButton, int iX, int iY)
{
	state->virtMouseDown(iButton, iX, iY);
}


void Psydp3Engine::virtMainLoopDoBeforeUpdate()
{
	state->virtMainLoopDoBeforeUpdate();
}


void Psydp3Engine::copyAllBackgroundBuffer()
{
	state->copyAllBackgroundBuffer();
}

void Psydp3Engine::setUpdateperiod(int p)
{
	m_iDefaultUpdatePeriod = p;
}

void Psydp3Engine::virtCreateSurfaces()
{
	state->virtCreateSurfaces();
}

void Psydp3Engine::setBackgroundSurface(DrawingSurface* d)
{
	m_pBackgroundSurface = d;
}

DrawingSurface* Psydp3Engine::getOBackgroundSurface()
{
	return &m_oTheBackgroundSurface;
}

DrawingSurface* Psydp3Engine::getOForegroundSurface()
{
	return &m_oTheForegroundSurface;
}