#include <iostream>
using namespace std;

//C�̍�@�@�Y��Ă悵
//#define NUM 3

//C++���萔��`
const int kArraySize = 3;

//�������萔�Ƃ��Ē�`������
const char* const kConstText = "�萔�Ƃ��Ē�`���ꂽ������";

int main()
{
	int tbl[kArraySize] = { 10,20,30 };

	for (int i = 0; i < kArraySize; i++)
	{
		cout << tbl[i] << endl;
	}

	cout << kConstText << endl;

	return 0;
}