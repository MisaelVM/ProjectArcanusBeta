#pragma once

#include "DialogDisplayer.h"

class DialogCommand : public Command {
private:
	std::shared_ptr<DialogDisplayer> dialogBox;
	std::string sDialog;

public:
	DialogCommand(const std::string &dialog, std::shared_ptr<DialogDisplayer> dialogbox);

	void start();
	void update(const float &fElapsedTime);
};