#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Movement.h"
#include "Constants.h"

class Entity
{
protected:
	sf::Sprite m_sprite;
	bool m_destoyed;
public:
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	sf::FloatRect getBoundingBox() const;
	sf::Vector2f getCentre() const;
	float x() const;
	float y() const;
	float left() const;
	float right() const;
	float top() const;
	float bottom() const;
	void destroy();
	bool isDestroyed() const;
};

