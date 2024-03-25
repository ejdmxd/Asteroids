#include "Game.h"

Game::Game() {
	alegreyaSans.loadFromFile("AlegreyaSansSC-ExtraBold.ttf");
	m_textState.setFont(alegreyaSans);
	m_textState.setString("");
	m_textState.setPosition(Constants::windowWidth / 2.0f - 125.0f, Constants::windowHeight / 2.0f - 100.0f);
	m_textState.setCharacterSize(32);
	m_textState.setFillColor(sf::Color::White);
}

void Game::startGame()
{
	sf::RenderWindow gameWindow{ {Constants::windowWidth, Constants::windowHeight},
		"Asteroids" };
	gameWindow.setFramerateLimit(60);
	EntityManager* manager = new EntityManager();

	manager->create<Background>(0.f, 0.f);
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
			m_textState.setString("Game Over!");
			gameWindow.draw(m_textState);
		}

		gameWindow.display();
	}
}
