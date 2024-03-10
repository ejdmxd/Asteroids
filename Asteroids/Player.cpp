#include "Player.h"

sf::Texture Player::m_texture;

Player::Player(float x, float y) : MovingEntity(){
	m_texture.loadFromFile("playersSpaceship.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);

	m_velocity = { Constants::playerSpeed, 0.0f };

	m_sprite.setOrigin(getCentre());

}

void Player::moveUp() {
	m_velocity.y = Constants::playerSpeed;
}

void Player::moveDown() {
	m_velocity.y = -Constants::playerSpeed;
}

void Player::moveLeft() {
	m_velocity.x = -Constants::playerSpeed;
}

void Player::moveRight() {
	m_velocity.x = Constants::playerSpeed;
}

void Player::update() {
	processPlayerInput();

	m_sprite.move(m_velocity);
}

void Player::moveHorizontally()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		if (x() >= 0) {
			moveLeft();
		}
		else {
			m_velocity.x = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		if (x() <= Constants::windowHeight) {
			moveRight();
		}
		else {
			m_velocity.x = 0;
		}
	}
	else {
		if (m_velocity.x > Constants::playersSlowestSpeed || m_velocity.x < -Constants::playersSlowestSpeed) {
			m_velocity.x = m_velocity.x * Constants::slowRatio;
		}
		else {
			m_velocity.x = 0;
		}
	}
}

void Player::moveVertically()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
		if (y() < Constants::windowHeight) {
			moveUp();
		}
		else {
			m_velocity.y = 0;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
		if (y() > 0) {
			moveDown();
		}
		else {
			m_velocity.y = 0;
		}
	}
	else {
		if (m_velocity.y > Constants::playersSlowestSpeed || m_velocity.y < -Constants::playersSlowestSpeed) {
			m_velocity.y = m_velocity.y * Constants::slowRatio;
		}
		else {
			m_velocity.y = 0;
		}
	}
}

void Player::processPlayerInput() {
	moveHorizontally();
	moveVertically();
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

void Player::loseHealth() {
	//TODO
}

