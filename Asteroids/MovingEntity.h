#pragma once
#include "Entity.h"

class MovingEntity : public Entity
{
protected:
	sf::Vector2f m_velocity;
public:
	virtual void moveDown() = 0;
	virtual void moveUp() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
};

