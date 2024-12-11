
#include <iostream>
#include <cmath>
using namespace std;

float NewtonMetod(double x0)
{
    bool flag = true;
    double xi, E = pow(10, -6);


    while (flag) 
    {
        xi = x0 - ((sqrt(1 - (0.4 * pow(x0, 2))) - asin(x0)) /
            (-1 / (sqrt(1 - pow(x0, 2))) - ((2 * x0) / (sqrt(5) * sqrt(5 - (2 * pow(x0, 2)))))));

        if(abs(x0 - xi) <= E)
        {
            flag = false;
        }
        x0 = xi;
        cout << x0 << endl;
    }
    return xi;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    double x0, coren;
    int a = 0, b = 1;
    cout << "введите приблизительное значение корня в интервале [0;1]" << endl << "x0 = ";
    cin >> x0;
    if ((x0 >= a) && (x0 <= b))
    {
        coren = NewtonMetod(x0);
        cout << "корень уравнения равен: " << coren;
    }
    else
    {
        cout << "в интервале [0;1] не существует введенное вами приблизительное значение корня";
    }
    return 0;
}
//Когда вы вводите начальное приближение 0 или 1, метод Ньютона начинает итерации и
// пытается найти корень функции. Однако в точках 0 и 1 производная функции равна 0, что приводит
// к делению на ноль в формуле для следующего приближения.