#include "map_ground.h"
#include "global.h"

Map_ground::Map_ground()
{

}

void Map_ground::Render()
{
	TextureElement* element = textureManager.GetTexture(GROUND);
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

void Map_ground::Update()
{
	if (!gameEntityManager.runPlayer->getIsDead())
	{
		x -= speed;
	}
}