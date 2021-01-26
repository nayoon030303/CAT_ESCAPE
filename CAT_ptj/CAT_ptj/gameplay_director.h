#pragma once

#include <vector>

using namespace std;

//n - n(x, y) comment

class GameAction
{
public:
	GameAction(int time, int type, int x, int y)
	{
		this->time = time;
		this->type = type;
		this->x = x;
		this->y = y;
	}

	int time;
	int type;
	int x;
	int y;
};

class GameplayDirector
{
public:
	GameplayDirector();
	void LoadAction(const char* filename);
	void Update();

	bool playing;
	int actionIndex;
	int actionFrame;
protected:
private:
	vector<GameAction> actions;

};
