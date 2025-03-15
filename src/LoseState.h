#pragma once
#include "State.h"
#include "Psydp3Engine.h"

class LoseState :
	public State
{
protected:
	DrawingSurface surface2;
	DrawingSurface surface3;
	DrawingSurface surface4;
	DrawingSurface surface5;
	int surfaceNum;
public:
	LoseState(Psydp3Engine* e) : State(e), surface2(e), surface3(e), surface4(e), surface5(e), surfaceNum(0)
	{
		engine->setUpdateperiod(100);
		engine->uploadScore();
	}
	void virtSetupBackgroundBuffer() override;
	void virtKeyDown(int) override;
	void copyAllBackgroundBuffer() override;
	void virtMainLoopDoBeforeUpdate() override;
	void virtCreateSurfaces() override;
	void virtDrawStringsUnderneath() override;
	~LoseState();
};

