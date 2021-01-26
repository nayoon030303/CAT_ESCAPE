#pragma once
#include <vector>

using namespace std;

class GameAction;

class GameMapDirection
{
public:
	GameMapDirection();
	void LoadAction(const char* filename);
	void Update();

	bool playing;
	int actionIndex;
	int actionFrame;

	int actionType;
	int actionX;
	int actionY;

protected:
private:
	vector<GameAction> actions;

};
