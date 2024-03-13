#pragma once
#include "MovingEntity.h"
#include "Constants.h"
#include "Movement.h"

class Meteor : public MovingEntity
{
private:
	static sf::Texture m_texture;
	int m_strength;
	float m_speed;
public:
	Meteor(float x, float y, int strength, float speed);
	Meteor(float x, float y, float speed);
	Meteor(float x, float y);
	void moveUp() override;
	void moveDown() override;
	void moveLeft() override;
	void moveRight() override;
	void loseHealth() override;
	void update() override;
	void draw(sf::RenderWindow& window) override;
};

