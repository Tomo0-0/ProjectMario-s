/*�X�[�p�[�}���I*/
#include "DxLib.h"

/*�\���̂̐錾*/

/*�񋓑̂̐錾*/
typedef enum GAME_MODE{
	GAME_TITLE,
	GAME_INIT,
	GAME_END,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER,
	END = 99
};

/*�ϐ��̐錾*/
int g_OldKey; // �O��̓��̓L�[
int g_NowKey; // ����̓��̓L�[
int g_KeyFlg; // ���̓L�[���

int g_GameState = GAME_TITLE; // �Q�[�����[�h

/*�֐��̃v���g�^�C�v�錾*/
void GameInit(void);	 //�Q�[������������
void DrawGameTitle(void);//�^�C�g���`��
void DrawEnd(void);		//�G���h�`�揈��

void DrawGameClear(void); //�Q�[���N���A����
void DrawGameOver(void); //�Q�[���I�[�o�[����

void GameMain(void);	//�Q�[�����C������

int LoadImages();	//�摜�Ǎ���

/*�v���O�����̊J�n*/

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){

	SetMainWindowText( " �X�[�p�[�}���I " ); // �^�C�g����ݒ�

	//ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��

	if ( DxLib_Init() == -1 ) return -1; // DX ���C�u�����̏���������

	SetDrawScreen( DX_SCREEN_BACK ); // �`����ʂ𗠂ɂ���

	if ( LoadImages() == -1 ) return -1; // �摜�Ǎ��݊֐����Ăяo��

	// �Q�[�����[�v
	while ( ProcessMessage() == 0 && g_GameState != END && !(g_KeyFlg & PAD_INPUT_START)){

		// ���̓L�[�擾
		g_OldKey = g_NowKey;
		g_NowKey = GetJoypadInputState( DX_INPUT_KEY_PAD1 );
		g_KeyFlg = g_NowKey & ~g_OldKey;

		ClearDrawScreen(); // ��ʂ̏�����

		switch (g_GameState){
		case GAME_TITLE:
			//DrawGameTitle(); //�Q�[���^�C�g������
			break;

		case GAME_INIT:
			//GameInit(); //�Q�[����������
			break;

		case GAME_END:
			//DrawEnd(); //�Q�[���G���h����
			break;

		case GAME_MAIN:
			GameMain(); //�Q�[�����C������
			break;
			
		case GAME_CLEAR:
			//DrawGameClear(); //�Q�[���N���A����
			break;

		case GAME_OVER:
			//DrawGameOver(); //�Q�[���I�[�o�[����
			break;
		}
		ScreenFlip(); // ����ʂ̓��e��\��ʂɔ��f
	}
	DxLib_End(); // DX ���C�u�����g�p�̏I������

	return 0; // �\�t�g�̏I��
}

/*�Q�[���^�C�g��*/
void DrawGameTitle(void){

}

/*�G���h�`��*/
void DrawEnd(void){

}

/*�Q�[����������*/
void GameInit(void){

}

/*�Q�[�����C������*/
void GameMain(void){

}

/*�Q�[���N���A����*/
void DrawGameClear(void){

}

/*�Q�[���I�[�o�[����*/
void DrawGameOver(void){

}

/*�摜�ǂݍ���*/
int  LoadImages(){

	return 0;
}