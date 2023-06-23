#include <iostream>
using namespace std;

//Cの作法　忘れてよし
//#define NUM 3

//C++風定数定義
//const int kArraySize = 3;	//定数定義としてこっちの書き方はちょっと古い

//現代的C++の定数定義
namespace
{
	constexpr int kConstexprNum = 3;		//constexpr:定数を定義するために準備された書き方
											//コンパイル時点で値が決まっている場合はこっち
	const int kConstNum = 3;				//const:変数の変更を不可能にするための書き方
											//最初に決めた値から変更できないという性質を利用して
											//定数定義に使用していた
}

//定数定義のまとめ
//namespace(無名名前空間 名前が設定されていないnamespace)の中に入れる
//無名名前空間の中に書いてある変数や定数、関数はそのソースコードのみで有効
namespace
{
	//基本的に定数はconstexprで定義する
	//定数名はgoogleのコーディング規約準拠
	//定数名の命名規則はほかのルールがいいならそれでいいが必ず統一すること
	constexpr int kNum = 16;

	constexpr int kDoubleNum = kNum * 2;	//定数を使用して定数を定義することも可能
	constexpr float kFloatNum = 12.25f;		//int以外でもOK

}	//namespace終了時セミコロン不要

namespace
{
	constexpr int kEnemyNum = 16;
}
//文字列を定数として定義したい
const char* const kConstText = "定数として定義された文字列";
const char* const kFileName = "data/image.png";		//ファイル名を定義する

//pNumの参照先変更不可
//pNumに中身固定ではない	初期化はできるということ
void func(const int* pNum)
{

}

int main()
{
	//constexpr,const共に値を変更することはできない
	/*kConstexprNum = 10;
	kConstNum = 10;*/

	//constは初期化はできる
	const int constNum = rand() % 16;
	//後から変更はできない
	//constNum = 10;

	//ng コンパイルした時点で値が決まらない
	//constexpr int constexprNum = rand() % 16;

	//定数定義はconstexprを使う
	//それ以外の変更をしてほしくない値はconstを使う

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