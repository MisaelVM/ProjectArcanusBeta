#pragma once

#include "MoveCommand.h"

class DialogDisplayer {
private:
	bool bShowingDialog;

	std::unique_ptr<sf::Font> sfFont;
	sf::Text sfText;

	sf::RectangleShape box;

public:
	DialogDisplayer(std::string dialog);

	const bool checkShowing() const;

	void show();
	void dontShow();

	void changeText(const std::string& newText);
	void display(sf::RenderTarget* sfTarget, float x, float y);
};