#include <vector>
#include <utility>
#include <iostream>

using namespace std;

struct Activity
{
	int start, end;
};

vector<Activity> greedySel(const vector<Activity> &activities)
{
	vector<Activity> selected;

	selected.push_back(activities[0]);

	int last = 0;

	for(int m  = 1; m < activities.size(); ++m)
	{
		if(activities[m].start >= activities[last].end)
		{
			selected.push_back(activities[m]);
			last = m;
		}
	}

	return selected;
}

int main(int argc, char const *argv[])
{
	vector<Activity> activities = {{1, 3}, {4, 6}, {2, 9}, {3, 10}, {7, 11}, {8, 12}, {11, 13}};

	vector<Activity> selected = greedySel(activities);

	cout << "Cardinalità: " << selected.size() << endl;

	cout << "Attività :" << endl;

	for(auto it: selected)
	{
		cout << "Start: " << it.start << "\tEnd: " << it.end << endl;
	}
	
	return 0;
}
