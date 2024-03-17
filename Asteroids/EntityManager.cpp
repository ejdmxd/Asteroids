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
    applyOn([&window](Entity* entity) {
        entity->draw(window);
        }, m_allEntities);
}

void EntityManager::update()
{
    applyOn([](Entity* entity) {
        entity->update();
        }, m_allEntities);
}

void EntityManager::interaction() {
    auto players = selectGroup<Player>();
    auto meteors = selectGroup<Meteor>();

    applyOn([&players](Meteor* meteor) {
        for (Player* player : players) {
            handleCollision(*player, *meteor);
        }
        }, meteors);
}


void EntityManager::applyOn(std::function<void(Entity*)> func, std::vector<Entity*> entities)
{
    std::for_each(entities.begin(), entities.end(), func);
}


EntityManager::~EntityManager() {
    for (auto it = m_allEntities.begin(); it != m_allEntities.end(); ++it) {
        delete *it;
    }
    m_allEntities.clear();
}
