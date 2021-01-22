// CAT_ptj.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "CAT_ptj.h"

#include "global.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HWND hWnd;
LPDIRECT3D9         g_pD3D = nullptr;
LPDIRECT3DDEVICE9   g_pd3dDevice = nullptr;
POINT pt;

ID3DXSprite* g_sprite = nullptr;
LPDIRECT3DTEXTURE9 g_texture = nullptr;
ID3DXFont* g_pFont = nullptr;

TextureManager textureManager;
InputManager inputManager;
StageManager stageManager;
GameEntityManager gameEntityManager;

DWORD prevTime = 0;
DWORD fps = 120;

void InitMyObject()
{
    textureManager.LoadTexture(L"stage/title.png", TITLE);
    textureManager.LoadTexture(L"stage/story1.png", STORY1);
    textureManager.LoadTexture(L"stage/story2.png", STORY1+1);
    textureManager.LoadTexture(L"stage/story3.png", STORY1+2);
    textureManager.LoadTexture(L"stage/story4.png", STORY1+3);
    textureManager.LoadTexture(L"stage/story5.png", STORY1+4);
    textureManager.LoadTexture(L"stage/mainstage.png", MAINSTAGE);
    textureManager.LoadTexture(L"stage/loadstage.png", LOADSTAGE);
    textureManager.LoadTexture(L"stage/minigamestage.png", MINIGAMESTAGE);
    textureManager.LoadTexture(L"stage/minigamestage_1.png", MINIGAMESTAGE_1);
    textureManager.LoadTexture(L"stage/minigamestage_2.png", MINIGAMESTAGE_2);
    textureManager.LoadTexture(L"stage/minigamestage_3.png", MINIGAMESTAGE_3);
    textureManager.LoadTexture(L"stage/minigamerunstage.png", MINIGAME_RUN_STAGE);
    textureManager.LoadTexture(L"stage/result.png", RESULT);
    textureManager.LoadTexture(L"stage/gameOver.png", GAME_OVER);
    textureManager.LoadTexture(L"stage/minigamermusicstage.png", MINIGAME_MUSIC_STAGE);
    textureManager.LoadTexture(L"stage/minigamerspstage.png", MINIGAME_R_S_P);
    textureManager.LoadTexture(L"stage/stockstage.png", STOCK_STAGE);
    textureManager.LoadTexture(L"stage/restaurantstage.png", RESTAURANT_STAGE);
    textureManager.LoadTexture(L"stage/restaurantstage_finsh1.png", RESTAURANT_STAGE_f1);
    textureManager.LoadTexture(L"stage/restaurantstage_finsh2.png", RESTAURANT_STAGE_f2);

    textureManager.LoadTexture(L"cat/catNw_1.png", CATN_1);
    textureManager.LoadTexture(L"cat/catNw_2.png", CATN_2);
    textureManager.LoadTexture(L"cat/catNw_3.png", CATN_3);
    /*  textureManager.LoadTexture(L"newtest.png", CATN_1);
      textureManager.LoadTexture(L"newtest.png", CATN_2);
      textureManager.LoadTexture(L"newtest.png", CATN_3);*/
    textureManager.LoadTexture(L"cat/cat_1.png", CATM_1);
    textureManager.LoadTexture(L"cat/cat_2.png", CATM_2);
    textureManager.LoadTexture(L"cat/cat_3.png", CATM_3);
    textureManager.LoadTexture(L"enemy/runEnemy1.png", RUN_ENEMY1);
    textureManager.LoadTexture(L"enemy/runEnemy2.png", RUN_ENEMY2);
    textureManager.LoadTexture(L"enemy/runEnemy3.png", RUN_ENEMY3);
    textureManager.LoadTexture(L"enemy/runEnemy4.png", RUN_ENEMY4);
    textureManager.LoadTexture(L"musicDirections/directions.png", DIRECTIONS);

    //글씨
    textureManager.LoadTexture(L"letter/start.png", START);
    textureManager.LoadTexture(L"letter/start_border.png", START_BORDER);
    textureManager.LoadTexture(L"letter/ranking.png", RANKING);
    textureManager.LoadTexture(L"letter/ranking_border.png", RANKING_BORDER);


    //gameStat.Load();
    stageManager.MakeTitleStage();
}

void Render()
{
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
        D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);


    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        stageManager.Render();
        /*RECT rc;
      SetRect(&rc, WINDOW_WIDTH-500, WINDOW_HEIGHT-500, 0, 0);
      WCHAR text[256];
       WCHAR abc[256] = { 0, };
       char str[256] = "초기화는 필수";
       MultiByteToWideChar(CP_ACP, 0, str, strlen(str), abc, 256);

       _stprintf_s<256>(text, _T("이름:%s"), abc);
       g_pFont->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
           D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f));*/

        g_pd3dDevice->EndScene();
    }


    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}


void Update()
{
    DWORD curTime = timeGetTime();

    DWORD deltaTime = curTime - prevTime;

    if (deltaTime > 1000 / fps)
    {
        //ESC 종료
        if (inputManager.prevKey[VK_ESCAPE] == 1 && inputManager.key[VK_ESCAPE] == 0)
        {
            PostQuitMessage(0);
        }
        if (inputManager.prevKey[VK_F1] == 1 && inputManager.key[VK_F1] == 0)
        {
            //stageManager.MakeTitleStage();
        }

        //마우스 커서 위치
        pt;
        GetCursorPos(&pt);
        ScreenToClient(hWnd, &pt);

        stageManager.Update();
        inputManager.Update();

        prevTime = curTime;
    }

}

void GameLoop()
{
    Update();
    Render();
}

HRESULT InitD3D(HWND hWnd)
{
    // Create the D3D object.
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
     d3dpp.Windowed = TRUE;
     d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
     d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
     d3dpp.EnableAutoDepthStencil = TRUE;
     d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

     //전체화면
   /* d3dpp.Windowed = false;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
    d3dpp.BackBufferWidth = WINDOW_WIDTH;
    d3dpp.BackBufferHeight = WINDOW_HEIGHT;*/

    // Create the D3DDevice
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }

    // Turn on the zbuffer
    g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

    // Turn on ambient lighting 
    g_pd3dDevice->SetRenderState(D3DRS_AMBIENT, 0xffffffff);


    ////폰트 생성
    //HDC hDC = GetDC(NULL);
    //int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
    //ReleaseDC(NULL, hDC);

    /*int fontSize = 15;
    int nHeight = -fontSize * nLogPixelsY / 72;*/

    TCHAR g_strFont[LF_FACESIZE];
    wcscpy_s(g_strFont, 32, L"Arial");

    //D3DXCreateFont(g_pd3dDevice,            // D3D device
    //    nHeight,               // Height
    //    0,                     // Width
    //    FW_BOLD,               // Weight
    //    1,                     // MipLevels, 0 = autogen mipmaps
    //    FALSE,                 // Italic
    //    DEFAULT_CHARSET,       // CharSet
    //    OUT_DEFAULT_PRECIS,    // OutputPrecision
    //    DEFAULT_QUALITY,       // Quality
    //    DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
    //    g_strFont,              // pFaceName
    //    &g_pFont);


    return S_OK;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_CATPTJ, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CATPTJ));

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
            GameLoop();
    }

    return (int)msg.wParam;
}




ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CATPTJ));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   InitD3D(hWnd);
   InitMyObject();

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYUP:
        inputManager.key[wParam] = 0;
        break;
    case WM_KEYDOWN:
        inputManager.key[wParam] = 1;
        break;
    case WM_LBUTTONDOWN:
        inputManager.key[VK_LBUTTON] = 1;
        break;
    case WM_LBUTTONUP:
        inputManager.key[VK_LBUTTON] = 0;
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
