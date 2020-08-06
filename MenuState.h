#pragma once

#include "Scene.h"
#include "MenuScene.h"

class MenuScene;
class Button;

// -- STATE PATTERN --

class MenuState {
private:

public:
	virtual void checkButtonClick(const int x, const int y) = 0;
	virtual void draw(sf::RenderTarget* sfTarget) = 0;
};

// States

class MainMenu : public MenuState {
private:
	MenuScene* context;
	std::vector<Button*> lButtons;

public:
	MainMenu(MenuScene* _context);

	void checkButtonClick(const int x, const int y);
	void draw(sf::RenderTarget* sfTarget);
};


class PauseMenu : public MenuState {
private:
	MenuScene* context;
	std::vector<Button*> lButtons;

public:
	PauseMenu(MenuScene* _context);

	void checkButtonClick(const int x, const int y);
	void draw(sf::RenderTarget* sfTarget);
};

class SettingsMenu : public MenuState {
private:
	MenuScene* context;
	std::vector<Button*> lButtons;

public:
	SettingsMenu(MenuScene* _context);

	void checkButtonClick(const int x, const int y);
	void draw(sf::RenderTarget* sfTarget);
};

class VideoSettingsMenu : public MenuState {
private:
	MenuScene* context;
	std::vector<Button*> lButtons;

	std::string resolution;
	std::string framerateLimit;
	std::string verticalSync;

public:
	VideoSettingsMenu(MenuScene* _context);

	void checkButtonClick(const int x, const int y);
	void draw(sf::RenderTarget* sfTarget);
};

class ControlSettingsMenu : public MenuState {
private:
	MenuScene* context;
	std::vector<Button*> lButtons;

	char input[4];

	std::string resolution;
	std::string framerateLimit;
	std::string verticalSync;

public:
	ControlSettingsMenu(MenuScene* _context);

	void checkInput(size_t n);

	void checkButtonClick(const int x, const int y);
	void draw(sf::RenderTarget* sfTarget);
};