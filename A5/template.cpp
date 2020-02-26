#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class myStack
{
public:
    void push(T n)
    {
        stack.push_back(n);
    };
    void pop()
    {
        stack.pop_back();
    };
    T top()
    {
        return stack.back();
    };
    bool empty()
    {
        return stack.empty();
    };
    int nElements()
    {
        return stack.size();
    };

private:
    vector<T> stack;
};

class Polynomial
{
public:
    Polynomial()
    {
        for (int i = 0; i < 1001; i++)
        {
            poly[i] = 0;
        }
    };
    void print()
    {
        bool flag = false;
        for (int i = 0; i < 1001; i++)
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
    Polynomial operator+(Polynomial p)
    {
        Polynomial out;
        for (int i = 0; i < 1001; i++)
            out.poly[i] = poly[i] + p.poly[i];
        return out;
    };
    Polynomial operator-(Polynomial p)
    {
        Polynomial out;
        for (int i = 0; i < 1001; i++)
            out.poly[i] = poly[i] - p.poly[i];
        return out;
    };
    Polynomial operator*(Polynomial p)
    {
        Polynomial out;
        for (int i = 0; i < 1001; i++)
        {
            int j, k;
            if (i < 501)
            {
                j = 0;
                k = i;
            }
            else
            {
                j = i - 500;
                k = 500;
            }
            for (; k >= 0 && j < 501; j++, k--)
            {
                out.poly[i] = out.poly[i] + (poly[j] * p.poly[k]);
            }
        }
        return out;
    };
    void takeInput(int exp, int coeff)
    {
        poly[exp] = coeff;
    };

private:
    int poly[1001];
};

void takeIntInput()
{

    string line, token;
    myStack<string> op;
    myStack<long long int> exp;

    cin.ignore();
    getline(cin, line);

    stringstream ss(line);

    while (ss >> token)
    {
        if (token[0] == '(' || token[0] == '+' || token[0] == '-' || token[0] == '*')
            op.push(token);
        else if (token[0] <= '9' || token[0] >= '0')
        {
            if (!op.empty())
            {
                if (op.top() == "*")
                {
                    long long int i = stoi(token), j = exp.top();
                    exp.pop();
                    i = i * j;
                    exp.push(i);
                    op.pop();
                }
            }
            else
                exp.push(stoi(token));
        }
        else if (token[0] == ')')
        {
            while (true)
            {
                if (op.top() == "(")
                {
                    op.pop();
                    while (!op.empty())
                    {
                        if (op.top() != "*")
                            break;
                        long long int i = exp.top(), j;
                        exp.pop();
                        j = exp.top();
                        exp.pop();
                        i = i * j;
                        exp.push(i);
                        op.pop();
                    }
                    break;
                }

                long long int i = exp.top(), j;
                exp.pop();
                j = exp.top();
                exp.pop();

                if (op.top() == "+")
                    i = i + j;
                else if (op.top() == "-")
                    i = i - j;

                exp.push(i);
                op.pop();
            }
        }
    }

    while (!op.empty())
    {
        long long int i = exp.top(), j;
        exp.pop();
        j = exp.top();
        exp.pop();

        if (op.top() == "+")
            i = i + j;
        else if (op.top() == "-")
            i = i - j;

        exp.push(i);
        op.pop();
    }
    cout << exp.top() << endl;
}

void takePolyInput()
{
    int num;
    cin >> num;

    string line;
    myStack<string> op;
    myStack<Polynomial> exp;

    cin.ignore();

    for (int i = 0; i < num; i++)
    {
        getline(cin, line);

        if (line.size() == 1)
        {
            if (line[0] == '(' || line[0] == '+' || line[0] == '-' || line[0] == '*')
                op.push(line);
            else if (line[0] == ')')
            {
                while (!op.empty())
                {
                    if (op.top() == "(")
                    {
                        op.pop();
                        while (!op.empty())
                        {
                            if (op.top() != "*")
                                break;
                            Polynomial i, j = exp.top(), k;
                            exp.pop();
                            i = exp.top();
                            exp.pop();
                            k = i * j;
                            exp.push(k);
                            op.pop();
                        }
                        break;
                    }

                    Polynomial i = exp.top(), j, k;
                    exp.pop();
                    j = exp.top();
                    exp.pop();

                    if (op.top() == "+")
                        k = i + j;
                    else if (op.top() == "-")
                        k = i - j;

                    exp.push(k);
                    op.pop();
                }
            }
        }
        else
        {
            // this will be a polynomial
            stringstream ss(line);

            int exponent;
            long long coeff;
            while (ss >> exponent, ss >> coeff)
            {
                // process the exponent and coefficient appropriately
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string e_type;
        cin >> e_type;
        if (e_type == "int")
            takeIntInput();
        else if (e_type == "poly")
            takePolyInput();
    }
}