#include <iostream>
using namespace std;

//C�̍�@�@�Y��Ă悵
//#define NUM 3

//C++���萔��`
//const int kArraySize = 3;	//�萔��`�Ƃ��Ă������̏������͂�����ƌÂ�

//����IC++�̒萔��`
namespace
{
	constexpr int kConstexprNum = 3;		//constexpr:�萔���`���邽�߂ɏ������ꂽ������
											//�R���p�C�����_�Œl�����܂��Ă���ꍇ�͂�����
	const int kConstNum = 3;				//const:�ϐ��̕ύX��s�\�ɂ��邽�߂̏�����
											//�ŏ��Ɍ��߂��l����ύX�ł��Ȃ��Ƃ��������𗘗p����
											//�萔��`�Ɏg�p���Ă���
}

//�萔��`�̂܂Ƃ�
//namespace(�������O��� ���O���ݒ肳��Ă��Ȃ�namespace)�̒��ɓ����
//�������O��Ԃ̒��ɏ����Ă���ϐ���萔�A�֐��͂��̃\�[�X�R�[�h�݂̂ŗL��
namespace
{
	//��{�I�ɒ萔��constexpr�Œ�`����
	//�萔����google�̃R�[�f�B���O�K�񏀋�
	//�萔���̖����K���͂ق��̃��[���������Ȃ炻��ł������K�����ꂷ�邱��
	constexpr int kNum = 16;

	constexpr int kDoubleNum = kNum * 2;	//�萔���g�p���Ē萔���`���邱�Ƃ��\
	constexpr float kFloatNum = 12.25f;		//int�ȊO�ł�OK

}	//namespace�I�����Z�~�R�����s�v

namespace
{
	constexpr int kEnemyNum = 16;
}
//�������萔�Ƃ��Ē�`������
const char* const kConstText = "�萔�Ƃ��Ē�`���ꂽ������";
const char* const kFileName = "data/image.png";		//�t�@�C�������`����

//pNum�̎Q�Ɛ�ύX�s��
//pNum�ɒ��g�Œ�ł͂Ȃ�	�������͂ł���Ƃ�������
void func(const int* pNum)
{

}

int main()
{
	//constexpr,const���ɒl��ύX���邱�Ƃ͂ł��Ȃ�
	/*kConstexprNum = 10;
	kConstNum = 10;*/

	//const�͏������͂ł���
	const int constNum = rand() % 16;
	//�ォ��ύX�͂ł��Ȃ�
	//constNum = 10;

	//ng �R���p�C���������_�Œl�����܂�Ȃ�
	//constexpr int constexprNum = rand() % 16;

	//�萔��`��constexpr���g��
	//����ȊO�̕ύX�����Ăق����Ȃ��l��const���g��

#if false
	int tbl[kArraySize] = { 10,20,30 };

	for (int i = 0; i < kArraySize; i++)
	{
		cout << tbl[i] << endl;
	}

	cout << kConstText << endl;
#endif

	return 0;
}