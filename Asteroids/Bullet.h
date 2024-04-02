#pragma once

#include "MovingEntity.h"
#include "Player.h"

// This class represents a bullet entity, designed to be used by entities capable of shooting.
// It provides functionality to create and manage bullet entities within the game.
class Bullet : public MovingEntity
{
	static sf::Texture m_texture;
public:
	Bullet(MovingEntity* entity);
	void moveUp() override;
	void moveDown() override;
	void moveLeft() override;
	void moveRight() override;
	void loseHealth() override;
	void update() override;
	void draw(sf::RenderWindow& window) override;
};

