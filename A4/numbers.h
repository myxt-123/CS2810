class Complex
{
public:
    Complex(double a, double b);
    void add(Complex n);
    void sub(Complex n);
    void mult(Complex n);

private:
    double real;
    double img;
};

class Rational: public Complex
{
public:
    Rational(int a, int b)
    :Complex((double)a / b, 0);
    void reduce();

private:
    int num;
    int den;
};

class Natural: public Rational
{
public:
    Natural(int a)
    :Complex(a, 0);
    void isPrime();
    void inverse();

private:
    int nat;
};
