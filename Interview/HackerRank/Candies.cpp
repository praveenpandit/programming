#include <iostream>
#include <vector>
using namespace std;

/* long candies_rec(int n, vector<int> arr, vector<long> &candy)
{
    if (n >= arr.size() - 1)
    {
        long sum = 0;
        for (auto i : candy)
            sum += i;
        return sum;
    }
    if (arr[n + 1] > arr[n])
        candy[n + 1] = candy[n] + 1;
    else if (arr[n + 1] == arr[n])
        candy[n + 1] = 1;
    else if (arr[n + 1] < arr[n] && candy[n] == 1)
        candy[n]++, candy[n + 1] = 1;
    else
        candy[n + 1] = 1;
    return candies_rec(n + 1, arr, candy);
} */
long candies_iter(int n, vector<int> arr)
{
    long candy = 1;
    long sum = candy;
    int ascCount = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            if (ascCount >= candy)
                sum += abs(ascCount - candy) + 1, candy = 1;
            else if (ascCount > 0)
                candy = 1;
            candy++, sum += candy, ascCount = 0;
        }
        else
            ascCount++, sum += ascCount;
    }
    return sum;
}
long candies_iter1(int n, vector<int> arr)
{
    vector<int> l2r(arr.size(), 1);
    vector<int> r2l(arr.size(), 1);
    long sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            l2r[i] += l2r[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
            r2l[i] += r2l[i + 1];
    }
    for (int i = 0; i < n; i++)
        sum += max(l2r[i], r2l[i]);
    return sum;
}

int main()
{
    vector<int> children = {2, 4, 2, 6, 1, 7, 8, 9, 8, 7, 6, 5, 3, 1, 2, 6, 8};
    vector<int> children1 = {1, 2, 1, 2, 1, 2, 3, 4, 1, 1, 1, 1, 1, 1, 2, 3, 4};
    vector<int> children2 = {1, 2, 1, 2, 1, 1, 1, 7, 6, 5, 4, 3, 2, 1, 1, 1, 1};
    vector<int> result = {1, 2, 1, 2, 1, 2, 3, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4};
    int sum = 0;
    for (auto i : result)
        sum += i;
    cout << sum << endl;
    // vector<int> children = {1, 2, 2};
    // vector<long> candy(children.size(), 0);
    // candy[0] = 1;
    // cout << candies_rec(0, children, candy);
    cout << candies_iter1(children.size(), children);
    return 0;
}