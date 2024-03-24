#include "EntityManager.h"

void EntityManager::refresh()
{
    // Remove destroyed entities from the entity list
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
    // Handle interactions between players and meteors
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

void EntityManager::startSpawning() {
    if (!m_isAdding) {
        m_isAdding = true;

        auto addMeteor = [this]() {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            {
                auto position = generateDirection(1, 2);
                float x;
                float y;
                if (position == 1) {
                    auto coinFlip = generateDirection(1, 2);
                    if (coinFlip == 1) {
                        y = 0;
                    }
                    else {
                        y = Constants::windowHeight;
                    }
                    x = generateDirection(0, Constants::windowWidth);
                }
                else {
                    auto coinFlip = generateDirection(1, 2);
                    if (coinFlip == 1) {
                        x = 0;
                    }
                    else {
                        x = Constants::windowWidth;
                    }
                    y = generateDirection(0, Constants::windowHeight);
                }
                std::lock_guard<std::mutex> guard(m_mutex);
                Meteor* meteor = create<Meteor>(x, y);
                if (x < Constants::meteorWidth / 2) {
                    meteor->moveRight();
                }
                else {
                    meteor->moveLeft();
                }
                if (y < Constants::meteorHeight / 2) {
                    meteor->moveDown();
                }
                else {
                    meteor->moveUp();
                }
            }
            m_isAdding = false;
            };

        std::thread meteorThread(addMeteor);
        meteorThread.detach();
    }
}


EntityManager::~EntityManager() {
    // Destructor to clean up memory allocated for entities.
    if (!m_allEntities.empty()) {
        for (auto it = m_allEntities.begin(); it != m_allEntities.end(); ++it) {
            delete* it;
        }
        m_allEntities.clear();
    }
}
