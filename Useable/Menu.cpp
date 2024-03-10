#include "MapOp.h"

void Menu(int pos)
{
	if (pos)
	{
		cout << "---1.���ص�ͼ----" << "\n";
		cout << "---2.��ʼ��Ϸ----" << "\n";
		cout << "---3.������Ϸ----" << "\n";
		cout << "---4.������Ϸ----" << "\n";
		cout << "---5.�������˵�--" << "\n";
		cout << "---6.�˳���Ϸ----" << "\n";
	}
	else
	{
		cout << "�ϣ�8  �£�2  ��4  �ң�6  �˵���ESC" << "\n";
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