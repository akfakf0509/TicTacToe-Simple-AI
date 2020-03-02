#include <iostream>
#include <Windows.h>
#include "GameSystem.h"
#include "AI.h"
#include "Board.h"

using namespace std;

int main() {
	GameSystem gamesystem;
	AI ai1;

	int x, y, turn = 0, key = 0;

	while (true)
	{
		gamesystem.PrintMap();

		cin >> x;
		cin >> y;
		
		if (!gamesystem.Place(x, y, turn ? Player::player_1 : Player::player_2)) {
			continue;
		}

		ai1.GetMap()->insert(pair<int, Board>(key++, *gamesystem.GetMap()));

		turn = !turn;
		
		int winner = gamesystem.CheckWinner(x, y);
		
		cout << winner << endl;

		if (winner) {
			gamesystem.PrintMap();
			break;
		}
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	ai1.PrintTree();
}

/*
0 0
1 0
0 1
1 1
0 2
*/