#pragma once
#include "State.h"
#include "Psydp3Engine.h"

class RunningState :
    public State
{
protected:
    int lives = 10;
    int level = 1;
public:
    RunningState(Psydp3Engine* e) : State(e) {}
    void virtSetupBackgroundBuffer() override;
    void virtInitialiseObjects() override;
    void virtKeyDown(int) override;
    void virtDrawStringsUnderneath() override;
    void virtMainLoopDoBeforeUpdate() override;
    void copyAllBackgroundBuffer() override;
    void virtCreateSurfaces() override;
    void virtKeyUp(int) override;
    void virtMouseDown(int, int, int) override;
    ~RunningState();
};

