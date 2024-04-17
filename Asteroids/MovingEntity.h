#pragma once
#include "Entity.h"

class MovingEntity : public Entity
{
protected:
	sf::Vector2f m_velocity;
	float m_health;
	float m_rotation;
public:
	virtual void moveDown() = 0;
	virtual void moveUp() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void loseHealth() = 0;
	void setHealth(float health) { m_health = health; }
	float getHealth() { return m_health; }
	float* getHealthPointer() { return &m_health; }
	sf::Vector2f getVelocity() { return m_velocity;  }
	float getRotation() { return m_rotation; }
};

