#include <iostream>

using namespace std;

int *merge(int arr_left[], int sz_left, int arr_right[], int sz_right)
{
    /* declaring an array using dynamic allocation of memory. 
        Merged the given two arrays into this third output Array */
    int *arr_merged = new int[sz_left + sz_right];
    // Add your code below this line. Do not modify any other code.
    int l = 0;
    int r = 0;
    int length = sz_left + sz_right;
    for (int i = 0; i < length; i++)
    {
        if (l < sz_left && r < sz_right)
        {
            if (arr_left[l] < arr_right[r])
            {
                arr_merged[i] = arr_left[l++];
            }
            else
            {
                arr_merged[i] = arr_right[r++];
            }
        }
        else if (l < sz_left)
        {
            arr_merged[i] = arr_left[l++];
        }
        else
        {
            arr_merged[i] = arr_right[r++];
        }
    }
    // Add your code above this line. Do not modify any other code.
    /* retun the merged array */
    for (int i = 0; i < length; i++)
    {
        cout << arr_merged[i] << "-";
    }
    return arr_merged;
}

int main()
{
    int arr1[3] = {};
    int arr2[2] = {2, 4};

    merge(arr1, 0, arr2, 2);
    // cout << "hello world!!! ssh testing" << endl;
    return 0;
}
