#include <iostream>
#include <vector>

using namespace std;

vector<int> CountSubarrays(vector<int> arr)
{
    vector<int> ret;
    for (int i = 0; i < arr.size(); i++)
    {
        int subarr = 0;
        for (int j = i; j < arr.size(); j++)
        {
            if (arr[i] >= arr[j])
                subarr++;
            else
                break;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] >= arr[j])
                subarr++;
            else
                break;
        }
        ret.push_back(subarr);
    }
    return ret;
}

int main()
{
    vector<int> a = {3, 4, 1, 6, 2};
    // for (auto i : CountSubarrays({3, 4, 1, 6, 2}))
    for (auto i : CountSubarrays({2, 4, 7, 1, 5, 3}))
        cout << i << " ";
    return 0;
}