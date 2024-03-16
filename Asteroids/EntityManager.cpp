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
    applyOnAll([&window](Entity* entity) {
        entity->draw(window);
        });
}

void EntityManager::update()
{
    applyOnAll([](Entity* entity) {
        entity->update();
        });
}

vo

void EntityManager::applyOnAll(std::function<void(Entity*)> func)
{
    std::for_each(m_allEntities.begin(), m_allEntities.end(), func);
}
