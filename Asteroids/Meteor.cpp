#include "Meteor.h"

sf::Texture Meteor::m_texture;

Meteor::Meteor(float x, float y, int health, sf::Vector2f velocity) {
	// Load the texture for the meteor from file
	setHealth(health);
	m_texture.loadFromFile("meteor.png");
	// Set the texture for the meteor sprite
	// Set its position to the specified (x, y) coordinates
	// Set its origin to the center of the sprite
	// Scale the sprite to 30% of its original size
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);
	m_sprite.setOrigin(getCentre());
	if (health == 2) {
		m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	}
	else {
		m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
	}
	// Set the velocity of the meteor to the specified speed
	m_velocity = velocity;
	m_destoyed = false;
	m_speed = generateDirection(1, 3);
}


Meteor::Meteor(float x, float y) : Meteor(x, y, 2, {0.f,0.f}) {
	// The contructor is prepared for future development.
}


//Each meteor will have slithly different angle of its trail
void Meteor::moveUp() {
	m_velocity.y = -1.0f * m_speed;
}

void Meteor::moveDown() {
	m_velocity.y = 1.0f * m_speed;
}

void Meteor::moveLeft() {
	m_velocity.x = -1.0f * m_speed;
}

void Meteor::moveRight() {
	m_velocity.x = 1.0f * m_speed;
}



void Meteor::loseHealth() {/*TODO*/ }

//TODO move

//Updates position of meteor
void Meteor::update() {
	m_sprite.move(m_velocity);
	if (y() < 0 - 100 || y() > Constants::windowHeight + 100 || x() < 0-100 || x() > Constants::windowWidth + 100) {
		m_destoyed = true;
	}
}

//Draws meteor's sprite
void Meteor::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}

void Meteor::setRotation() {
	m_sprite.setRotation(std::atan2(m_velocity.y, m_velocity.x) * 180.f / Constants::PI);
	std::cout << m_rotation;
}