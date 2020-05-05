#include <iostream>
using namespace std;

bool binary_search_rec(int arr[], int l, int r, int n)
{
    if (r >= l)
    {
        int m = (l + r) / 2;
        if (arr[m] == n)
            return true;
        if (arr[m] > n)
            return binary_search_rec(arr, l, m - 1, n);
        return binary_search_rec(arr, m + 1, r, n);
    }
    return false;
}
bool binary_search(int arr[], int size, int n)
{
    return binary_search_rec(arr, 0, size - 1, n);
}
int main()
{
    int arr[] = {2, 5, 7, 8, 9};
    cout << binary_search(arr, 5, 1);
    cout << binary_search(arr, 5, 2);
    cout << binary_search(arr, 5, 3);
    cout << binary_search(arr, 5, 4);
    cout << binary_search(arr, 5, 5);
    cout << binary_search(arr, 5, 6);
    cout << binary_search(arr, 5, 7);
    cout << binary_search(arr, 5, 8);
    cout << binary_search(arr, 5, 9);
    cout << binary_search(arr, 5, 10);
    return 0;
}