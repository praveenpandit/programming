#include <iostream>
#include <vector>

using namespace std;

vector<int> findMaxProduct(vector<int> arr)
{
    vector<int> ret = {-1, -1};
    vector<int> v;
    if (arr.size() < 2)
        return ret;
    v.push_back(arr[0]);
    v.push_back(arr[1]);
    for (int i = 2; i < arr.size(); i++)
    {
        v.push_back(arr[i]);
        push_heap(v.begin(), v.end());
        int a1 = v.front();
        pop_heap(v.begin(), v.end());
        int a2 = v.front();
        pop_heap(v.begin(), v.end() - 1);
        int a3 = v.front();

        ret.push_back(a1 * a2 * a3);
        push_heap(v.begin(), v.end());
    }
    return ret;
}

int main()
{
    for (auto i : findMaxProduct({2, 4, 7, 1, 5, 3}))
        cout << i << " ";
    for (auto i : findMaxProduct({1, 2, 3, 4, 5}))
        cout << i << " ";
    return 0;
}
