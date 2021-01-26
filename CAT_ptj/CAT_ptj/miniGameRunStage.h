#pragma once
#include "stage.h"
#include "runBackground.h"
#include "runPlayer.h"
#include "game_stage_ui.h"
#include "game_clear_stage.h"
//#include "runEnemy_1.h"
//#include "runStage_ui.h"
//#include "gameOver.h"

class MiniGameRunStage :public Stage
{
public:
	MiniGameRunStage();
	void Render()override;
	void Update() override;

	bool isPlaying;
	bool isDone;
	bool isScral;
	int time;

	RunBackGround runBackground;
	RunPlayer runPlayer;
	GameStageUi gameStageUi;
	GameClearStage gameClearStage;
	//RunEnemy_1 runEnemy1;
	//RunStage_Ui runStage_ui;
	//GameOver gameOver;
};