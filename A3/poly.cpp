#include <iostream>

using namespace std;

class Polynomial
{
private:
	double poly[11];

public:
	Polynomial()
	{
		for(int i = 0; i < 11; i++)
			poly[i] = 0;
	};
	Polynomial &operator + (Polynomial p)
	{
		Polynomial out;
		for (int i = 0; i < 11; i++)
			out.poly[i] = poly[i] + p.poly[i];
		return out;
	};
	Polynomial &operator - (Polynomial p)
	{
		Polynomial out;
		for (int i = 0; i < 11; i++)
			out.poly[i] = poly[i] - p.poly[i];
		return out;
	};
	Polynomial &operator * (Polynomial p)
	{
		Polynomial out;
		for (int i = 0; i < 11; i++)
		{
			int j = 0; 
			int k = i;
			for(; j <= i; j++, k--){
				out.poly[i] += (poly[j] * p.poly[k]);
			}
		}
	};
	double evaluate(double n);
	void print();
	void takeinput();
};

int main()
{
	int n, c1, c2;
	double m;
	char op;
	Polynomial p1, p2, p;
	cin >> n;
	std::cout.precision(3);
	std::cout << std::fixed;

	for (int i = 0; i < n; i++)
	{
		cin >> op;
		switch(op)
		{
			case 'a':
				p1.takeinput();
				p2.takeinput();
				p = p1 + p2;
				p.print();

			case 's':
				p1.takeinput();
				p2.takeinput();
				p = p1 - p2;
				p.print();

			case 'm':
				p1.takeinput();
				p2.takeinput();
				p = p1 * p2;
				p.print();

			case 'e':
				p1.takeinput();
				cin >> m;
				cout << p1.evaluate(m) << endl;
		}
	}
}