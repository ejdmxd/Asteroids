#include "Game.h"

Game::Game() {
	alegreyaSans.loadFromFile("AlegreyaSansSC-ExtraBold.ttf");
	m_textState.setFont(alegreyaSans);
	m_textState.setString("");
	m_textState.setPosition(Constants::windowWidth / 2.0f - 100.f, Constants::windowHeight / 2.0f);
	m_textState.setCharacterSize(32);
	m_textState.setFillColor(sf::Color::White);

	m_entityManager = new EntityManager();
}

void Game::startGame()
{
	sf::RenderWindow gameWindow{ {Constants::windowWidth, Constants::windowHeight},
		"Asteroids" };
	gameWindow.setFramerateLimit(60);
	reset();
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
			reset();
		}

		if (m_gameState == GameState::Playing) {
			m_entityManager->startSpawning();
			m_entityManager->update();
			if (*m_playersHealth <= 0) {
				m_gameState = GameState::GameOver;
			}
			m_entityManager->interaction();
			m_entityManager->refresh();
			m_entityManager->draw(gameWindow);
		}
		else if (m_gameState == GameState::GameOver) {
			m_textState.setString("Game Over!");
			gameWindow.draw(m_textState);
		}

		gameWindow.display();
	}
}


void Game::reset() {
	m_entityManager->clear();
	m_entityManager->create<Background>(0.f, 0.f);
	m_playersHealth = m_entityManager->create<HealthBar>(*m_entityManager->create<Player>(Constants::windowWidth/2, Constants::windowHeight / 2))->getHealth();
	m_gameState = GameState::Playing;
}