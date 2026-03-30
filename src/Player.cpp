#include "Player.h"

Player::Player(char c) : symbol(c) {}

char Player::getSymbol() const {
	return symbol;
}