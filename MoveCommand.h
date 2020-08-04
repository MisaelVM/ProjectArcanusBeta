#pragma once

#include "Command.h"

class MoveCommand : public Command {
private:
	Entity *object;

	float fStartingPosX;
	float fStartingPosY;
	float fTargetPosX;
	float fTargetPosY;
	float fDuration;
	float fTimeChrono;

public:
	MoveCommand(Entity *_object, const float x, const float y, const float duration = 0.f);

	void start();
	void update(const float& fElapsedTime);
};