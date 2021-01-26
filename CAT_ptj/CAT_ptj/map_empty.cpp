#include "map_empty.h"
#include "global.h"

Map_empty::Map_empty()
{

}

void Map_empty::Render()
{
	TextureElement* element = textureManager.GetTexture(GROUND_EMPTY);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = 250;
	rc.bottom = 250;

	//int sx = (int(screenX) % 2400);

	D3DXVECTOR3 pos(x, y, 0);

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();
}

void Map_empty::Update()
{
	if (!gameEntityManager.runPlayer->getIsDead())
	{
		x -= speed;
	}
}