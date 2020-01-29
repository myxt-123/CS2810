#include <iostream>
#include <cmath>

using namespace std;

class Polynomial
{
private:
	double poly[21];

public:
	Polynomial()
	{
		for (int i = 0; i < 21; i++)
			poly[i] = 0;
	};
	~Polynomial(){};
	Polynomial operator+(Polynomial p)
	{
		Polynomial out;
		for (int i = 0; i < 11; i++)
			out.poly[i] = poly[i] + p.poly[i];
		return out;
	};
	Polynomial operator-(Polynomial p)
	{
		Polynomial out;
		for (int i = 0; i < 11; i++)
			out.poly[i] = poly[i] - p.poly[i];
		return out;
	};
	Polynomial operator*(Polynomial p)
	{
		Polynomial out;
		for (int i = 0; i < 21; i++)
		{
			int j, k;
			if (i < 11)
			{
				j = 0;
				k = i;
			}
			else
			{
				j = i - 10;
				k = 10;
			}
			for (; k >= 0 && j < 11; j++, k--)
			{
				out.poly[i] = out.poly[i] + (poly[j] * p.poly[k]);
			}
		}
		return out;
	};
	double evaluate(double n)
	{
		double value = poly[10];
		for (int i = 9; i >= 0; --i)
		{
			value = value * n + poly[i];
			// cout << poly[i] << endl;
		}
		return value;
	};
	void print()
	{
		bool flag = false;
		for (int i = 0; i < 21; i++)
		{
			if (poly[i] != 0)
			{
				if (poly[i] < 0 && !flag)
				{
					cout << "-";
				}
				else if (poly[i] > 0 && flag)
				{
					cout << "+ ";
				}
				else if (poly[i] < 0 && flag)
				{
					cout << "- ";
				}
				cout << abs(poly[i]) << "x^" << i << " ";
				flag = true;
			}
		}
		cout << endl;
	};
	void takeinput()
	{
		int m, d1;
		double d2;
		cin >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> d1;
			cin >> d2;
			poly[d1] = d2;
			// cout << poly[d1] << endl;
		}
	};
};

int main()
{
	int n;
	double m;
	char op;
	cin >> n;

	std::cout.precision(3);
	std::cout << std::fixed;

	for (int i = 0; i < n; i++)
	{
		Polynomial p1, p2, p;
		cin >> op;
		switch (op)
		{
		case 'a':
			p1.takeinput();
			p2.takeinput();
			p = p1 + p2;
			p.print();
			break;

		case 's':
			p1.takeinput();
			p2.takeinput();
			// p1.print();
			// p2.print();
			p = p1 - p2;
			p.print();
			break;

		case 'm':
			p1.takeinput();
			p2.takeinput();
			p = p1 * p2;
			p.print();
			break;

		case 'e':
			p1.takeinput();
			cin >> m;
			cout << p1.evaluate(m) << endl;
			break;
		}
	}
}