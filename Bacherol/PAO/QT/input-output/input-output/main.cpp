#include <QCoreApplication>
#include <QFile>
#include <iostream>
#include <QDebug>
#include <vector>

#include "a.h"

using namespace std;

void readJson();
void writeJson();

int main(int argc, char *argv[])
{

//	writeJson();

	readJson();



	return 0;
}

void writeJson()
{
	vector<A *> v;

	for(int i = 0; i < 10; ++i)
	{
		v.push_back(new A("A" + to_string(i)));
	}

	for(int i = 0; i < 10; ++i)
	{
		v.push_back(new B("B" + to_string(i), i%2 == 0));
	}

	QJsonArray entries;

	for(auto it = v.begin(); it != v.end(); ++it)
	{
		entries.push_back((*it)->serialize());
	}

	QJsonObject obj;
	obj.insert("entries", entries);

	QJsonDocument document;
	document.setObject(obj);

	QFile file;
	file.setFileName("../data.json");
	file.open(QFile::WriteOnly | QFile::Text);
//	cout << file.readAll().toStdString() << endl;
	file.write(document.toJson());
//	file.write()
	file.close();
}

void readJson()
{
	QString val;
	QFile file;
	file.setFileName(":/data.json");
	file.open(QFile::ReadOnly | QIODevice::Text);

	val = file.readAll();
	file.close();

	QJsonObject json = QJsonDocument::fromJson(val.toUtf8()).object();
	QJsonArray entries = json.value("contacts").toArray();

	for(auto it = entries.begin(); it != entries.end(); ++it)
	{
		QJsonObject entry = it->toObject();

//		qWarning() << entry.value("title");

		cout << "Name: " << entry.value("name").toString().toStdString() << ", " << "Lastname: " << entry.value("lastname").toString().toStdString() << " Mail: " << entry.value("mail").toString().toStdString() << endl;
	}

}
