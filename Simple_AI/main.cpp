#include <iostream>
#include "AI.h"
#include "GameBoard.h"

using namespace std;

int main() {
	GameBoard gameboard;
	AI ai1;

	gameboard.PrintMap();

	Player player = Player::player_2;

	while (true)
	{
		int x;
		int y;

		if (player == Player::player_2) {
			cin >> x;
			cin >> y;

			if (!gameboard.Place({ y, x }, player))
				continue;
		}
		else if (player == Player::player_1) {
			ai1.ComputerPlace(gameboard.GetMap());
		}

		player = player == Player::player_1 ? Player::player_2 : Player::player_1;

		gameboard.PrintMap();

		int winner = gameboard.isWin();

		if (winner) {
			cout << "Winnder is " << winner << endl;
			break;
		}
	}
}