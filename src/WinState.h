#pragma once
#include "State.h"
#include "Psydp3Engine.h"

class WinState : public State
{
public:
	WinState(Psydp3Engine* e) : State(e) {}
	void virtSetupBackgroundBuffer() override;
	void virtKeyDown(int) override;
	void copyAllBackgroundBuffer() override;
	void virtCreateSurfaces() override;
	void virtInitialiseObjects() override;
};