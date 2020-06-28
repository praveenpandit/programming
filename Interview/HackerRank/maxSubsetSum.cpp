#include <iostream>
#include <vector>
using namespace std;

void maxSubsetSum(vector<int> arr, int n, int &sum, int &max)
{
    if (n > arr.size())
        return;
    maxSubsetSum(arr, n + 2, sum += arr[n], max);
    if (sum > max)
        max = sum;
    sum -= arr[n];
    maxSubsetSum(arr, n + 1, sum, max);
}

// int maxSubsetSum(vector<int> arr)
// {
//     int sum = 0;
//     int max = 0;
//     maxSubsetSum(arr, 0, sum, max);
//     return max;
// }
int dp[10];
int maxSubsetSum(vector<int> arr)
{

    dp[0] = max(0, arr[0]);
    if (arr.size() == 1)
        return dp[0];
    dp[1] = max(dp[0], arr[1]);
    for (int i = 2; i < arr.size(); i++)
    {
        dp[i] = max(dp[i - 2], max(dp[i - 1], dp[i - 2] + arr[i]));
    }
    int n = arr.size();
    return max(dp[n - 1], dp[n - 2]);
}
int main()
{
    cout << maxSubsetSum({3, 7, 4, 6, 5}) << endl;
    cout << maxSubsetSum({-2, 1, 3, -4, 5}) << endl;
    return 0;
}