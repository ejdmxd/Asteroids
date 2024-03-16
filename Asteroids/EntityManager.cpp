#include "EntityManager.h"

void EntityManager::refresh()
{
    if (!m_allEntities.empty()) {
        m_allEntities.erase(std::remove_if(m_allEntities.begin(), m_allEntities.end(),
            [](Entity* entity) { return entity->isDestroyed(); }), m_allEntities.end());
    }
}

void EntityManager::draw(sf::RenderWindow& window)
{
   
}

void EntityManager::update()
{
}

void EntityManager::applyOnAll(std::function<void(Entity&)> func)
{
}
