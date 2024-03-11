#include "Movement.h"
#include "Entity.h"

const float PI = 3.14159265358979323846;

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
