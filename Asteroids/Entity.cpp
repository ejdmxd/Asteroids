#include "Entity.h"


sf::FloatRect Entity::getBoundingBox() const {
	return m_sprite.getGlobalBounds();
}

sf::Vector2f Entity::getCentre() const {
	auto box = getBoundingBox();
	return { box.width / 2.0f, box.height / 2.0f };
}

float Entity::x() const {
	return m_sprite.getPosition().x;
}

float Entity::y() const {
	return m_sprite.getPosition().y;
}

float Entity::left() const {
	auto box = getBoundingBox();
	return x() - box.width / 2.0f;
}

float Entity::right() const {
	auto box = getBoundingBox();
	return x() - box.width / 2.0f;
}

float Entity::top() const {
	auto box = getBoundingBox();
	return y() - box.height / 2.0f;
}

float Entity::bottom() const {
	auto box = getBoundingBox();
	return y() + box.height / 2.0f;
}

void Entity::destroy() {
	m_destoyed = true;
}

bool Entity::isDestroyed() const {
	return m_destoyed;
}