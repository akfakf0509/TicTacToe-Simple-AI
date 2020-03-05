#pragma once
#include "GameBoard.h"
class AI
{
public:
	AI();
	~AI();

	void ComputerPlace(int[3][3], int);
	int NegaMax(int[3][3], int);
};

