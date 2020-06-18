#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
/* int xoringNinja(vector<int> arr)
{
    int sum = 0;
    unsigned int count = pow(2, arr.size());
    for (int i = 0; i < count; i++)
    {
        int start = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (i & (1 << j))
                start ^= arr[j];
        }
        sum += start;
    }
    return sum;
} */

/* int xoringNinja(vector<int> arr)
{
    int OR = 1;
    int power = pow(2, arr.size() - 1);
    for (auto i : arr)
        OR |= i;
    return OR * pow(2, arr.size() - 1);
}
 */
void findPowerSet(vector<int> arr, vector<int> set, int n, int &sum)
{
    if (n == 0)
    {
        for (auto i : set)
            cout << i << " ";
        cout << endl;
        // int XOR = 0;
        // for (auto i : set)
        //     XOR ^= i;
        // sum += XOR;
        return;
    }
    set.push_back(arr[n - 1]);
    findPowerSet(arr, set, n - 1, sum);
    set.pop_back();
    findPowerSet(arr, set, n - 1, sum);
}
int xoringNinja(vector<int> arr)
{
    vector<int> set;
    int sum = 0;
    findPowerSet(arr, set, arr.size(), sum);
    return sum;
}
int main()
{
    // cout << pow(2, 87290) << endl;
    cout << xoringNinja({1, 2, 3}) << endl;
    return 0;
}