#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

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

void takeIntInput() {

    std::string line, token;
    std::cin.ignore();
    std::getline(std::cin, line);

    std::stringstream ss(line);
    
    while(ss >> token) {
        // process each token
        // this will either be an operator, a parenthesis or an integer
    }
}

void takePolyInput() {
    int num;
    std::cin >> num;

    std::string line;

    std::cin.ignore();

    for(int i = 0; i < num; i++) {
        std::getline(std::cin, line);

        if(line.size() == 1) {
            // process the line
            // this will be either an operator or a parenthesis
        }
        else {
            // this will be a polynomial
            std::stringstream ss(line);

            int exponent;
            long long coeff;
            while(ss >> exponent, ss >> coeff) {
                // process the exponent and coefficient appropriately
            }

        }
    }
}

int main() {
	int n;

}