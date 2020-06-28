#include <iostream>
#include <vector>
using namespace std;

float taxSlab[][2] = {
    {5000, 0},
    {10000, 0.1},
    {20000, 0.2},
    {10000, 0.3},
    {0, 0.4}};

double taxCalc(float salary)
{
    double tax = 0;
    for (int i = 0; i < 5 && salary > 0; i++)
    {
        if (taxSlab[i][0] && salary > taxSlab[i][0])
            tax += taxSlab[i][0] * taxSlab[i][1];
        else
            tax += salary * taxSlab[i][1];
        salary -= taxSlab[i][0];
    }
    return tax;
}

int main()
{
    cout << taxCalc(46000) << endl;
    return 0;
}