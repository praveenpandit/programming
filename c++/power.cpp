#include <iostream>

using namespace std;

double multiply(double x, int y)
{
    if (y)
        return (x + multiply(x, y - 1));
    else
        return 0;
}
double power_rec(double x, int n)
{
    if (n)
        return multiply(x, power_rec(x, n - 1));
    else
        return 1;
}
/* double power(double x, int n)
{
    if (n < 0)
        return (1 / power_rec(x, -n));
    else
        return power_rec(x, n);
} */
double power(double x, int n)
{
    if (n == 0)
        return 1;
    if (n == 1 || x == 0)
        return x;
    if (n < 0)
    {
        x = 1 / x;
        n = -n;
    }
    if (n % 2 > 0)
        return x * power(x * x, n / 2);
    else
        return power(x * x, n / 2);
}

int main()
{
    cout << power(2, -3);
    return 0;
}