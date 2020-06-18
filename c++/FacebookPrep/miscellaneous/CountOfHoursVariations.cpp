#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool isValidTime(vector<int> arr)
{
    int hour = arr[0] * 10 + arr[1];
    int minitus = arr[2] * 10 + arr[3];
    if ((hour >= 0 && hour < 24) && (minitus >= 0 && minitus < 60))
        return true;
    return false;
}
void permutation(vector<int> str, int l, int r, int &sum)
{
    if (l == r)
    {
        // for (auto i : str)
        //     cout << i << " ";
        // cout << endl;
        sum += isValidTime(str) ? 1 : 0;
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[i], str[l]);
            permutation(str, l + 1, r, sum);
            swap(str[i], str[l]);
        }
    }
}
int CountOfHoursVariations(int a, int b, int c, int d)
{
    vector<int> arr = {a, b, c, d};
    map<int, int> mp;
    for (auto i : arr)
        mp[i]++;
    int sum = 0;
    permutation(arr, 0, arr.size() - 1, sum);
    for (auto i : mp)
    {
        int temp = i.second;
        do
        {
            sum /= temp;
        } while (--temp);
    }
    // cout << i.first << " : " << i.second << endl;
    return sum;
}
int main()
{
    cout << CountOfHoursVariations(1, 0, 0, 2) << endl;
    cout << CountOfHoursVariations(1, 2, 1, 2) << endl;
    cout << CountOfHoursVariations(1, 8, 4, 2) << endl;
    cout << CountOfHoursVariations(2, 2, 2, 2) << endl;
    // int sum = 0;
    // permutation({1, 2, 4, 8}, 0, 3, sum);
    // cout << sum;

    return 0;
}