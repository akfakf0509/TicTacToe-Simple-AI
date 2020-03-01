#pragma once

typedef enum { player_1 = 100, player_2 }Player;

class GameSystem
{
private:
	int map[3][3];
public:
	GameSystem();
	~GameSystem();

	void PrintMap();

	bool Place(int, int, Player);

	int CheckWinner();
	int CheckWinner(int, int);
};

