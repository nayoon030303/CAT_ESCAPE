#include "mainStage.h"	
#include "global.h"

MainStage::MainStage()
{
	state = MINIGAMESTAGE;
	classType = MINI_GAME_CHOOSE;
}

void MainStage::Render()
{
	RECT rc;

	TextureElement* element = textureManager.GetTexture(state);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;
	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();

}

void MainStage::Update()
{
	//director.LoadAction("actions.txt");
	state = MINIGAMESTAGE;

	//´Þ¸®±â
	if (pt.x > 180 && pt.x < 430 && pt.y > 400 && pt.y < 560)
	{
		//state = MINIGAMESTAGE_1;
		if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
		{
			stageManager.MakeMiniGameRunStage();
		}
	}
}