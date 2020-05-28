#include <iostream>
#include <vector>
using namespace std;

int minSteps(vector<int> arr, int n = 0, int m = 1)
{
    if (m >= arr.size() || n < 0)
        return 0;
    if (arr[n] != arr[m])
    {
        arr[n] = arr[m];
        return (1 + minSteps(arr, m, m + 1) + minSteps(arr, 0, 1));
    }
    else
        return 0;
}
int main()
{
    int step = 0;
    cout << minSteps({7, 5, 2, 1});
    // cout << step;
    return 0;
}