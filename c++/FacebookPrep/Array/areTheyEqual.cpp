#include <iostream>
#include <vector>
using namespace std;

/* bool areTheyEqual(vector<int> &array_a, vector<int> &array_b)
{
    if (array_a.size() != array_b.size())
        return false;
    int i = 0;
    int j = 0;
    for (; i < array_a.size(); i++)
    {
        int k = i;
        if (array_a[i] == array_b[i])
            continue;
        else
        {
            j = i;
            if ((i + 1) == array_a.size())
                return false;
            while (array_a[i] != array_b[j])
                j++;
            while (array_a[i] == array_b[j--])
                i++;
            i--;
            if (j > i)
                return false;
        }
    }
    return true;
} */
bool areTheyEqual(vector<int> &array_a, vector<int> &array_b)
{
    if (array_a.size() != array_b.size())
        return false;
    sort(array_a.begin(), array_a.end());
    sort(array_b.begin(), array_b.end());
    for (int i = 0; i < array_a.size(); i++)
        if (array_a[i] != array_b[i])
            return false;
    return true;
}
int main()
{
    vector<int> arr_a = {1, 2, 3, 5, 7, 5, 6, 6, 4, 8};
    vector<int> arr_b = {1, 3, 2, 5, 4, 6, 6, 5, 7, 8};
    // vector<int> arr_a = {1, 2, 3, 4}; //, 7, 5, 6, 6, 4, 8};
    // vector<int> arr_b = {1, 4, 3, 2}; //5, 4, 6, 6, 5, 7, 9};
    cout << areTheyEqual(arr_a, arr_b);
    // sort(arr_a.begin(), arr_a.end());
    // sort(arr_b.begin(), arr_b.end());
    // reverse(arr_a.begin() + 1, arr_a.begin() + 3);
    // cout << (*(arr_a.begin() + 1) == *(arr_b.begin() + 1));
    return 0;
}