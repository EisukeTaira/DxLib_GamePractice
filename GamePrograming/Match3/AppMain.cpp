/*************************************************
* プログラミング実習
* マッチ３ゲームの制作
**************************************************/
#include "DxLib.h"
#include "FreamControl.h"
#include "InputControl.h"
#include "SceneManager.h"

/*************************************************
* マクロ定義
**************************************************/
#define SCREEN_HEIGHT	(480)		// スクリーンサイズ（高さ）
#define SCREEN_WIDTH	(640)		// スクリーンサイズ（幅）
#define SCREEN_COLORBIT	(32)		// スクリーンカラービット
#define FONT_SIZE		(20)		// 文字サイズ

/*************************************************
* 型定義
**************************************************/


/*************************************************
* グローバル変数宣言
**************************************************/


/*************************************************
* プロトタイプ宣言
**************************************************/



/*************************************************
* プログラムの開始
**************************************************/
int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ウィンドウタイトルの設定
	SetMainWindowText("Match 3 Puzzule");

	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// 画面サイズの最大サイズ, カラービット数の設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLORBIT);


	// DXライブラリの初期化
	if (DxLib_Init() == D_ERROR)
	{
		return D_ERROR;
	}

	// 各機能の初期化処理
	FreamControl_Initialize();
	Input_Initialize();

	// シーンマネージャー初期化処理
	// エラーが発生したら、終了する
	if (SceneManager_Initialize() == D_ERROR)
	{
		return D_ERROR;
	}

	// 描画先画面を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	// フォントサイズの変更
	SetFontSize(FONT_SIZE);

	// ゲームループ
	while (ProcessMessage() != D_ERROR && Input_Escape() == FALSE)
	{
		// 入力制御機能更新処理
		Input_Update();

		// シーンマネージャー更新処理
		SceneManager_Update();

		// 画面クリア
		ClearDrawScreen();

		// シーンマネージャー描画処理
		SceneManager_Draw();

		// フレームレート制御処理
		FreamCotrol_Update();

		// 画面の内容を表画面に反映
		ScreenFlip();

	}

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}
