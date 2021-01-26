#include "mapManager.h"
#include "map_ground.h"
#include "map_empty.h"
#include "map.h"
void MapManager::AddMaps(int type ,int x, int y)
{
	//start
	if (type == 0)
	{
		Map* map = new Map_empty();
		map->setPosX(x);
		map->setPosY(y);
		maps.push_back(map);
	}
	else if (type == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			Map* map = new Map_ground();
			map->setPosX(x + (i * 250));
			map->setPosY(y);
			maps.push_back(map);
		}
		
	}

}

void MapManager::Update()
{
	for (int i = 0; i < maps.size(); i++)
	{
		maps[i]->Update();
	}

	auto iter = maps.begin();
	while (iter != maps.end())
	{
		//화면 바깥으로 나가면 삭제
		if ((*iter)->x < -250)
		{
			iter = maps.erase(iter);
		}
		else
		{
			iter++;
		}
	}
}

void MapManager::Render()
{
	for (int i = 0; i < maps.size(); ++i)
	{
		maps[i]->Render();
	}
}