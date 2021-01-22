#pragma once

class Stage
{
public:
	virtual void Render() = 0;
	virtual void Update() = 0;


	int classType;
	int start_state;
	int ranking_state;
}; 