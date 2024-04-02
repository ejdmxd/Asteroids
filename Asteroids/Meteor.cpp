#include "Meteor.h"

sf::Texture Meteor::m_texture;

Meteor::Meteor(float x, float y, int strength, float speed) {
	// Load the texture for the meteor from file
	m_texture.loadFromFile("meteor.png");
	// Set the texture for the meteor sprite
	// Set its position to the specified (x, y) coordinates
	// Set its origin to the center of the sprite
	// Scale the sprite to 30% of its original size
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);
	m_sprite.setOrigin(getCentre());
	m_sprite.setScale(sf::Vector2f(0.3f, 0.3f));
	// Set the velocity of the meteor to the specified speed
	m_velocity = { 0.0f, 0.0f };
	m_destoyed = false;
}

Meteor::Meteor(float x, float y, float speed) : Meteor(x, y, 1, speed) {
	// This constructor initializes a meteor at the specified position (x, y) with the given speed.
	// TODO: In the future, smaller meteors with varying attributes may spawn from this meteor.
	// The contructor is prepared for future development.
}

Meteor::Meteor(float x, float y) : Meteor(x, y, 1) {
	// The contructor is prepared for future development.
}


//Each meteor will have slithly different angle of its trail
void Meteor::moveUp() {
	m_velocity.y = -1.0f * generateDirection(1, 3);
}

void Meteor::moveDown() {
	m_velocity.y = 1.0f * generateDirection(1, 3);
}

void Meteor::moveLeft() {
	m_velocity.x = -1.0f * generateDirection(1, 3);
}

void Meteor::moveRight() {
	m_velocity.x = 1.0f * generateDirection(1, 3);
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

