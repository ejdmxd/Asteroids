#pragma once

#include "Constants.h"

class Entity;

float getXDirection(float speed, float rotationAngle);
float getYDirection(float speed, float rotationAngle);
bool checkWindowWidth(float velocity, Entity& e);
bool checkWindowHeight(float velocity, Entity& e);
