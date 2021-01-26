#include "game_stage_ui.h"
#include "global.h"
#include <tchar.h>

GameStageUi::GameStageUi()
{
	//폰트1 생성
	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);
	int fontSize = 30;
	int nHeight = -fontSize * nLogPixelsY / 72;
	TCHAR g_strFont[LF_FACESIZE];
	wcscpy_s(g_strFont, 32, L"Arial");
	D3DXCreateFont(g_pd3dDevice,            // D3D device
		nHeight,               // Height
		0,                     // Width
		FW_BOLD,               // Weight
		1,                     // MipLevels, 0 = autogen mipmaps
		FALSE,                 // Italic
		DEFAULT_CHARSET,       // CharSet
		OUT_DEFAULT_PRECIS,    // OutputPrecision
		DEFAULT_QUALITY,       // Quality
		DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
		g_strFont,              // pFaceName
		&font1);
}

void GameStageUi::Render()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	WCHAR text[256];

	//고양이
	element = textureManager.GetTexture(CAT_UI);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 40;
	rc.bottom = 40;

	float n = (WINDOW_WIDTH / 2 - EXP_TEXTURE_WIDTH / 2) + float(EXP_TEXTURE_WIDTH) / (gameEntityManager.timeOut+150.0) * gameEntityManager.time;
	pos = {  n, 10, 0 };
	//cen = { EXP_TEXTURE_WIDTH / 2 , 0, 0 };

	element->g_pSprite->Draw(element->g_Texture, &rc, nullptr, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();


	//EXP_배경
	element = textureManager.GetTexture(EXP_01);
	element->g_pSprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = EXP_TEXTURE_WIDTH;;
	rc.bottom = EXP_TEXTURE_HEIGHT;

	pos = { WINDOW_WIDTH / 2, 10, 0 };
	cen = { EXP_TEXTURE_WIDTH / 2 , 0, 0 };

	element->g_pSprite->Draw(element->g_Texture, &rc, &cen, &pos, D3DCOLOR_XRGB(255, 255, 255));
	element->g_pSprite->End();

	//디버깅

	 //점수
	rc;
	rc.left = 100;
	rc.top = 100;
	text[256];
	int t = gameEntityManager.time;
	_stprintf_s<256>(text, _T("score: %d"), t);
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));
}

void GameStageUi::Update()
{

}