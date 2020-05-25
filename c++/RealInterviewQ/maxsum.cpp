#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class solution
{
    int *arr;
    int length;
    map<int, vector<int>> mp;
    int sumDigit(int a)
    {
        if (a == 0)
            return 0;
        else
            return (a % 10 + sumDigit(a / 10));
    }
    void createMap(void)
    {
        for (int i = 0; i < length; i++)
        {
            int index = sumDigit(arr[i]);
            if (!mp.count(index))
            {
                vector<int> v;
                v.push_back(arr[i]);
                mp.insert(pair(index, v));
                make_heap(mp.at(index).begin(), mp.at(index).end());
            }
            else
            {
                mp.at(index).push_back(arr[i]);
                push_heap(mp.at(index).begin(), mp.at(index).end());
            }
        }
    }

public:
    solution(int *data, int size)
    {
        arr = data;
        length = size;
        createMap();
    }

    void display()
    {
        for (auto i : mp)
        {
            cout << i.first << "->";
            for (auto j : i.second)
                cout << j << "-";
            cout << endl;
        }
    }
    int getMaxSum(void)
    {
        auto max = -1;
        for (auto i : mp)
        {
            // cout << i.first << endl;
            if (i.second.size() > 1)
            {
                auto a1 = i.second.front();
                pop_heap(i.second.begin(), i.second.end());
                auto a2 = i.second.front();
                if (max < (a1 + a2))
                    max = a1 + a2;
            }
        }
        return max;
    }
};

int main()
{
    int arr[3] = {51, 32, 43};
    solution s(arr, sizeof(arr) / sizeof(arr[0]));
    // s.display();
    cout << s.getMaxSum();
}