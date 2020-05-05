#include <iostream>
using namespace std;
int find_missing_number(int arr[], int n)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        if (arr[i] ^ (i + 1))
            break;
    }
    return i + 1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    cout << find_missing_number(arr, 9) << endl;
    return 0;
}