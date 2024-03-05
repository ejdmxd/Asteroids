#pragma once
#include "MovingEntity.h"
class Player : public MovingEntity
{
private:
	static sf::Texture m_texture;
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

