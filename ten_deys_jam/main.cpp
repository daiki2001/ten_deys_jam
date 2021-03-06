#include <DxLib.h>
#include "./Header/SceneMgr.h"
#include "./Header/Input.h"
#include "./Header/fps.h"

// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "201_TurnLeft";

// ウィンドウ横幅
const int WIN_WIDTH = 640 + 250;

// ウィンドウ縦幅
const int WIN_HEIGHT = 640;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

#ifdef _DEBUG
	//デバッグ用画面サイズ
	SetGraphMode(WIN_WIDTH + 210, WIN_HEIGHT, 32);
#else
	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
#endif // DEBUG

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み

	// ゲームループで使う変数の宣言
	SceneMgr scenemgr;
	scenemgr.Initialize();

	// ゲームループ
	while (1)
	{
		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		Input::Update();
		scenemgr.Update();

		// 描画処理
		scenemgr.Draw();

		fps::Update();
		fps::Draw(WIN_WIDTH + 10, 30);

		DrawFormatString(WIN_WIDTH + 10, 50, GetColor(255, 255, 255), "mCount : %d", fps::GetFrameCount());
		DrawFormatString(WIN_WIDTH + 10, 70, GetColor(255, 255, 255), "frame  : %d", fps::GetFrame());

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();	

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1)
		{
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)
		{
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}