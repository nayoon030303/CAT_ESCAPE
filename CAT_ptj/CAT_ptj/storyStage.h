#pragma once

#include "Stage.h"

class StoryStage :public Stage
{
public:
	StoryStage();
	void Render()override;
	void Update()override;

	int count = 0;

};