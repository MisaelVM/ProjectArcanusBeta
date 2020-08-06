#include "DialogDisplayer.h"

DialogDisplayer::DialogDisplayer(std::string dialog) {
	bShowingDialog = false;

	sfFont = new sf::Font;
	sfFont->loadFromFile("Resources/font1.ttf");

	sfText.setFont(*sfFont);
	sfText.setString(dialog);
	sfText.setFillColor(sf::Color::Black);

	box = sf::RectangleShape(sf::Vector2f(750, 150));
	box.setFillColor(sf::Color::Yellow);
}

DialogDisplayer::~DialogDisplayer() {
	delete sfFont;
}

const bool DialogDisplayer::checkShowing() const {
	return bShowingDialog;
}

void DialogDisplayer::show() {
	bShowingDialog = true;
}

void DialogDisplayer::dontShow() {
	bShowingDialog = false;
}

void DialogDisplayer::changeText(const std::string& newText) {
	sfText.setString(newText);
}

void DialogDisplayer::display(sf::RenderTarget* sfTarget, float x, float y) {
	if (bShowingDialog) {
		sfText.setPosition(sf::Vector2f(x - 370, y + 130));
		box.setPosition(sf::Vector2f(x - 375, y + 125));
		sfTarget->draw(box);
		sfTarget->draw(sfText);
	}
}