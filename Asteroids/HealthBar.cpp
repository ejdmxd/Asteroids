#include "HealthBar.h"

HealthBar::HealthBar(Player& player) {
	m_playersHealth = player.getHealth();
	hpBar.setFillColor(sf::Color(255, 0, 0, 128));
	hpBar.setSize(sf::Vector2f((float)Constants::playersHealth * 0.5f, 100.f));
	std::cout << Constants::playersHealth * 0.5f << std::endl;
	hpBar.setPosition(250.f, 50.f);
}

void HealthBar::update()
{
	if (hpBar.getSize().x != *m_playersHealth * 5.f) {
		hpBar.setSize(sf::Vector2f((float)*m_playersHealth * 0.5f, 20.f));
	}
	else if (*m_playersHealth == 0) {
		m_destoyed = true;
	}
}

void HealthBar::draw(sf::RenderWindow& window)
{
	window.draw(hpBar);
}

