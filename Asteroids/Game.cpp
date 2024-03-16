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
	EntityManager* manager = new EntityManager();

	manager->create<Background>(0, 0);
	manager->create<Meteor>(300, 300);
	manager->create<Meteor>(500, 500);
	manager->create<HealthBar>(manager->create<Player>(10, 10));
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;
		manager->update();	
		manager->refresh();
		manager->draw(gameWindow);
		gameWindow.display();
	}
}
