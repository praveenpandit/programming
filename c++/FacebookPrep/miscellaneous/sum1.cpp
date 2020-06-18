#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int xoringNinja(vector<int> arr)
{
    int sum = 0;
    unsigned int count = pow(2, arr.size());
    for (int i = 0; i < count; i++)
    {
        int start = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
                start ^= arr[j];
            }
        }
        cout << endl;
        sum += start;
    }
    return sum;
}
void findPowerSet(vector<int> arr, vector<int> set, int n)
{
    if (n == 0)
    {
        for (auto i : set)
            cout << i << " ";
        cout << endl;
        return;
    }
    set.push_back(arr[n - 1]);
    findPowerSet(arr, set, n - 1);
    set.pop_back();
    findPowerSet(arr, set, n - 1);
}
int main()
{
    cout << sizeof(double) << endl;
    // vector<int> set;
    // findPowerSet({1, 2, 3}, {}, 3);
    return 0;
}