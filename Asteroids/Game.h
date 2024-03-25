#pragma once

#include <iostream>
#include "Background.h"
#include "Interaction.h"
#include "HealthBar.h"
#include "EntityManager.h"
#include <SFML/Graphics.hpp>


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

