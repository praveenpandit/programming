#include <iostream>
#include <vector>
using namespace std;

long sum(vector<int> arr, int start, int end)
{
    long sum = 0;
    for (int i = start; i < end; i++)
        sum += arr[i];
    return sum;
}
bool balancedSplitExists_utils(vector<int> arr, int split_idx, long left, long right)
{
    if (split_idx == arr.size() || split_idx == 0)
        return false;
    if (left < right)
        return balancedSplitExists_utils(arr, split_idx + 1, left + arr[split_idx + 1], right - arr[split_idx + 1]);
    else if (left > right)
        return balancedSplitExists_utils(arr, split_idx - 1, left - arr[split_idx - 1], right + arr[split_idx - 1]);
    else
        return arr[split_idx] != arr[split_idx + 1];
}
bool balancedSplitExists(vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int mid = arr.size() / 2;
    long left = sum(arr, 0, mid + 1);
    long right = sum(arr, mid + 1, arr.size());
    return balancedSplitExists_utils(arr, mid, left, right);
    // return false;
}
int main()
{
    // vector<int> arr = {2, 1, 2, 5};
    vector<int> arr = {3, 6, 3, 4, 4};
    // vector<int> arr = {1, 5, 7, 1};
    // vector<int> arr = {12, 7, 6, 7, 6};
    cout << balancedSplitExists(arr) << endl;
    return 0;
}