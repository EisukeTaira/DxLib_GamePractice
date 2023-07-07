#include "DxLib.h"

int WINAPI WinMain(_In_ HINSTANCE ih, _In_opt_ HINSTANCE ioh, _In_ LPSTR il, _In_ int ii)
{
	// ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	// DXライブラリの初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// フォントサイズの変更
	SetFontSize(200);



	// 入力待機
	WaitKey();

	// DXライブラリの終了処理
	DxLib_End();

	return 0;
}