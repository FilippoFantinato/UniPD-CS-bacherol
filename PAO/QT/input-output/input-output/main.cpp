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

	writeJson();

//	readJson();



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
	QJsonArray entries = json.value("entries").toArray();

	for(auto it = entries.begin(); it != entries.end(); ++it)
	{
		QJsonObject entry = it->toObject();

//		qWarning() << entry.value("title");

		cout << "Type: " << entry.value("type").toString().toStdString() << ", " << "Title: " << entry.value("title").toString().toStdString() << endl;
	}

//	QJsonObject v;

//	v["ciao"] = true;

//	json["AppName"] = v;

//	QJsonObject item = value.toObject();
//	cout << "Description: " << v["ciao"].toString().toStdString() << endl;
////	qWarning() << item << endl;

//	/* in case of string value get value and convert into string*/
////	cout << item["description"].toString().toStdString() << endl;
//	QJsonValue subobj = item["description"];
//	cout << subobj.toString().toStdString() << endl;

//	/* in case of array get array and convert into string*/
////	qWarning() << tr("QJsonObject[appName] of value: ") << item["imp"];
//	QJsonArray test = item["imp"].toArray();

////	std::cout <<
////	qWarning() << test[1].toString();
}
