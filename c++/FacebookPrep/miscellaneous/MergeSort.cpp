#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end)
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= end)
        temp[k++] = arr[j++];
    for (int i = start; i <= end; i++)
        arr[i] = temp[i - start];
}

vector<int> &mergeSort(vector<int> &arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    return arr;
}

int main()
{
    vector<int> arr = {50, 23, 9, 18, 61, 32};
    for (auto i : mergeSort(arr, 0, arr.size() - 1))
        cout << i << " ";
    cout << endl;
    return 0;
}