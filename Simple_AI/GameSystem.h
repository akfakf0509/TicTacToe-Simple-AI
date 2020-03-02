#pragma once
#include "Board.h"

typedef enum { player_1 = 100, player_2 }Player;

class GameSystem
{
private:
	Board map;
public:
	GameSystem();
	~GameSystem();

	void PrintMap();
	void PrintMap(Board, int);

	Board* GetMap();

	bool Place(int, int, Player);

	int CheckWinner();
	int CheckWinner(int, int);
};

