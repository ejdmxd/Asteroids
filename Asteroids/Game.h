#pragma once

#include <iostream>
#include "Background.h"
#include "EntityManager.h"
#include "GameState.h"
#include <SFML/Graphics.hpp>

// The Game class manages the overall game state and runs the main game loop.
// It controls the flow of the game and handles initialization, updating, and rendering of game entities.
class Game
{
	GameState m_gameState{ GameState::Playing };
	float* m_playersHealth;
	sf::Text m_textState;
	sf::Font alegreyaSans;
	EntityManager* m_entityManager;
public:
	Game();
	void startGame();
	void reset();
	GameState getGameState() { return m_gameState;  }
};

