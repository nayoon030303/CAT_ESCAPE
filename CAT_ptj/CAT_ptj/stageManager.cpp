#include "stageManager.h"
#include "global.h"
#include "titleStage.h"
#include "storyStage.h"
#include "mainStage.h"
#include "miniGameRunStage.h"
//#include "MiniGameRunStage.h"
//#include "MiniGameMusicStage.h"
//#include "MiniGameRuckScissorsPaper.h"
//#include "StockStage.h"
//#include "resStage.h"

StageManager::StageManager()
{

}

void StageManager::Render()
{
	if (currentStage != nullptr)
	{
		currentStage->Render();
	}
}

void StageManager::Update()
{
	if (currentStage != nullptr)
	{
		currentStage->Update();

	}
}

void StageManager::MakeTitleStage()
{

	if (currentStage != nullptr)
	{
		prevStage = currentStage;
		delete currentStage;
	}
	TitleStage* stage = new TitleStage();
	currentStage = stage;
}

void StageManager::MakeStoryStage()
{
	if (currentStage != nullptr)
	{
		prevStage = currentStage;
		delete currentStage;
	}
	StoryStage* stage = new StoryStage();
	currentStage = stage;

}

void StageManager::MakeMainStage()
{
	if (currentStage != nullptr)
	{
		prevStage = currentStage;
		delete currentStage;
	}
	MainStage* stage = new MainStage();
	currentStage = stage;
}


void StageManager::MakeMiniGameRunStage()
{

	if (currentStage != nullptr)
	{
		prevStage = currentStage;

		if (prevStage->classType == MINI_GAME_CHOOSE)
		{
			gameEntityManager.ClearAll();
			gameEntityManager.setIsRunStage(true);
		}
		delete currentStage;
	}
	MiniGameRunStage* stage = new MiniGameRunStage();
	currentStage = stage;
}

//void StageManager::MakeMiniGameMusicStage()
//{
//
//	if (currentStage != nullptr)
//	{
//		prevStage = currentStage;
//
//		if (prevStage->classType == MINI_GAME_CHOOSE)
//		{
//			gameEntityManager.ClearAll();
//			gameEntityManager.setIsMusicStage(true);
//		}
//		delete currentStage;
//	}
//	MiniGameMusicStage* stage = new MiniGameMusicStage();
//	currentStage = stage;
//}

