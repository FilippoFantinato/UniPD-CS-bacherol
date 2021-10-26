#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QFile>
#include <QDialog>
#include <QLabel>
#include <sstream>

#include "button.h"

class Controller;

class TicTacToe : public QWidget
{
    Q_OBJECT
private:
	Controller *controller;
	QVBoxLayout *mainLayout;
	QGridLayout *gridLayout;

	/**
	 * @brief Aggiunge le celle
	 */
	void addButtons();

	/**
	 * @brief Aggiunge il menu
	 */
	void addMenu();

	/**
	 * @brief Imposta lo stile dell'applicazione
	 */
	void setApplicationStyle();

public:
	TicTacToe(Controller *controller, QWidget *parent = nullptr);
    ~TicTacToe();

	/**
	 * @brief Aggiorna la griglia
	 */
	void updateGrid();

	/**
	 * @brief Reset della griglia
	 */
	void resetGrid();

	/**
	 * @brief Mostra il vincitore
	 */
	void showWinner();

	/**
	 * @brief Mostra il messaggio d'errore
	 * @param s: Messaggio d'errore
	 */
	void showErrorMessage(const QString& s) const;

public slots:
	void cellHandle(unsigned int, unsigned int);
};
#endif // TICTACTOE_H
