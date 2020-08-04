#pragma once

#include "Entity.h"

class Command {
private:

protected:
	bool bStarted;
	bool bCompleted;

public:
	Command();

	const bool checkStarted() const;
	const bool checkCompleted() const;

	virtual void start() = 0;
	virtual void update(const float& fElapsedTime) = 0;
};