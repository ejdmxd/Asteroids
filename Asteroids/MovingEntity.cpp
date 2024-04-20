#include "MovingEntity.h"

void MovingEntity::setHealth(float health) {
	m_health = health;
}

void MovingEntity::setRotation(float rotation) {
	m_rotation = rotation;
	m_sprite.setRotation(m_rotation);
}