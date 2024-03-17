#pragma once
#include "Meteor.h"
#include "Item.h"
#include "Player.h"
#include "HealthBar.h"
#include "Interaction.h"

#include <functional>
class EntityManager
{
public:
	std::vector<Entity*> m_allEntities;
	std::vector<Entity*> m_selectedEntities;
	void refresh();
	void draw(sf::RenderWindow& window);
	void update();
	void interaction();
	void startSpawning();


	void applyOn(std::function<void (Entity*)> func, std::vector<Entity*> entities);

	template <class T>
	std::vector<T*> selectGroup() {
		std::vector<T*> selectedEntities;
		for (Entity* entity : m_allEntities) {
			if (dynamic_cast<T*>(entity) != nullptr) {
				selectedEntities.push_back(entity);
			}
		}
		return selectedEntities;
	}

	template <class T, typename... Args>
	T& create(Args&&... args) {
		T* ptr = new T(std::forward<Args>(args)...);
		m_allEntities.push_back(ptr);
		return *ptr;
	}

	~EntityManager();
};

