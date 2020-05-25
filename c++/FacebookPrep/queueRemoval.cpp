#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void popQueue(queue<pair<int, int>> &oq, vector<pair<int, int>> &nq, int x, int &max)
{
    if (x > 0 && !oq.empty())
    {
        if (max < oq.front().second)
            max = oq.front().second;
        nq.push_back(oq.front());
        oq.pop();
        popQueue(oq, nq, x - 1, max);
        if (nq.at(x).second != max)
        {
            int temp = nq.at(x).second ? nq.at(x).second - 1 : 0;
            oq.push(pair(nq.at(x).first, temp));
        }
        else
            max = INT32_MAX;
    }
}
int updateQueue(queue<pair<int, int>> &q, vector<pair<int, int>> v)
{
    int max = -1;
    int ret = 1;
    /* for (auto i : v)
    {
        if (i.second > max)
        {
            max = i.second;
            ret = i.first;
        }
    }
    bool flg = false;
    for (auto i : v)
    {
        if (i.second != max)
        {
            int temp = i.second ? (i.second - 1) : 0;
            q.push(pair(i.first, temp));
            flg = true;
        }
    }
    if (!flg)
        q.push(v[1]); */
    for (auto it = v.begin(); it != v.end(); it++)
    {
        if (it->second != max)
            q.push(*it);
        else
        {
            max = INT32_MAX;
            ret = it->first;
        }
    }
    return ret;
}
vector<int> findPositions(vector<int> arr, int x)
{
    queue<pair<int, int>> q;
    vector<int> ret;
    int j = 1;
    int max = -1;
    for (auto i : arr)
        q.push(pair(j++, i));
    for (int i = 0; i < x; i++)
    {
        vector<pair<int, int>> v;
        popQueue(q, v, x, max);
        ret.push_back(updateQueue(q, v));
    }
    return ret;
}

int main()
{
    vector<int> arr_1{1, 2, 2, 3, 4, 5};
    // cout << arr_1.front();
    /* vector<int> arr_2{2, 4, 2, 4, 3, 1, 2, 2, 3, 4, 3, 4, 4};
    vector<int> out;
    out = findPositions(arr_1, 5);
    for (auto i : out)
        cout << i << " ";
    out = findPositions(arr_2, 4);
    for (auto i : out)
        cout << i << " "; */
    return 0;
    // findPositions(arr_1, 5);
}