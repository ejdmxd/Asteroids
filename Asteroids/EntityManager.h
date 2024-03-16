#pragma once
#include "Meteor.h"
#include "Item.h"
#include "Player.h"
#include "HealthBar.h"
#include <functional>
class EntityManager
{
public:
	std::vector<Entity*> m_allEntities;
	void refresh();
	void draw(sf::RenderWindow& window);
	void update();
	void startSpawning();
	void applyOnAll(std::function<void (Entity*)> func);
	template <class T, typename... Args>
	T& create(Args&&... args) {
		T* ptr = new T(std::forward<Args>(args)...);
		m_allEntities.push_back(ptr);
		return *ptr;
	}
};

