#include "Game.h"


int main() {
	Game* hra = new Game();
	hra->startGame();
	delete hra;
	return 0;
}