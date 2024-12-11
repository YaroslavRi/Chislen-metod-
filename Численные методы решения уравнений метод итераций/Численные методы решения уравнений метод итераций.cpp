#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return sqrt(1 - 0.4 * x * x) - asin(x);
}

double fprime(double x) {
    return (1 / 2) * pow((1 - 0.4 * pow(x, 2)), (-1 / 2)) * (-0.8 * x) - 1 / (sqrt(1 - pow(x, 2)));
}

int main() {
    setlocale(LC_ALL, "rus");
    double x0, x1, pogreshnost;
    bool flag = true;
    cout << "Введите начальное приближение: ";
    cin >> x0;
    cout << "Введите погрешность: ";
    cin >> pogreshnost;

    int iterations = 0;

    do {
        // Вычисляем следующее приближение
        x1 = x0 - f(x0) / fprime(x0);
        iterations++;

        // Проверяем условие сходимости
        double proizvodnaia = fprime(x0);
        if (abs(proizvodnaia) <= 1) {
            cout << "Внимание! Метод итераций может не сходиться для данного начального приближения." << endl;
        }

        // Проверяем достижение погрешности
        if (abs(x1 - x0) < pogreshnost) {
            flag = false;
        }

        x0 = x1;
        cout << "итерация " << iterations << ": " << x1 << endl;
    } while (flag);

    cout << "Корень уравнения: " << x1 << endl;
    cout << "Количество итераций: " << iterations << endl;

    return 0;
}
