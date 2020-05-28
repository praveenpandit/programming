#include <iostream>
#include <vector>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int diff = INT32_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        // for (int j = i + 1; j < arr.size(); j++)
        // {
        int temp = std::abs(arr[i] - arr[i + 1]);
        if (diff > temp)
            diff = temp;
        // }
    }
    return diff;
}
int main()
{
    vector<int> arr = {-59, -36, -13, 1, -53, -92, -2, -96, -54, 75};
    cout << minimumAbsoluteDifference(arr);
    return 0;
}