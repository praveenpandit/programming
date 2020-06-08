#include <iostream>
#include <vector>
using namespace std;
vector<int> findMedian(vector<int> arr)
{
    vector<int> v;
    make_heap(v.begin(), v.end());
    for (int i = 0; i < arr.size(); i++)
    {
        v.push_back(arr[i]);
        cout << v.size() << " ";
        push_heap(v.begin(), v.end());
    }
    return v;
}
int main()
{
    for (auto i : findMedian({5, 15, 1, 3}))
        cout << i << " ";
    return 0;
}