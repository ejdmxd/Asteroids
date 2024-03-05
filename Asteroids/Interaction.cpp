#include "Interaction.h"

bool isInteracting(const Entity& e1, const Entity& e2) {
	auto box1 = e1.getBoundingBox();
	auto box2 = e2.getBoundingBox();
	return box1.intersects(box2);
}

void handleCollision(Player& p, Meteor& m) {
	if (isInteracting(p, m)) {
		m.destroy();
		p.loseHealth();
	}
}

void handleCollision(const Player& p, const Item& i) {
	//TODO
}