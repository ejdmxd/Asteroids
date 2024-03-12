#include "Game.h"

Game::Game() {
	hpBar.setFillColor(sf::Color(255, 0, 0, 128));
	hpBar.setSize(sf::Vector2f((float)Constants::playersHealth*5.f, 20.f));
	hpBar.setPosition(10.f, 10.f);
}

void Game::startGame()
{
	std::cout << "Zdravim" << std::endl;
	sf::RenderWindow gameWindow{ {Constants::windowWidth, Constants::windowHeight},
		"Asteroids" };
	gameWindow.setFramerateLimit(60);
	Background* background = new Background(0, 0);
	Meteor* meteor = new Meteor(300, 300);
	Meteor* meteor1 = new Meteor(500, 500);
	Player* player = new Player(10, 10);
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;
		background->draw(gameWindow);
		meteor->draw(gameWindow);
		meteor1->draw(gameWindow);
		player->draw(gameWindow);
		gameWindow.draw(hpBar); //In future I should consider to make this health bar as a class, then I could add it to entities and also add interaction between it and another entities
		player->update();
		handleCollision(*player, *meteor);
		handleCollision(*player, *meteor1);
		gameWindow.display();
	}
	delete background;
}
