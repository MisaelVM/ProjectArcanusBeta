#include "LevelScene.h"

LevelScene::LevelScene(const std::string _sSceneName, const std::string _sNextScene,
	const std::string sceneTextures[], const int nTextures, const std::map<std::string, sf::Texture> sourceTextures,
	sf::Music& sceneMusic,
	const float playerPosX, const float playerPosY, const std::string playerTexture,
	const int rows, const int columns, const std::string textureArchive, const char* tilemapArchive)
	: sfMusic(sceneMusic) {
	bSceneEnd = false;
	sNextScene = _sNextScene;

	sSceneName = _sSceneName;

	camera = new sf::View(sf::FloatRect(0, 0, 800, 600));

	for (int i = 0; i < nTextures; i++)
		mSceneResourceTextures[sceneTextures[i]] = sourceTextures.at(sceneTextures[i]);

	sceneMap = new TileMap(rows, columns, textureArchive, tilemapArchive);

	startingPosX = playerPosX;
	startingPosY = playerPosY;

	player = Player::getInstance();
	player->refresh(playerPosX, playerPosY, mSceneResourceTextures[playerTexture]);

	dialogDisplayer = new DialogDisplayer("Sample text");
}

LevelScene::~LevelScene() {
	delete dialogDisplayer;
	delete sceneMap;
	delete camera;
}

char LevelScene::getCollision(const float x, const float y) {
	return sceneMap->GetChar(y / 35, x / 35);
}

const bool LevelScene::checkCollision(const char& tile) const {
	return (tile == '"') || (tile == '$')
		|| (tile == 'p') || (tile == 'm') || (tile == 'j') || (tile == 'k') || (tile == 'l') || (tile == 'o') || (tile == 'r')
		|| (tile == 'G') || (tile == 'R') || (tile == 'L');
}

void LevelScene::checkTrigger(const char& tile) {
	switch (tile) {
	case 'n':
		startingPosX = player->getPosition().x;
		startingPosY = player->getPosition().y;
		startingPosY += 10;
		end();
		break;
	}
}

void LevelScene::checkcamera() {
	if (ceil(player->getPosition().x / 35) <= 12 && ceil(player->getPosition().y / 35) <= 10)
		camera->setCenter(sf::Vector2f(400.0f, 335.0f));
	else if (ceil(player->getPosition().x / 35) >= 109 && ceil(player->getPosition().y / 35) >= 70)
		camera->setCenter(sf::Vector2f(3800.0f, 2430.0f));
	else if (ceil(player->getPosition().x / 35) >= 109 && ceil(player->getPosition().y / 35) <= 10)
		camera->setCenter(sf::Vector2f(3800.0f, 335.0f));
	else if (ceil(player->getPosition().x / 35) <= 109 && ceil(player->getPosition().y / 35) >= 70)
		camera->setCenter(sf::Vector2f(400.0f, 2430.0f));
	else if (ceil(player->getPosition().x / 35) >= 109)
		camera->setCenter(sf::Vector2f(3800.0f, player->getPosition().y));
	else if (ceil(player->getPosition().y / 35) >= 70)
		camera->setCenter(sf::Vector2f(player->getPosition().x, 2430.0f));
	else if (ceil(player->getPosition().x / 35) <= 12)
		camera->setCenter(sf::Vector2f(400.0f, player->getPosition().y));
	else if (ceil(player->getPosition().y / 35) <= 10)
		camera->setCenter(sf::Vector2f(player->getPosition().x, 335.0f));
	else
		camera->setCenter(player->getPosition());
}

void LevelScene::getPlayerInput(bool input[4], const float& fElapsedTime) {
	sf::Vector2f vfVelocitySense(0, 0);
	sf::Vector2i viLastSense = player->getLastSense();
	float playerSpeed = player->getMovementSpeed();
	if (input[0]) { vfVelocitySense.x = -1.f; viLastSense.x = -1; viLastSense.y = 0; }
	if (input[1]) { vfVelocitySense.x = 1.f; viLastSense.x = 1; viLastSense.y = 0; }
	if (input[2]) { vfVelocitySense.y = -1.f; viLastSense.x = 0; viLastSense.y = -1; }
	if (input[3]) { vfVelocitySense.y = 1.f; viLastSense.x = 0; viLastSense.y = 1; }

	sf::Vector2f vfNewVelocitySense = vfVelocitySense * fElapsedTime;

	// --- COLLISIONS REQUIRE SOME FIXING! ---
	if (vfNewVelocitySense.x <= 0) {
		if (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y + 0.9f * 35.f))) {
			vfVelocitySense.x = 0.f;
			std::cout << "CollisionLeft\n";
		}
	}
	else {
		if (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 20.f, player->getHitboxPosition().y)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 20.f, player->getHitboxPosition().y + 0.9f * 35.f))) {
			vfVelocitySense.x = 0.f;
			std::cout << "CollisionRight\n";
		}
	}
	//
	if (vfNewVelocitySense.y <= 0) {
		if (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y + vfNewVelocitySense.y)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 0.9f * 20.f, player->getHitboxPosition().y + vfNewVelocitySense.y))) {
			vfVelocitySense.y = 0.f;
			std::cout << "CollisionUp\n";
		}
	}
	else {
		if (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y + vfNewVelocitySense.y + 35.f)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 0.9f * 20.f, player->getHitboxPosition().y + vfNewVelocitySense.y + 35.f))) {
			vfVelocitySense.y = 0.f;
			std::cout << "CollisionDown\n";
		}
	}

	std::cout << "Player Position: (" << player->getPosition().x << ", " << player->getPosition().y << ")\n";
	std::cout << "Hitbox Position: (" << player->getHitboxPosition().x << ", " << player->getHitboxPosition().y << ")\n";
	std::cout << "Current Tile: " << getCollision(player->getPosition().x, player->getPosition().y) << "\n";
	std::cout << "Collision Left: " << (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y + 0.9f * 35.f))) << "\n";
	std::cout << "Collision Right: " << (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 20.f, player->getHitboxPosition().y)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 20.f, player->getHitboxPosition().y + 0.9f * 35.f))) << "\n";
	std::cout << "Collision Up: " << (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y + vfNewVelocitySense.y)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 0.9f * 20.f, player->getHitboxPosition().y + vfNewVelocitySense.y))) << "\n";
	std::cout << "Collision Down: " << (checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x, player->getHitboxPosition().y + vfNewVelocitySense.y + 35.f)) || checkCollision(getCollision(player->getHitboxPosition().x + vfNewVelocitySense.x + 0.9f * 20.f, player->getHitboxPosition().y + vfNewVelocitySense.y + 35.f))) << "\n";

	player->setPlayerInput(vfVelocitySense, viLastSense);
	checkTrigger(getCollision(player->getHitboxPosition().x, player->getHitboxPosition().y));
}

std::string LevelScene::getNextScene() const {
	return sNextScene;
}

const bool LevelScene::getEnd() const {
	return bSceneEnd;
}

void LevelScene::save(const float x, const float y) {
	startingPosX = player->getPosition().x + x;
	startingPosY = player->getPosition().y + y;
}

void LevelScene::update(const float& fElapsedTime) {
	cutscene.processCommand(fElapsedTime);

	bEnabledInput = cutscene.UserInputEnabled();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && bEnabledInput) {
		cutscene.addCommand(new MoveCommand(player, 1000, 1000, 3.f));
		cutscene.addCommand(new MoveCommand(player, 1500, 1000, 3.f));
		cutscene.addCommand(new DialogCommand("Hola hola", dialogDisplayer));
		cutscene.addCommand(new DialogCommand("Probando\nProbando", dialogDisplayer));
		cutscene.addCommand(new MoveCommand(player, 1500, 1500, 3.f));
		cutscene.addCommand(new DialogCommand("Random dialogue 1", dialogDisplayer));
		cutscene.addCommand(new DialogCommand("Testing commands", dialogDisplayer));
		cutscene.addCommand(new MoveCommand(player, 1000, 1000, 3.f));
		cutscene.addCommand(new DialogCommand("Final command", dialogDisplayer));
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && dialogDisplayer->checkShowing()) {
			dialogDisplayer->dontShow();
		}
	}

	player->update(fElapsedTime);
	checkcamera();// Set of camera position by the player position
}

void LevelScene::awake() {
	bSceneEnd = false;
	sfMusic.play();
	sfMusic.setLoop(true);
	sfMusic.setVolume(50.f);
	player->setPosition(startingPosX, startingPosY);
}

void LevelScene::end() {
	if (!bSceneEnd) {
		save();
		bSceneEnd = true;
		sfMusic.stop();
	}
}

void LevelScene::end(const float x, const float y) {
	if (!bSceneEnd) {
		save(x, y);
		bSceneEnd = true;
		sfMusic.stop();
	}
}

void LevelScene::draw(sf::RenderTarget* sfTarget) {
	sceneMap->Displaytilemap(sfTarget, camera->getCenter());
	player->draw(sfTarget);
	dialogDisplayer->display(sfTarget, camera->getCenter().x, camera->getCenter().y);
	sfTarget->setView(*camera);
}