#include "TitleStage.h"
#include "global.h"
#include "StageManager.h"

#define START_BUTTON_X 840
#define START_BUTTON_Y 450 
#define RANKING_BUTTON_Y 620
//#define LOAD_BUTTON_Y 650
//#define EXIT_BUTTON_Y 3

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 100

TitleStage::TitleStage()
{
    classType = TITLE_STAGE;
    start_state = START;
    ranking_state = RANKING;
}

void TitleStage::Render()
{
    D3DXVECTOR3 pos;
    TextureElement* element = textureManager.GetTexture(TITLE);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = WINDOW_WIDTH;
    srcRect.bottom = WINDOW_HEIGHT;

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();

   
    //start
    element = textureManager.GetTexture(start_state);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 200;
    srcRect.bottom = 100;

    pos = D3DXVECTOR3(840, 450, 0);

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();

    //start
    element = textureManager.GetTexture(ranking_state);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = 300;
    srcRect.bottom = 100;

    pos = D3DXVECTOR3(840, 620, 0);

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();
}

void TitleStage::Update()
{
    //start버튼
    if (pt.x > START_BUTTON_X && pt.x<START_BUTTON_X + BUTTON_WIDTH
        && pt.y>START_BUTTON_Y && pt.y < START_BUTTON_Y + BUTTON_HEIGHT)
    {
        start_state = START_BORDER;
        if (inputManager.prevKey[VK_LBUTTON]==1 && inputManager.key[VK_LBUTTON] == 0)
        {
            stageManager.MakeStoryStage();
        }
       
    }
    else
    {
        start_state = START;
    }

    //ranking 버튼
    if (pt.x > START_BUTTON_X && pt.x<START_BUTTON_X + BUTTON_WIDTH
        && pt.y>RANKING_BUTTON_Y && pt.y < RANKING_BUTTON_Y + BUTTON_HEIGHT)
    {
        ranking_state = RANKING_BORDER;
        if (inputManager.prevKey[VK_LBUTTON] == 1 && inputManager.key[VK_LBUTTON] == 0)
        {
           //stageManager.MakeStoryStage();
        }

    }
    else 
    {
        ranking_state = RANKING;
    }

}