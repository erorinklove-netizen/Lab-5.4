// Lab 5.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// < Якимів Наталія > 
// Лабораторна робота № 5.4
// Варіант 7
// Лабораторна робота № 5.4 (модифікована під варіант 7)
#include <iostream>
#include <cmath>
using namespace std;

// Ітераційна форма
double S0(const int N)
{
    double s = 0;
    for (int i = 1; i <= N; i++)
        s += 1.0 / pow(2 * i + 1, 2);
    return s;
}

// Рекурсія (рух вгору: i++)
double S1(const int N, const int i)
{
    if (i > N)
        return 0;
    else
        return 1.0 / pow(2 * i + 1, 2) + S1(N, i + 1);
}

// Рекурсія (рух вниз: i--)
double S2(const int i)
{
    if (i < 1)
        return 0;
    else
        return 1.0 / pow(2 * i + 1, 2) + S2(i - 1);
}

// Рекурсія з акумулятором (рух вгору)
double S3(const int N, const int i, double t)
{
    t = t + 1.0 / pow(2 * i + 1, 2);

    if (i >= N)
        return t;
    else
        return S3(N, i + 1, t);
}

// Рекурсія з акумулятором (рух вниз)
double S4(const int i, double t)
{
    t = t + 1.0 / pow(2 * i + 1, 2);

    if (i <= 1)
        return t;
    else
        return S4(i - 1, t);
}

int main()
{
    int N;
    cout << "N = ";
    cin >> N;

    cout << "(iter)        S0 = " << S0(N) << endl;
    cout << "(rec up ++)   S1 = " << S1(N, 1) << endl;
    cout << "(rec down --) S2 = " << S2(N) << endl;
    cout << "(rec up t)    S3 = " << S3(N, 1, 0) << endl;
    cout << "(rec down t)  S4 = " << S4(N, 0) << endl;

    return 0;
}
