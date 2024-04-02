#pragma once
#include "Player.h"

// The HealthBar class represents a graphical health bar displayed on the screen.
// It inherits from the Entity class and contains a pointer to the player's health variable.
class HealthBar : public Entity
{
	float* m_playersHealth;
	sf::RectangleShape hpBar;
public:
	HealthBar(Player& player);
	void update();
	void draw(sf::RenderWindow& window);
	float* getHealth() { return m_playersHealth;  }
};


