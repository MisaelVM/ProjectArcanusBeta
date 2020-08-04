#include "MoveCommand.h"

MoveCommand::MoveCommand(Entity* _object, const float x, const float y, const float duration) {
	fStartingPosX = 0.f;
	fStartingPosY = 0.f;
	fTargetPosX = x;
	fTargetPosY = y;
	fTimeChrono = 0.f;
	fDuration = duration;
	object = _object;
}

void MoveCommand::start() {
	bStarted = true;
	fStartingPosX = object->getPosition().x;
	fStartingPosY = object->getPosition().y;
}

void MoveCommand::update(const float& fElapsedTime) {
	fTimeChrono += fElapsedTime;
	float t = fTimeChrono / fDuration;
	if (t > 1.f) t = 1.f;

	object->setPosition((fTargetPosX - fStartingPosX) * t + fStartingPosX, (fTargetPosY - fStartingPosY) * t + fStartingPosY);
	object->setVelocity((fTargetPosX - fStartingPosX) / fDuration, (fTargetPosY - fStartingPosY) / fDuration);
	if (fTimeChrono >= fDuration) {
		object->setVelocity(0.f, 0.f);
		bCompleted = true;
	}
}