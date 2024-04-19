#pragma once
#include "MovingEntity.h"

// Meteors interact with the player and bullets, and there are plans to implement health for meteors.
class Meteor : public MovingEntity
{
private:
	static sf::Texture m_texture;
public:
	Meteor(float x, float y, float health, sf::Vector2f velocity);
	Meteor(float x, float y);
	void moveUp() override;
	void moveDown() override;
	void moveLeft() override;
	void moveRight() override;
	void calculateVector() override;
	float setRotationHorizontally(int originalRotation, int deviation);
	float setRotationVertically(int originalRotation, int deviation);
	void loseHealth() override;
	void update() override;
	void draw(sf::RenderWindow& window) override;
};

