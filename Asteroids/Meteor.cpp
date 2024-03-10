#include "Meteor.h"

sf::Texture Meteor::m_texture;

Meteor::Meteor(float x, float y, int strength, float speed) {
	m_texture.loadFromFile("meteor.png");
	m_sprite.setTexture(m_texture);

	m_sprite.setPosition(x, y);
	m_velocity = { Constants::meteorSpeed, Constants::meteorSpeed };
	m_sprite.setOrigin(getCentre());
}

Meteor::Meteor(float x, float y, float speed) : Meteor(x, y, 1, speed) {

}

Meteor::Meteor(float x, float y) : Meteor(x, y, 1, 1) {

}


//Each meteor will have slithly different angle of its trail
void Meteor::moveUp() {}

void Meteor::moveDown() {}

void Meteor::moveLeft() {}

void Meteor::moveRight() {}

void Meteor::loseHealth() {/*TODO*/ }

//TODO move

//Updates position of meteor
void Meteor::update() {
	m_sprite.move(m_velocity);
}

//Draws meteor's sprite
void Meteor::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}