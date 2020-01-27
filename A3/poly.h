class Polynomial
{
private:
	double poly[11];

public:
	Polynomial();
	~Polynomial();
	Polynomial &operator + (Polynomial p);
	Polynomial &operator - (Polynomial p);
	Polynomial &operator * (Polynomial p);
	double evaluate(double n);
	void print();
	void takeinput();
};