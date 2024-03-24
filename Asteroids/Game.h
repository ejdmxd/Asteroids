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
public:
	Game();
	void startGame();
	GameState getGameState() { return m_gameState;  }
};

