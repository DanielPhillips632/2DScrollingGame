#pragma once
class Psydp3Engine;

class State
{
protected:
	Psydp3Engine* engine;
public:
	State(Psydp3Engine* e) { engine = e; }
	virtual void virtSetupBackgroundBuffer();
	virtual void virtInitialiseObjects();
	virtual void virtKeyDown(int);
	virtual void virtDrawStringsUnderneath();
	virtual void virtMouseDown(int, int, int);
	virtual void virtMainLoopDoBeforeUpdate();
	virtual void copyAllBackgroundBuffer();
	virtual void virtCreateSurfaces();
	virtual void virtKeyUp(int iKeyCode);
	virtual ~State();
};

