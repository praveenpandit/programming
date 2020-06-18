#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{
    int pivot = end;
    int p_index = start;
    for (int i = start; i < end; i++)
        if (arr[i] < arr[pivot])
            swap(arr[i], arr[p_index++]);
    swap(arr[pivot], arr[p_index]);
    return p_index;
}

vector<int> &quickSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = partition(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
    return arr;
}

int main()
{
    vector<int> arr = {50, 23, 9, 18, 61, 32};
    // quickSort(arr, 0, arr.size() - 1);
    for (auto i : quickSort(arr, 0, arr.size() - 1))
        cout << i << " ";
    cout << endl;
    return 0;
}