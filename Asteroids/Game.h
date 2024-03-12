#pragma once

#include <iostream>
#include "Meteor.h"
#include "Player.h"
#include "Background.h"
#include "Interaction.h"
#include <SFML/Graphics.hpp>

class Game
{
	sf::RectangleShape hpBar;
public:
	Game();
	void startGame();
};

