#pragma once

#include "MovingEntity.h"
#include "Player.h"

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

