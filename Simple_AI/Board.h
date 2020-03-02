#pragma once
class Board
{
private:
	int board[3][3];
public:
	Board();
	~Board();

	void Clone(int[][3]);

	bool IsFull();
	
	int* operator[](int);
};

