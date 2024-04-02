#include "Game.h"

Game::Game() {
	// Load the font for displaying text
	alegreyaSans.loadFromFile("AlegreyaSansSC-ExtraBold.ttf");
	m_textState.setFont(alegreyaSans);
	m_textState.setString("");
	m_textState.setPosition(Constants::windowWidth / 2.0f - 100.f, Constants::windowHeight / 2.0f);
	m_textState.setCharacterSize(32);
	m_textState.setFillColor(sf::Color::White);


	// Create an instance of EntityManager to manage game entities
	m_entityManager = new EntityManager();
}

void Game::startGame()
{
	// Create the game window
	sf::RenderWindow gameWindow{ {Constants::windowWidth, Constants::windowHeight},
		"Asteroids" };
	gameWindow.setFramerateLimit(60);
	reset();
	// Main game loop
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);

		// Check for user input to exit the game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;

		// Check for user input to reset the game
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
			reset();
		}

		if (m_gameState == GameState::Playing) {
			m_entityManager->startSpawning(); // Start spawning meteors
			m_entityManager->update(); // Update entity positions and states
			if (*m_playersHealth <= 0) { 
				m_gameState = GameState::GameOver; // Change game state to Game Over if player's health is zero
			}
			m_entityManager->interaction(); // Handle interactions between entities
			m_entityManager->refresh(); // Remove destroyed entities
			m_entityManager->draw(gameWindow); // Draw entities on the game window
		}
		else if (m_gameState == GameState::GameOver) {
			m_textState.setString("Game Over!"); // Display "Game Over!" message
			gameWindow.draw(m_textState);
		}

		gameWindow.display();
	}
}


void Game::reset() {
	// Clear all entities from the entity manager
	m_entityManager->clear(); 
	m_entityManager->create<Background>(0.f, 0.f);
	// Create a player entity and a health bar entity
	m_playersHealth = m_entityManager->create<HealthBar>(*m_entityManager->create<Player>(Constants::windowWidth/2, Constants::windowHeight / 2))->getHealth();
	// Set the game state to Playing
	m_gameState = GameState::Playing;
}