#include "GameBoard.h"
#include <iostream>
#include <Windows.h>

using namespace std;

GameBoard::GameBoard() {}

GameBoard::~GameBoard() {}

bool GameBoard::Place(Vector2 position, Player player) {
	if (map[position.y][position.x] || position.x < 0 || position.x > 2 || position.y < 0 || position.y > 2)
		return false;
	map[position.y][position.x] = player;
	return true;
}

bool GameBoard::Place(Vector2 position, Player player, int board[3][3]) {
	if (board[position.y][position.x] || position.x < 0 || position.x > 2 || position.y < 0 || position.y > 2)
		return false;
	board[position.y][position.x] = player;
	return true;
}

void GameBoard::Set(Vector2 position, int player) {
	map[position.y][position.x] = player;
}

void GameBoard::Set(Vector2 position, int player, int board[3][3]) {
	board[position.y][position.x] = player;
}

bool GameBoard::CanPlace(Vector2 position) {
	return !(map[position.y][position.x] || position.x < 0 || position.x > 2 || position.y < 0 || position.y > 2);
}

bool GameBoard::CanPlace(Vector2 position, int board[3][3]) {
	return !(board[position.y][position.x] || position.x < 0 || position.x > 2 || position.y < 0 || position.y > 2);
}

void GameBoard::PrintMap() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			switch (map[j][i])
			{
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

void GameBoard::PrintMap(int board[3][3]) {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			switch (board[j][i])
			{
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

int GameBoard::isWin() {
	int wins[8][3] = { { 0, 1, 2 }, { 3 ,4 ,5 }, { 6 ,7 ,8 }, { 0 ,3 ,6 }, { 1 ,4 ,7 }, { 2 ,5 ,8 }, { 0 ,4 ,8 }, { 2, 4, 6 } };

	for (int i = 0; i < 8; i++) {
		if (map[wins[i][0] / 3][wins[i][0] % 3] != 0 &&
			map[wins[i][0] / 3][wins[i][0] % 3] == map[wins[i][1] / 3][wins[i][1] % 3] &&
			map[wins[i][1] / 3][wins[i][1] % 3] == map[wins[i][2] / 3][wins[i][2] % 3]) {
			return map[wins[i][2] / 3][wins[i][2] % 3];
		}
	}

	return 0;
}

int GameBoard::isWin(int board[3][3]) {
	int wins[8][3] = { { 0, 1, 2 }, { 3 ,4 ,5 }, { 6 ,7 ,8 }, { 0 ,3 ,6 }, { 1 ,4 ,7 }, { 2 ,5 ,8 }, { 0 ,4 ,8 }, { 2, 4, 6 } };

	for (int i = 0; i < 8; i++) {
		if (board[wins[i][0] / 3][wins[i][0] % 3] != 0 &&
			board[wins[i][0] / 3][wins[i][0] % 3] == board[wins[i][1] / 3][wins[i][1] % 3] &&
			board[wins[i][1] / 3][wins[i][1] % 3] == board[wins[i][2] / 3][wins[i][2] % 3]) {
			return board[wins[i][2] / 3][wins[i][2] % 3];
		}
	}

	return 0;
}

int(*GameBoard::GetMap())[3]{
	return map;
}