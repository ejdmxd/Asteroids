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
public:
	Game();
	void startGame();
	GameState getGameState() { return m_gameState;  }
};

