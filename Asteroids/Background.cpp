#include "Background.h"

sf::Texture Background::m_texture;

Background::Background(float x, float y) {
	m_texture.loadFromFile("background.jpg");
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(x, y);
}

void Background::update() {

}

void Background::draw(sf::RenderWindow& window) {
	window.draw(m_sprite);
}