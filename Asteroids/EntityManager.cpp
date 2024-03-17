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
    if (!m_allEntities.empty()) {
        applyOn<Entity>([&window](Entity* entity) {
            entity->draw(window);
            }, m_allEntities);
    }
}

void EntityManager::update()
{
    if (!m_allEntities.empty()) {
        applyOn<Entity>([](Entity* entity) {
            entity->update();
            }, m_allEntities);
    }
}

void EntityManager::interaction() {
    if (!m_allEntities.empty()) {
        auto players = selectGroup<Player>();
        auto meteors = selectGroup<Meteor>();
        if(!players.empty() && !meteors.empty()){
            applyOn<Meteor>([&players](Meteor* meteor) {
            for (Player* player : players) {
                handleCollision(*player, *meteor);
            }
            }, meteors);
        }
    }
}


EntityManager::~EntityManager() {
    if (!m_allEntities.empty()) {
        for (auto it = m_allEntities.begin(); it != m_allEntities.end(); ++it) {
            delete* it;
        }
        m_allEntities.clear();
    }
}
