#pragma once

typedef enum { player_1 = 100, player_2 }Player;
typedef struct { int y; int x; }Vector2;

class GameBoard
{
private:
	int map[3][3] = { {0,}, };
	int place_count = 0;
public:
	GameBoard();
	~GameBoard();

	bool Place(Vector2, Player);
	static bool Place(Vector2, Player, int[3][3]);

	void Set(Vector2, int);
	static void Set(Vector2, int, int[3][3]);

	bool CanPlace(Vector2);
	static bool CanPlace(Vector2, int[3][3]);

	void PrintMap();
	static void PrintMap(int[3][3]);

	int isWin();
	static int isWin(int[3][3]);

	int(*GetMap())[3];
};

