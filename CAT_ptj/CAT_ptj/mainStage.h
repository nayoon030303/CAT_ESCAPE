#pragma once
#include "Stage.h"

class MainStage :public Stage
{
public:
	MainStage();
	void Render() override;
	void Update() override;
	int state;

};
