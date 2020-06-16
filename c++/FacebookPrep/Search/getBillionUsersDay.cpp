#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getBillionUsersDay(vector<float> growthRates)
{
    int i = 2;
    while (true)
    {
        double sum = 0;
        for (auto j : growthRates)
            sum += pow(j, i);
        if (sum > 1000000000)
            break;
        i++;
    }
    return i;
}
int main()
{
    cout << getBillionUsersDay({1.2}) << endl;
    return 0;
}