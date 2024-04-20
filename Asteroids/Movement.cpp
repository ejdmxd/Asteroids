#include "Movement.h"
#include "Entity.h"

// Calculates movement direction on the X-axis based on the object's speed and rotation angle (in degrees)
float getXDirection(float speed, float rotationAngle)
{
	float direction = speed * std::cos(rotationAngle * (Constants::PI / 180.0f));
	return direction;
}

float getYDirection(float speed, float rotationAngle)
{
	float direction = speed * std::sin(rotationAngle * (Constants::PI / 180.0f));
	return direction;
}

// Checks if the entity stays within the window
bool checkWindowWidth(float velocity, Entity& e)
{
	bool podminka = e.x() + velocity > 0 && e.x() + velocity < Constants::windowWidth;
	return podminka;
}

bool checkWindowHeight(float velocity, Entity& e)
{
	bool podminka = e.y() + velocity > 0 && e.y() + velocity < Constants::windowHeight;
	return podminka;
}


// Generates random number
float generatNumber(int val1, int val2) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(val1, val2);
	return float(dis(rd));
}


/*
sf::Vector2f normalize(sf::Vector2f vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	sf::Vector2f normalizedVelocity;
	if (length != 0) {
		normalizedVelocity.x = vector.x / length;
		normalizedVelocity.y = vector.y / length;
	}
	else {
		normalizedVelocity.x = 0;
		normalizedVelocity.y = 0;
	}
	return normalizedVelocity;
}
*/
