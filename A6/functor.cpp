#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
public:
	void findavg()
	{
		avg = ( Mscore + Pscore + Cscore ) / 3;
	};
	string getName()
	{
		return name;
	};
	double getAvg()
	{
		return avg;
	}
	void takeInput()
	{
		cin >> name >> rollNo >> Pscore >> Cscore >> Mscore;
	}
private:
	string name;
	int rollNo;
	int Mscore;
	int Pscore;
	int Cscore;
	double avg;
}

int main()
{
	cout.precision(4);
	cout << fixed;
	int n;
	cin >> n;
	Student list[n];
	for(int i = 0; i < n; i++)
	{
		takeInput();
	}
	int op;
	cin >> op;

	if (op == 3)
	{
		for (int i = 0; i < n; i++)
		{
			list[n].findAvg();
		}
		
	}
}