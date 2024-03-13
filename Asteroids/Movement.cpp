#include "Movement.h"
#include "Entity.h"

const float PI = 3.14159265358979323846;

// Calculates movement direction on the X-axis based on the object's speed and rotation angle (in degrees)
float getXDirection(float speed, float rotationAngle)
{
	float direction = speed * std::cos(rotationAngle * (PI / 180.0f));
	return direction;
}

float getYDirection(float speed, float rotationAngle)
{
	float direction = speed * std::sin(rotationAngle * (PI / 180.0f));
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

float generateDirection(int val1, int val2) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(val1, val2);
	return dis(rd);
}