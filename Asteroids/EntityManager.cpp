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
    // Draw all entities on the provided window
    if (!m_allEntities.empty()) {
        applyOn<Entity>([&window](Entity* entity) {
            entity->draw(window);
            }, m_allEntities);
    }
}

void EntityManager::update()
{
    // Update all entities' positions and states
    if (!m_allEntities.empty()) {
        shoot(); // Handle shooting
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
            meteorPlayerInteraction(player, meteors);
        }
        if (!meteors.empty()) {
            bulletMeteorInteraction(meteors);
        }
    }

    //TODO It is alternative way how to handle interactions, but it is not working in the moment
    /*
    if (!m_allEntities.empty()) {
        auto player = selectGroup<Player>();
        auto meteors = selectGroup<Meteor>();
        if (!player.empty() && !meteors.empty()) {
            auto meteorInteraction = [&player, &meteors, this]() {
                meteorPlayerInteraction(player, meteors);
                };
            std::thread meteorInteractionThread(meteorInteraction);
            meteorInteractionThread.detach();

        }
        if (!meteors.empty()) {
            auto bulletInteraction = [&meteors, this]() {
                bulletMeteorInteraction(meteors);
                };
            std::thread bulletInteractionThread(bulletInteraction);
            bulletInteractionThread.detach();
        }
    */

}

void EntityManager::meteorPlayerInteraction(std::vector<Player*>& player, std::vector<Meteor*>& meteors)
{
    // Handle collisions between players and meteors
    applyOn<Meteor>([&player](Meteor* meteor) {
        for (Player* player : player) {
            handleCollision(*player, *meteor);
        }
        }, meteors);
}

void EntityManager::bulletMeteorInteraction(std::vector<Meteor*>& meteors)
{
    // Handle collisions between bullets and meteors
    auto bullets = selectGroup<Bullet>();
    if (!bullets.empty()) {
        applyOn<Bullet>([&meteors, this](Bullet* bullet) {
            for (Meteor* meteor : meteors) {
                bool didValueChanged = meteor->isDestroyed();
                handleCollision(*meteor, *bullet);
                if (didValueChanged != meteor->isDestroyed() && meteor->getHealth() > 1) {
                    splitMeteor(meteor);
                }
            }
            }, bullets);
    }
}

void EntityManager::startSpawning() {
    // Start spawning meteors
    if (!m_isAdding) {
        m_isAdding = true;

        auto addMeteor = [this]() {
            // Add a meteor after a delay
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
    // Set the direction of the meteor based on its initial position
    if (meteor->x() < Constants::windowWidth / 2) {
        meteor->moveRight();
    }
    else {
        meteor->moveLeft();
    }
    if (meteor->y() < Constants::windowHeight / 2) {
        meteor->moveDown();
    }
    else {
        meteor->moveUp();
    }
    meteor->setRotation();
}

void EntityManager::splitMeteor(Meteor* meteor)
{
    sf::Vector2f velocity = meteor->getVelocity();
    velocity = { getXDirection(meteor->getSpeed(), meteor->getRotation() + 20.f), getYDirection(meteor->getSpeed(), meteor->getRotation() + 20.f)};
    create<Meteor>(meteor->x(), meteor->y(), meteor->getHealth() - 1, velocity);
    velocity = meteor->getVelocity();
    velocity = { getXDirection(meteor->getSpeed(), meteor->getRotation() - 10.f), getYDirection(meteor->getSpeed(), meteor->getRotation() - 10.f)};
    create<Meteor>(meteor->x(), meteor->y(), meteor->getHealth() - 1, velocity);

    /*
    setMeteorDirection(create<Meteor>(meteor->x(), meteor->y(), meteor->getHealth() - 1, velocity));
    setMeteorDirection(create<Meteor>(meteor->x(), meteor->y(), meteor->getHealth() - 1, velocity));
    */
}

void EntityManager::clear() {
    // Clear all entities from the entity list and deallocate memory
    if (!m_allEntities.empty()) {
        for (auto it = m_allEntities.begin(); it != m_allEntities.end(); ++it) {
            delete* it;
        }
        m_allEntities.clear();
    }
}

void EntityManager::shoot()
{
    // Handle shooting from the player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if (!m_isShooting) {
            m_isShooting = true;

           auto player = selectGroup<Player>();
            if (!player.empty()) {
                Player* nevim = player.at(0);
                create<Bullet>(nevim);
            }
        }
    }
    else {
        m_isShooting = false;
    }
}

EntityManager::~EntityManager() {
    // Destructor to clean up memory allocated for entities.
    clear();
}
