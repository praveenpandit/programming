#include <iostream>
#include <vector>
using namespace std;

int maxCandies(vector<int> arr, int k)
{
    make_heap(arr.begin(), arr.end());
    int sum = 0;
    for (int i = k; i > 0; i--)
    {
        int a = arr.front();
        sum += a;
        pop_heap(arr.begin(), arr.end());
        arr.pop_back();
        arr.push_back(a / 2);
        push_heap(arr.begin(), arr.end());
    }
    return sum;
}

int main()
{
    cout << maxCandies({2, 1, 7, 4, 2}, 3) << endl;
    cout << maxCandies({19, 78, 76, 72, 48, 8, 24, 74, 29}, 3) << endl;
    return 0;
}