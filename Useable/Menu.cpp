#include "MapOp.h"

void Menu(int pos)
{
	if (pos)
	{
		cout << "---1.加载地图----" << "\n";
		cout << "---2.开始游戏----" << "\n";
		cout << "---3.加载游戏----" << "\n";
		cout << "---4.保存游戏----" << "\n";
		cout << "---5.返回主菜单--" << "\n";
		cout << "---6.退出游戏----" << "\n";
	}
	else
	{
		cout << "上：8  下：2  左：4  右：6  菜单：ESC" << "\n";
	}
}
int main()
{
	Map game;
	int pos = 1;
	int player = game.plmark;
	while (pos)
	{
		Menu(1);
		int key = _getch();
		switch (key)
		{
		case 49:
			game.MapRead();
			break;
		case 50:
			game.MapShow();
			game.ShowPlayer();
			while (player != game.goal)
			{
				Menu(0);
				int check = game.PlayerMove();
				if (check == 27)
				{
					break;
				}
				else
				{
					player = check;
				}
			}
			if (player == game.goal)
			{
				cout << "Game Clear!" << "\n";
				Menu(0);
				system("PAUSE");
				player = game.plmark;
				system("cls");
			}
			break;
		case 51:
			player = game.LoadGame();
			system("cls");
			game.MapShow(player);
			while (pos != game.goal)
			{
				Menu(0);
				int check = game.PlayerMove();
				if (check == 27)
				{
					break;
				}
				else
				{
					player = check;
				}
			}
			if (player == game.goal)
			{
				cout << "Game Clear!" << "\n";
				Menu(0);
				system("PAUSE");
				player = game.plmark;
				system("cls");
			}
			break;
		case 52:
			game.GameSave(player);
			system("PAUSE");
			system("cls");
			break;
		case 54:
			pos = 0;
			system("cls");
			break;
		default:
			break;
		}
	}
}