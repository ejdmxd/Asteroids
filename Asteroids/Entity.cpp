#include "Entity.h"

//Return the bounding box of the entity
sf::FloatRect Entity::getBoundingBox() const {
	return m_sprite.getGlobalBounds();
}

//Return the center of the entity's bounding box
sf::Vector2f Entity::getCentre() const {
	auto box = getBoundingBox();
	return { box.width / 2.0f, box.height / 2.0f };
}

//Return the x-coordinate of the entity's position
float Entity::x() const {
	return m_sprite.getPosition().x;
}

//Return the y-coordinate of the entity's position
float Entity::y() const {
	return m_sprite.getPosition().y;
}

//Return edges of entity's bounging box
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

//Functions for maniging destroyed state
void Entity::destroy() {
	m_destoyed = true;
}

bool Entity::isDestroyed() const {
	return m_destoyed;
}