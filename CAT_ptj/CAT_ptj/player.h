#pragma once
#include <string>
#include <string.h>
#include <string>

using namespace std;

class Player
{
public:
	Player();

	int id;
	char name[128];

	bool isStage1_clear;
	bool isStage2_clear;
	bool isStage3_clear;

	//id
	void SetId(int id) { this->id = id; }
	int GetId() { return id; }

	//name
	void SetName(string name) { strcpy_s(this->name, name.c_str()); }
	char* GetName() { return name; }

	//stage
	void setStage1_clear(bool isClear) { this->isStage1_clear = isClear; }
	void setStage2_clear(bool isClear) { this->isStage2_clear = isClear; }
	void setStage3_clear(bool isClear) { this->isStage3_clear = isClear; }
};