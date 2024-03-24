#pragma once
#include "Player.h"
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


