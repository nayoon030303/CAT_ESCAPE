#pragma once

#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )

#include "textureManager.h"
#include "inputManager.h"
#include "stageManager.h"
#include "gameEntityManager.h"
#include "gameplay_director.h"
#include "gamemap_direction.h"
#include "mapManager.h"
#include "SDKsound.h"
#include "SDKwavefile.h"
//#include "player.h"


//윈도우 사이즈
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 1024

//클래스 타입
#define MINI_GAME_CHOOSE 2000
#define TITLE_STAGE 2001
#define STORY1_STAGE 2002
//#define MINI_GAME_RUN_STAGE 2003
//#define MAIN_STAGE 2004
//#define LOAD_STAGE 2005
//#define MINI_GAME_MUSIC_STAGE 2006
//

//이미지 넘버//

//배경(stage)
#define TITLE 100
#define STORY1 200
#define MAINSTAGE 300
#define HOLE_1 310
#define HOLE_2 320
#define LOADSTAGE 400
#define LOAD_SQUARE 500
#define MINIGAMESTAGE 600
#define MINIGAME_RUN_STAGE 700
#define RESULT 800
#define GAME_OVER 900
#define MINIGAME_MUSIC_STAGE 1000
#define MINIGAMESTAGE_1 1100
#define MINIGAMESTAGE_2 1200
#define MINIGAMESTAGE_3 1300
#define MINIGAME_R_S_P 1400
#define STOCK_STAGE 1500
#define RESTAURANT_STAGE 1600
#define RESTAURANT_STAGE_f1 1700
#define RESTAURANT_STAGE_f2 1800
#define GROUND 1900
#define GROUND_EMPTY 2000

//오브젝트
#define CATN_1 1
#define CATN_2 2
#define CATN_3 3
#define CATM_1 10
#define CATM_2 20
#define CATM_3 30

#define RUN_ENEMY1 40
#define RUN_ENEMY2 50
#define RUN_ENEMY3 60
#define RUN_ENEMY4 70

#define DIRECTIONS 80
#define R_S_P 90

#define GAME_OUT 2500


//ui
#define START 2100
#define START_BORDER 2200
#define RANKING 2300
#define RANKING_BORDER 2400
#define EXP_01 2500
#define CAT_UI 2600


//이미지 크기
#define CAT_WIDTH 150
#define CAT_HEIGHT 200
#define RUN_ENEMY1_WIDTH  130
#define RUN_ENEMY1_HEIGHT  160
#define RUN_ENEMY2_WIDTH  100
#define RUN_ENEMY2_HEIGHT  230
#define RUN_ENEMY3_WIDTH  250
#define RUN_ENEMY3_HEIGHT  150
#define RUN_ENEMY4_WIDTH  150
#define RUN_ENEMY4_HEIGHT  130
#define GAME_OVER_TEXTURE_WIDTH 1150
#define GAME_OVER_TEXTULRE_HEIGHT 800
#define MINIGAME_BUTTON_WIDTH 200
#define MINIGAME_BUTTON_HEIGHT 80
#define BOTTOM_Y  900
#define EXP_TEXTURE_WIDTH 1024
#define EXP_TEXTURE_HEIGHT 32


//위치
#define MINIGAME_BUTTON_X 980
#define MINIGAME_BUTTON_Y 780

#define SPEED 15;


extern HWND hWnd;
extern LPDIRECT3D9         g_pD3D;
extern LPDIRECT3DDEVICE9   g_pd3dDevice;
extern POINT pt;

//all the managers...
extern GameEntityManager gameEntityManager;
extern MapManager mapManager;
extern  TextureManager textureManager;
extern InputManager inputManager;
extern StageManager stageManager;
//extern GameStat gameStat;
//extern vector<Player> playerInfos;	//데이터 저장
//extern Player* player; 
extern CSoundManager soundManager;

extern GameplayDirector director_enemy;
extern GameMapDirection director_map;