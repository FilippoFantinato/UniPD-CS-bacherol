#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	// Imposto il foglio di stile
	QFile file(":/style.css");
	file.open(QFile::ReadOnly);

	QString stylesheet = QLatin1String(file.readAll());

	setStyleSheet(stylesheet);
}

MainWindow::~MainWindow()
{
	delete ui;
}

