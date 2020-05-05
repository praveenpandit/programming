#include <iostream>
using namespace std;

int positive_diff(int a, int b)
{
    return (a - b < 0) ? (b - a) : 0;
}

int max_gain(int arr[], int sz)
{
    int l = 0;
    int r = 1;
    int d = positive_diff(arr[l], arr[r]);
    for (int i = 2; i < sz; i++)
    {
        if (d < positive_diff(arr[l], arr[i]))
        {
            r = i;
        }
        else if (d < positive_diff(arr[r], arr[i]))
        {
            l = r;
            r = i;
        }
        d = positive_diff(arr[l], arr[r]);
    }
    return d;
}
int main()
{
    int arr[4] = {100, 40, 20, 10};
    // int arr[4] = {1, 5, 3, 10};
    cout << max_gain(arr, 4);
    return 0;
}