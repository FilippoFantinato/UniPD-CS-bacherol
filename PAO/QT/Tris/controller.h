#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "model.h"
#include "tictactoe.h"

class Controller : public QObject
{
	Q_OBJECT
private:
	Model *model;
	TicTacToe *view;

public:
	Controller(Model *model, QObject *parent = nullptr);

	/**
	 * @brief setView
	 * @param view
	 */
	void setView(TicTacToe *view);

	/**
	 * @brief getPlayer
	 * @param x
	 * @param y
	 * @return Player
	 */
	Player getPlayer(u_int x, u_int y) const;

	/**
	 * @brief getWinner
	 * @return Plater
	 */
	Player getWinner() const;

public slots:
	/**
	 * @brief move
	 */
	void move(unsigned int, unsigned int);

	/**
	 * @brief reset
	 */
	void reset();
};

#endif // CONTROLLER_H
