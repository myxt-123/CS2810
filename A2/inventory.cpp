#include <iostream>
#include <string>
#include <vector>

using namespace std;

class InventoryItem
{
public:
	int id;
	float price;
	string manufacturer;
	string type;

	static vector<InventoryItem> list1;

	InventoryItem(int i, float p, string m, string t)
	{
		id = i;
		price = p;
		manufacturer = m;
		type = t;
	};
	int getID();
	float getPrice();
	string getManufacturer();
	string getType();
};

vector<InventoryItem> InventoryItem::list1;

class Pen
{
public:
	int id;
	float width;
	string colour;
	string style;

	static vector<Pen> list2;

	Pen(int i, float w, string c, string s)
	{
		id = i;
		width = w;
		colour = c;
		style = s;
	};
	int getID();
	float getWidth();
	string getColour();
	string getStyle();
};

vector<Pen> Pen::list2;

class Pencil
{
public:
	int id;
	float width;
	string hardness;
	string size;

	static vector<Pencil> list3;

	Pencil(int i, float w, string h, string s)
	{
		id = i;
		width = w;
		hardness = h;
		size = s;
	};
	int getID();
	float getWidth();
	string getHardness();
	string getSize();
};

vector<Pencil> Pencil::list3;

void sortlist1(vector<InventoryItem> list)
{
	int n = list.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (list[j].id > list[j + 1].id)
			{
				InventoryItem temp(0, 0, "a", "a");
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << list[i].id << " " << list[i].price << " " << list[i].manufacturer << " " << list[i].type << endl;
	}
}

void sortlist2(vector<Pen> list)
{
	int n = list.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (list[j].id > list[j + 1].id)
			{
				Pen temp(0, 0, "a", "a");
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << list[i].id << " " << list[i].width << " " << list[i].colour << " " << list[i].style << endl;
	}
}

void sortlist3(vector<Pencil> list)
{
	int n = list.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (list[j].id > list[j + 1].id)
			{
				Pencil temp(0, 0, "a", "a");
				list[j] = temp;
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << list[i].id << " " << list[i].width << " " << list[i].hardness << " " << list[i].size << endl;
	}
}

void deleteInventory(vector<InventoryItem> &list, int a, int n1)
{
	for (int i = 0; i < n1; i++)
	{
		if (list[i].id == a)
		{
			list.erase(list.begin() + i);
			//cout << "here" << endl;
		}
	}
}

int main()
{
	int t;
	int n1 = 0, n2 = 0, n3 = 0;
	InventoryItem inv(0, 0, "a", "a");
	Pen pen(0, 0, "a", "a");
	Pencil pencil(0, 0, "a", "a");
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		char op;
		cin >> op;
		switch (op)
		{
		case 'a':
		{
			int a1;
			float a2;
			string b1, b2;
			cin >> a1 >> a2 >> b1 >> b2;
			InventoryItem temp(a1, a2, b1, b2);
			inv.list1.push_back(temp);
			++n1;
			break;
		}

		case 'b':
		{
			int a1;
			float a2;
			string b1, b2;
			cin >> a1 >> a2 >> b1 >> b2;
			Pen temp(a1, a2, b1, b2);
			pen.list2.push_back(temp);
			++n2;
			break;
		}

		case 'c':
		{
			int a1;
			float a2;
			string b1, b2;
			cin >> a1 >> a2 >> b1 >> b2;
			Pencil temp(a1, a2, b1, b2);
			pencil.list3.push_back(temp);
			++n3;
			break;
		}

		case 'd':
		{
			int a;
			bool flag = false;
			cin >> a;
			for (int ii = 0; ii < n2; ii++)
			{
				if (a == pen.list2[ii].id)
				{
					flag = true;
					//cout << a << endl;
					pen.list2.erase(pen.list2.begin() + ii);
					deleteInventory(inv.list1, a, n1);
					n1--;
					n2--;
					break;
				}
			}
			if (flag == false)
			{
				for (int ii = 0; ii < n3; ii++)
				{
					if (a == pencil.list3[ii].id)
					{
						flag = true;
						pencil.list3.erase(pencil.list3.begin() + ii);
						deleteInventory(inv.list1, a, n1);
						n1--;
						n3--;
						break;
					}
				}
			}
			break;
		}

		case 'p':
			sortlist1(inv.list1);
			//cout << "p" << endl;
			break;

		case 'q':
			sortlist2(pen.list2);
			//cout << "q" << endl;
			break;

		case 'r':
			sortlist3(pencil.list3);
			//cout << "r" << endl;
			break;
		}
	}
	return 0;
}
