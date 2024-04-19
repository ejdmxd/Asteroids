#pragma once

#include "MovingEntity.h"

// The Player class represents the player-controlled entity in the game.
// The player interacts with meteors and has the ability to shoot, facilitated by the EntityManager class.
class Player : public MovingEntity
{
private:
	static sf::Texture m_texture;
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
	void calculateVector() override;
	void update() override;
	bool canPlayerSlow(const float velocity, const float position, const float screenLimit);
	bool isAtSlowestSpeed(const float velocity);
	void slowDown(float& position);
	void draw(sf::RenderWindow& window) override;
	void loseHealth() override;
};

