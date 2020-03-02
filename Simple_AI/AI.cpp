#include "AI.h"
#include "GameSystem.h"
#include <iostream>

using namespace std;

AI::AI() {}

AI::~AI() {}

void AI::PrintTree() {
	GameSystem gamesystem;

	for (int i = 0; i < tree.size(); i++) {

		gamesystem.PrintMap(tree[i], false);
		cout << tree.size() << " " << &tree[i] <<  endl;
	}
}

map<int, Board>* AI::GetMap() {
	return &tree;
}