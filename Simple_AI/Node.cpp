#include "Node.h"

Node::Node() : key(0), position({ 0,0 }), player(Player::player_1) {}

Node::Node(int x_, int y_, Player player_) : key(3 * y_ + x_), position({ x_,y_ }), player(player_) {}

Node::~Node() {}

void Node::SetX(int x_) {
	position.x = x_;
}

void Node::SetY(int y_) {
	position.y = y_;
}

void Node::SetPlayer(Player player_) {
	player = player_;
}

int Node::GetX() {
	return position.x;
}

int Node::GetY() {
	return position.y;
}

int Node::GetKey() {
	return key;
}

Player Node::GetPlayer() {
	return player;
}