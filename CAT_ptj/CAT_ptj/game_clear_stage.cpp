#include "game_clear_stage.h"
#include "global.h"

GameClearStage::GameClearStage()
{

}

void GameClearStage::Render()
{
	TextureElement* element = textureManager.GetTexture(RUN_ENEMY1);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = RUN_ENEMY1_WIDTH;
	rc.bottom = RUN_ENEMY1_HEIGHT;

	D3DXVECTOR3 pos(0, 0, 0);
	//D3DXVECTOR3 cen(RUN_ENEMY1_WIDTH / 2, RUN_ENEMY1_HEIGHT / 2, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void GameClearStage::Update()
{

}

