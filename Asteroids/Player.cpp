#include "Player.h"

sf::Texture Player::m_texture;

Player::Player(float x, float y) : MovingEntity(){
	m_texture.loadFromFile("playersSpaceship.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);
	m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));

	m_velocity = { 0.0f, 0.0f };

	m_sprite.setOrigin(getCentre());

	m_rotation = 0.0f;
}

void Player::moveUp() {
	float dx = Constants::playerSpeed * std::cos(m_rotation* (M_PI / 180.0f));
	float dy = Constants::playerSpeed * std::sin(m_rotation * (M_PI / 180.0f));
	m_velocity.y = dy;
	m_velocity.x = dx;
}

void Player::moveDown() {
	float dx = -Constants::playerSpeed * std::cos(m_rotation * (M_PI / 180.0f));
	float dy = -Constants::playerSpeed * std::sin(m_rotation * (M_PI / 180.0f));
	m_velocity.y = dy;
	m_velocity.x = dx;
}

void Player::moveLeft() {
	m_rotation += -Constants::playerRotationSpeed;
}

void Player::moveRight() {
	m_rotation += Constants::playerRotationSpeed;
}

void Player::update() {
	processPlayerInput();
	m_sprite.move(m_velocity);
}


/*
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
*/

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
		if (m_velocity.y > Constants::playersSlowestSpeed || m_velocity.y < -Constants::playersSlowestSpeed) {
			m_velocity.y = m_velocity.y * Constants::slowRatio;
		}
		else {
			m_velocity.y = 0;
		}
		if (m_velocity.x > Constants::playersSlowestSpeed || m_velocity.x < -Constants::playersSlowestSpeed) {
			m_velocity.x = m_velocity.x * Constants::slowRatio;
		}
		else {
			m_velocity.x = 0;
		}
	}
}

void Player::draw(sf::RenderWindow& window) {
	m_sprite.setRotation(m_rotation);
	window.draw(m_sprite);
}

void Player::loseHealth() {
	//TODO
}

