#include <iostream>
using namespace std;

//Cの作法　忘れてよし
//#define NUM 3

//C++風定数定義
const int kArraySize = 3;

//文字列を定数として定義したい
const char* const kConstText = "定数として定義された文字列";

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