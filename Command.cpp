#include "Command.h"

Command::Command() {
	bStarted = false;
	bCompleted = false;
}

const bool Command::checkStarted() const {
	return bStarted;
}

const bool Command::checkCompleted() const {
	return bCompleted;
}