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
        shoot();
        applyOn<Entity>([](Entity* entity) {
            entity->update();
            }, m_allEntities);
    }
}

void EntityManager::interaction() {
    // Handle interactions between players and meteors
    if (!m_allEntities.empty()) {
        auto player = selectGroup<Player>();
        auto meteors = selectGroup<Meteor>();
        if(!player.empty() && !meteors.empty()){
            applyOn<Meteor>([&player](Meteor* meteor) {
            for (Player* player : player) {
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
                int direction = generateDirection(1, 4);
                float x, y;
                switch (direction) {
                case 1:
                    x = 0;
                    y = generateDirection(0, Constants::windowHeight);
                    break;
                case 2:
                    x = generateDirection(0, Constants::windowWidth);
                    y = 0;
                    break;
                case 3: 
                    x = Constants::windowWidth;
                    y = generateDirection(0, Constants::windowHeight);
                    break;
                default: 
                    x = generateDirection(0, Constants::windowWidth);
                    y = Constants::windowHeight;
                    break;
                }
                std::lock_guard<std::mutex> guard(m_mutex);
                Meteor* meteor = create<Meteor>(x, y);
                setMeteorDirection(meteor);
            }
            m_isAdding = false;
            };

        std::thread meteorThread(addMeteor);
        meteorThread.detach();
    }
}

void EntityManager::setMeteorDirection(Meteor* meteor) {
    if (meteor->x() < Constants::meteorWidth / 2) {
        meteor->moveRight();
    }
    else {
        meteor->moveLeft();
    }
    if (meteor->y() < Constants::meteorHeight / 2) {
        meteor->moveDown();
    }
    else {
        meteor->moveUp();
    }
}

void EntityManager::clear() {
    if (!m_allEntities.empty()) {
        for (auto it = m_allEntities.begin(); it != m_allEntities.end(); ++it) {
            delete* it;
        }
        m_allEntities.clear();
    }
}

void EntityManager::shoot()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        auto player = selectGroup<Player>();
        if (!player.empty()) {
            Player* nevim = player.at(0);
            create<Bullet>(nevim);
        }
    }
}

EntityManager::~EntityManager() {
    // Destructor to clean up memory allocated for entities.
    clear();
}
