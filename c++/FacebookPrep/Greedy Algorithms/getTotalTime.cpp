#include <iostream>
#include <vector>

using namespace std;

int getTotalTime(vector<int> arr)
{
    if (arr.size() == 1)
        return 0;
    make_heap(arr.begin(), arr.end());
    int top = arr.front();
    pop_heap(arr.begin(), arr.end());
    int top1 = arr.front();
    arr = vector(arr.begin() + 1, arr.end() - 1);
    arr.push_back(top1 + top);
    return top1 + top + getTotalTime(arr);
}
int main()
{
    cout << getTotalTime({4, 2, 1, 3}) << endl;
    cout << getTotalTime({2, 3, 9, 8, 4}) << endl;
    return 0;
}