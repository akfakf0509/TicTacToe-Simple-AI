#include "AI.h"
#include <iostream>
#include <conio.h>

using namespace std;

AI::AI() {}
AI::~AI() {}

void AI::ComputerPlace(int board[3][3], int player) {
	int score = -2;
	int moveY = -1, moveX = -1;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (GameBoard::CanPlace({ j,i }, board)) {
				GameBoard::Set({ j,i }, player, board);
				int tempScore = -NegaMax(board, player * -1);
				GameBoard::Set({ j,i }, 0, board);
				if (tempScore >= score) {
					score = tempScore;
					moveY = j;
					moveX = i;
				}
			}
		}
	}
	GameBoard::Place({ moveY,moveX }, (Player)player, board);
}

int AI::NegaMax(int board[3][3], int player) {
	int win = GameBoard::isWin(board);
	if (win)
		return win * player;

	int score = -2;
	bool hasCandidateMove = false;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (GameBoard::CanPlace({ j,i }, board)) {
				GameBoard::Set({ j,i }, player, board);
				int tempScore = -NegaMax(board, player * -1);
				GameBoard::Set({ j,i }, 0, board);

				if (tempScore > score) {
					score = tempScore;
					hasCandidateMove = true;
				}
			}
		}
	}

	if (hasCandidateMove)
		return score;
	else
		return 0;
}