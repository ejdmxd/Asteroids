#include "HealthBar.h"

HealthBar::HealthBar(Player& player) {
	m_playersHealth = player.getHealthPointer();
	hpBar.setFillColor(sf::Color(255, 0, 0, 128));
	hpBar.setSize(sf::Vector2f((float)Constants::playersHealth * 0.5f, 100.f));
	hpBar.setPosition(250.f, 50.f);
}

void HealthBar::update()
{
	// Checks if player's health has changed from the attribute
	if (hpBar.getSize().x != *m_playersHealth * 5.f) {
		hpBar.setSize(sf::Vector2f((float)*m_playersHealth * 0.5f, 20.f));
	}
	//If players health reachs zero, healthBar is marked for remove
	else if (*m_playersHealth == 0) {
		m_destoyed = true;
	}
}

void HealthBar::draw(sf::RenderWindow& window)
{
	window.draw(hpBar);
}

