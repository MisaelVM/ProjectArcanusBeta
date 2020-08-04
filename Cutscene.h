#pragma once

#include "DialogCommand.h"

class Cutscene {
private:
	std::list<Command*> lCutsceneCommands;

	bool bUserControlEnabled;

public:
	Cutscene();

	bool UserInputEnabled() const;

	void addCommand(Command *cmd);
	void processCommand(float const &fElapsedTime);
};