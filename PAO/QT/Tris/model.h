#ifndef MODEL_H
#define MODEL_H

#include <stdexcept>
#include "moveexception.h"

enum Player
{
	none = 0,
	player1 = 1,
	player2 = 2
};

class Model
{
private:
	bool turn = false;
	int *z = new int(4);
	Player cells[9];

	bool checkWinner(u_int i, u_int j, u_int k) const;

public:
	/**
	 * @brief Model
	 */
	Model();

	/**
	 * @brief Esegue una mossa
	 * @param x
	 * @param y
	 * @throw std::exception
	 */
	void move(u_int x, u_int y);

	/**
	 * @brief Segnalazione del vincitore
	 * @return Player
	 */
	Player winner() const;

	/**
	 * @brief Reset delle celle
	 */
	void reset();

	/**
	 * @brief Viene invocata per conoscere su quante celle è presente il player indicato
	 * @param player
	 * @return
	 */
	u_int counterFrame(Player player) const;

	/**
	 * @brief operator () usato per accedere ad una specifica cella e scoprire che gioocatore è presente
	 * @param row
	 * @param column
	 * @return
	 */
	Player operator()(u_int row, u_int column) const;

};

#endif // MODEL_H
