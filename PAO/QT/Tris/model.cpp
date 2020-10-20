#include "model.h"

Model::Model()
{
	for(u_int i = 0; i < 9; ++i)
	{
		cells[i] = Player::none;
	}
}

void Model::move(u_int x, u_int y)
{
	u_int index = x * 3 + y;

	if(x > 2 || y > 2)
	{
		throw new std::domain_error("Exception: ("+ std::to_string(x) + ", " + std::to_string(y) + ") out of grid's bounds");
	}

	if(winner())
	{
		throw new MoveException(x, y);
	}

	if(cells[index] != Player::none)
	{
		throw new MoveException(x, y);
	}


	cells[index] = turn ? Player::player2 : Player::player1;
	turn = !turn;
}

Player Model::winner() const
{
	// Vincita orrizontale
	for(u_int i = 0; i < 9; i += 3)
	{
		if(checkWinner(i, i+1, i+2))
			return cells[i];
	}

	// Vincita verticale
	for(u_int i = 0; i < 3; ++i)
	{
		if(checkWinner(i, i+3, i+6))
			return cells[i];
	}

	// Vincita diagonale
	if(checkWinner(0, 4, 8))
		return cells[0];

	if(checkWinner(2, 4, 6))
		return cells[2];

	return Player::none;
}

bool Model::checkWinner(unsigned int i, unsigned int j, unsigned int k) const
{
	return cells[i] != Player::none && (cells[i] == cells[j]) && (cells[j] == cells[k]);
}

void Model::reset()
{
	turn = false;

	for(u_int i = 0; i < 9; ++i)
	{
		cells[i] = Player::none;
	}
}

unsigned int Model::counterFrame(Player player) const
{
	u_int count = 0;

	for(u_int i = 0; i < 9; ++i)
	{
		if(cells[i] == player) count++;
	}

	return count;
}

Player Model::operator()(unsigned int row, unsigned int column) const
{
	if(row < 0 || row > 2 || column < 0 || column > 2) return Player::none;

	return cells[row*3 + column];
}
