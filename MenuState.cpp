#include "MenuState.h"

// States - MainMenu

MainMenu::MainMenu(MenuScene* _context) : context(_context) {
	lButtons.push_back(new Button("Start demo", "font1.ttf", 200.f, 40.f));
	lButtons[0]->setButtonPosition(100.f, 100.f);
	lButtons[0]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[0]->setTextColor(sf::Color::Black);
	lButtons[0]->setTextSize(20);

	lButtons.push_back(new Button("Settings", "font1.ttf", 200.f, 40.f));
	lButtons[1]->setButtonPosition(100.f, 200.f);
	lButtons[1]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[1]->setTextColor(sf::Color::Black);
	lButtons[1]->setTextSize(20);

	lButtons.push_back(new Button("Quit Game", "font1.ttf", 200.f, 40.f));
	lButtons[2]->setButtonPosition(100.f, 300.f);
	lButtons[2]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[2]->setTextColor(sf::Color::Black);
	lButtons[2]->setTextSize(20);
}

void MainMenu::checkButtonClick(const int x, const int y) {
	if (lButtons[0]->GetClick(x, y, context->getCamera())) {
		context->setNextScene("LEVEL_1");
		context->end();
	}
	else if (lButtons[1]->GetClick(x, y, context->getCamera())) {
		context->setState(new SettingsMenu(context));
	}
	else if (lButtons[2]->GetClick(x, y, context->getCamera())) {
		context->setGameExit();
	}
}

void MainMenu::draw(sf::RenderTarget* sfTarget) {
	for (auto ref : lButtons)
		ref->draw(sfTarget);
}

// States - PauseMenu

PauseMenu::PauseMenu(MenuScene* _context) : context(_context) {
	lButtons.push_back(new Button("Back to Game", "font1.ttf", 200.f, 40.f));
	lButtons[0]->setButtonPosition(100.f, 100.f);
	lButtons[0]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[0]->setTextColor(sf::Color::Black);
	lButtons[0]->setTextSize(20);

	lButtons.push_back(new Button("Settings", "font1.ttf", 200.f, 40.f));
	lButtons[1]->setButtonPosition(100.f, 200.f);
	lButtons[1]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[1]->setTextColor(sf::Color::Black);
	lButtons[1]->setTextSize(20);

	lButtons.push_back(new Button("Quit to Title", "font1.ttf", 200.f, 40.f));
	lButtons[2]->setButtonPosition(100.f, 300.f);
	lButtons[2]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[2]->setTextColor(sf::Color::Black);
	lButtons[2]->setTextSize(20);
}

void PauseMenu::checkButtonClick(const int x, const int y) {
	if (lButtons[0]->GetClick(x, y, context->getCamera())) {
		context->setNextScene("LEVEL_1");
		context->end();
	}
	else if (lButtons[1]->GetClick(x, y, context->getCamera())) {
		context->setState(new SettingsMenu(context));
	}
	else if (lButtons[2]->GetClick(x, y, context->getCamera())) {
		context->setNextScene("MAIN_MENU");
		context->end();
	}
}

void PauseMenu::draw(sf::RenderTarget* sfTarget) {
	for (auto ref : lButtons)
		ref->draw(sfTarget);
}

// States - SettingsMenu

SettingsMenu::SettingsMenu(MenuScene* _context) : context(_context) {
	lButtons.push_back(new Button("Video Settings", "font1.ttf", 200.f, 40.f));
	lButtons[0]->setButtonPosition(100.f, 100.f);
	lButtons[0]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[0]->setTextColor(sf::Color::Black);
	lButtons[0]->setTextSize(20);

	lButtons.push_back(new Button("Controls", "font1.ttf", 200.f, 40.f));
	lButtons[1]->setButtonPosition(100.f, 200.f);
	lButtons[1]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[1]->setTextColor(sf::Color::Black);
	lButtons[1]->setTextSize(20);

	lButtons.push_back(new Button("Done", "font1.ttf", 200.f, 40.f));
	lButtons[2]->setButtonPosition(100.f, 300.f);
	lButtons[2]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[2]->setTextColor(sf::Color::Black);
	lButtons[2]->setTextSize(20);
}

void SettingsMenu::checkButtonClick(const int x, const int y) {
	if (lButtons[0]->GetClick(x, y, context->getCamera())) { // Video Settings
		context->setState(new VideoSettingsMenu(context));
	}
	else if (lButtons[1]->GetClick(x, y, context->getCamera())) { // Controls
		context->setState(new ControlSettingsMenu(context));
	}
	else if (lButtons[2]->GetClick(x, y, context->getCamera())) {
		if (context->getSceneName() == "MAIN_MENU")
			context->setState(new MainMenu(context));
		else
			context->setState(new PauseMenu(context));
	}
}

void SettingsMenu::draw(sf::RenderTarget* sfTarget) {
	for (auto ref : lButtons)
		ref->draw(sfTarget);
}

// States - VideoSettingsMenu

VideoSettingsMenu::VideoSettingsMenu(MenuScene* _context) : context(_context) {
	resolution = "NULL"; framerateLimit = "NULL"; verticalSync = "NULL";

	// Resolution
	lButtons.push_back(new Button("640x480", "font1.ttf", 60.f, 30.f));
	lButtons[0]->setButtonPosition(170.f, 100.f);
	lButtons[0]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[0]->setTextColor(sf::Color::Black);
	lButtons[0]->setTextSize(20);

	lButtons.push_back(new Button("800x600", "font1.ttf", 60.f, 30.f));
	lButtons[1]->setButtonPosition(240.f, 100.f);
	lButtons[1]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[1]->setTextColor(sf::Color::Black);
	lButtons[1]->setTextSize(20);

	lButtons.push_back(new Button("960x720", "font1.ttf", 60.f, 30.f));
	lButtons[2]->setButtonPosition(310.f, 100.f);
	lButtons[2]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[2]->setTextColor(sf::Color::Black);
	lButtons[2]->setTextSize(20);

	lButtons.push_back(new Button("1280x720", "font1.ttf", 60.f, 30.f));
	lButtons[3]->setButtonPosition(380.f, 100.f);
	lButtons[3]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[3]->setTextColor(sf::Color::Black);
	lButtons[3]->setTextSize(20);

	lButtons.push_back(new Button("1366x768", "font1.ttf", 60.f, 30.f));
	lButtons[4]->setButtonPosition(450.f, 100.f);
	lButtons[4]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[4]->setTextColor(sf::Color::Black);
	lButtons[4]->setTextSize(20);

	lButtons.push_back(new Button("1600x900", "font1.ttf", 60.f, 30.f));
	lButtons[5]->setButtonPosition(520.f, 100.f);
	lButtons[5]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[5]->setTextColor(sf::Color::Black);
	lButtons[5]->setTextSize(20);

	lButtons.push_back(new Button("1920x1080", "font1.ttf", 60.f, 30.f));
	lButtons[6]->setButtonPosition(590.f, 100.f);
	lButtons[6]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[6]->setTextColor(sf::Color::Black);
	lButtons[6]->setTextSize(20);

	// FPS
	lButtons.push_back(new Button("30", "font1.ttf", 60.f, 30.f));
	lButtons[7]->setButtonPosition(100.f, 150.f);
	lButtons[7]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[7]->setTextColor(sf::Color::Black);
	lButtons[7]->setTextSize(20);

	lButtons.push_back(new Button("40", "font1.ttf", 60.f, 30.f));
	lButtons[8]->setButtonPosition(170.f, 150.f);
	lButtons[8]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[8]->setTextColor(sf::Color::Black);
	lButtons[8]->setTextSize(20);

	lButtons.push_back(new Button("50", "font1.ttf", 60.f, 30.f));
	lButtons[9]->setButtonPosition(240.f, 150.f);
	lButtons[9]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[9]->setTextColor(sf::Color::Black);
	lButtons[9]->setTextSize(20);

	lButtons.push_back(new Button("60", "font1.ttf", 60.f, 30.f));
	lButtons[10]->setButtonPosition(310.f, 150.f);
	lButtons[10]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[10]->setTextColor(sf::Color::Black);
	lButtons[10]->setTextSize(20);

	lButtons.push_back(new Button("100", "font1.ttf", 60.f, 30.f));
	lButtons[11]->setButtonPosition(380.f, 150.f);
	lButtons[11]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[11]->setTextColor(sf::Color::Black);
	lButtons[11]->setTextSize(20);

	lButtons.push_back(new Button("120", "font1.ttf", 60.f, 30.f));
	lButtons[12]->setButtonPosition(450.f, 150.f);
	lButtons[12]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[12]->setTextColor(sf::Color::Black);
	lButtons[12]->setTextSize(20);

	lButtons.push_back(new Button("144", "font1.ttf", 60.f, 30.f));
	lButtons[13]->setButtonPosition(520.f, 150.f);
	lButtons[13]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[13]->setTextColor(sf::Color::Black);
	lButtons[13]->setTextSize(20);

	lButtons.push_back(new Button("Unlimited", "font1.ttf", 60.f, 30.f));
	lButtons[14]->setButtonPosition(590.f, 150.f);
	lButtons[14]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[14]->setTextColor(sf::Color::Black);
	lButtons[14]->setTextSize(20);

	// Vertical Sync
	lButtons.push_back(new Button("Enable", "font1.ttf", 60.f, 30.f));
	lButtons[15]->setButtonPosition(520.f, 200.f);
	lButtons[15]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[15]->setTextColor(sf::Color::Black);
	lButtons[15]->setTextSize(20);

	lButtons.push_back(new Button("Disable", "font1.ttf", 60.f, 30.f));
	lButtons[16]->setButtonPosition(590.f, 200.f);
	lButtons[16]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[16]->setTextColor(sf::Color::Black);
	lButtons[16]->setTextSize(20);

	// Done
	lButtons.push_back(new Button("Done", "font1.ttf", 60.f, 30.f));
	lButtons[17]->setButtonPosition(590.f, 300.f);
	lButtons[17]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[17]->setTextColor(sf::Color::Black);
	lButtons[17]->setTextSize(20);
}

void VideoSettingsMenu::checkButtonClick(const int x, const int y) {
	// Resolution
	if (lButtons[0]->GetClick(x, y, context->getCamera()))
		resolution = "640 480";
	else if (lButtons[1]->GetClick(x, y, context->getCamera()))
		resolution = "800 600";
	else if (lButtons[2]->GetClick(x, y, context->getCamera()))
		resolution = "960 720";
	else if (lButtons[3]->GetClick(x, y, context->getCamera()))
		resolution = "1280 720";
	else if (lButtons[4]->GetClick(x, y, context->getCamera()))
		resolution = "1366 768";
	else if (lButtons[5]->GetClick(x, y, context->getCamera()))
		resolution = "1600 900";
	else if (lButtons[6]->GetClick(x, y, context->getCamera()))
		resolution = "1920 1080";
	// FPS
	else if (lButtons[7]->GetClick(x, y, context->getCamera()))
		framerateLimit = lButtons[7]->getText();
	else if (lButtons[8]->GetClick(x, y, context->getCamera()))
		framerateLimit = lButtons[8]->getText();
	else if (lButtons[9]->GetClick(x, y, context->getCamera()))
		framerateLimit = lButtons[9]->getText();
	else if (lButtons[10]->GetClick(x, y, context->getCamera()))
		framerateLimit = lButtons[10]->getText();
	else if (lButtons[11]->GetClick(x, y, context->getCamera()))
		framerateLimit = lButtons[11]->getText();
	else if (lButtons[12]->GetClick(x, y, context->getCamera()))
		framerateLimit = lButtons[12]->getText();
	else if (lButtons[13]->GetClick(x, y, context->getCamera()))
		framerateLimit = lButtons[13]->getText();
	else if (lButtons[14]->GetClick(x, y, context->getCamera()))
		framerateLimit = "0";
	// Vertical Sync
	else if (lButtons[15]->GetClick(x, y, context->getCamera()))
		verticalSync = "1";
	else if (lButtons[16]->GetClick(x, y, context->getCamera()))
		verticalSync = "0";
	// Done
	else if (lButtons[17]->GetClick(x, y, context->getCamera())) {
		if (resolution != "NULL" && framerateLimit != "NULL" && verticalSync != "NULL") {
			std::ofstream newConfiguration("Resources/BaseWindow.ini", std::ofstream::trunc);
			if (newConfiguration.is_open()) {
				newConfiguration << "[GameEngine.sfWindow]\n";
				newConfiguration << "windowTitle=TheHolyQuest\n";
				newConfiguration << "windowSize=" << resolution << "\n";
				newConfiguration << "framerateLimit=" << framerateLimit << "\n";
				newConfiguration << "verticalSyncEnabled=" << verticalSync << "\n";
			}
			newConfiguration.close();
		}
		context->setState(new SettingsMenu(context));
	}
}

void VideoSettingsMenu::draw(sf::RenderTarget* sfTarget) {
	for (auto ref : lButtons)
		ref->draw(sfTarget);
}

// States - ControlSettingsMenu

ControlSettingsMenu::ControlSettingsMenu(MenuScene* _context) : context(_context) {
	input[0] = '\0'; input[1] = '\0'; input[2] = '\0'; input[3] = '\0';

	lButtons.push_back(new Button("Move Up", "font1.ttf", 80.f, 30.f));
	lButtons[0]->setButtonPosition(100.f, 100.f);
	lButtons[0]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[0]->setTextColor(sf::Color::Black);
	lButtons[0]->setTextSize(20);

	lButtons.push_back(new Button("Move Down", "font1.ttf", 80.f, 30.f));
	lButtons[1]->setButtonPosition(100.f, 150.f);
	lButtons[1]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[1]->setTextColor(sf::Color::Black);
	lButtons[1]->setTextSize(20);

	lButtons.push_back(new Button("Move Left", "font1.ttf", 80.f, 30.f));
	lButtons[2]->setButtonPosition(100.f, 200.f);
	lButtons[2]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[2]->setTextColor(sf::Color::Black);
	lButtons[2]->setTextSize(20);

	lButtons.push_back(new Button("Move Right", "font1.ttf", 80.f, 30.f));
	lButtons[3]->setButtonPosition(100.f, 250.f);
	lButtons[3]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[3]->setTextColor(sf::Color::Black);
	lButtons[3]->setTextSize(20);

	lButtons.push_back(new Button("Done", "font1.ttf", 80.f, 30.f));
	lButtons[4]->setButtonPosition(100.f, 300.f);
	lButtons[4]->getRectangle()->setFillColor(sf::Color::Yellow);
	lButtons[4]->setTextColor(sf::Color::Black);
	lButtons[4]->setTextSize(20);
}

void ControlSettingsMenu::checkInput(size_t n) {
	input[n] = '\0';
	while (!input[n])
		for (int i = 0; i < 26; i++)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(i)))
				input[n] = 'A' + (char)i;
}

void ControlSettingsMenu::checkButtonClick(const int x, const int y) {
	if (lButtons[0]->GetClick(x, y, context->getCamera()))
		checkInput(0);
	else if (lButtons[1]->GetClick(x, y, context->getCamera()))
		checkInput(1);
	else if (lButtons[2]->GetClick(x, y, context->getCamera()))
		checkInput(2);
	else if (lButtons[3]->GetClick(x, y, context->getCamera()))
		checkInput(3);
	else if (lButtons[4]->GetClick(x, y, context->getCamera())) {
		if (input[0] && input[1] && input[2] && input[3]) {
			std::ofstream newInputConfiguration("Resources/BaseInput.ini", std::ofstream::trunc);
			if (newInputConfiguration.is_open()) {
				newInputConfiguration << "[GameEngine.gameInput]\n";
				newInputConfiguration << "ESCAPE=" << "Escape" << "\n";
				newInputConfiguration << "MOVE_UP=" << input[0] << "\n";
				newInputConfiguration << "MOVE_DOWN=" << input[1] << "\n";
				newInputConfiguration << "MOVE_LEFT=" << input[2] << "\n";
				newInputConfiguration << "MOVE_RIGHT=" << input[3] << "\n";
			}
			newInputConfiguration.close();
		}
		context->setNewSettings();
		context->setState(new SettingsMenu(context));
	}
}

void ControlSettingsMenu::draw(sf::RenderTarget* sfTarget) {
	for (auto ref : lButtons)
		ref->draw(sfTarget);
}