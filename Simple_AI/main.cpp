#include <iostream>
#include "GameSystem.h"

using namespace std;

int main() {
	GameSystem gamesystem;

	int x, y, turn = 0;

	while (true)
	{
		gamesystem.PrintMap();

		cin >> x;
		cin >> y;
		
		if (!gamesystem.Place(x, y, turn ? Player::player_1 : Player::player_2)) {
			continue;
		}
		turn = !turn;

		int winner = gamesystem.CheckWinner(x, y);
		
		cout << winner << endl;

		if (winner) {
			break;
		}
	}
}