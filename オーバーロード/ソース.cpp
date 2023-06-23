#include<iostream>
using namespace std;

void printMsg(void)
{
	cout << "test" << endl;
}

//NG 戻り値が違うだけの同名関数は作成できない
//int printMsg(void)
//{
//	cout << "test2" << endl;
//	return 10;
//}

//引数の数が違えば同じ名前の関数を作成できる
void printMsg(int score)
{
	cout << "テストの点:" << score << endl;
}

//C++では関数の引数にデフォルトの値を設定できる
struct Player
{
	int hp;
	int mp;
};

//仮引数の後に = 50のように省略した場合に設定される数値を指定できる
//これをデフォルト引数という
//デフォルト引数が設定されている場合、引数を省略することができる
//省略した場合、仮引数には設定した値が入る
void initPlayer(Player& player, int hp = 100, int mp = 50)
//void initPlayer(Player& player, int hp = 100, int mp)	//ng 最後の引数から順次にデフォルト設定できる
{
	player.hp = hp;
	player.mp = mp;
}

int main()
{
	Player player;
	initPlayer(player, 200, 0);

	//キャラクター選択可能
	//100種類のキャラクターがいる
	// 1体目は体力自慢		HP200,MP0
	// 1体は魔法使い		HP50,MP100
	// それ以外の98体は		HP100,MP50

	cout << "HP:" << player.hp << endl;
	cout << "MP:" << player.mp << endl;


	return 0;
}