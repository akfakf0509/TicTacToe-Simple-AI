#pragma once
#include <map>
#include "Board.h"

using namespace std;

class AI
{
private:
	map<int, Board> tree;
public:
	AI();
	~AI();

	void PrintTree();

	map<int, Board>* GetMap();
};