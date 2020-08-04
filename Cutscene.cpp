#include "Cutscene.h"

Cutscene::Cutscene() {
	bUserControlEnabled = true;
}

bool Cutscene::UserInputEnabled() const {
	return bUserControlEnabled;
}

void Cutscene::addCommand(Command* cmd) {
	lCutsceneCommands.push_back(cmd);
}

void Cutscene::processCommand(float const& fElapsedTime) {
	bUserControlEnabled = lCutsceneCommands.empty();

	if (!lCutsceneCommands.empty()) {
		if (!lCutsceneCommands.front()->checkCompleted()) {
			if (!lCutsceneCommands.front()->checkStarted()) {
				lCutsceneCommands.front()->start();
			}
			else
				lCutsceneCommands.front()->update(fElapsedTime);
		}
		else {
			delete lCutsceneCommands.front();
			lCutsceneCommands.pop_front();
		}
	}
}