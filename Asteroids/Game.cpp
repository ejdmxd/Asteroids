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
	HealthBar* healthBar = new HealthBar(*player);
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;
		background->draw(gameWindow);
		meteor->draw(gameWindow);
		meteor1->draw(gameWindow);
		player->draw(gameWindow);
		healthBar->draw(gameWindow);
		handleCollision(*player, *meteor);
		handleCollision(*player, *meteor1);
		player->update();
		healthBar->update();
		gameWindow.display();
	}
	delete background;
}
