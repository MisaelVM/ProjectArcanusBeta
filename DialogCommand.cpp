#include "DialogCommand.h"

DialogCommand::DialogCommand(const std::string &dialog, DialogDisplayer *dialogbox) {
	dialogBox = dialogbox;
	sDialog = dialog;
}

void DialogCommand::start() {
	bStarted = true;
	dialogBox->changeText(sDialog);
	dialogBox->show();
}

void DialogCommand::update(const float &fElapsedTime) {
	if (!dialogBox->checkShowing())
		bCompleted = true;
}