#include<iostream>
using namespace std;

void printMsg(void)
{
	cout << "test" << endl;
}

//NG �߂�l���Ⴄ�����̓����֐��͍쐬�ł��Ȃ�
//int printMsg(void)
//{
//	cout << "test2" << endl;
//	return 10;
//}

//�����̐����Ⴆ�Γ������O�̊֐����쐬�ł���
void printMsg(int score)
{
	cout << "�e�X�g�̓_:" << score << endl;
}

//C++�ł͊֐��̈����Ƀf�t�H���g�̒l��ݒ�ł���
struct Player
{
	int hp;
	int mp;
};

//�������̌�� = 50�̂悤�ɏȗ������ꍇ�ɐݒ肳��鐔�l���w��ł���
//������f�t�H���g�����Ƃ���
//�f�t�H���g�������ݒ肳��Ă���ꍇ�A�������ȗ����邱�Ƃ��ł���
//�ȗ������ꍇ�A�������ɂ͐ݒ肵���l������
void initPlayer(Player& player, int hp = 100, int mp = 50)
//void initPlayer(Player& player, int hp = 100, int mp)	//ng �Ō�̈������珇���Ƀf�t�H���g�ݒ�ł���
{
	player.hp = hp;
	player.mp = mp;
}

int main()
{
	Player player;
	initPlayer(player, 200, 0);

	//�L�����N�^�[�I���\
	//100��ނ̃L�����N�^�[������
	// 1�̖ڂ̗͎͑���		HP200,MP0
	// 1�͖̂��@�g��		HP50,MP100
	// ����ȊO��98�̂�		HP100,MP50

	cout << "HP:" << player.hp << endl;
	cout << "MP:" << player.mp << endl;


	return 0;
}