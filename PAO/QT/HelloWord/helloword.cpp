#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QPushButton hello("Hello Word");
	hello.show();

	return QApplication::exec();
}
