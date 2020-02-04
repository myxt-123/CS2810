#include <iostream>
#include <string>
#include <math.h>

#define M 1000000007

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

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
    };
    void sub(Complex n)
    {
        real = real - n.real;
        img = img - n.img;
    };
    void mult(Complex n)
    {
        double n1, n2;
        n1 = real * n.real - img * n.img;
        n2 = real * n.img + img * n.real;
        real = n1;
        img = n2;
    };
    double getReal()
    {
        return real;
    };
    double getImg()
    {
        return img;
    };

private:
    double real;
    double img;
};

class Rational : public Complex
{
public:
    Rational(int a, int b)
        : Complex((double)a / b, 0)
    {
        num = a;
        den = b;
    };
    int getNum()
    {
        return num;
    };
    int getDen()
    {
        return den;
    };
    void reduce()
    {
        int k = gcd(getNum(), getDen());
        num = num / k;
        den = den / k;
        if (num > 0 && den < 0)
        {
            num = -num;
            den = -den;
        }
        cout << num << " " << den << endl;
    };

private:
    int num;
    int den;
};

class Natural : public Rational
{
public:
    Natural(int a)
        : Rational(a, 1)
    {
        nat = a;
    };
    void isPrime()
    {
        for (int i = 2; i <= sqrt(nat); i++)
        {
            if (nat % i == 0)
            {
                cout << "0" << endl;
                return;
            }
        }
        cout << "1" << endl;
    };
    void inverse()
    {
        int x, y;
        int g = gcdExtended(nat, M, &x, &y);
        if (g != 1)
            return;
        else
        {
            // m is added to handle negative x
            int res = (x % M + M) % M;
            cout << res << endl;
        }
    }

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
            cout << a.getReal() << " " << a.getImg() << endl;
        }
        if (type == "rational")
        {
            string op;
            cin >> op;
            double c, d;
            cin >> c >> d;
            Rational a(c, d);
            if (op == "reduce")
            {
                a.reduce();
                continue;
            }
            cin >> c >> d;
            Rational b(c, d);
            if (op == "add")
                a.add(b);
            if (op == "mult")
                a.mult(b);
            if (op == "sub")
                a.sub(b);
            cout << a.getReal() << endl;
        }
        if (type == "natural")
        {
            string op;
            cin >> op;
            int c;
            cin >> c;
            Natural a(c);
            if (op == "isprime")
                a.isPrime();
            if (op == "inverse")
                a.inverse();
        }
    }

    return 0;
}