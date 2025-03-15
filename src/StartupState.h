#pragma once
#include "State.h"
#include "Psydp3Engine.h"

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class StartupState : public State
{
public:
	StartupState(Psydp3Engine* e) : State(e) {}
	void virtSetupBackgroundBuffer() override;
	void virtKeyDown(int) override;
	void virtDrawStringsUnderneath() override;
	void virtMouseDown(int, int, int);
	void virtInitialiseObjects() override;
	void copyAllBackgroundBuffer() override;
	void virtCreateSurfaces() override;

	friend ifstream& operator>>(ifstream& ifs, NumberTiles& v);
	friend ofstream& operator<<(ofstream& ofs, NumberTiles& obj);
};

