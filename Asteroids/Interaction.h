#pragma once
#include "Player.h"
#include "Meteor.h"
#include "Item.h"
#include "Bullet.h"

// The interactions namespace contains functions for handling various interactions between game entities.
bool isInteracting(const Entity& e1, const Entity& e2);
void handleCollision(Player& p, Meteor& m);
void handleCollision(const Player& p, const Item& i);
void handleCollision(Meteor& m, Bullet& b);


