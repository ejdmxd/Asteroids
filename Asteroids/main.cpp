#include <iostream>
#include "Meteor.h"
#include "Player.h"
#include "Background.h"


int main() {
	std::cout << "Zdravim" << std::endl;
	sf::RenderWindow gameWindow{ {Constants::windowWidth, Constants::windowHeight},
		"Asteroids" };
	gameWindow.setFramerateLimit(60);
	bool pause_key_active{ false };
	Background* background = new Background(0, 0);
	Meteor* meteor = new Meteor(10, 10);
	Player* player = new Player(10, 10);
	while (gameWindow.isOpen()) {
		gameWindow.clear(sf::Color::Black);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			break;
		background->draw(gameWindow);
		meteor->draw(gameWindow);
		player->draw(gameWindow);
		player->update();
		gameWindow.display();
	}
	delete background;
	return 0;
}