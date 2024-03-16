#pragma once

#include <iostream>
#include "Background.h"
#include "Interaction.h"
#include "HealthBar.h"
#include "EntityManager.h"
#include <SFML/Graphics.hpp>

class Game
{
	sf::RectangleShape hpBar;
public:
	Game();
	void startGame();
};

