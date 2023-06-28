#include "DxLib.h"

//定数
namespace
{
	constexpr int kStartPosX = 320;
	constexpr int kStartPosY = 320;
	//移動速度
	constexpr int kSpeed = 2;
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	SetDrawScreen(DX_SCREEN_BACK);
	
	//グラフィックのロード
	int handle = LoadGraph("data/player.png");
	int posX = kStartPosX;
	int posY = kStartPosY;

	//グラフィック反転フラグ
	bool isTurn = false;

	//ゲームループ
	while (ProcessMessage() != -1)
	{
		//このフレームの開始時刻を覚えておく
		LONGLONG start = GetNowHiPerformanceCount();

		// 描画を行う前に画面をクリアする
		ClearDrawScreen();

		//ゲームの処理
		int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (pad & PAD_INPUT_UP)
		{
			//上キーが押されている
			posY -= kSpeed;	//上方向に移動させる
		}
		if (pad & PAD_INPUT_DOWN)
		{
			//下キーが押されている
			posY += kSpeed;	//下方向に移動させる
		}
		if (pad & PAD_INPUT_RIGHT)
		{
			//右キーが押されている
			posX += kSpeed;	//右方向に移動させる
			isTurn = true;
		}
		if (pad & PAD_INPUT_LEFT)
		{
			//左キーが押されている
			posX -= kSpeed;	//左方向に移動させる
			isTurn = false;
		}

		//描画
		if (isTurn)
		{
			DrawTurnGraph(posX, posY, handle, false);	//左右反転表示
		}
		else
		{
			DrawGraph(posX, posY, handle, false);
		}
		// 画面が切り替わるのを待つ
		ScreenFlip();

		//escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60固定にする
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	//グラフィックをメモリから削除
	DeleteGraph(handle);

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}