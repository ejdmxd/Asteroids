#include "Player.h"

// Static member to store the player's texture
sf::Texture Player::m_texture;

Player::Player(float x, float y) : MovingEntity(){
	//Loads a texture from and image
	m_texture.loadFromFile("playersSpaceship.png");
	m_sprite.setTexture(m_texture);

	//Setting initial position, velocity and rotation of a sprite
	m_sprite.setPosition(x, y);
	m_rotation = 0.0f;
	m_velocity = { 0.0f, 0.0f };

	//Defaultly actions are related to top left corner of a sprite
	m_sprite.setOrigin(getCentre());
	m_sprite.setScale(sf::Vector2f(0.1f, 0.1f));
}

void Player::checkBorders(float dx, float dy)
{
	//TODO: In future maybe I will use it as a virtual function
	// Checks if player stays within window bounds
	if (checkWindowWidth(dx, *this)) {
		m_velocity.x = dx;
	}
	else {
		m_velocity.x = 0;
	}
	if (checkWindowHeight(dy, *this)) {
		m_velocity.y = dy;
	}
	else {
		m_velocity.y = 0;
	}
}

// Uses methods from Movement.h (getXDirection, getYDirection) to calculate direction based on player's rotation
void Player::moveUp() {
	float dx = getXDirection(Constants::playerSpeed, m_rotation);
	float dy = getYDirection(Constants::playerSpeed, m_rotation);
	checkBorders(dx, dy);
}

void Player::moveDown() {
	float dx = -getXDirection(Constants::playerSpeed, m_rotation);
	float dy = -getYDirection(Constants::playerSpeed, m_rotation);
	checkBorders(dx, dy);
}

//Rotates the player
void Player::moveLeft() {
	m_rotation += -Constants::playerRotationSpeed;
}

void Player::moveRight() {
	m_rotation += Constants::playerRotationSpeed;
}

// Updates player's rotation, position, and movement based on input
void Player::update() {
	processPlayerInput();
	m_sprite.setRotation(m_rotation);
	m_sprite.move(m_velocity);
}

//Checks if player is not off screen and can slow down
bool Player::canPlayerSlow(const float velocity, const float position, const float screenLimit) {
	return isAtSlowestSpeed(velocity) && position + velocity > 0 && position + velocity < screenLimit;
}

//Checks if player reached possible slowest speed
bool Player::isAtSlowestSpeed(const float velocity) {
	return velocity > Constants::playersSlowestSpeed || velocity < -Constants::playersSlowestSpeed;
}

//Slightly changes players speed
void Player::slowDown(float& position) {
	position = position * Constants::slowRatio;
}

// Handles player movement and slowing down based on input
void Player::processPlayerInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		moveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		moveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		moveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		moveDown();
	}
	else {
		if (canPlayerSlow(m_velocity.y, y(), Constants::windowHeight)) {
			slowDown(m_velocity.y);
		}
		else {
			m_velocity.y = 0;
		}
		if (canPlayerSlow(m_velocity.x, x(), Constants::windowWidth)){
			slowDown(m_velocity.x);
		}
		else {
			m_velocity.x = 0;
		}
	}
}

//Window draws the players texture
void Player::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

void Player::loseHealth() {
	//TODO
}

