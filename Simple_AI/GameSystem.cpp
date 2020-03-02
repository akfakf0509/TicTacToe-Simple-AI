#include "GameSystem.h"
#include <iostream>
#include <Windows.h>

using namespace std;

GameSystem::GameSystem() {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			map[j][i] = 0;
		}
	}
}

GameSystem::~GameSystem() {}

void GameSystem::PrintMap() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			switch (map[j][i]) {
			case 0:
				cout << "  ";
				break;
			case Player::player_1:
				cout << "¡Û";
				break;
			case Player::player_2:
				cout << "¡Ü";
				break;
			}
		}
		cout << endl;
	}
}

void GameSystem::PrintMap(Board map_, int do_clear) {
	if(do_clear)
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			switch (map_[j][i]) {
			case 0:
				cout << "  ";
				break;
			case Player::player_1:
				cout << "¡Û";
				break;
			case Player::player_2:
				cout << "¡Ü";
				break;
			}
		}
		cout << endl;
	}
}

Board* GameSystem::GetMap() {
	return &map;
}

bool GameSystem::Place(int x, int y, Player player) {
	if (map[y][x] != 0 || x < 0 || y < 0 || x >= 3 || y >= 3)
		return false;

	map[y][x] = player;
	
	return true;
}

int GameSystem::CheckWinner() {
	int check[8] = { 0, };

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (map[j][i] == Player::player_1) {
				check[i]++;
				check[3 + j]++;
			}
			else if (map[j][i] == Player::player_2) {
				check[i]--;
				check[3 + j]--;
			}

			if (j == i) {
				if (map[j][i] == Player::player_1) {
					check[6]++;
				}
				else if (map[j][i] == Player::player_2) {
					check[6]--;
				}
			}

			if (j == -i + 2) {
				if (map[j][i] == Player::player_1) {
					check[7]++;
				}
				else if (map[j][i] == Player::player_2) {
					check[7]--;
				}
			}
		}
	}

	for (int i = 0; i < 8; i++) {
		if (check[i] == 3) {
			return Player::player_1;
		}
		else if (check[i] == -3) {
			return Player::player_2;
		}
	}

	return 0;
}

int GameSystem::CheckWinner(int x,int y) {
	int check = 0;

	for (int i = 0; i < 3; i++) {
		if (map[y][i] == Player::player_1)
			check++;
		else if (map[y][i] == Player::player_2)
			check--;
	}

	if (check == 3) {
		return Player::player_1;
	}
	else if (check == -3) {
		return Player::player_2;
	}
	
	check = 0;

	for (int i = 0; i < 3; i++) {
		if (map[i][x] == Player::player_1)
			check++;
		else if (map[i][x] == Player::player_2)
			check--;
	}

	if (check == 3) {
		return Player::player_1;
	}
	else if (check == -3) {
		return Player::player_2;
	}

	check = 0;

	if (y == x) {
		for (int i = 0; i < 3; i++) {
			if (map[i][i] == Player::player_1)
				check++;
			else if (map[i][i] == Player::player_2)
				check--;
		}

		if (check == 3) {
			return Player::player_1;
		}
		else if (check == -3) {
			return Player::player_2;
		}

		check = 0;
	}

	if (y == -x + 2) {
		for (int i = 0; i < 3; i++) {
			if (map[i][-i + 2] == Player::player_1)
				check++;
			else if (map[i][-i + 2] == Player::player_2)
				check--;
		}

		if (check == 3) {
			return Player::player_1;
		}
		else if (check == -3) {
			return Player::player_2;
		}
	}

	return 0;
}