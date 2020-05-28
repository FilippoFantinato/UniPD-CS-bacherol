#include "tictactoe.h"
#include "controller.h"

TicTacToe::TicTacToe(Controller *controller, QWidget *parent)
	: QWidget(parent), controller(controller)
{
	mainLayout = new QVBoxLayout(this);
	gridLayout = new QGridLayout(this);

	// Aggiungere il menu
	addMenu();

	// Aggiungere le celle come bottoni
	addButtons();

	// Imposto lo stile dell'applicazione
	setApplicationStyle();

	mainLayout->addLayout(gridLayout);
	setLayout(mainLayout);
}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::addMenu()
{
	// Creazione del menu, barra del menu ed azioni correlate
	QMenuBar *menuBar = new QMenuBar(this);
	QMenu *menu = new QMenu("File", menuBar);
	QAction *exit = new QAction("Exit", menu),
			*reset = new QAction("Reset", menu);

	// Aggiungo le azioni
	menu->addAction(reset);
	menu->addAction(exit);

	connect(reset, SIGNAL(triggered()), controller, SLOT(reset()));
	connect(exit, SIGNAL(triggered()), this, SLOT(close()));

	// Aggiungo il menu
	menuBar->addMenu(menu);

	mainLayout->addWidget(menuBar);
}

void TicTacToe::addButtons()
{
	for(u_int i = 0; i < 3; ++i)
	{
		for(u_int j = 0; j < 3; ++j)
		{
			Button *button = new Button(i, j);

			button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			gridLayout->addWidget(button, i, j);
//			connect(button, SIGNAL(clickedCell(unsigned int, unsigned int)), this, SLOT(cellHandle(unsigned int, unsigned int)));
			connect(button, SIGNAL(clickedCell(unsigned int, unsigned int)), controller, SLOT(move(unsigned int, unsigned int)));
		}
	}
}

void TicTacToe::setApplicationStyle()
{
	// Tolgo i margini
	gridLayout->setSpacing(0);

	// Imposto le dimensioni
	setMinimumSize(300, 300);
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	// Imposto il foglio di stile
	QFile file(":/resources/style.css");
	file.open(QFile::ReadOnly);

	QString stylesheet = QLatin1String(file.readAll());

	setStyleSheet(stylesheet);
}


void TicTacToe::updateGrid()
{
	for(u_int i = 0; i < 9; ++i)
	{
		int x = i/3,
			y = i%3;

		QLayoutItem *item = gridLayout->itemAtPosition(x, y);
		int player = controller->getPlayer(x, y);

		if(player != 0)
		{
			Button *button = static_cast<Button *>(item->widget());

			if(player == 1)
			{
				button->setIcon(QIcon(":/resources/player1.png"));
			}
			else
			{
				button->setIcon(QIcon(":/resources/player2.png"));
			}

			button->setEnabled(false);
		}
	}
}


void TicTacToe::resetGrid()
{
	for(u_int i = 0; i < 9; ++i)
	{
		QLayoutItem *item = gridLayout->itemAtPosition(i/3, i%3);
		Button *button = static_cast<Button *>(item->widget());

		button->setIcon(QIcon());
		button->setEnabled(true);
	}
}

void TicTacToe::showWinner()
{
	// Creo il dialog
	QDialog *dialog = new QDialog(this);
	QVBoxLayout *layout = new QVBoxLayout(dialog);

	// Creo il messaggio
//	QString text = "";
//	if(winner)
//	{
//		text.push_back("Ha vinto il giocatore: ");
//		text.push_back(string(winner));
//	}
//	else
//	{
//		text.push_back("Pareggio");
//	}
	Player winner = controller->getWinner();

	std::stringstream text;
	if(winner)
	{
		text << "Ha vinto il giocatore: " << winner;
	}
	else
	{
		text << "Pareggio";
	}

	layout->addWidget(new QLabel(QString::fromStdString(text.str()), dialog));

	dialog->show();
}

void TicTacToe::showErrorMessage(const QString& s) const
{
	QDialog *dialog = new QDialog();
	QVBoxLayout *layout = new QVBoxLayout(dialog);

	layout->addWidget(new QLabel(s, dialog));

	dialog->show();
}

// Slots
void TicTacToe::cellHandle(unsigned int x, unsigned int y)
{
	// Creo il dialog
	QDialog *dialog = new QDialog();
	QVBoxLayout *layout = new QVBoxLayout(dialog);

	std::stringstream text;

	text << "Hai cliccato: (" << x << ", " << y << ")";

	layout->addWidget(new QLabel(QString::fromStdString(text.str()), dialog));

	dialog->show();
}
