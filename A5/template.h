template <typename T>
class myStack {
public:
	void push(T n);
	void pop();
	T top();

private:
	vector<T> stack;
};

class Polynomial {
public:
	Polynomial();
	void print();
	Polynomial operator+(Polynomial P);
	Polynomial operator-(Polynomial P);
	Polynomial operator*(Polynomial P);
	void takeInput();

private:
	vector <int> poly;
};