#pragma once
#include "Player.h"
#include "Meteor.h"
#include "Item.h"


bool isInteracting(const Entity& e1, const Entity& e2);
void handleCollision(Player& p, Meteor& m);
void handleCollision(const Player& p, const Item& i);


