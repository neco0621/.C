#include "DxLib.h"

//�萔
namespace
{
	constexpr int kStartPosX = 320;
	constexpr int kStartPosY = 320;
	//�ړ����x
	constexpr int kSpeed = 2;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
	ChangeWindowMode(true);


	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}

	SetDrawScreen(DX_SCREEN_BACK);
	
	//�O���t�B�b�N�̃��[�h
	int handle = LoadGraph("data/player.png");
	int posX = kStartPosX;
	int posY = kStartPosY;

	//�O���t�B�b�N���]�t���O
	bool isTurn = false;

	//�Q�[�����[�v
	while (ProcessMessage() != -1)
	{
		//���̃t���[���̊J�n�������o���Ă���
		LONGLONG start = GetNowHiPerformanceCount();

		// �`����s���O�ɉ�ʂ��N���A����
		ClearDrawScreen();

		//�Q�[���̏���
		int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
		if (pad & PAD_INPUT_UP)
		{
			//��L�[��������Ă���
			posY -= kSpeed;	//������Ɉړ�������
		}
		if (pad & PAD_INPUT_DOWN)
		{
			//���L�[��������Ă���
			posY += kSpeed;	//�������Ɉړ�������
		}
		if (pad & PAD_INPUT_RIGHT)
		{
			//�E�L�[��������Ă���
			posX += kSpeed;	//�E�����Ɉړ�������
			isTurn = true;
		}
		if (pad & PAD_INPUT_LEFT)
		{
			//���L�[��������Ă���
			posX -= kSpeed;	//�������Ɉړ�������
			isTurn = false;
		}

		//�`��
		if (isTurn)
		{
			DrawTurnGraph(posX, posY, handle, false);	//���E���]�\��
		}
		else
		{
			DrawGraph(posX, posY, handle, false);
		}
		// ��ʂ��؂�ւ��̂�҂�
		ScreenFlip();

		//esc�L�[�ŃQ�[���I��
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		//FPS60�Œ�ɂ���
		while (GetNowHiPerformanceCount() - start < 16667)
		{
			//16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
		}
	}

	//�O���t�B�b�N������������폜
	DeleteGraph(handle);

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}