#include "storyStage.h"
#include "global.h"
#include "StageManager.h"


StoryStage::StoryStage()
{
    classType = STORY1_STAGE;
}

void StoryStage::Render()
{
    TextureElement* element = textureManager.GetTexture(STORY1+count);
    element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

    RECT srcRect;
    srcRect.left = 0;
    srcRect.top = 0;
    srcRect.right = WINDOW_WIDTH;
    srcRect.bottom = WINDOW_HEIGHT;

    element->g_pSprite->Draw(element->g_Texture, &srcRect, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
    element->g_pSprite->End();

}

void StoryStage::Update()
{
    count += 1;
    if (count >= 5) {
        stageManager.MakeMainStage();
    }
}