#include "Board.h"

Board::Board() {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			board[j][i] = 0;
		}
	}
}

Board::~Board() {}

void Board::Clone(int target[][3]) {
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			board[j][i] = target[j][i];
		}
	}
}

bool Board::IsFull()
{
	int size = 0;

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			if (!board[j][i])
				size++;
		}
	}

	if (size == 9)
		return true;

	return false;
}

int* Board::operator[](int num)
{
	return board[num];
}
