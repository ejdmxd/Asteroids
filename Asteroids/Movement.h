#pragma once

#include "Constants.h"
#include <random>

class Entity;

float getXDirection(float speed, float rotationAngle);
float getYDirection(float speed, float rotationAngle);
bool checkWindowWidth(float velocity, Entity& e);
bool checkWindowHeight(float velocity, Entity& e);
float generateDirection(int val1, int val2);