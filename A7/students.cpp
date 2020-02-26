#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Student
{
public:
	int id;
	int m[5];
	int skill;
	int rank;
};

class List
{
public:
	vector<Student> list;

	void insert(Student stu)
	{
		if (list.size() == 0)
		{
			list.push_back(stu);
			return;
		}

		bool flag = false;
		for (int i = 0; i < list.size(); i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (stu.m[j] < list[i].m[j])
					break;
				else if (stu.m[j] > list[i].m[j])
				{
					list.insert(list.begin() + i, stu);
					flag = true;
					return;
				}
			}
		}
		if (flag == false)
			list.push_back(stu);
	};
	void updateRanks()
	{
		for (int i = 0; i < list.size(); i++)
			list[i].rank = i + 1;
	};
	int find(int id1, int id2)
	{
		updateRanks();
		int r1 = 0, r2 = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (r1 * r2 == 0)
			{
				if (list[i].id == id1)
					r1 = list[i].rank;
				if (list[i].id == id2)
					r2 = list[i].rank;
			}
		}
		return abs(r1 - r2);
	};
	int count(int gid, int d)
	{
		int s, count = 0;
		for (int i = 0; i < list.size(); i++)
		{
			if (list[i].id == gid)
			{
				s = list[i].skill;
				break;
			}
		}
		for (int i = 0; i < list.size(); i++)
		{
			if (abs(list[i].skill - s) > d)
				count++;
		}
		return count;
	};
	void print()
	{
		for (int i = 0; i < list.size(); i++)
			cout << list[i].id << " ";
		cout << endl;
	};
};

int main()
{
	string op;
	List students;
	cin >> op;
	while (!cin.eof())
	{
		if (op == "ADD")
		{
			Student temp;
			cin >> temp.id >> temp.m[0] >> temp.m[1] >> temp.m[2] >> temp.m[3] >> temp.m[4] >> temp.skill;
			students.insert(temp);
		}
		else if (op == "PRINT")
		{
			students.print();
		}
		else if (op == "COUNT")
		{
			int t1, t2;
			cin >> t1 >> t2;
			cout << students.count(t1, t2) << endl;
		}
		else if (op == "FIND")
		{
			int t1, t2;
			cin >> t1 >> t2;
			cout << students.find(t1, t2) << endl;
		}
		cin >> op;
	}
}