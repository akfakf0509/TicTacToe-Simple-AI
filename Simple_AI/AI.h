#pragma once
#include "Board.h"

using namespace std;

class AI
{
public:	
	AI();
	~AI();

	Vector2 Place(Board);
};