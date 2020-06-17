#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* int numberOfWays(vector<int> arr, int k)
{
    int count = 0;
    int temp = k;
    for (int i = 0; i < arr.size(); i++)
    {
        k = temp;
        k -= arr[i];
        for (int j = i + 1; k > 0 && j < arr.size(); j++)
        {
            if (arr[j] == k)
                count++;
        }
    }
    return count;
} */
int numberOfWays(vector<int> arr, int k)
{
    map<int, int> mp;
    for (auto i : arr)
    {
        if (!mp.count(i))
            mp.insert(pair(i, 1));
        else
            mp[i]++;
    }
    for (auto i : mp)
        cout << i.first << " : " << i.second << endl;
    for (auto i : mp)
        cout << mp.at(i.first) << " : ";
    // for (auto j : mp.find(i.first))
    //     cout
    //         << j << endl;

    /*  map<int, vector<int>> mp_new;
    for (auto i : mp)
    {
        cout << i.first << " : " << i.second << endl;
        if (!mp_new.count(i.second))
        {
            vector<int> temp = {i.first};
            mp_new.insert(pair(i.second, temp));
        }
        else
            mp_new[i.second].push_back(i.first);
    }
    for (auto i : mp_new)
    {
        cout << i.first << " : ";
        for (auto j : i.second)
            cout << j << " ";
        cout << endl;
    } */
    // cout << i.first << " : " << i.second << endl;
    /* for (auto i = mp.begin(); i != mp.end(); i++)
    {
        for (auto j = i; j != mp.end(); j++)
            cout << i->first << " : " << i->second << endl;
    } */
    return 0;
}
int main()
{
    cout << numberOfWays({1, 2, 3, 4, 3}, 6) << endl;
    return 0;
}