#include <iostream>
using namespace std;

//�g���̔z���n���Ă��ꂼ��̕W���̏d��\������֐�	�g��-105��\��
//�ϐ�����|�C���^�̐錾�O��const�����邱�Ƃł��̒��g��ύX���邱�Ƃ��ł��Ȃ��Ȃ�
void dispStandardWeight(const int height[])
{
	cout << "�W���̏d" << endl;
	for (int i = 0; i < 3; i++)
	{
		
		int stdWeight = height[i] - 105;
		cout << i + 1 << ":" << stdWeight << endl;
	}
}

//�g����\������֐�
void dispHeight(int height[])
{
	cout << "�g��" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << i + 1 << ":" << height[i] << endl;
	}
}

struct Test
{
	int testData0;
	int testData1;
};

//�|�C���^���Q�Ƃ�const�ɂ���Ƃ��̃����o�[��ύX�ł��Ȃ��Ȃ�
void testFunc(const Test& Test)
{
	Test->testData0 = 100;
	Test->testData1 = 100;
}

int main()
{
	Test test;
	testFunc(test);

#if false
	//3�l���̐L���f�[�^
	int height[3] = { 170,180,190 };

	//�W���̏d��\������
	dispStandardWeight(height);

	//�g���f�[�^��\������
	dispHeight(height);

	//�W���̏d��\������
	dispStandardWeight(height);
	
	//�g���f�[�^��\������
	dispHeight(height);

#endif
	return 0;
}