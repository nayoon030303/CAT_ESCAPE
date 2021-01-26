#pragma once
#include "map.h"

class Map_ground : public Map
{
public:
	Map_ground();

	void Update()override;
	void Render()override;
};