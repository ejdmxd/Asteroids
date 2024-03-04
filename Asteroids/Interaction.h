#pragma once
#include "Player.h"
#include "Meteor.h"
#include "Item.h"

bool isInteracting(Entity& e1, Entity& e2);
void handleCollision(Player& const player, Meteor& const meteor);
void handleCollision(Player& const player, Item& const item);

