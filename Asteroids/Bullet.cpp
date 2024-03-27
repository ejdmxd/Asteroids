#include "Bullet.h"

sf::Texture Bullet::m_texture;

Bullet::Bullet(MovingEntity* entity) {
	m_texture.loadFromFile("bullet.png");
	m_sprite.setTexture(m_texture);
	m_velocity = normalize(entity->getVelocity()) * Constants::bulletSpeed;
	m_sprite.setPosition(entity->x(), entity->y());
	m_sprite.setOrigin(getCentre());

}

void Bullet::moveUp()
{
}

void Bullet::moveDown()
{
}

void Bullet::moveLeft()
{
}

void Bullet::moveRight()
{
}

void Bullet::loseHealth()
{
}

void Bullet::update()
{
	m_sprite.move(m_velocity);
	if (y() < 0 - 100 || y() > Constants::windowHeight + 100 || x() < 0 - 100 || x() > Constants::windowWidth + 100) {
		m_destoyed = true;
	}
}

void Bullet::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
