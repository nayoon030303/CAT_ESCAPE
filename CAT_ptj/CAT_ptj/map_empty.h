#pragma once
#include "map.h"

class Map_empty : public Map
{
public:
	Map_empty();

	void Update()override;
	void Render()override;
};