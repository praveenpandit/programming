#include <iostream>
#include <vector>
using namespace std;

int calsawkwardness(vector<int> arr, int l)
{
    int cals = 0;
    for (int i = 0; i < l; i++)
    {
        int temp = (i == (l - 1)) ? std::abs(arr[i] - arr[0]) : std::abs(arr[i] - arr[i + 1]);
        cals = temp > cals ? temp : cals;
    }
    return cals;
}

int permutation(vector<int> arr, int i, int l, int &awkwardness)
{
    if (i == l)
    {
        int temp = calsawkwardness(arr, l);
        awkwardness = temp < awkwardness ? temp : awkwardness;
    }
    else
    {
        for (int j = i; j < l; j++)
        {
            swap(arr[j], arr[i]);
            permutation(arr, i + 1, l, awkwardness);
            swap(arr[j], arr[i]);
        }
    }
    return awkwardness;
}
int minOverallAwkwardness(vector<int> arr)
{
    int awkwardness = INT32_MAX;
    return permutation(arr, 0, arr.size(), awkwardness);
}
int main()
{
    cout << minOverallAwkwardness({5, 10, 6, 8}) << endl;
    cout << minOverallAwkwardness({1, 2, 5, 3, 7}) << endl;
    return 0;
}