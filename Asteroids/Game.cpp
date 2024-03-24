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
	m_playersHealth = manager->create<HealthBar>(*manager->create<Player>(10, 10))->getHealth();
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;
		if (m_gameState == GameState::Playing) {
			manager->startSpawning();
			manager->update();
			if (*m_playersHealth <= 0) {
				m_gameState = GameState::GameOver;
			}
			manager->interaction();
			manager->refresh();
			manager->draw(gameWindow);
		}
		else if (m_gameState == GameState::GameOver) {
			//TODO
		}
		gameWindow.display();
	}
}
