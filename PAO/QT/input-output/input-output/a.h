#ifndef A_H
#define A_H

#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <string>
#include <QMap>
#include <QHash>

using namespace std;

class A
{
protected:
	string title;

	virtual string getType()
	{
		return "A";
	}

public:
	A(string title) : title(title) { }

	virtual QJsonObject serialize()
	{
		QJsonObject object;

		object.insert("type", getType().c_str());
		object.insert("title", QJsonValue(title.c_str()));

		return object;
	}
};

class B : public A
{
protected:
	bool checked;

	virtual string getType() override
	{
		return "B";
	}

public:
	B(string title, bool checked) : A(title), checked(checked) { }

	virtual QJsonObject serialize() override
	{
		QJsonObject object = A::serialize();

		object.insert("checked", QJsonValue(checked));

		return object;
	}
};


#endif // A_H
