#include<iostream>
using namespace std;

int main()
{
	bool isFlag = true;
#if false
	if (isFlag)
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
#else
	//3項演算子を使って書き換え
	cout << (isFlag ? "TRUE" : "FALSE") << endl;
#endif

	return 0;
}
