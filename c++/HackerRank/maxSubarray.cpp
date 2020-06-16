#include <iostream>
#include <vector>
using namespace std;

long subArraySum(vector<int> arr, int i)
{
    long sum = 0;
    while (i)
    {
        sum += arr[i];
        i -= i & -i;
    }
    return sum;
}

vector<int> maxSubarray(vector<int> arr)
{
    vector<int> ret(2, INT32_MIN);
    vector<int> m_arr = vector<int>(arr.size() + 1, 0);
    for (int i = 0; i < arr.size(); i++)
        m_arr[i + 1] = arr[i];
    for (int i = 1; i < m_arr.size(); i++)
    {
        int id = i + (i & -i);
        if (id < m_arr.size())
            m_arr[id] += m_arr[i];
    }
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
    for (auto i : m_arr)
        cout << i << " ";
    cout << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr.size(); j > i; j--)
        {
            long temp = subArraySum(m_arr, j) - subArraySum(m_arr, i);
            // cout << temp << endl;
            ret[0] = ret[0] > temp ? ret[0] : temp;
        }
    }
    // cout << ret[0] << endl;
    vector<int> p_arr;
    vector<int> n_arr;
    for (auto i : arr)
    {
        if (i > 0)
            p_arr.push_back(i);
        else
            n_arr.push_back(i);
    }
    if (p_arr.size() == 0)
    {
        make_heap(n_arr.begin(), n_arr.end());
        ret[1] = n_arr.front();
    }
    else
    {
        ret[1] = 0;
        for (auto i : p_arr)
            ret[1] += i;
    }
    // make_heap(arr.begin(), arr.end());
    // ret[1] = arr.front();
    // int i = 0;
    // while (arr.size() - 1 > i)
    // {
    //     pop_heap(arr.begin(), arr.end() - i);
    //     if (arr.front() < 0)
    //         break;
    //     ret[1] += arr.front();
    //     i++;
    // }
    // cout << ret[1] << endl;
    return ret;
}

int max_SubArray(vector<int> arr)
{
    int f = arr[0];
    int ans = f;
    for (int i = 1; i < arr.size(); i++)
    {
        f = max(arr[i], f + arr[i]);
        // cout << f << " ";
        ans = max(f, ans);
    }
    return ans;
}
int max_sum_subsequence(vector<int> arr)
{
    int m = arr[0];
    int t = 0;
    int j = 0;
    for (auto i : arr)
    {
        m = max(m, i);
        if (arr[j] >= 0)
            t += arr[j];
        j++;
    }
    return m >= 0 ? t : m;
}
int main()
{
    // cout << max_SubArray({2, -1, 2, 3, 4, -5}) << endl;
    // cout << max_sum_subsequence({2, -1, 2, 3, 4, -5}) << endl;
    // cout << max_SubArray({-2, -3, -1, -4, -6}) << endl;
    // cout << max_SubArray({1, 2, 3, 4}) << endl;
    for (auto i : maxSubarray({10, 20, 30, 40, 50, 60, 70, 80, 90, 100}))
        cout << i << " ";
    cout << endl;
    // for (auto i : maxSubarray({2, -1, 2, 3, 4, -5}))
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : maxSubarray({-2, -3, -1, -4, -6}))
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : maxSubarray({1, 2, 3, 4}))
    //     cout << i << " ";
    // cout << endl;
    // maxSubarray({-2, -3, -1, -4, -6});
    // maxSubarray({1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5});
    return 0;
}