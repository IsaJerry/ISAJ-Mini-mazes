#include "MapOp.h"

Map::Map()
{
}

Map::~Map()
{
}
void Map::MapRead()
{
	int num = 1;
	int mark = 1;
	string line;
	fs.open("./map.txt", ios::in);
	while (getline(fs, line))
	{
		int head = 0;
		for (int i = 1; i < (line.length()); i++)
		{
			maplist[num].mapElm = line.substr(head, 1);
			maplist[num].mark = mark;
			if (maplist[num].mapElm.compare("@") == 0)
			{
				maplist[num].passable = 0;
			}
			else if (maplist[num].mapElm.compare("$") == 0)
			{
				maplist[num].passable = 0;
				goal = num;
			}
			else
			{
				maplist[num].passable = 1;
			}
			num++;
			head++;
		}
		mark++;
	}
	fs.close();
	cout << "地图载入成功！" << "\n";
}

void Map::MapShow()
{
	map<int, MapElm>::iterator it;
	int mark = 1;
	string str = "@";
	for ( it = maplist.begin(); it != maplist.end(); it++)
	{
		if (mark == it->second.mark)
		{
			if (str.compare(it->second.mapElm))
			{
				cout << it->second.mapElm;
			}
			else
			{
				cout << " ";
			}
			margin++;
		}
		else
		{
			if (str.compare(it->second.mapElm))
			{
				cout << "\n" << it->second.mapElm;
			}
			else
			{
				cout << "\n" << " ";
			}
			mark = it->second.mark;
			margin = 1;
		}
	}
	cout << "\n" << "地图加载成功！";
}

void Map::MapShow(int pos)
{
	map<int, MapElm>::iterator it;
	int mark = 1;
	string str = "@";
	for (it = maplist.begin(); it != maplist.end(); it++)
	{
		if (mark == it->second.mark)
		{
			if (str.compare(it->second.mapElm))
			{
				cout << it->second.mapElm;
			}
			else if (it->first == pos)
			{
				cout << player.chater;
			}
			else
			{
				cout << " ";
			}
			margin++;
		}
		else
		{
			if (str.compare(it->second.mapElm))
			{
				cout << "\n" << it->second.mapElm;
			}
			else
			{
				cout << "\n" << " ";
			}
			mark = it->second.mark;
			margin = 1;
		}
	}
	cout << "\n";
}

int Map::InitPlayer()
{
	int row = (int)(maplist.size()) / margin;
	int pos = (row - 1) * margin + 1;
	while (maplist[pos].mapElm.compare("@") != 0)
	{
		pos++;
	}
	plmark = pos;
	return pos;
}

void Map::ShowPlayer()
{
	player.position = InitPlayer();
	system("cls");
	MapShow(player.position);
}

int Map::PlayerOpCK()
{
	int op = _getch();
	system("cls");
	if (op == 52)
	{
		if (maplist[player.position-1].passable != 0)
		{
			return player.position;
		}
		else
		{
			int pp = player.position / margin;
			int pos = pp * margin + 1;
			if ((player.position - 1) >= pos)
			{
				return player.position - 1;
			}
			else
			{
				return player.position;
			}
		}
	}
	else if (op == 54)
	{
		if (maplist[player.position + 1].passable != 0)
		{
			return player.position;
		}
		else
		{
			int pp = player.position / margin;
			int pos = (pp + 1) * margin;
			if ((player.position + 1) <= pos)
			{
				return player.position + 1;
			}
			else
			{
				return player.position;
			}
		}
	}
	else if (op == 56)
	{
		int pp = player.position / margin;
		int res = player.position - (pp * margin + 1);
		if (maplist[((pp - 1) * margin + 1) + res].passable != 0)
		{
			return player.position;
		}
		else
		{
			int pos = ((pp - 1) * margin + 1) + res;
			if (pos > 0)
			{
				return pos;
			}
			else
			{
				return player.position;
			}
		}
	}
	else if (op == 50)
	{
		int pp = player.position / margin;
		int res = player.position - (pp * margin + 1);
		if (maplist[((pp + 1) * margin + 1) + res].passable != 0)
		{
			return player.position;
		}
		else
		{
			int pos = ((pp + 1) * margin + 1) + res;
			if (pos <= maplist.size())
			{
				return pos;
			}
			else
			{
				return player.position;
			}
		}
	}
	else if (op == 27)
	{
		return (op + (int)maplist.size());
	}
	else
	{
		return player.position;
	}
}

int Map::PlayerMove()
{
	int key = PlayerOpCK();
	if ((maplist.size() + 27) == key)
	{
		return key - (int)maplist.size();
	}
	else
	{
		player.position = key;
		MapShow(player.position);
		return player.position;
	}
}

void Map::GameSave(int position)
{
	fs.open("./save.txt", ios::out);
	fs << position;
	fs.close();
	cout << "Game Saved!" << "\n";
}

int Map::LoadGame()
{
	string pos;
	fs.open("./save.txt", ios::in);
	getline(fs, pos);
	int position = stoi(pos);
	fs.close();
	if (position >= 0)
	{
		player.position = position;
		MapRead();
		cout << "加载成功！" << "\n";
		return position;
	}
	else
	{
		cout << "加载失败！" << "\n";
		return -1;
	}
}
