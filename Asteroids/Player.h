#pragma once

#include "MovingEntity.h"

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
	void checkBorders(float dx, float dy);
	void moveUp() override;
	void moveDown() override;
	void moveLeft() override;
	void moveRight() override;
	void update() override;
	bool canPlayerSlow(const float velocity, const float position, const float screenLimit);
	bool isAtSlowestSpeed(const float velocity);
	void slowDown(float& position);
	void draw(sf::RenderWindow& window) override;
	void loseHealth() override;
};

