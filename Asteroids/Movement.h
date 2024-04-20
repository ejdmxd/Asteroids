#pragma once

#include "Constants.h"
//#include <SFML/Graphics.hpp>
#include <random>

class Entity;

//TODO one function for velocity
float getXDirection(float speed, float rotationAngle);
float getYDirection(float speed, float rotationAngle);
bool checkWindowWidth(float velocity, Entity& e);
bool checkWindowHeight(float velocity, Entity& e);
float generatNumber(int val1, int val2);
//sf::Vector2f normalize(sf::Vector2f vector);