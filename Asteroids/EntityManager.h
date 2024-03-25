#pragma once
#include "Meteor.h"
#include "Item.h"
#include "Player.h"
#include "HealthBar.h"
#include "Interaction.h"
#include "GameState.h"
#include <thread>
#include <mutex>
#include <functional>


// EntityManager class manages entities in the game world.
class EntityManager
{
	std::mutex m_mutex;
	bool m_isAdding = false;
public:
	// Vector containing all entities.
	std::vector<Entity*> m_allEntities;
	std::vector<Entity*> m_selectedEntities;
	void refresh();
	void draw(sf::RenderWindow& window);
	void update();
	void interaction();
	void startSpawning();

	void setMeteorDirection(Meteor* meteor);

	void clear();

	// Applies the given function to each entity in the provided vector.
	template <class T>
	void applyOn(std::function<void(T*)> func, std::vector<T*> entities) {
			std::for_each(entities.begin(), entities.end(), func);
	}
	
	// Selects entities of the specified type and returns them in a vector.
	template <class T>
	std::vector<T*> selectGroup() {
		std::vector<T*> selectedEntities;
		for (Entity* entity : m_allEntities) {
			if (dynamic_cast<T*>(entity) != nullptr) {
				selectedEntities.push_back(dynamic_cast<T*>(entity));
			}
		}
		return selectedEntities;
	}

	// Creates an entity of the specified type with the provided arguments.
	template <class T, typename... Args>
	T* create(Args&&... args) {
		T* ptr = new T(std::forward<Args>(args)...);
		m_allEntities.push_back(ptr);
		return ptr;
	}

	~EntityManager();
};

