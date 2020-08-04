#pragma once

#include "DialogDisplayer.h"

class DialogCommand : public Command {
private:
	DialogDisplayer *dialogBox;
	std::string sDialog;

public:
	DialogCommand(const std::string &dialog, DialogDisplayer *dialogbox);

	void start();
	void update(const float &fElapsedTime);
};