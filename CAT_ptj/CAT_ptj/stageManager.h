#pragma once
class Stage;

class StageManager
{
public:
	StageManager();

	void MakeTitleStage();
	void MakeStoryStage();
	void MakeMainStage();

	void MakeMiniGameRunStage();
	void MakeMiniGameMusicStage();
	void MakeMiniGameRockSPStage();
	void MakeRankStage();

	//±âº»
	void Render();
	void Update();



	//stage
	Stage* currentStage;
	Stage* prevStage;
}; 
