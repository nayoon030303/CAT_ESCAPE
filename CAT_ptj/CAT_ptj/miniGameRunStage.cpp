#include "MiniGameRunStage.h"	
#include "global.h"


MiniGameRunStage::MiniGameRunStage()
{
	gameEntityManager.runPlayer = &runPlayer;
	time = 0;
	//classType = MINI_GAME_RUN_STAGE;
}

void MiniGameRunStage::Render()
{
	
	if (runPlayer.isDead)
	{
		//gameOver.Render();
	}

	if (runPlayer.isGameClear)
	{
		if (time > 30)
		{
			gameClearStage.Render();
		}
	}
	runBackground.Render();
	runPlayer.Render();
	gameEntityManager.Render();
	gameStageUi.Render();
}

void MiniGameRunStage::Update()
{	
	if (runPlayer.isGameClear) 
	{
		runPlayer.Update();
		
		time++;
		
	
	}
	else if (runPlayer.isGameClear)
	{

	}
	else if (runPlayer.getIsDead())
	{
		//gameOver.Render();
	}
	else
	{
		director_enemy.Update();
		runBackground.Update();
		runPlayer.Update();
		gameStageUi.Update();
		gameEntityManager.Update();
		
	}
}