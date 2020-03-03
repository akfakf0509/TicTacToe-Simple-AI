#pragma once
#include <vector>
#include "GameSystem.h"

class Node
{
private:
	int key;
	Vector2 position;
	Player player;
	std::vector<Node*> childs;
public:
	Node();
	Node(int, int, Player);
	~Node();

	void SetX(int);
	void SetY(int);
	void SetPlayer(Player);

	int GetX();
	int GetY();
	int GetKey();
	Player GetPlayer();
};

