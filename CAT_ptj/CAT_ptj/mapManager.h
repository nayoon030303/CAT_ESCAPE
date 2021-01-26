#pragma once
#include <vector>
using namespace std;

class Map;

class MapManager
{
public:
	int type;
	enum
	{
		ground,
		bridge
	};
	

	vector<Map*> maps;

	void AddMaps(int type,int x, int y);
	void Render();
	void Update();

};

