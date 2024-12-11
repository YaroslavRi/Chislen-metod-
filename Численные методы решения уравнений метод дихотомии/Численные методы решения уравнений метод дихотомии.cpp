#include <iostream>
#include <cmath>
using namespace std;

float f(double x0)
{
    return sqrt(1 - 0.4 * pow(x0, 2)) - asin(x0);
}
double MetodDichotomy(double a, double b)
{
    double x0, xi = 0, E = pow(10, -6);
    bool flag = true;
    while (flag)
    {
        x0 = (a + b) / 2;
        if (abs(x0 - xi) <= E)
        {
            flag = false;
        }
        if (f(x0) * f(a) < 0)
        {
            b = x0;
            xi = x0;
            cout << xi << endl;
        }
        else
        {
            a = x0;
            xi = x0;
            cout << xi << endl;
        }
    }
    return x0;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double coren, a = 0, b = 1;
    coren = MetodDichotomy(a, b);
    cout << "корень уравнения = " << coren;
}