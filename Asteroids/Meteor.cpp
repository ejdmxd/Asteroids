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
}


Meteor::Meteor(float x, float y) : Meteor(x, y, 2, {0.f,0.f}) {
	// The contructor is prepared for future development.
}



//TODO - center directions, randomize speed
//Each meteor will have slithly different angle of its trail
void Meteor::moveUp() {
	if (x() < Constants::windowWidth/2.f) {
		m_rotation = generateDirection(45, 90);
	}
	else {
		m_rotation = generateDirection(90, 135);
	}
	m_velocity.y = getYDirection(Constants::meteorSpeed, m_rotation);
	m_velocity.x = getXDirection(Constants::meteorSpeed, m_rotation);
	setRotation(m_rotation);
}

void Meteor::moveDown() {
	if (x() < Constants::windowWidth/2.f) {
		m_rotation = -generateDirection(45, 90);
	}
	else {
		m_rotation = -generateDirection(90, 135);
	}
	m_velocity.y = getYDirection(Constants::meteorSpeed, m_rotation);
	m_velocity.x = getXDirection(Constants::meteorSpeed, m_rotation);
	setRotation(m_rotation);
}

void Meteor::moveLeft() {
	if (y() < Constants::windowHeight / 2.f) {
		m_rotation = -generateDirection(180, 225);
	}
	else {
		m_rotation = -generateDirection(135, 180);
	}
	m_velocity.y = getYDirection(Constants::meteorSpeed, m_rotation);
	m_velocity.x = getXDirection(Constants::meteorSpeed, m_rotation);
	std::cout << m_rotation << std::endl;
	setRotation(m_rotation);
}

void Meteor::moveRight() {
	if (y() < Constants::windowHeight / 2.f) {
		m_rotation = -generateDirection(1, 45);
	}
	else {
		m_rotation = generateDirection(1, 45);
	}
	m_velocity.y = getYDirection(Constants::meteorSpeed, m_rotation);
	m_velocity.x = getXDirection(Constants::meteorSpeed, m_rotation);
	setRotation(m_rotation);
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

void Meteor::setRotation(float rotation) {
	m_sprite.setRotation(rotation);
}