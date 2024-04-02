#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Movement.h"
#include "Constants.h"

// The Entity class serves as a base class for all game entities.
// It provides common functionality and attributes shared by all entities.
// By utilizing object-oriented programming (OOP), each object in the game
// is represented as an entity, allowing for easier management and manipulation.
class Entity
{
protected:
	sf::Sprite m_sprite;
	bool m_destoyed = false;
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

