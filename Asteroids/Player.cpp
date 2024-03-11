#include "Player.h"

sf::Texture Player::m_texture;

Player::Player(float x, float y) : MovingEntity(){
	m_texture.loadFromFile("playersSpaceship.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);

	m_velocity = { 0.0f, 0.0f };

	m_sprite.setOrigin(getCentre());
	m_sprite.setScale(sf::Vector2f(0.1f, 0.1f));

	m_rotation = 0.0f;
}

void Player::checkBorders(float dx, float dy)
{
	//TODO: In future maybe I will use it as a virtual function
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

void Player::moveUp() {
	float dx = getXDirection(Constants::playerSpeed, m_rotation);
	float dy = getYDirection(Constants::playerSpeed, m_rotation);
	checkBorders(dx, dy);
}

void Player::moveDown() {
	float dx = -getXDirection(Constants::playerSpeed, m_rotation);;
	float dy = -getYDirection(Constants::playerSpeed, m_rotation);
	checkBorders(dx, dy);
}

void Player::moveLeft() {
	m_rotation += -Constants::playerRotationSpeed;
}

void Player::moveRight() {
	m_rotation += Constants::playerRotationSpeed;
}

void Player::update() {
	processPlayerInput();
	m_sprite.setRotation(m_rotation);
	m_sprite.move(m_velocity);
}

bool Player::canPlayerSlow(const float velocity, const float position, const float screenLimit) {
	return isItSlowestSpeed(velocity) && position + velocity > 0 && position + velocity < screenLimit;
}

bool Player::isItSlowestSpeed(const float velocity) {
	return velocity > Constants::playersSlowestSpeed || velocity < -Constants::playersSlowestSpeed;
}

void Player::slowDown(float& position) {
	position = position * Constants::slowRatio;
}

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

void Player::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

void Player::loseHealth() {
	//TODO
}

