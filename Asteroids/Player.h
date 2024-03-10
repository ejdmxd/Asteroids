#pragma once
#define _USE_MATH_DEFINES

#include "MovingEntity.h"
#include <cmath>

class Player : public MovingEntity
{
private:
	static sf::Texture m_texture;
	float m_rotation;
	/*
	void moveHorizontally();
	void moveVertically();
	*/
	void processPlayerInput();
public:
	Player(float x, float y);
	void moveUp() override;
	void moveDown() override;
	void moveLeft() override;
	void moveRight() override;
	void update() override;
	void draw(sf::RenderWindow& window) override;
	void loseHealth() override;
};

