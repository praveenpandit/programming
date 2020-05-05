#include <iostream>

using namespace std;

int *selection_sort_array(int arr[], int size)
{

    // Add your code above this line. Do not modify any other code.
    /* save the sorted array in int arr[] and return the same array */
    for (int i = 0; i < size; i++)
    {
        int k = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[k] > arr[j])
            {
                k = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    return arr;
}

int main()
{
    int arr[5] = {1, 5, 0, -1, 3};
    selection_sort_array(arr, 5);
    return 0;
}