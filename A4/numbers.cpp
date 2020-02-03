#include <iostream>
#include <string>

using namespace std;

class Complex
{
public:
    Complex(double a, double b)
    {
        real = a;
        img = b;
    };
    void add(Complex n)
    {
        real = real + n.real;
        img = img + n.img;
        cout << real << " " << img << endl;
    };
    void sub(Complex n)
    {
        real = real - n.real;
        img = img - n.img;
        cout << real << " " << img << endl;
    };
    void mult(Complex n)
    {
        double n1, n2;
        n1 = real * n.real - img * n.img;
        n2 = real * n.img + img * n.real;
        cout << n1 << " " << n2 << endl;
    };

private:
    double real;
    double img;
};

class Rational: public Complex
{
public:
    Rational(int a, int b)
    {
        num = a;
        den = b;
    };
    void reduce()
    {

    };

private:
    int num;
    int den;
};

class Natural: public Rational
{
public:
    Natural();
    void isPrime();
    void inverse();

private:
    int nat;
};

int main()
{
    std::cout.precision(3);
    std::cout << std::fixed;

    int n;
    string type;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type == "complex")
        {
            string op;
            cin >> op;
            double c, d;
            cin >> c >> d;
            Complex a(c, d);
            cin >> c >> d;
            Complex b(c, d);
            if (op == "add")
                a.add(b);
            if (op == "mult")
                a.mult(b);
            if (op == "sub")
                a.sub(b);
        }
        else if (type == "rational")
        {
        	string op;
        	cin >> op;
        	double c, d;
            cin >> c >> d;
            Rational a(c, d);
            cin >> c >> d;
            Rational b(c, d);

        }

    }
}