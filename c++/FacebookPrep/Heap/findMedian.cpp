#include <iostream>
#include <vector>
using namespace std;

int median(vector<int> v, int i, int front)
{
    if (!(i / 2))
        return front;
    pop_heap(v.begin(), v.end());
    if (i % 2)
        median(v, i - 1, v.front());
    else
        median(v, i - 1, (front + v.front()) / 2);
    return;
}

vector<int> findMedian(vector<int> arr)
{
    vector<int> v;
    make_heap(v.begin(), v.end());
    for (int i = 0; i < arr.size(); i++)
    {
        v.push_back(arr[i]);
        push_heap(v.begin(), v.end());
        median(v, i + 1);
        // cout << v.size() << " " << v.front();
    }
    cout << endl;
    return v;
}
int main()
{
    for (auto i : findMedian({5, 15, 1, 3}))
        cout << i << " ";
    return 0;
}