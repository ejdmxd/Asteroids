#pragma once
#include "Meteor.h"
#include "Item.h"
#include "Player.h"
class EntityManager
{
private:
	std::vector<Entity*> m_allEntities;
	void refresh();
	void draw(sf::RenderWindow& window);
	void update();
	void startSpawning();
	template <typename T, typename... Args>
	T& create(Args&&... args);
};

