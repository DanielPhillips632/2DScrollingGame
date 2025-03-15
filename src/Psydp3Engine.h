#pragma once
#include "BaseEngine.h"
#include "State.h"
#include "NumberTiles.h"
#include "CircuitTiles.h"
#include "ImagePixelMapping.h"
#include "ScrollPoints.h"
#include "ZoomPoints.h"

class Psydp3Engine : public BaseEngine
{
protected:
    State* state;
    bool beginning = true;
public:
    Psydp3Engine();
    ~Psydp3Engine();
    void virtSetupBackgroundBuffer() override;
    int virtInitialiseObjects() override;
    void setState(State* state);
    void virtKeyDown(int iKeyCode) override;
    void virtKeyUp(int iKeyCode) override;
    int highScore = 0;
    int score = 0;
    int offset = 0;
    std::string name = "";
    void virtDrawStringsUnderneath() override;
    void uploadScore();
    NumberTiles numberTiles;
    CircuitTiles circuitTiles;
    void virtMouseDown(int, int, int) override;
    void virtMainLoopDoBeforeUpdate() override;
    void copyAllBackgroundBuffer() override;
    void setUpdateperiod(int);
    void virtCreateSurfaces() override;
    void setBackgroundSurface(DrawingSurface*);
    DrawingSurface* getOBackgroundSurface();
    DrawingSurface* getOForegroundSurface();
    int virtInitialise() override;
    ScrollPoints scroll;
    ZoomPoints zoom;
    int scrollAmount = 10;
    int stretchCompress = 0;
};

