#include "gamemap_direction.h"
#include "global.h"
#include <string>
#include "mapManager.h"

GameMapDirection::GameMapDirection()
{
	actionIndex = 0;
	actionFrame = 0;
	playing = true;
}

void GameMapDirection::LoadAction(const char* filename)
{
	FILE* fp = fopen(filename, "rt");


	while (!feof(fp))
	{
		int time;
		int type;
		int x;
		int y;
	
		int r = fscanf(fp, "%d - %d (%d, %d)\n", &time, &type, &x, &y);

		GameAction action(time, type, x, y);
		actions.push_back(action);
	}

	fclose(fp);
}

void GameMapDirection::Update()
{
	if (playing)
	{
		actionFrame++;

		if (actionFrame > actions[actionIndex].time)
		{
			int actionType = actions[actionIndex].type;

			mapManager.AddMaps(actionType, actions[actionIndex].x, actions[actionIndex].y);


			actionIndex++;

			if (actionIndex >= actions.size())
			{
				playing = false;
			}

			actionFrame = 0;
		}
	}
}
