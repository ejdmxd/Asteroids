#include "Game.h"

Game::Game() {
}

void Game::startGame()
{
	sf::RenderWindow gameWindow{ {Constants::windowWidth, Constants::windowHeight},
		"Asteroids" };
	gameWindow.setFramerateLimit(60);
	EntityManager* manager = new EntityManager();

	manager->create<Background>(0.f, 0.f);
	manager->create<Meteor>(300.f, 300.f);
	manager->create<Meteor>(500.f, 500.f);
	manager->create<HealthBar>(manager->create<Player>(10, 10));
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;
		manager->startSpawning();
		manager->update();	
		manager->interaction();
		manager->refresh();
		manager->draw(gameWindow);
		gameWindow.display();
	}
}
