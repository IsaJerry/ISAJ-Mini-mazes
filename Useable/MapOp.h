#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <Windows.h>
#include <cstdio>
#include <conio.h>
using namespace std;

struct MapElm
{
	int mark;
	int passable;
	string mapElm;
};

struct Player
{
	int position;
	const string chater = "@";
};

class Map
{
public:
	int goal;
	int plmark;

	Map();
	~Map();
	void MapRead();
	void MapShow();
	void MapShow(int pos);
	int InitPlayer();
	void ShowPlayer();
	int PlayerOpCK();
	int PlayerMove();
	void GameSave(int position);
	int LoadGame();

private:
	fstream fs;
	Player player;
	map<int, MapElm> maplist;
	int margin = 1;
};