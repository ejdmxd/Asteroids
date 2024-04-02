#pragma once

#include "Entity.h"

// The Background class represents a background entity in the game.
class Background : public Entity
{
	static sf::Texture m_texture;
public:
	Background(float x, float y);
	void update() override;
	void draw(sf::RenderWindow& window) override;
};

