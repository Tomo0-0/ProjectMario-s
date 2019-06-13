/*スーパーマリオ*/
#include "DxLib.h"

/*構造体の宣言*/

/*列挙体の宣言*/
typedef enum GAME_MODE{
	GAME_TITLE,
	GAME_INIT,
	GAME_END,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER,
	END = 99
};

/*変数の宣言*/
int g_OldKey; // 前回の入力キー
int g_NowKey; // 今回の入力キー
int g_KeyFlg; // 入力キー情報

int g_GameState = GAME_TITLE; // ゲームモード

/*関数のプロトタイプ宣言*/
void GameInit(void);	 //ゲーム初期化処理
void DrawGameTitle(void);//タイトル描画
void DrawEnd(void);		//エンド描画処理

void DrawGameClear(void); //ゲームクリア処理
void DrawGameOver(void); //ゲームオーバー処理

void GameMain(void);	//ゲームメイン処理

int LoadImages();	//画像読込み

/*プログラムの開始*/

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

	SetMainWindowText( " スーパーマリオ " ); // タイトルを設定

	//ChangeWindowMode(TRUE); // ウィンドウモードで起動

	if ( DxLib_Init() == -1 ) return -1; // DX ライブラリの初期化処理

	SetDrawScreen( DX_SCREEN_BACK ); // 描画先画面を裏にする

	if ( LoadImages() == -1 ) return -1; // 画像読込み関数を呼び出し

	// ゲームループ
	while ( ProcessMessage() == 0 && g_GameState != END && !(g_KeyFlg & PAD_INPUT_START)){

		// 入力キー取得
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen(); // 画面の初期化

		switch (g_GameState){
		case GAME_TITLE:
			//DrawGameTitle(); //ゲームタイトル処理
			break;

		case GAME_INIT:
			//GameInit(); //ゲーム初期処理
			break;

		case GAME_END:
			//DrawEnd(); //ゲームエンド処理
			break;

		case GAME_MAIN:
			GameMain(); //ゲームメイン処理
			break;
			
		case GAME_CLEAR:
			//DrawGameClear(); //ゲームクリア処理
			break;

		case GAME_OVER:
			//DrawGameOver(); //ゲームオーバー処理
			break;
		}
		ScreenFlip(); // 裏画面の内容を表画面に反映
	}
	DxLib_End(); // DX ライブラリ使用の終了処理

	return 0; // ソフトの終了
}

/*ゲームタイトル*/
void DrawGameTitle(void){

}

/*エンド描画*/
void DrawEnd(void){

}

/*ゲーム初期処理*/
void GameInit(void){

}

/*ゲームメイン処理*/
void GameMain(void){

}

/*ゲームクリア処理*/
void DrawGameClear(void){

}

/*ゲームオーバー処理*/
void DrawGameOver(void){

}

/*画像読み込み*/
int  LoadImages(){

	return 0;
}