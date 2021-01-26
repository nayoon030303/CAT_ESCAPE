#pragma once
#include "global.h"

class Map
{
public:

	int x, y,speed = SPEED;

	void setPosX(int x) { this->x = x; }
	int getPosX() { return x; }

	void setPosY(int y) { this->y = y; }
	int getPosY() { return y; }

	virtual void Render() = 0;
	virtual void Update() = 0;
};