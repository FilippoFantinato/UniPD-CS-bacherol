#ifndef A_H
#define A_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <string>

using namespace std;

class A
{
protected:
	string title;

public:
	A(string title) : title(title) { }

	virtual QJsonObject serialize()
	{
		QJsonObject object;

		object.insert("type", "A");
		object.insert("title", QJsonValue(title.c_str()));

		return object;
	}
};

class B : public A
{
protected:
	bool checked;

public:
	B(string title, bool checked) : A(title), checked(checked) { }

	virtual QJsonObject serialize() override
	{
		QJsonObject object;

		object.insert("type", "B");
		object.insert("title", QJsonValue(title.c_str()));
		object.insert("checked", QJsonValue(checked));

		return object;
	}
};


#endif // A_H
