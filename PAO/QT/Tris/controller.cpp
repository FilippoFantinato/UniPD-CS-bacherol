#include "controller.h"

Controller::Controller(Model *model, QObject *parent) : QObject(parent), model(model), view(nullptr)
{

}

void Controller::setView(TicTacToe *view)
{
	this->view = view;
}

Player Controller::getPlayer(u_int x, u_int y) const
{
	return model->operator()(x, y);
}

Player Controller::getWinner() const
{
	return model->winner();
}

void Controller::move(unsigned int x, unsigned int y)
{
	// Proviamo ad eseguire la mossa
	try {
		model->move(x, y);

		view->updateGrid();

		if(getWinner() || ((model->counterFrame(Player::player1) + model->counterFrame(Player::player2)) == 9) )
		{
			view->showWinner();
			reset();
		}
	}
	catch(const std::exception *e)
	{
		view->showErrorMessage(e->what());
	}
}

void Controller::reset()
{
	// Reimpostare il modello
	model->reset();

	// Reimpostare la vista
	view->resetGrid();
}
