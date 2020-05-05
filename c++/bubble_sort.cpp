#include <iostream>

using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *bubble_sort_array(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap((arr + j), (arr + j + 1));
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "-";
    }

    // Add your code above this line. Do not modify any other code.
    /* save the sorted array in int arr[] and return the same array */
    return arr;
}
int main()
{
    int arr[] = {5, 4, 3, 0, -1};
    bubble_sort_array(arr, 5);
    return 0;
}