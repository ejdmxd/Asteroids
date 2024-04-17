#include "Interaction.h"

//Check if there is any interaction between two entities
bool isInteracting(const Entity& e1, const Entity& e2) {
	auto box1 = e1.getBoundingBox();
	auto box2 = e2.getBoundingBox();
	return box1.intersects(box2);
}

//Player loses health and meteor is destroyed if they interact with each other
void handleCollision(Player& p, Meteor& m) {
	if (isInteracting(p, m)) {
		m.destroy();
		p.loseHealth();
	}
}

void handleCollision(const Player& p, const Item& i) {
	//TODO
}

//If bullet colides with meteors both of them are destroyed
void handleCollision(Meteor& m, Bullet& b)
{
	if (isInteracting(m, b)) {
		m.destroy();
		b.destroy();
	}
}
