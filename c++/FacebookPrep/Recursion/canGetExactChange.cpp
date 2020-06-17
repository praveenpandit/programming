#include <iostream>
#include <vector>
using namespace std;

bool canGetExactChange(int targetMoney, vector<int> &denominations)
{
    int index = denominations.size() - 1;
    if (index < 0)
        return false;
    if (targetMoney == 0)
        return true;
    else if (targetMoney > 0)
        targetMoney -= denominations[index];
    else if (targetMoney < 0)
        targetMoney += denominations[index] - denominations[index - 1], denominations.pop_back();
    return canGetExactChange(targetMoney, denominations);
}
int main()
{
    vector<int> denominations = {5, 10, 25, 100, 200};
    cout << canGetExactChange(94, denominations) << endl;
    denominations = {4, 17, 29};
    cout << canGetExactChange(75, denominations) << endl;
    return 0;
}