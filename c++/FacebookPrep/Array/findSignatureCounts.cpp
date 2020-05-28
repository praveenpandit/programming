#include <iostream>
#include <vector>
using namespace std;
vector<int> findSignatureCounts(vector<int> arr)
{
    vector<int> sign(arr.size(), 1);
    for (int i = 0; i < arr.size(); i++)
    {
        if ((i + 1) == arr[i])
            continue;
        else
        {
            sign[i]++;
            sign[arr[i] - 1]++;
            swap(arr[arr[i] - 1], arr[i]);
        }
    }
    return sign;
}
int main()
{
    for (auto i : findSignatureCounts({1, 2}))
        cout << i << " ";
    return 0;
}